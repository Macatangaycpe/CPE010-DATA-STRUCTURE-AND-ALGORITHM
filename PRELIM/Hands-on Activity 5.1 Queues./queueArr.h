#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

//ARRAY BASED QUEUE IMPLEMENTATION
template <typename T>
class QueueArr{
    private:
    //dynamic array allocate the queue
    T* q_array;

    //maximum number of elements in the queue
    size_t q_capacity;
    //current number of elements in the queue
    size_t q_size;
    //index of the front element in the queue
    int q_front;
    //index of the back element in the queue
    int q_back;


    public:
    //constructor
    QueueArr(size_t capacity = 10);
    //copy constructor
    QueueArr(const QueueArr<T>& other);
    //copy assignment operator
    QueueArr<T>& operator=(const QueueArr<T>& other);
    //destructor
    ~QueueArr();
    //queue operator
    bool Empty();
    bool Full();

    size_t Size();

    void clear();
    T Front();
    T Back();
    void Enqueue(T value);
    T Dequeue();
};

// Constructor
template <typename T>
QueueArr<T>::QueueArr(size_t capacity) {
    q_capacity = capacity;
    q_array = new T[q_capacity];
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

// Copy Constructor
template <typename T>
QueueArr<T>::QueueArr(const QueueArr<T>& other) {
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;
    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; i++) {
        q_array[i] = other.q_array[i];
    }
}

// Copy Assignment Operator
template <typename T>
QueueArr<T>& QueueArr<T>::operator=(const QueueArr<T>& other) {
    if (this != &other) {
        delete[] q_array;
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_array = new T[q_capacity];
        for (size_t i = 0; i < q_capacity; i++) {
            q_array[i] = other.q_array[i];
        }
    }
    return *this;
}

// Destructor
template <typename T>
QueueArr<T>::~QueueArr() {
    delete[] q_array;
}

//empty
template <typename T>
bool QueueArr<T>::Empty(){
    //check if the size if zero
    return q_size == 0;
}

//full
template <typename T>
bool QueueArr<T>::Full(){
    //check size if its max capacity
    return q_size == q_capacity;
}

//size_t
template <typename T>
size_t QueueArr<T>::Size(){
    return q_size;
}

// Front
template <typename T>
T QueueArr<T>::Front(){
    if(Empty()){
        std::cout<<"Queue is Empty\n";
        return T();
    }
    return q_array[q_front];
}

// Back
template<typename T>
T QueueArr<T>::Back(){
    //Check if the queue is empty
    if(Empty()){
        std::cout<<"Queue is empty"<<std::endl;
        return T();
    }
    //return to the back
    return q_array[q_back];
}

//clear all
template <typename T>
void QueueArr<T>::clear(){
    //reset the size and front and back index
    q_size = 0;
    q_front = 0;
    q_back = -1;
}

//Void Enqueue 
template <typename T>
void QueueArr<T>::Enqueue(T value){

    //check if the queue is full
    if(Full()){
        std::cout<<"Queue is full\n";
        return;
    }
    //move q_back circularly
    q_back = (q_back + 1) % q_capacity;

    //store  the value to the back
    q_array[q_back] = value;

    //increment the q_size
    q_size++;
}

//T Dequeue
template <typename T>
T QueueArr<T>::Dequeue(){
    //check if the queue is empty
    if(Empty()){
        std::cout<<"Queue is empty\n";
        return T();
    }
    //store the front value to return
    T value = q_array[q_front];

    //move q_front circularly
    q_front = (q_front + 1) % q_capacity;

    //decrement the size
    q_size--;

    // reset indexes if queue becomes empty
    if(Empty()) clear();

    //return to temporary value
    return value;
}

#endif