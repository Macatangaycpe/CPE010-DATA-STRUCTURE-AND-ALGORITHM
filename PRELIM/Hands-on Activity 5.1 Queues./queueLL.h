#ifndef QUEUELL_H
#define QUEUELL_H


template <typename T>
class qNode{
    public:
       T data;
       qNode* next;
};

template <typename T>
qNode<T>* new_node(T newData){

    //
    qNode<T>* newNode = new qNode<T>;

    //store the newData to the newNode 
    newNode -> data = newData;
    //point the newNode next to null
    newNode -> next = nullptr;

    return newNode;


}

//enqueue 
template <typename T>
void enqueue(T newData, qNode<T>**frontPtr, qNode<T>** backPtr ){
    //create a new node 
    qNode <T>* newNode = new_node(newData);

    //check if the queue is empty
    if((*frontPtr)==nullptr && (*backPtr)== nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
        return;
    }

    //if not then insert at the back
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;

}
//dequeue
template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    //
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout<< "The queue is empty"<<std::endl;
        return;
    }
    //create a temporary variables to store the node to be deleted 
    qNode<T>* deleteTemp = nullptr;

    //assign the current front to the deleteTemp
    deleteTemp = (*frontPtr);

    //chech if the queue has only 1 item
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        //means only 1 item is inside the queue
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteTemp;
        return;
    }

    (*frontPtr) = (*frontPtr)->next;
    deleteTemp->next = nullptr;

    //delete node
    delete deleteTemp;
}

//display
template <typename T>
void displayQ(qNode<T>** frontPtr, qNode<T>** backPtr){
    //check is empty 
    if((*frontPtr) == nullptr && (*backPtr) == nullptr){
        std::cout<< "The queue is empty"<<std::endl;
        return;
    }
    //display all items
    while ((*frontPtr) != nullptr){
        std::cout<<(*frontPtr)->data;
        if((*frontPtr)->next != nullptr){
            std::cout<<" ";

        }
        (*frontPtr) = (*backPtr)->next;
    }
    std::cout<<std::endl;


};
//isEmpty
template <typename T>
bool isEmpty(qNode<T>** frontPtr,qNode<T>** backPtr){
    return((*frontPtr) == nullptr && (*backPtr) == nullptr);
}




#endif