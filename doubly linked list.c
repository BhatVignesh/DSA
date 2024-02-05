#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head=NULL;
struct node* insertAtLeft(int x){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        p->data=x;
        p->prev=NULL;
        p->next=NULL;
        head=p;
    }
    else{
        p->data=x;
        p->prev=NULL;
        p->next=head;
        head->prev=p;
        head=p;
    }
    return head;
}
void deleteVal(int x){
    struct node* p=head;
    int ch=0;
    while(p->next!=NULL){
        if(p->data==x){
            ch++;
            break;
        }
        p=p->next;
    }
    if(ch==0){
        printf("Value %d not found in linked list\n",x);
    }
    else{
        p->prev->next=p->next;
        p->next->prev=p->prev;
        printf("%d has been removed\n",p->data);
        free(p);
    }
}
void print(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void main(){
    int ch=0;
    int x=0;
    while(ch!=4){
        printf("1.Insert at Left\n2.Delete value\n3.display\n4.exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter value to be inserted:");
                    scanf("%d",&x);
                    head=insertAtLeft(x);
                    break;
            case 2:printf("Enter value to be deleted:");
                    scanf("%d",&x);
                    deleteVal(x);
                    break;
            case 3:print();
            break;
            case 4:exit(0);
            break;
            default:printf("Invalid choice");
        }
    }
}

