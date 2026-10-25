#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <iostream>

template <typename T>
class DoubleList {
public:
    T data;
    DoubleList<T>* prev = NULL;
    DoubleList<T>* next = NULL;
};

template <typename T>
DoubleList<T>* CreateNewNode(T newData) {
    DoubleList<T>* newNode = new DoubleList<T>;
    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode) { 
    DoubleList<T>* tail = NULL;

    if (currentNode == NULL) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    
    std::cout << "Forward:\n";
    while (currentNode != NULL) {
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout << std::endl;

    std::cout << "Backward:\n";
    while (tail != NULL) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead) {
    DoubleList<T>* newNode = CreateNewNode(newData);
    newNode->next = *currentHead;

    if (*currentHead != NULL) {
        (*currentHead)->prev = newNode;
    }
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead) {
    if (currentHead == NULL) return;

    DoubleList<T>* newNode = CreateNewNode(newData);
    
    while (currentHead->next != NULL) {
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;
    newNode->prev = currentHead;
}

template <typename T>
void dllGenInsert(T newData, DoubleList<T>* currentHead) {
    if (currentHead == NULL) {
        std::cout << "Target node cannot be Null" << std::endl;
        return;
    }

    DoubleList<T>* newNode = CreateNewNode(newData);
    newNode->next = currentHead->next;
    newNode->prev = currentHead;

    if (currentHead->next != NULL) {
        currentHead->next->prev = newNode;
    }
    currentHead->next = newNode;
}

template <typename T>
void dllDelNode(T findData, DoubleList<T>** currentHead) {
    if (currentHead == NULL || *currentHead == NULL) return;

    DoubleList<T>* currNode = *currentHead;

    while (currNode != NULL && currNode->data != findData) {
        currNode = currNode->next;
    }

    if (currNode == NULL) return; // Node not found

    if (currNode == *currentHead) {
        *currentHead = currNode->next;
    }
    
    if (currNode->prev != NULL) {
        currNode->prev->next = currNode->next;
    }

    if (currNode->next != NULL) {
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}

#endif
