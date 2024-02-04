//
// Created by viggi on 04-02-2024.
//
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;
void insert(int x){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=head;
    head=p;
}
struct node* reverse(struct node *head){
    struct node* prev=NULL;
    struct node* current=head;
    struct node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void print(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
void main(){
    int n,x;
    printf("Enter the size of the linked list:");
    scanf("%d",&n);
    printf("Enter values to be inserted one by one:");
    while(n>0){
        scanf("%d",&x);
        insert(x);
        n--;
    }
    printf("Before reversing:");
    print();
    printf("\nAfter reversing:");
    head=reverse(head);
    print();
}