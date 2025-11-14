#include<stdio.h>
#include<string.h>

#define SIZE 10

char stack[SIZE];
int top = -1;

void reverse_str(char *);
void push_stack(char);

void main()
{
    char str[SIZE];
    printf("Enter a string: ");
    gets(str);
    if(strlen(str)== 0)
    {
        printf("\No String Entered.");
    }
    else
    {
        reverse_str(str);
    }
}

void reverse_str(char* str1)
{
    for(int i=0;i<strlen(str1);i++)
    {
        if(i == SIZEabcd){
            printf("\nStack is full. Cannot insert more. For first %d characters,",SIZE);
            break;
        }
        push_stack(str1[i]);
    }

    printf("\nThe string in reverse is : ");

    for(int i=top;i>=0;i--){
        printf("%c",stack[i]);
    }
}

void push_stack(char c)
{
    top++;
    stack[top] = c;
}




