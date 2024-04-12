//
// Created by Vadim on 12.04.2024.
//

#ifndef DATASTRUCTURE_INPUTRESTRICTEDQUEUE_H
#define DATASTRUCTURE_INPUTRESTRICTEDQUEUE_H
#include "../node/Queuenode.h"
#include <iostream>
using namespace std;
using namespace queuenode;

template<typename T>
class Inputrestrictedqueue {
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
    T DeleteFromEnd() {
        if (!tail) {
            throw runtime_error("Queue is empty");;
        }

        T temp = tail->data;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->previous.lock();
            tail->next = nullptr;
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
    T PeekFromEnd(){
        if(!tail){
            throw runtime_error("Queue is empty");
        }
        return tail->data;
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

    friend ostream &operator<<(ostream &os, Inputrestrictedqueue &obj) {
        os << "Queue data: " << endl;
        shared_ptr<QueueNode<T>> current = obj.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
        return os;
    }

    Inputrestrictedqueue(): head{nullptr}, tail{nullptr}, size{0} {};
    Inputrestrictedqueue(T data) : head{make_shared<QueueNode<T>>(data)}, tail{head}, size{1} {};
    ~Inputrestrictedqueue() {};
};

#endif //DATASTRUCTURE_INPUTRESTRICTEDQUEUE_H
