#include <iostream>
//Structure which acts as the blocks in the linked list
// TODO need to change the Node from being a structure to a class
struct Node{
    int data; // The data part of the linked list
    Node* next; // The link part which is a pointer to next node in the list
};

Node* head; // The first element of the linked list

// TODO need to rename the function to be more clear that it adds the element at the beginning
void insert(int x); // Function to insert an element to the linked list

void print(); // Function to print all the elements of the linked list

int main() {
    int n,x;
    std::cout << "Hello Github!\n";
    head = NULL;

    std::cout << "how many numbers \n"; //Input for how many elements we want to add to the list
    std::cin >> n;

    for(int i =0; i <n; i++){
        std::cout << "Enter the numbers\n";
        std::cin >> x;
        insert(x); // Take n inputs from stdin and insert at the beginning of the list using insert()function
        print(); // simple function to print the list
    }

    return 0;
}

void insert(int x){
    Node* temp = new Node; //Make a new temp node
    temp -> data =x; // Set the data in node to our value
    temp -> next = head; // Set the value of pointer to next node as the previous value of first node
    head = temp; // Then make temp the first Node
}

void print(){
    Node* temp = head; // Make a new node pointer that points to the first element in the list
    std::cout << "List is: ";
    while(temp !=NULL){ // go through the list untill no more next elements to go to are left
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << "\n";

}
