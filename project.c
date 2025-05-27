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

BFS 
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Queue {
    int items[MAX];
    int front;
    int rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
     q->front = -1;
    q->rear = -1;
    return q;
}
int isEmpty(struct Queue* q) {
    return q->front == -1;
}
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;

}
int dequeue(struct Queue* q) {
    if (isEmpty(q))
        return -1;
    int item = q->items[q->front];
    if (q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}
int visited[MAX];
int adjMatrix[MAX][MAX];
int numVertices;
void BFS(int startVertex) {
    struct Queue* q = createQueue();
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
	for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    free(q);
}
void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}
void inputGraph() {
    int edges, u, v;
     printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = 0;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
}
void printAdjMatrix() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
	     }
        printf("\n");
    }
}
int main() {
    int startVertex;
    inputGraph();
    printAdjMatrix();
    for (int i = 0; i < MAX; i++)
        visited[i] = 0;
 printf("Enter start vertex for BFS: ");
    scanf("%d", &startVertex);
    printf("BFS traversal starting from vertex %d: ", startVertex);
    BFS(startVertex);
    printf("\n");
    return 0;
}




DFS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adjMatrix[MAX][MAX];
int visited[MAX];
int numVertices;
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i])
            DFS(i);
    }
}
void inputGraph() {
    int edges, u, v;
     printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = 0;
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
	  adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}
void printAdjMatrix() {
    printf("Adjacency Matrix:\n");
     for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            printf("%d ", adjMatrix[i][j]);
	printf("\n");
    }
}
int main() {
    int startVertex;
    inputGraph();
    printAdjMatrix();
    for (int i = 0; i < MAX; i++)
	      visited[i] = 0;
    printf("Enter start vertex for DFS: ");
    scanf("%d", &startVertex);
    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFS(startVertex);
    printf("\n");
    return 0;
}

Enter number of vertices: 4
Enter number of edges: 4
Enter edge 1 (u v): 0 1
Enter edge 2 (u v): 0 2
Enter edge 3 (u v): 1 3
Enter edge 4 (u v): 2 3
Enter start vertex for DFS: 0


		    Adjacency Matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
DFS traversal starting from vertex 0: 0 1 3 2

