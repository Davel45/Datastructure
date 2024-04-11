//
// Created by Vadim on 11.04.2024.
//

#ifndef DATASTRUCTURE_SINGLELINKEDLIST_H
#define DATASTRUCTURE_SINGLELINKEDLIST_H
#include "../node/SingleNode.h"
#include <iostream>

using namespace std;
using namespace singlenode;
template<typename T>

class SinglyLinkedList {
private:
    unique_ptr<SingleNode<T>> head;
    int size;
    void CheckIndex(int index) const{
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
    }

public:
    void AddToBack(T data){
        unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(data);
        SingleNode<T> *current = head.get();

        if (!current) {
            head = move(newNode);
            size++;
            return;
        }

        while (current->next) {
            current = current->next.get();
        }
        current->next = move(newNode);
        size++;
    }
    void AddToBeginning(T data){
        unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(data);
        newNode->next = move(head);
        head = move(newNode);
        size++;
    }
    void AddAtIndex(int index, int data) {
        CheckIndex(index);

        if (index == 0) {
            AddToBeginning(data);
            return;

        } else if (index == size) {
            AddToBack(data);
            return;
        }

        else {
            unique_ptr<SingleNode<T>> newNode = make_unique<SingleNode<T>>(data);
            SingleNode<T> *current = head.get();

            for (int i = 0; i < index-1; i++) {
                current = current->next.get();
            }
            newNode->next = move(current->next);
            current->next = move(newNode);
            size++;
        }
    }

    void DeleteFromBeginning() {
        if (!head) {
            throw out_of_range("List is empty!");
        }
        head = move(head->next);
        --size;
    }
    void DeleteFromEnd() {
        if (!head) {
            throw out_of_range("List is empty!");
        }
        if (size == 1) {
            head.reset();
            --size;
            return;
        }
        SingleNode<T> *current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        --size;
    }
    void DeleteAtIndex(int index) {
        CheckIndex(index);

        if (index == 0) {
            DeleteFromBeginning();

        } else if (index == size - 1) {
            DeleteFromEnd();
        }
        else{
            SingleNode<T> *current = head.get();

            for (int i = 0; i < index - 1; i++) {
                current = current->next.get();
            }
            current->next = move(current->next->next);
            --size;
        }
    }

    T& operator[](const int index) const {
        CheckIndex(index);
        SingleNode<T> *current = head.get();
        for (int i = 0; i < index; i++) {
            current = current->next.get();
        }
        return current->data;
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

    friend ostream &operator<<(ostream &os, SinglyLinkedList &obj){
        SingleNode<T> *current = obj.head.get();
        os << "List data: " << endl;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << endl;
        return os;
    }

    bool Search(T data) const {
        SingleNode<T> *current = head.get();
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next.get();
        }
        return false;
    }

    SinglyLinkedList() : head{nullptr}, size{0} {};
    SinglyLinkedList(int value) : head{make_unique<SingleNode<T>>(value)}, size{1} {};

    ~SinglyLinkedList(){};
};
#endif //DATASTRUCTURE_SINGLELINKEDLIST_H
