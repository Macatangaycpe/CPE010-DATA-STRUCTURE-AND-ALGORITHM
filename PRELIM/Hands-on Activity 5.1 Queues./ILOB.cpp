#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    if(isEmpty(&front, &back)){
        std::cout << "The queue is empty\n";
    }
        
    

    enqueue('J', &front, &back);
    std::cout<<"front: "<< front->data <<" "<<"back: " <<back->data<<std::endl;
      enqueue('A', &front, &back);
    std::cout<<"front: "<< front->data <<" "<<"back: " <<back->data<<std::endl;
     enqueue('K', &front, &back);
    std::cout<<"front: "<< front->data <<" "<<"back: " <<back->data<<std::endl;
      enqueue('E', &front, &back);
    std::cout<<"front: "<< front->data <<" "<<"back: " <<back->data<<std::endl;

    //testing the all display
    std::cout<<"Queue elements: ";
    displayQ(&front, &back);

    std::cout<<"Testing the dequeue operator: \n ";
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data <<" "<<"back: " <<back->data<<std::endl;
    dequeue(&front, &back);
    std::cout<<"front: "<< front->data <<" "<<"back: " <<back->data<<std::endl;
    dequeue(&front, &back);
    dequeue(&front, &back);
    dequeue(&front, &back);

  
    return 0;
}