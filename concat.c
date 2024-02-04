//
// Created by viggi on 04-02-2024.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* head1 = NULL;

struct node* insert(int x, struct node* temp) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;

    if (temp == NULL) {
        return p;
    } else {
        struct node* q = temp;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
        return temp;
    }
}

struct node* insert1(int x, struct node* temp) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = temp;
    return p;
}

struct node* concat(struct node* list1, struct node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

void print(struct node* temp) {
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int n, x;

    printf("Enter the size of the linked list1: ");
    scanf("%d", &n);
    printf("Enter values to be inserted one by one: ");
    while (n > 0) {
        scanf("%d", &x);
        head = insert(x, head);
        n--;
    }

    printf("Enter the size of the linked list2: ");
    scanf("%d", &n);
    printf("Enter values to be inserted one by one: ");
    while (n > 0) {
        scanf("%d", &x);
        head1 = insert(x, head1);
        n--;
    }

    head = concat(head, head1);

    printf("After concatenation: ");
    print(head);

}
