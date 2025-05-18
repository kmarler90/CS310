Initialize head to nullptr:
 The original code declared Node* head but did not initialize it. Using an uninitialized pointer leads to undefined behavior when checking if (head == nullptr). Initializing the head to nullptr ensures the condition works as intended on the first iteration.
Allocate memory for new nodes with new:
 The original code had Node* newNode = nullptr, followed by (*newNode).data = I, which dereferences a null pointer, causing a crash. Fixing this by Node* newNode = new Node () appropriately allocates memory on the heap for the new Node.
Curr must be a pointer, not an object:
 The code used Node curr = head, which tries to assign a pointer (head) to an object (curr), a type mismatch and incorrect for traversing a linked list. Changing it to Node* curr = head allows traversal through the list via pointer.  Overall this one was a lot of fun to go through.












#include <iostream>

using namespace std;

// Node struct for a Linked List
struct Node {
    int data;
    Node* next;
};

int main() {
    const int LINKED_LIST_SIZE = 5;

    // Initialize a linked list
    Node* head = nullptr;      // Fix 1: Initialize head to nullptr
    Node* current = nullptr;

    // Use a loop to create 5 nodes and assign their data values (1 through 5)
    for (int i = 1; i <= LINKED_LIST_SIZE; i++) {
        // Assign a pointer to a new Node location in memory
        Node* newNode = new Node();   // Fix 2: Allocate memory with new
        newNode->data = i;
        newNode->next = nullptr;

        // If this is the first iteration, head is nullptr
        if (head == nullptr) {
            // Head becomes the first new node
            head = newNode;
            // Set current to point to the same node as head (used to add more nodes)
            current = head;
        }
        else {
            // Link the previous node's next to this new node
            current->next = newNode;
            // Update the current to this new node for next iteration
            current = newNode;
        }
    }

    // Print each node's data contents of the linked list
    cout << "Linked List contents:" << endl;
    // Track the current node to print
    Node* curr = head;    // Fix 3: curr must be a pointer, not an object
    // When we hit a nullptr, that's the end of the linked list
    while (curr != nullptr) {
        // Print the data value
        cout << curr->data << " ";
        // Move curr to the next node
        curr = curr->next;
    }
    cout << endl;

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
