#include <iostream>
#include <string>

class Job {
private:
    int jobID;
    std:: string userName;
    int numberOfPages;

public:
    Job() : jobID(0), userName(""), numberOfPages(0) {}

    Job(int id, std::string name, int pages)
        : jobID(id), userName(name), numberOfPages(pages) {}

    int getJobID() const { return jobID; }
    std::string getUserName() const { return userName; }
    int getNumberOfPages() const { return numberOfPages; }

    void printDetails() const {
        std::cout <<"[Job ID: " << jobID
                  <<" | User: " << userName 
                  <<" | Pages: " << numberOfPages << "]";
    }

};

struct Node {
    Job data;
    Node* next;
    Node(Job j) : data(j), next (nullptr) {}
};

class Printer {
    private:
    Node* frontPtr;
    Node* backPtr;
    int jobCount;

public:
    Printer() : frontPtr(nullptr), backPtr(nullptr), jobCount(0) {}

    ~Printer() {
        while (!isEmpty()) {
            processNextJob();
        }
    }

    bool isEmpty() const {
        return frontPtr == nullptr;
    }

void addJob(const Job& newJob) {
    Node* newNode = new Node(newJob);
    if (isEmpty()) {
        frontPtr = newNode;
        backPtr = newNode;
    } else {
        backPtr->next = newNode;
        backPtr = newNode;
    }
    jobCount++;
    std::cout << "-> Added to Spooler: ";
    newJob.printDetails();
    std::cout << "\n";
}

void processNextJob() {
    if(isEmpty()) {
        std::cout << "Printer status: No pending jobs to process \n";
        return; 
    }
    Node* tempPtr = frontPtr;
    std::cout << "=> Processing: ";
    tempPtr->data.printDetails();
    std::cout << " ... Done!\n";

    frontPtr = frontPtr->next;
    if (frontPtr == nullptr) {
        backPtr = nullptr;
    }

    delete tempPtr;
    jobCount--;
}

void displayPendingJobs() const {
    if(isEmpty()) {
        std::cout << "Printer Queue Status: Empty \n";
        return;
    }

    std::cout << "\n--- Current Pending Jobs in Printer Queue (" << jobCount<< ") ---\n";
    Node* current = frontPtr;
    int position = 1;
    while (current != nullptr) {
        std::cout << position++ << ". ";
        current->data.printDetails();
        std::cout << "\n";
        current = current->next;
    }
    std::cout << "----------------------------------------\n\n";
}
};

int main() {
    Printer officePrinter;

    std::cout << "=== OFFICE SHARED PRINTER ===\n\n";
    officePrinter.addJob(Job(101, "Justin", 19));
    officePrinter.addJob(Job(102, "Zamond", 20));
    officePrinter.addJob(Job(103, "Romuel", 21));

    officePrinter.displayPendingJobs();

    std::cout << "--- Printer begins processing ---\n";
    officePrinter.processNextJob();
    officePrinter.processNextJob();
    

    officePrinter.processNextJob();

    std::cout << "--- New Job sumbitted while printing ---\n";
    while (!officePrinter.isEmpty()) {
        officePrinter.processNextJob();
    }

    officePrinter.displayPendingJobs();

    return 0;

    
}