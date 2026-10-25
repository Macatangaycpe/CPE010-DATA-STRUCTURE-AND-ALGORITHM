#include <iostream>
#include <stack>

int main() {
    std::string newString;
    bool isSymmetrical = true;
    std::cout<<"Enter a not String maybe?: ";
    std::cin >> newString;

    for (size_t j = 0; j < newString.length(): j++) {
        char num = newString[j];
        push(num);
        char poppoedStack[] = pop();
    }
        if (j>0 && num==top()) {
         if (isEmpty<char>()){
            std::cout<<"The Stack is Empty?"<<std::endl;
            isSymmetrical = false;
         }
         char poppedIndex = pop();
         bool match = isMatching(poppedIndex, num);
         if (match == 1){
            std::cout<<poppedIndex<<" and "<<num<<"are match"<<std::endl;
         }else{
            stdd::cout<<"ERROR: "<<poppedIndex<< " and "<<num<<"are not match"<<std::endl;
         }
         if (!isMatchingPair(poppedIndex, num)) {
            isSymmetrical = false; 
            break;
         }
}

if (isSymmetrical && isEmpty<char>()) {
    std::cout<< "The expression is Symmetrical" <<std::endl;
} else {
    std::cout<< "The expression is not Symmetrical" <<std::endl;
}

return 0;

}
