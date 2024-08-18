// This source code was edited from Thareja, Reema - Data structures using C (2014, Oxford University Press)
// by Boonchoo Jitnupong

#include <stdio.h>   // Standard input-output header
#include <stdlib.h>  // Standard library header for memory allocation
#include <conio.h>   // Console input-output header (platform-specific)
#include <malloc.h>  // Memory allocation header

// Define the structure for a node in the linked list
struct node {
    int data;           // Data part of the node
    struct node *next;  // Pointer to the next node
};

// Initialize the start of the linked list to NULL
struct node *start = NULL;

// Function prototypes for linked list operations
struct node *create_ll();                     // Function to create the linked list
struct node *display();                       // Function to display the linked list
struct node *insert_beg(struct node *);       // Function to insert a node at the beginning
struct node *insert_end(struct node *);       // Function to insert a node at the end
struct node *delete_beg(struct node *);       // Function to delete a node from the beginning
struct node *delete_end(struct node *);       // Function to delete a node from the end
struct node *delete_list(struct node *);      // Function to delete the entire list (not implemented here)
struct node *find_data (struct node *);

// Main function
void main() {
    int option;  // Variable to store user's menu choice
    do {
        // Display the menu
        printf("\n\n * ****MAIN MENU * ****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Find data");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\nSelect your choice: ");
        scanf("%d", &option);  // Read user's choice

        // Perform the selected operation
        switch (option) {
            case 1: start = create_ll(start); printf("\n LINKED LIST CREATED"); break;
            case 2: start = display(start); break;
            case 3: start = insert_beg(start); break;
            case 4: start = insert_end(start); break;
            case 7: start = delete_beg(start); break;
            case 8: start = delete_end(start); break;
            case 5: start = find_data(start); break;
        }
    } while (option != 10);  // Continue until the user selects option 5 (exit)
}

// Function to create the linked list
struct node *create_ll() {
    struct node *new_node, *ptr;  // Pointers for new node and traversal
    int num[] = {20, 30, 50, 60, 90}, i;  // Array of data to initialize the list

    for (i = 0; i < 5; i++) {  // Loop to create 5 nodes
        new_node = (struct node *)malloc(sizeof(struct node));  // Allocate memory for new node
        new_node->data = num[i];  // Assign data to the new node

        if (start == NULL) {  // If the list is empty
            new_node->next = NULL;  // Set next of new node to NULL
            start = new_node;       // Make new node the start of the list
        } else {  // If the list is not empty
            ptr = start;  // Initialize ptr to start of the list
            while (ptr->next != NULL)  // Traverse to the last node
                ptr = ptr->next;
            ptr->next = new_node;  // Link the last node to the new node
            new_node->next = NULL;  // Set next of new node to NULL
        }
    }
    return start;  // Return the start of the list
}

// Function to display the linked list
struct node *display() {
    struct node *ptr;  // Pointer for traversal
    ptr = start;  // Initialize ptr to start of the list
    while (ptr != NULL) {  // Traverse until the end of the list
        printf("%d ", ptr->data);  // Print the data of the current node
        printf("%p\t", ptr->next);  // Print the address of the next node
        ptr = ptr->next;  // Move to the next node
    }
    return start;  // Return the start of the list
}

// Function to insert a node at the beginning
struct node *insert_beg(struct node *start) {
    struct node *new_node;  // Pointer for the new node
    int num;  // Variable to store user input data
    printf("\n Enter the data: ");
    scanf("%d", &num);  // Read user input data
    new_node = (struct node *)malloc(sizeof(struct node));  // Allocate memory for new node
    new_node->data = num;  // Assign data to the new node
    new_node->next = start;  // Link new node to the current start
    start = new_node;  // Make new node the start of the list
    return start;  // Return the updated start of the list
}

// Function to insert a node at the end
struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;  // Pointers for traversal and new node
    int num;  // Variable to store user input data
    printf("\n Enter the data: ");
    scanf("%d", &num);  // Read user input data
    new_node = (struct node *)malloc(sizeof(struct node));  // Allocate memory for new node
    new_node->data = num;  // Assign data to the new node
    new_node->next = NULL;  // Set next of new node to NULL
    ptr = start;  // Initialize ptr to start of the list
    while (ptr->next != NULL)  // Traverse to the last node
        ptr = ptr->next;
    ptr->next = new_node;  // Link the last node to the new node
    return start;  // Return the start of the list
}

// Function to delete a node from the beginning
struct node *delete_beg(struct node *start) {
    struct node *ptr;  // Pointer to the node to be deleted
    ptr = start;  // Initialize ptr to start of the list
    start = start->next;  // Move start to the next node
    free(ptr);  // Free the memory of the deleted node
    return start;  // Return the updated start of the list
}

// Function to delete a node from the end
struct node *delete_end(struct node *start) {
    struct node *ptr, *preptr;  // Pointers for traversal and the previous node
    ptr = start;  // Initialize ptr to start of the list
    while (ptr->next != NULL) {  // Traverse to the last node
        preptr = ptr;  // Keep track of the previous node
        ptr = ptr->next;  // Move to the next node
    }
    preptr->next = NULL;  // Set next of the second last node to NULL
    free(ptr);  // Free the memory of the deleted node
    return start;  // Return the start of the list
}

struct node *find_data (struct node *start){
	struct node *ptr = start;
	int search;
	printf("Find data :");
	scanf("%d",&search);
	while (ptr != NULL && ptr->data != search){
		ptr = ptr->next;
	}
	if (ptr != NULL && ptr->data == search){
		printf("%d",ptr->data);
		printf("%p\n",ptr->next);
	}else{
		printf("mai ru na eiei");
	}
	return start;
}
