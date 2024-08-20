#include <stdio.h> 
#include <stdlib.h> 
  
// Template for a doubly linked list node 
struct Node { 
    int value;             // To store the data
    struct Node* nextPtr;  // Pointer to the next node
    struct Node* prevPtr;  // Pointer to the previous node
}; 
  
// Pointers to the start (headPtr) and end (tailPtr) of the linked list 
struct Node* headPtr = NULL; 
struct Node* tailPtr = NULL; 
  
// Function to create a new node with the provided value
struct Node* create_node(int value) 
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->value = value;         // Assign the value to the new node
    newNode->nextPtr = NULL;        // Initialize next pointer to NULL
    newNode->prevPtr = NULL;        // Initialize previous pointer to NULL
    return newNode;                 // Return the pointer to the newly created node
} 
  
// Function to insert a node at the beginning of the list 
void insert_at_head(int value) 
{ 
    struct Node* newNode = create_node(value); // Create a new node with the provided value
    if (headPtr == NULL) { 
        headPtr = newNode; // If the list is empty, set headPtr and tailPtr to the new node
        tailPtr = newNode; 
    } 
    else { 
        newNode->nextPtr = headPtr; // Link the new node to the current head node
        headPtr->prevPtr = newNode; // Link the current head node back to the new node
        headPtr = newNode;          // Update headPtr to the new node
    } 
} 
  
// Function to insert a node at the end of the list 
void insert_at_tail(int value) 
{ 
    struct Node* newNode = create_node(value); // Create a new node with the provided value
    if (tailPtr == NULL) { 
        headPtr = newNode; // If the list is empty, set headPtr and tailPtr to the new node
        tailPtr = newNode; 
    } 
    else { 
        newNode->prevPtr = tailPtr; // Link the new node to the current tail node
        tailPtr->nextPtr = newNode; // Link the current tail node forward to the new node
        tailPtr = newNode;          // Update tailPtr to the new node
    } 
} 
  
// Function to delete the node at the beginning of the list 
void delete_at_head() 
{ 
    if (headPtr == NULL) { 
        return; // If the list is empty, there's nothing to delete
    } 
    struct Node* tempNode = headPtr; // Temporary pointer to hold the node to be deleted
    if (headPtr == tailPtr) { 
        headPtr = NULL; // If the list has only one node, reset headPtr and tailPtr
        tailPtr = NULL; 
    } 
    else { 
        headPtr = headPtr->nextPtr; // Move headPtr to the next node
        headPtr->prevPtr = NULL;    // Set the previous pointer of the new head to NULL
    } 
    free(tempNode); // Free the memory of the deleted node
} 
  
// Function to delete the node at the end of the list 
void delete_at_tail() 
{ 
    if (tailPtr == NULL) { 
        return; // If the list is empty, there's nothing to delete
    } 
    struct Node* tempNode = tailPtr; // Temporary pointer to hold the node to be deleted
    if (headPtr == tailPtr) { 
        headPtr = NULL; // If the list has only one node, reset headPtr and tailPtr
        tailPtr = NULL; 
    } 
    else { 
        tailPtr = tailPtr->prevPtr; // Move tailPtr to the previous node
        tailPtr->nextPtr = NULL;    // Set the next pointer of the new tail to NULL
    } 
    free(tempNode); // Free the memory of the deleted node
} 
  
// Function to display the list in forward direction 
void display_forward() 
{ 
    struct Node* currentPtr = headPtr; // Start from the head of the list
    while (currentPtr != NULL) { 
        printf("%d ", currentPtr->value); // Print the current node's value
        currentPtr = currentPtr->nextPtr; // Move to the next node
    } 
    printf("\n"); 
} 
  
// Function to display the list in backward direction 
void display_backward() 
{ 
    struct Node* currentPtr = tailPtr; // Start from the tail of the list
    while (currentPtr != NULL) { 
        printf("%d ", currentPtr->value); // Print the current node's value
        currentPtr = currentPtr->prevPtr; // Move to the previous node
    } 
    printf("\n"); 
} 
  
// Driver code to test the doubly linked list 
int main() 
{ 
    insert_at_head(100); 
    insert_at_head(200); 
    insert_at_tail(450); 
    insert_at_tail(230); 
    insert_at_tail(900); 
    insert_at_tail(60); 
    display_forward();   // expected output: 200 100 450 230 900 60 
    display_backward();  // expected output: 60 900 230 450 100 200 
    delete_at_head(); 
    delete_at_tail(); 
    display_forward();   // expected output: 100 450 230 900 
    display_backward();  // expected output: 900 230 450 100 
  
    return 0; 
}

