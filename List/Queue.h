//
// Created by Vadim on 12.04.2024.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H
#include "../node/Queuenode.h"
#include <iostream>
using namespace std;
using namespace queuenode;

template<typename T>
class Queue {
private:
    shared_ptr<QueueNode<T>> head;
    shared_ptr<QueueNode<T>> tail;
    int size;

public:
    void Enqueue(T data) {
        shared_ptr<QueueNode<T>> newNode = make_shared<QueueNode<T>>(data);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    }

    T Dequeue() {
        if (!head) {
            throw runtime_error("Queue is empty");
        }

        T temp = head->data;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->previous.reset();
        }
        size--;
        return temp;
    }

    T Peek() {
        if (!head) {
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    bool IsEmpty(){
        if(size==0){
            return true;
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    friend ostream &operator<<(ostream &os, Queue<T> &obj) {
        os << "Queue data: " << endl;
        shared_ptr<QueueNode<T>> current = obj.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
        return os;
    }

    Queue(): head{nullptr}, tail{nullptr}, size{0} {};
    Queue(T data) : head{make_shared<QueueNode<T>>(data)}, tail{head}, size{1} {};
    ~Queue() {};
};
#endif //DATASTRUCTURE_QUEUE_H
