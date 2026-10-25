#include <iostream>
#include "doubly_ll.h"

int main() {
    
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third ->prev = second;
    
    std::cout<<"Testing the DLL Traversal"<<std::endl;
    dllTraverse(head);

std::cout<<"Testing the insertion at the head node"<<std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    std::cout<<"Testing the insertion at the end node"<<std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

std::cout<<"Testing the insertion at the General Insert node"<<std::endl;
    dllGenInsert('6', head -> next-> next);
    dllTraverse(head);

std::cout<<"Testing the insertion of the Delete node"<<std::endl;
    dllDelNode('P', &head);
    dllTraverse(head);

    return 0;
}
