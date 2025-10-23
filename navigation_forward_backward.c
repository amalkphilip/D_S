#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[100];
    struct node* next;   
    struct node* prev;    
};
typedef struct node Node;
void create(Node** head, char* url) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newnode->data, url);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*head == NULL) {
        *head = newnode;  
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;  
        newnode->prev = temp;  
    }
}
void printCurrent(Node* current) {
    if (current != NULL) {
        printf("Currently viewing: %s\n", current->data);
    } else {
        printf("No webpage to view!\n");
    }
}
void goForward(Node** current) {
    if (*current != NULL && (*current)->next != NULL) {
        *current = (*current)->next;
        printCurrent(*current);
    } else {
        printf(" You are at the last page.\n");
    }
}
void goBackward(Node** current) {
    if (*current != NULL && (*current)->prev != NULL) {
        *current = (*current)->prev;
        printCurrent(*current);
    } else {
        printf(" You are at the first page.\n");
    }
}
void clearHistory(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    *head = NULL;  
    printf("\n\t\tSAFE ayiee mwoneee......\n");
}
int main() {
    Node* head = NULL;  
    Node* current = NULL;  
    int choice;
    char url[100];
    while (1) {
        printf("\n---Browser Navigation Menu---\n");
        printf("1. Visit a webpage\n");
        printf("2. Go Forward\n");
        printf("3. Go Backward\n");
        printf("4. Clear History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the URL to visit: ");
                scanf("%s", url);
                create(&head, url);  
                if (current == NULL) {
                    current = head;
                }
                printCurrent(current);  
                break;
            case 2:
                goForward(&current); 
                break;
            case 3:
                goBackward(&current);  
                break;
            case 4:
            	clearHistory(&head);
            	break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
