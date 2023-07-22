#include<stdio.h>

struct node
{
    int data;
    struct node *right,*left;
};

struct node *delete_node(struct node *curr, int key)
{
    struct node*temp;
    if(key>curr->data)
        curr->right=delete_node(curr->right,key);
    else if(key<curr->data)
        curr->left=delete_node(curr->left,key);
    else{
    if(curr->left==NULL&&curr->right==NULL)
        return NULL;
    else if(curr->right!=NULL&&curr->left==NULL)
        return curr->right;
    else if(curr->right==NULL&&curr->left!=NULL)
        return curr->left;
    else
    {
        temp=curr;
        temp=temp->left;
        if(temp->right!=NULL)
        {
            while((temp->right)->right!=NULL)
                temp=temp->right;
            curr->data=(temp->right)->data;
            temp->right=(temp->right)->left;
        }
        else
        {
            curr->data=temp->data;
            curr->left=temp->left;
        }
    }
    }
    return curr;
}

struct node * find(int key,struct node *curr)
{
    if(curr==NULL)
        return NULL;
    else if(key>curr->data)
        return(find(key,curr->right));
    else if(key<curr->data)
        return(find(key,curr->left));
    else if(key==curr->data)
        return curr;
}

struct node *insert_tree(struct node *newnode,struct node *curr)
{
    if(curr==NULL)
    {
        newnode->left=newnode->right=NULL;
        return newnode;
    }
    else if(newnode->data<curr->data)
        curr->left=insert_tree(newnode,curr->left);
    else if(newnode->data>=curr->data)
        curr->right=insert_tree(newnode,curr->right);
    return curr;
}

void inorder(struct node *curr)
{
    if(curr==NULL)
    {
        return;
    }
    inorder(curr->left);
    printf("%d ",curr->data);
    inorder(curr->right);
}

void preorder(struct node *curr)
{
    if(curr==NULL)
    {
        return ;
    }
    printf("%d ",curr->data);
    preorder(curr->left);
    preorder(curr->right);
}

void postorder(struct node *curr)
{
    if(curr==NULL)
    {
        return;
    }
    postorder(curr->left);
    postorder(curr->right);
    printf("%d ",curr->data);
}

int main()
{
    int x,r;
    struct node *newnode,*root=NULL;
    while(1)
    {
        printf("\n1->Insert\n2->Delete\n3->Inorder\n4->Pre-Order\n5->Post-Order\n6->Exit\n");
        scanf("%d",&r);
        switch(r)
        {
            case 1:printf("Enter data\n");
                   scanf("%d",&x);
                   newnode=(struct node *)malloc(sizeof(struct node));
                   newnode->data=x;
                   root=insert_tree(newnode,root);
                   break;

            case 2:printf("Enter key to delete\n");
                   scanf("%d",&x);
                   if(find(x,root))
                    root=delete_node(root,x);
                   else
                    printf("Key not found\n");
                    break;
            case 3:inorder(root);
                   break;
            case 4:preorder(root);
                   break;
            case 5:postorder(root);
                   break;
            case 6:exit(0);
                   break;
            default:printf("Enter correct option\n");
                    break;
        }
    }
}
