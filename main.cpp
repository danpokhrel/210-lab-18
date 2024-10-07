// COMSC-210 | Lab 18 | Dan Pokhrel
// IDE used: Visual Studio Code
#include <iostream>
#include <string>
using namespace std;

struct Movie { // linked list node
    float rating;
    string comment;
    Movie *next = nullptr;
};

// Prototypes
void pushFront(Movie **head, Movie *node); // Adds node to front of list
void pushBack(Movie **head, Movie *node); // Adds node to back of list
void deleteList(Movie **head); // Deletes entire list

int main() {
    Movie *moviesHd;

    // Get linked list input preference
    cout << "Which linked list method should we use?\n";
    cout << "\t[1] New nodes are added at the head of the linked list";
    cout << "\t[2] New nodes are added at the tail of the linked list";
    cout << "\tChoice: ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 2){ // Input validation
        cout << "Invalid Input";
        return 0;
    }

    //  Input Movie Data
    bool stop = false;
    while (!stop){
        // Variables
        Movie *tmp;
        char another;

        // Inputs
        cout << "Enter review rating 0-5: ";
        cin >> tmp->rating;
        if (tmp->rating < 0 || tmp->rating > 5){ // Input validation
            cout << "Invalid Input";
            return 0;
        }
        cout << "Enter review comments: ";
        cin.ignore();
        getline(cin, tmp->comment);

        cout << "Enter another review? Y/N: ";
        cin >> another;
    }

    return 0;
}

void pushFront(Movie **head, Movie *node){
    if (!head) // First node
        *head = node;
    else{ // Add node before head
        node->next = *head;
        *head = node;
    }
}

void pushBack(Movie **head, Movie *node){
    if (!(*head)){ // First node
        *head = node;
        return;
    }
    Movie *current = *head;
    while (current->next) // iterate through list
        current = current->next;

    current->next = node;
}

void deleteList(Movie **head){
    Movie *current = *head;
    while (current){ // iterate through list
        *head = current->next;
        delete current;
        current = *head;
    }
    *head = nullptr;
}