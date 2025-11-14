#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 40

int stack[SIZE],top=-1;

int pop(){
    return stack[top--];
}

void push(int x){
    stack[++top] = x;
}

void main(){
    char *ptr;
    char s[SIZE];
    int n1,n2,n3,num;
    printf("Enter the postfix expression: ");
    gets(s);
    ptr = s;
    while(*ptr!='\0'){
        if(isdigit(*ptr))
            {
                num = *ptr - 48;
                push(num);
            }
        else{
            n1 = pop();
            n2 = pop();
            switch(*ptr){
            case '+' :
                n3 = n1 + n2;
                break;
            case '-' :
                n3 = n2-n1;
                break;
            case '*' :
                n3 = n1*n2;
                break;
            case '/' :
                n3 = n2/n1;
                break;
            }
            push(n3);
        }
        ptr++;
    }
    printf("The final result is: %d",pop());
}
