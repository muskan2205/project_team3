#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAfter(int, int);
void deleteByValue(int);
void deleteAtBeginning();
void deleteAtEnd();
void search(int);
void display();
int countNodes();
void reverseList();
int main() {
    int choice, data, position;
    while (1) {
	    printf("\n\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete by Value\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Search for Element\n");
        printf("8. Display List\n");
        printf("9. Count Nodes\n");
        printf("10. Reverse List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	 switch (choice) {
