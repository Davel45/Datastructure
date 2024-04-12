//
// Created by Vadim on 12.04.2024.
//

#ifndef DATASTRUCTURE_STACKOFMASIV_H
#define DATASTRUCTURE_STACKOFMASIV_H
#define SIZE 10
#include <iostream>

using namespace std;
template<typename T>
class StackOnMassifs {
private:
    T items[SIZE];
    int top;

public:
    bool isFull(){
        if(top == SIZE-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    void Push(T data){
        if(isFull()){
            throw runtime_error("Stack is Full!");
        }
        items[++top] = data;
    }

    T Pop(){
        if(isEmpty()){
            throw runtime_error("Stack is Empty");
        }
        T temp = items[top];

        T temp_mas[SIZE];

        for(int i=0;i<top;i++){
            temp_mas[i]=items[i];
        }

        for(int i=0;i<size(temp_mas);i++){
            items[i]=temp_mas[i];
        }

        top--;
        return  temp;
    }

    T Peek(){
        if(isEmpty()){
            throw runtime_error("Stack is Empty");
        }
        return items[top];
    }

    int getSize(){
        return top+1;
    }

    friend ostream &operator<<(ostream &os, StackOnMassifs<T> &obj) {
        if(obj.isEmpty()){
            os << "Stack is Empty";
        }
        else{
            os << "Stack data: " << endl;
            for(int i=obj.top; i>=0;i--){
                os << obj.items[i];
                os<<" ";
            }
            os << endl;
        }
        return os;
    }

    StackOnMassifs():top{-1}{};
    StackOnMassifs(T data):top{0} {items[top]=data;};
    ~StackOnMassifs(){};
};
#endif //DATASTRUCTURE_STACKOFMASIV_H
