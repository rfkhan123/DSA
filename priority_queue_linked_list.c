#include<stdio.h>
//size of queue
#define SIZE 5
int top=0;

struct node
{
   int data;
   int priority;
   struct node *next;
};

struct node *head=NULL,*temp,*newnode;
//removing from queue
int dequeue()
{
    if(head==NULL)
        return 0;
    int x;
    x=head->data;
    head=head->next;
    return x;
}
//entering into queue
int enqueue(int x)
{
    if((top++)>=SIZE)
        return 0;
    else
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->priority=rand()%(SIZE+1);
    temp=head;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->data=x;
        return 1;
    }
    if(newnode->priority>head->priority)
    {
    while((temp->next!=NULL)&&(newnode->priority>(temp->next)->priority))
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->data=x;
    return 1;
    }
    else
    {
        newnode->next=head;
        newnode->data=x;
        head=newnode;
        return 1;
    }
    }
}
//printing queue into file
void display(struct node*que)
{
    temp=head;
    if(temp==NULL)
    {
        printf("Queue is empty");
        fprintf(que,"Queue is empty");
    }
    while(temp!=NULL)
    {
        fprintf(que,"%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    struct node *newnode;
    int q,x,*arr,r,i,a,y;
    FILE *que,*enq,*deq,*log,*fp;
    char c;
    printf("Enter range : ");
    scanf("%d",&r);
    arr=(int*)malloc(r*sizeof(int));
    fp=fopen("C:\\Users\\Roshan Khan\\Documents\\file.txt","r+");
    for(i=0;i<r;i++)
    {
        fprintf(fp,"%d ",rand()%(r+1));
    }
    fclose(fp);
    fp=fopen("C:\\Users\\Roshan Khan\\Documents\\file.txt","r+");
    que=fopen("C:\\Users\\Roshan Khan\\Documents\\queue.txt","w+");
    enq=fopen("C:\\Users\\Roshan Khan\\Documents\\enqueue.txt","w+");
    deq=fopen("C:\\Users\\Roshan Khan\\Documents\\dequeue.txt","w+");
    log=fopen("C:\\Users\\Roshan Khan\\Documents\\log.txt","w+");
    i=0;
    while(1)
    {
        printf("Do you want to enqueue,dequeue or end(1,2 or 3)");
        scanf("%d",&a);
        if(a==3)
            break;
        if(a==1)
        {
            fscanf(fp,"%d ",&q);
            if(enqueue(q)==0)
                printf("OVERFLOW\n");
            else
                fprintf(enq,"%d ",q);
            fprintf(log,"enqueue ");
        }
        else if(a==2)
        {
            y=dequeue();
            if(y==0)
                printf("UNDERFLOW\n");
            else
                fprintf(deq,"%d ",y);
            fprintf(log,"dequeue ");
        }
    }
    display(que);
    fclose(fp);
    fclose(que);
    fclose(deq);
    fclose(log);
    fclose(enq);
    return 0;
}
