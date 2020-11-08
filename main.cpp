#include "part2.h"
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <map>
#include <algorithm>


using namespace std;
using namespace std::chrono;

mutex mxt;

int index = 0;
atomic<int> atomicIndex = 0;
map<thread::id, long> timestamps;
int8_t a;
void executeTaskMutexFreeze(vector<int8_t>& tasks) {
    int size = tasks.size();
    int tmpIndex;
    auto start = steady_clock::now();
    do {
        mxt.lock();
        tmpIndex = index++;
        mxt.unlock();
        tasks[tmpIndex]++;
        this_thread::sleep_for(nanoseconds(10));
    } while (tmpIndex < size);
    auto finish = steady_clock::now();
    auto duration = duration_cast<milliseconds>(finish - start).count();
    auto id = this_thread::get_id();
    mxt.lock();
    timestamps[id] = duration;
    mxt.unlock();
}

void executeTaskMutexNoFreeze(vector<int8_t>& tasks) {
    int size = tasks.size();
    int tmpIndex;
    auto start = steady_clock::now();
    do {
        mxt.lock();
        tmpIndex = index++;
        mxt.unlock();
        tasks[tmpIndex]++;
    } while (tmpIndex < size);
    auto finish = steady_clock::now();
    auto duration = duration_cast<milliseconds>(finish - start).count();
    auto id = this_thread::get_id();
    mxt.lock();
    timestamps[id] = duration;
    mxt.unlock();
}

int increment() {
    return atomicIndex++;
}

void executeTaskAtomicFreeze(vector<int8_t>& tasks) {
    int size = tasks.size();
    int tmpIndex;
    auto start = steady_clock::now();
    do {
        tmpIndex = increment();
        tasks[tmpIndex]++;
        this_thread::sleep_for(nanoseconds(10));
    } while (tmpIndex < size);
    auto finish = steady_clock::now();
    auto duration = duration_cast<milliseconds>(finish - start).count();
    auto id = this_thread::get_id();
    mxt.lock();
    timestamps[id] = duration;
    mxt.unlock();
}

void executeTaskAtomicNoFreeze(vector<int8_t>& tasks) {
    int size = tasks.size();
    int tmpIndex;
    auto start = steady_clock::now();
    do {
        tmpIndex = increment();
        tasks[tmpIndex]++;
    } while (tmpIndex < size);
    auto finish = steady_clock::now();
    auto duration = duration_cast<milliseconds>(finish - start).count();
    auto id = this_thread::get_id();
    mxt.lock();
    timestamps[id] = duration;
    mxt.unlock();
}

void instantiate(vector<int8_t>& tasks, const int& size ) {
    tasks.resize(size, 0);
}

void showMsg() {
    cout << "Enter command. Examples:" << endl;
    cout << "exec -num 16 -m -d" << endl;
    cout << "exec -num 32 -d" << endl;
    cout << "exec -num 8 -m" << endl;
    cout << "Use -num flag to specify amount of threads" << endl;
    cout << "Select -m option to execute mutex-way. Otherwise it's executed using atomic" << endl;
    cout << "Select -d option to execute with delays(heavy calculations)" << endl;
}

void initOptions(bool& sleep, bool& choice, int& NumThreads) {
    cout << "Enter ThreadsNum(4, 8, 16 32), m to exec mutex-way, a to exec atomic-way," << endl;
    cout << "d to exec with delays, n to exec without delays" << endl;
    cin >> NumThreads;
    string input;
    cin >> input;
    if (input == "m")
        choice = true;
    cin >> input;
    if (input == "d")
        sleep = true;

    if (choice)
        cout << "Mutex ";
    else
        cout << "Atomic ";
    if (sleep)
        cout << "with delay, ";
    else
        cout<< "without delay, ";
    cout << NumThreads << " threads" << endl;
}

void dumpTimestamps() {
    int inc = 1;
    for (auto [id, duration]: timestamps) {
        cout << inc << ") " << "Id: " << id << ", duration: " << duration << endl;
        inc++;
    }
    cout << endl;
}
void checkTasks(const vector<int8_t>& v) {
    for (auto item : v) {
        if(item != 1) {
            cout << "I messed up" << endl;
            break;
        }
    }
    cout << "All tasks are completed successfully!" << endl;
}

void executeTask1() {
    int NumTasks = 1024 * 1024 * 4;
    int NumThreads = 32;
    bool sleep;
    bool mutexChosen;

    initOptions(sleep, mutexChosen, NumThreads);

    vector<int8_t> tasks;
    instantiate(tasks, NumTasks);

    vector<thread> threads;
    threads.reserve(NumThreads);

    if (mutexChosen) {
        if (sleep)
            for (int i = 0; i < NumThreads; i++)
                threads.push_back(move(thread(executeTaskMutexFreeze, ref(tasks))));
        else
            for (int i = 0; i < NumThreads; i++)
                threads.push_back(move(thread(executeTaskMutexNoFreeze, ref(tasks))));
    } else {
        if (sleep)
            for (int i = 0; i < NumThreads; i++)
                threads.push_back(move(thread(executeTaskAtomicFreeze, ref(tasks))));
        else
            for (int i = 0; i < NumThreads; i++)
                threads.push_back(move(thread(executeTaskAtomicNoFreeze, ref(tasks))));
    }
    for (auto & th : threads)
        th.join();

    dumpTimestamps();

    checkTasks(tasks);
}

int main() {
    cout << "Enter Part(1, 2)" << endl;
    cout << "1st part: " << "Параллельный обход массива элементов" << endl;
    cout << "2st part: " << "Производитель + потребитель" << endl;
    int choice = 0;
    cin >> choice;
    if (choice == 1)
        executeTask1();
    else
        executeTask2();

    return 0;
}
