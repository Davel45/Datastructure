//
// Created by Vadim on 12.04.2024.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H
#include "../node/StackNode.h"
#include <iostream>

using namespace std;
using namespace stacknode;

template<typename T>
class Stack {
private:
    unique_ptr<StackNode<T>> head;
    int size;

public:
    void Push(T data){
        unique_ptr<StackNode<T>> newNode = make_unique<StackNode<T>>(data);
        newNode->next = move(head);
        head = move(newNode);
        size++;
    }

    T Pop() {
        if (!head) {
            throw runtime_error("Stack is empty!");
        }
        T temp = head->data;
        head = move(head->next);
        --size;
        return temp;
    }

    T Peek(){
        if (!head) {
            throw runtime_error("Stack is empty!");
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

    friend ostream &operator<<(ostream &os, Stack &obj){
        StackNode<T> *current = obj.head.get();
        os << "Stack data: " << endl;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << endl;
        return os;
    }

    Stack() : head{nullptr}, size{0} {};
    Stack(int value) : head{make_unique<StackNode<T>>(value)}, size{1} {};

    ~Stack(){};
};
#endif //DATASTRUCTURE_STACK_H
