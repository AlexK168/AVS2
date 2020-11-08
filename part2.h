//
// Created by alex on 7.11.20.
//

#ifndef AVS2_PART2_H
#define AVS2_PART2_H

#include <queue>
#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable>
#include <atomic>
#include <map>

using namespace std;
using namespace std::chrono;

extern mutex mtx2;

void executeTask2();

class Queue {
protected:
    mutex mtx;
    queue<uint8_t> q;
public:
    virtual void push(uint8_t val) = 0;
    virtual bool pop(uint8_t & val) = 0;
};

class Queue1 : public Queue{
public:
    void push(uint8_t val) override {
        mtx.lock();
        q.push(val);
        mtx.unlock();
    }
    bool pop(uint8_t& val) override {
        mtx.lock();
        if (q.empty()) {
            mtx.unlock();
            this_thread::sleep_for(milliseconds(1));
            mtx.lock();
            if (q.empty()) {
                mtx.unlock();
                return false;
            }
        }
        val = q.front();
        q.pop();
        mtx.unlock();
        return true;
    }
};

class Queue2 : public Queue {
protected:
    condition_variable cv;
    int sizeLimit;
public:
    explicit Queue2(int newSize) {
        sizeLimit = newSize;
    }

    void push(uint8_t val) override {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, [&]{return (q.size() < sizeLimit);});
        q.push(val);
        cv.notify_one();
    }

    bool pop(uint8_t& val) override {
        unique_lock<mutex> ul(mtx);
        if (q.empty()) {
            cv.wait_for(ul, milliseconds(1));
            if (q.empty()) {
                ul.unlock();
                return false;
            }
        }
        val = q.front();
        q.pop();
        cv.notify_one();
        return true;
    }
};

class Consumer {
private:
    int counter = 0;
public:
    void consume(Queue* q, vector<int> & timestamps) {
        auto start = steady_clock::now();
        uint8_t tmp = 0;
        while (q->pop(tmp)) {
            counter += tmp;
        }
        auto finish = steady_clock::now();
        auto duration = duration_cast<milliseconds>(finish - start).count();

        mtx2.lock();
        timestamps.push_back(duration);
        mtx2.unlock();
    }

    int getCounter()  {return counter;}
};

class Producer {
private:
    int TaskNum;
public:
    explicit Producer(int taskNum) {TaskNum = taskNum;}
    void produce(Queue* q, vector<int> & timestamps) {
        auto start = steady_clock::now();
        for (int i = 0; i < TaskNum; i++) {
            q->push(1);
        }
        auto finish = steady_clock::now();
        auto duration = duration_cast<milliseconds>(finish - start).count();

        mtx2.lock();
        timestamps.push_back(duration);
        mtx2.unlock();
    }
};

#endif //AVS2_PART2_H


