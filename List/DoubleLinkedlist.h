//
// Created by Vadim on 11.04.2024.
//

#ifndef DATASTRUCTURE_DOUBLELINKEDLIST_H
#define DATASTRUCTURE_DOUBLELINKEDLIST_H
#include "../node/DoubleNode.h"
#include <iostream>
using namespace std;
using namespace doublenode;

template<typename T>
class DoubleLinkedList {
private:
    shared_ptr<DoubleNode<T>> head;
    shared_ptr<DoubleNode<T>> tail;
    int size;
    void CheckIndex(int index) const{
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
    }
public:
    void AddToBeginning(T data) {
        shared_ptr<DoubleNode<T>> newNode = make_shared<DoubleNode<T>>(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        size++;
    }
    void AddToBack(T data) {
        shared_ptr<DoubleNode<T>> newNode = make_shared<DoubleNode<T>>(data);
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
    void AddAtIndex(int index, T data) {
        CheckIndex(index);

        if (index == 0) {
            AddToBeginning(data);
        }

        if (index == size) {
            AddToBack(data);
        }

        shared_ptr<DoubleNode<T>> newNode = make_shared<DoubleNode<T>>(data);
        shared_ptr<DoubleNode<T>> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
        size++;
    }

    void DeleteFromBeginning() {
        if (!head) {
            return;
        }

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->previous.reset();
        }
        size--;
    }
    void DeleteFromEnd() {
        if (!tail) {
            return;
        }

        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->previous.lock();
            tail->next = nullptr;
        }
        size--;
    }
    void DeleteAtIndex(int index) {
        CheckIndex(index);

        if (index == 0) {
            head = head->next;
            if (head) {
                head->previous.reset();
            } else {
                tail.reset();
            }
        }
        else if (index == size - 1) {
            tail = tail->previous.lock();
            tail->next.reset();
        }
        else {
            shared_ptr<DoubleNode<T>> current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->previous.lock()->next = current->next;
            current->next->previous = current->previous;
        }
        size--;
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

    int operator[](int index) const {
        CheckIndex(index);

        shared_ptr<DoubleNode<T>> current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        return current->data;
    }

    bool Search(T value) const {
        shared_ptr<DoubleNode<T>> current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, DoubleLinkedList &obj) {
        os << "List data: " << endl;
        shared_ptr<DoubleNode<T>> current = obj.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        os << endl;
        return os;
    }


    DoubleLinkedList() : head{nullptr}, tail{nullptr}, size{0} {};
    DoubleLinkedList(T data) : head{make_shared<DoubleNode<T>>(data)}, tail{head}, size{1} {};
    ~DoubleLinkedList() {};

};
#endif //DATASTRUCTURE_DOUBLELINKEDLIST_H
