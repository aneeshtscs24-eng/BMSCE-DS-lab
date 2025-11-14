#include<stdio.h>
#define SIZE 3

int front = -1, rear = -1, queue[SIZE];

int isFull(){
    if(front == rear + 1 || (front == 0 && rear == SIZE-1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(){
    if (isFull())
        printf("\nQueue is full!!");
    else{
        if(front == -1)
            front = 0;
        int ele;
        printf("\nEnter the element to be inserted: ");
        scanf("%d",&ele);
        rear= (rear+1)%SIZE;
        queue[rear] = ele;
    }
}

void dequeue(){
    if (isEmpty())
        printf("\nQueue is empty!!");
    else{
        printf("\nDeleted element is : %d",queue[front]);
        if(front==rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%SIZE;
        }
    }
}

void display(){
    int i;
    if(isEmpty())
        printf("\nQueue is empty!!");
    else{
        printf("\nThe elements in the queue are : ");
        for(i=front; i!=rear; i=(i+1)%SIZE){
            printf("%d ",queue[i]);
        }
        printf("%d ",queue[i]);
    }
}

void main(){
    int ch;
    while(1)
    {
        printf("\n***MAIN MENU***");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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
