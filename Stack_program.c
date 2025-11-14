#include<stdio.h>

#define SIZE 3

void push();
void pop();
void display();
void peek();

int stack[SIZE],top = -1;

void main()
{
    int choice = -2;
    while(choice !=  -1)
    {
        printf("\n\n*****MENU******\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n-1.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
              push();
              break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case -1:
            {
                printf("\Program Terminated!");
                break;
            }
        }
    }
}

void push(){
    int ele;
    if(top >= SIZE - 1)
    {
        printf("\nStack is full. Cannot insert.");
    }
    else{
        printf("\nEnter element: ");
        scanf("%d",&ele);
        top++;
        stack[top] = ele;
    }
}

void pop(){
    int ele;
    if(top == - 1)
    {
        printf("\nStack is empty. Nothing to pop.");
    }
    else{
        ele = stack[top];
        top--;
        printf("\nThe element popped = %d",ele);
    }
}

void display()
{
    if(top == - 1)
    {
        printf("\nStack is empty. Nothing to display.");
    }
    else
    {
        printf("\nThe elements in the stack are : ");
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
    }
}

void peek()
{
    int ele;
    if(top == - 1)
    {
        printf("\nStack is empty. Nothing to peek.");
    }
    else
    {
        ele = stack[top];
        printf("\nThe element at TOP = %d",ele);
    }
}
