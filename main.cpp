// COMSC-210 | Lab 18 | Dan Pokhrel
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

struct Node { // linked list node
    float value;
    Node *next = nullptr;
};

// Prototypes
void pushFront(Node **head, Node *node); // Adds node to front of list
void pushBack(Node **head, Node *node); // Adds node to back of list
void deleteList(Node **head); // Deletes entire list

int main() {
    

    return 0;
}

void pushFront(Node **head, Node *node){
    if (!head) // First node
        *head = node;
    else{ // Add node before head
        node->next = *head;
        *head = node;
    }
}

void pushBack(Node **head, Node *node){
    if (!(*head)){ // First node
        *head = node;
        return;
    }
    Node *current = *head;
    while (current->next) // iterate through list
        current = current->next;

    current->next = node;
}

void deleteList(Node **head){
    Node *current = *head;
    while (current){ // iterate through list
        *head = current->next;
        delete current;
        current = *head;
    }
    *head = nullptr;
}