#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createnode(int data) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void inst_atend(struct node **head, int data) {
    struct node *newnode = createnode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node *head) {
    printf("Train Route:");
    struct node *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int n;
    printf("Enter the number of train cars: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of train cars\n");
        return 1;
    }

    struct node *head = NULL;
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        inst_atend(&head, data);
    }

    display(head);
    free(head);  

    return 0;
}
