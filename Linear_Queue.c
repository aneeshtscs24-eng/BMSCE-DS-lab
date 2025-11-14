#include<stdio.h>
#define SIZE 3

int front = -1, rear = -1, queue[SIZE];

void insert(){
    if (rear == SIZE-1)
        printf("\nOverflow condition. Cannot insert");
    else{
        if(front == -1)
            front = 0;
        int ele;
        printf("\nEnter the element to be inserted: ");
        scanf("%d",&ele);
        rear += 1;
        queue[rear] = ele;
    }
}

void delete(){
    if (front==-1||rear<front)
        printf("\nUnderflow condition. No element in the queue.");
    else{
        printf("\nDeleted element is : %d",queue[front]);
        if(front==rear){
            front = -1;
            rear = -1;
        }
        else{
            front += 1;
        }
    }
}

void display(){
    if(front==-1)
        printf("\nQueue is empty");
    else{
        printf("\nThe elements in the queue are : ");
        for(int i=front; i<=rear; i++){
            printf("%d ",queue[i]);
        }
    }
}

void main(){
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("\nInvalid choice");
        }
    }
}
