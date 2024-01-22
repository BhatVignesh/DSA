//
// Created by viggi on 22-01-2024.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertAtStart(int x) {
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = x;
    p->next = head;
    head = p;
    printf("%d has been inserted at the start\n", x);
}
void insertAtEnd(int x){
    struct node *p=(struct node *) malloc(sizeof(struct node));
    struct node *q=head;
    while(q->next!=NULL){
        q=q->next;
    }
    p->data=x;
    q->next=p;
    p->next=NULL;
    printf("%d has been inserted at the end\n",x);
}
void insertAtPos(int pos,int x){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    struct node *q=head;
    p->data=x;
    for(int i=1;i<pos;i++){
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
    printf("%d has been added at position %d\n",x,pos);
}

void deleteAtStart(){
    int x=head->data;
    head=head->next;
    printf("%d has been deleted from the start\n",x);
}
void deleteAtEnd(){
    struct node *p=head;
    struct node *q;
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    int x=p->data;
    q->next=NULL;
    free(p);
    printf("%d has been deleted from the back\n",x);
}
void deleteAtPos(int pos){
    struct node *p=head;
    struct node *q;
    for(int i=1;i<pos;i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    int x=p->data;
    printf("%d has been deleted from position %d\n",x,pos);
}

void display() {
    struct node *p = head;
    int x;
    printf("The linked list is:");
    while (p != NULL) {
        x = p->data;
        printf("%d ", x);
        p = p->next;
    }

    printf("\n");
}

int main() {
    insertAtStart(10);
    insertAtStart(20);
    insertAtStart(30);
    insertAtEnd(1);
    insertAtPos(2,3);
    display();
    printf("\n");
    deleteAtStart();
    display();

    deleteAtEnd();
    display();

    deleteAtPos(3);
    display();

    return 0;
}