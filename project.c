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
