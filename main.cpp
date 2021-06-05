#include <iostream>
//Structure which acts as the blocks in the linked list
// TODO need to change the Node from being a structure to a class
struct Node{
    int data; // The data part of the linked list
    Node* next; // The link part which is a pointer to next node in the list
};

Node* head; // The first element of the linked list

// TODO need to rename the function to be more clear that it adds the element at the beginning
void insert(int data); // Function to insert an element to the linked list
void insert(int data,int index);
void print(); // Function to print all the elements of the linked list
void deleteAt(int index);
int main() {
    int n,x;
    std::cout << "Hello Github!\n";
    head = NULL;

    std::cout << "How many numbers \n"; //Input for how many elements we want to add to the list
    std::cin >> n;

    for(int i =0; i <n; i++){
        std::cout << "Enter the numbers\n";
        std::cin >> x;
        insert(x); // Take n inputs from stdin and insert at the beginning of the list using insert()function
        print(); // simple function to print the list
    }
    insert(10,1);
    print();
    insert(11,4);
    print();
    deleteAt(0);
    print();
    deleteAt(3);
    print();
    return 0;
}

void insert(int data){
    Node* temp = new Node; //Make a new temp node
    temp -> data = data; // Set the data in node to our value
    temp -> next = head; // Set the value of pointer to next node as the previous value of first node
    head = temp; // Then make temp the first Node
}

void insert(int data,int index){
    Node* temp1 = new Node;
    temp1->data = data;
    temp1->next = NULL;
    if(index==0){
        temp1-> next = head; // Set the value of pointer to next node as the previous value of first node
        head = temp1; // Then make temp the first Node
        return;
    }
    Node* temp2 = head;
    for(int i = 0; i < index-1; i++){
      temp2 = temp2 -> next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void deleteAt(int index){
    Node* temp;
    if(index == 0){
        temp = head;
        head = temp->next;
        delete temp;
        return;
    }
    Node* currentNode = head;
    for(int i =0; i < index-1; i++ ){
        currentNode = currentNode->next;
    }
    temp = currentNode->next;
    currentNode->next = temp->next;
    delete temp;

}

void print(){
    Node* temp = head; // Make a new node pointer that points to the first element in the list
    std::cout << "List is: ";
    // go through the list untill no more next elements to go to are left
    while(temp !=NULL){
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << "\n";

}
