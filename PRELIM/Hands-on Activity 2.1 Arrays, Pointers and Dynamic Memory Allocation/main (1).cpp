#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:

      //Constructor
      Student(std::string newName ="Joe Doe", int newAge=18){
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." << std::endl;
      };

      //Deconstructor 
      ~Student(){
        std::cout << "Destrcutor Called." << std::endl;
      }

      //Copy Constructor 
      Student(const Student &copyStudent){
        std::cout << "Copy Constructor Called" << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
      }

      //Display Attributes
      void printDetails(){
        std::cout << this->studentName << " " << this->studentAge << std::endl;

      }

};

int main() {
  const size_t j = 5;

   Student studentList[j] = {};
    std::string nameList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    Student student1("Roman", 28);
    Student student2(student1);
    Student student3;
    student3 = student2;

    for(int i = 0; i < j; i++) { //loop A
       Student *ptr = new Student(nameList[i], ageList[i]);
       studentList[i] = *ptr;

       delete ptr;

       ptr = nullptr; 

     }

    for(int i = 0; i < j; i++){ //loop B
       studentList[i].printDetails();
    }

    return 0;

}



   

   



  
