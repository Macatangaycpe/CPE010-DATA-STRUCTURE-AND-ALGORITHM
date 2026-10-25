#ifndef SINGLE_LL_H
#define SINGLE_LL_H

#include <iostream>

template <typename T>
class SingleList {
public:
    T data;
    SingleList<T>* next = NULL;
};

// Traversal
template <typename T>
void ListTraversal(SingleList<T>* head) {
    if (head == NULL) {
        std::cout << "The List has no contents.";
    }
    while (head != NULL) {
        std::cout << head->data;
        if (head->next != NULL)
            std::cout << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

// Insert at the Head
template <typename T>
void stillinsertheader(T newData, SingleList<T>** head) {
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// General Inserter
template <typename T>
void stillGeneralInserter(T newData, SingleList<T>* preNode){
    if (preNode == NULL) {
        std::cout << "Previous Value cannot be null." << std::endl;
        return;
    }
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = preNode->next;
    preNode->next = newNode;
}

// Insert at End
template <typename T>
void stillInsertEnd(T newData, SingleList<T>** head) {
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    SingleList<T>* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Deletes a specific node
template <typename T>
void sllDeleteNode(T findData, SingleList<T>** head) {
    if(*head == NULL) return;

    SingleList<T>* currentNode = *head;
    SingleList<T>* prevNode = NULL;

    while(currentNode != NULL && currentNode->data != findData) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        std::cout << "Data does not exist. Try again." << std::endl;
        return;
    }

    if (prevNode == NULL) {
        *head = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }

    delete currentNode;
}

// Delete all Nodes
template <typename T>
void stillDeleteAllNodes(SingleList<T> **head) {
    SingleList<T>* current = *head;
    while (current != NULL) {
        SingleList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = NULL;
}

#endif