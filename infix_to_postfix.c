#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 50

char stack[SIZE],top=-1;

char pop(){
    return stack[top--];
}
void push(char ele){
    stack[++top] = ele;
}

int precedence(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void main(){
    char infix[SIZE],postfix[SIZE];
    int i=0,k=0;
    char ch,elem;
    printf("Enter the expression: ");
    gets(infix);
    push('#');
    while((ch=infix[i++]) != '\0'){
        if(ch == '('){
            push(ch);
        }
        else{
            if(ch==')')
            {
                while(stack[top] != '(')
                    postfix[k++] = pop();
                elem = pop();

            }
            else if(isalnum(ch)){
                postfix[k++] = ch;
            }
            else{
                while(precedence(stack[top]) >= precedence(ch))
                    postfix[k++] = pop();
                push(ch);
            }
        }
    }
    while(stack[top] != '#')
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("The postfix expression is : %s",postfix);
}
