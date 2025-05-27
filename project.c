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
		 case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
		case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
		case 3:
                printf("Enter node value to insert after: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfter(position, data);
                break;
		case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(data);
                break;
		case 5:
                deleteAtBeginning();
                break;
		 case 6:
                deleteAtEnd();
                break;
		 case 7:
                printf("Enter value to search: ");
                scanf("%d", &data);
                search(data);
                break;
		case 8:
                display();
                break;
		case 9:
                printf("Total nodes = %d\n", countNodes());
                break;
		 case 10:
                reverseList();
                printf("List reversed successfully.\n");
                break;
		 case 11:
                printf("Exiting...\n");
                exit(0);
		default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void insertAtBeginning(int data) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", data);
}
void insertAtEnd(int data) {
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
 if (head == NULL) {
        head = newNode;
	 } else {
		 struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", data);

}
void insertAfter(int value, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d after %d.\n", data, value);
}
void deleteByValue(int value) {
    struct Node *temp = head, *prev = NULL;

project.c
if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Deleted node with value %d.\n", value);
        return;
    }
while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }
 prev->next = temp->next;
    free(temp);
    printf("Deleted node with value %d.\n", value);
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Deleted node at beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted last node.\n");
        return;
    }
 struct Node *temp = head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
prev->next = NULL;
    free(temp);
    printf("Deleted last node.\n");
}
void search(int key) {
    struct Node* temp = head;
    int position = 1;
    void search(int key) {
    struct Node* temp = head;
    int position = 1;
while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d.\n", key, position);
            return;
        }
	temp = temp->next;
        position++;
    }
printf("Value %d not found in the list.\n", key);
}
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
   printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int countNodes() {
    int count = 0;
    struct Node* temp = head;
     while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
	}
    head = prev;
}







CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAfter(int posData, int data);
void deleteByValue(int data);
void deleteAtBeginning();
void deleteAtEnd();
void search(int data);
void displayForward();
void displayBackward();
int countNodes();
void reverseList();
int main() {
    int choice, data, pos;
    while (1) {
        printf("\n\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete by Value\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Search for Element\n");
        printf("8. Display Forward\n");
        printf("9. Display Backward\n");
        printf("10. Count Nodes\n");
        printf("11. Reverse List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
	switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
		case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
		case 3:
                printf("Enter existing node value: ");
                scanf("%d", &pos);
                printf("Enter new data to insert: ");
                scanf("%d", &data);
                insertAfter(pos, data);
                break;
		 case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteByValue(data);
                break;
		case 5:
                deleteAtBeginning();
                break;
		case 6:
                deleteAtEnd();
                break;
		case 7:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(data);
                break;
		case 8:
                displayForward();
                break;
		case 9:
                displayBackward();
                break;
		case 10:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 11:
		  reverseList();
                printf("List reversed.\n");
                break;
		case 12:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
    printf("Inserted %d at beginning.\n", data);
}
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
	 } else {
        struct Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end.\n", data);
}
void insertAfter(int posData, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != posData) temp = temp->next;
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    printf("Inserted %d after %d.\n", data, posData);
}
void deleteByValue(int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != data) temp = temp->next;
    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
    printf("Deleted node with data %d.\n", data);
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
