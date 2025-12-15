
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*create(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Allocation failed");
        exit(1);
    }
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
};
struct node*insert(struct node*root,int x)
{
    if(root==NULL)
        return create(x);
    if(x<root->data)
        root->left=insert(root->left,x);
    else if(x>root->data)
        root->right=insert(root->right,x);
    return root;
};
struct node*find_min(struct node*ptr)
{
    struct node*current=ptr;
    while(current&&current->left!=NULL)
        current=current->left;
    return current;
};
void inorder_tra(struct node*root)
{
    if(root!=NULL)
    {
        inorder_tra(root->left);
        printf("%d",root->data);
        inorder_tra(root->right);
    }
}
void preorder_tra(struct node*root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder_tra(root->left);
        preorder_tra(root->right);
    }
}
void postorder_tra(struct node*root)
{
    if(root!=NULL)
    {
        postorder_tra(root->left);
        postorder_tra(root->right);
        printf("%d",root->data);
    }
}
void display(struct node*root)
{
    printf("Tree elements(Inorder traversal):");
    inorder_tra(root);
    printf("\n");
}
int main()
{
    struct node*root=NULL;
    int ch,val;
    do{
        printf("\n1.Construct/Insert node\n2.Traversal(preorder,postorder,inorder)\n3.Display elements\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter value:");
                   scanf("%d",&val);
                   root=insert(root,val);
                   break;
            case 2:printf("Inorder:");
                   inorder_tra(root);
                   printf("\n");
                   printf("Preorder:");
                   preorder_tra(root);
                   printf("\n");
                   printf("Postorder:");
                   postorder_tra(root);
                   printf("\n");
            case 3:display(root);
                   break;
            case 4:break;
            default:printf("Invalid choice");

        }
    }while(ch!=4);
    return 0;
}
