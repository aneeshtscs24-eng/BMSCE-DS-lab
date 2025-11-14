#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head = NULL;

struct node *create(int val){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
};

void insert_begin(int val){
    struct node *t;
    t = create(val);
    if(head==NULL)
        head = t;
    else{
        t->next = head;
        head = t;
    }
}

void insert_end(int val){
    struct node *t,*temp;
    t = create(val);
    if(head==NULL)
        head = t;
    else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = t;
    }
}

void display(){
    struct node *temp;
    if(head==NULL)
        printf("\nLinked list empty");
    else{
        temp = head;
        while(temp->next != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("%d ",temp->data);

    }
}

void main(){
    int ch;
    do{
        printf("\n1.Insert at begin\n2.Insert at end\n3.Display\n-1.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            {
                int e;
                printf("Enter data value : ");
                scanf("%d",&e);
                insert_begin(e);
                break;
            }
        case 2:
            {
                int e;
                printf("Enter data value : ");
                scanf("%d",&e);
                insert_end(e);
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case -1:
            break;
        }
    }while(ch!=-1);
}
