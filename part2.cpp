//
// Created by alex on 7.11.20.
//

#include "part2.h"

mutex mtx2;

void initOptions(int & ProducerNum, int & ConsumerNum, int & QueueSize, int & queueChoice) {
    cout << "Enter task(1, 2)" << endl;
    cout << "1st task: Non-fixed size queue" << endl;
    cout << "2nd task: Fixed size queue" << endl;
    cin >> queueChoice;
    cout << "Enter ProducerNum(1, 2, 4), ConsumerNum(1, 2, 4)";
    if (queueChoice == 2)
        cout << ", QueueSize(1, 4, 16)";
    cout << endl;
    cin >> ProducerNum;
    cin >> ConsumerNum;
    if (queueChoice == 2)
        cin >> QueueSize;
}

void dumpTimestamps(const vector<int> & timestamps) {
    int i = 1;
    for (auto duration : timestamps) {
        cout << i << ") " << " " << duration << endl;
        i++;
    }
    cout << endl;
}

void dumpTasks(const int & ProducerNum, const int & NumTasks, const vector<Consumer> & consumers) {
    cout << "NumTasks * ProducerNum = " << NumTasks * ProducerNum << endl;
    cout << "Consumers counters:" << endl;
    int total = 0;
    for (auto c : consumers) {
        total += c.getCounter();
        cout << c.getCounter() << endl;
    }
    cout << "Total:" << total << endl;
}

void executeTask2() {
    vector<int> timestamps;

    int NumTasks = 1024 * 1024 * 4;
    int ProducerNum;
    int ConsumerNum;
    int QueueSize;
    int queueChoice;

    initOptions(ProducerNum, ConsumerNum, QueueSize, queueChoice);
    Queue *q;
    if (queueChoice == 1)
        q = new Queue1();
    else
        q = new Queue2(QueueSize);

    vector<Consumer> consumers(ConsumerNum);
    vector<Producer> producers(ProducerNum, Producer(NumTasks));
    vector<thread> threads;
    threads.reserve(ProducerNum + ConsumerNum);

    for(const auto& p : producers)
        threads.push_back(move(thread(&Producer::produce, p, q, ref(timestamps))));

    for (auto& c : consumers)
        threads.push_back(move(thread(&Consumer::consume, ref(c), q, ref(timestamps))));

    for (auto & th : threads)
        th.join();

    dumpTasks(ProducerNum, NumTasks, consumers);

    dumpTimestamps(timestamps);

    delete (q);
}