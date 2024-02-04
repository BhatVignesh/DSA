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
struct node* sorted=NULL;
void insert(int x){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=head;
    head=p;
}
void sort(struct node* p){
    if(sorted==NULL || sorted->data>=p->data){
        p->next=sorted;
        sorted=p;
    }
    else{
        struct node* current=sorted;
        while(current->next!=NULL && current->next->data<p->data){
            current=current->next;
        }
        p->next=current->next;
        current->next=p;
    }
}
void insertionSort(){
    struct node* current=head;
    while(current!=NULL){
        struct node* next=current->next;
        sort(current);
        current=next;
    }
    head=sorted;
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
    printf("Before sorting:");
    print();
    printf("\nAfter sorting:");
    insertionSort();
    print();
}