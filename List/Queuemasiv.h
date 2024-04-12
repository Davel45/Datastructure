//
// Created by Vadim on 12.04.2024.
//

#ifndef DATASTRUCTURE_QUEUEMASIV_H
#define DATASTRUCTURE_QUEUEMASIV_H
#define SIZE 10
#include <iostream>

using namespace std;
template<typename T>
class QueueOnMassifs {
private:
    T items[SIZE];
    int front, rear;

public:
    bool isFull(){
        if(front == 0 and rear == SIZE-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }

    void Enqueue(T data){
        if(isFull()){
            throw runtime_error("Queue is Full");
        }

        if(front==-1){
            front=0;
        }
        rear++;
        items[rear] = data;
    }

    T Dequeue(){
        if(isEmpty()){
            throw runtime_error("Queue is Empty");
        }

        T temp = items[front];

        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            T temp_mas[SIZE];

            for(int i=0;i<=rear;i++){
                temp_mas[i]=items[i+1];
            }

            for(int i=0;i<size(temp_mas);i++){
                items[i]=temp_mas[i];
            }
            rear--;
        }
        return temp;
    }

    T Peek(){
        if(isEmpty()){
            throw runtime_error("Queue is Empty");
        }
        return items[front];
    }

    friend ostream &operator<<(ostream &os, QueueOnMassifs<T> &obj) {
        if(obj.isEmpty()){
            os << "Queue is Empty";
        }
        else{
            os << "Queue data: " << endl;
            for(int i=obj.front; i<=obj.rear;i++){
                os << obj.items[i];
                os<<" ";
            }
            os << endl;
        }
        return os;
    }

    int getSize(){
        return rear+1;
    }

    QueueOnMassifs(): front{-1}, rear{-1}{};
    QueueOnMassifs(T data):front{0},rear{0} {items[front]=data;};
    ~QueueOnMassifs(){};
};
#endif //DATASTRUCTURE_QUEUEMASIV_H
