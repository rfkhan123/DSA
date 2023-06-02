#include<stdio.h>
#include<math.h>
//size of queue
#define SIZE 5
int top=0,rear=0;

struct node
{
   int data;
   struct node *next;
   struct node *prev;
};

struct node *head=NULL,*temp,*newnode;
//removing from front queue
int front_dequeue()
{
    int x;
    if(head==NULL)
        return -1;
    if(head->next==NULL&&head->prev==NULL)
    {
        x=head->data;
        head=NULL;
        return x;
    }
    struct node *temp1;
    x=head->data;
    temp1=head;
    head=head->next;
    head->prev=NULL;
    free(temp1);
    rear++;
    return x;
}
//entering into rear of queue
int rear_enqueue(int x)
{
    if((top)>=SIZE)
        return 0;
    else
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=head;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        newnode->data=x;
        newnode->prev=NULL;
        top++;
        return 1;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next=NULL;
    newnode->data=x;
    top++;
    return 1;
    }
}
//printing queue into file

int front_enqueue(int x)
{
    if(rear==0)
        return 0;
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        head->prev=newnode;
        newnode->next=head;
        newnode->prev=head;
        newnode->data=x;
        head=newnode;
        rear--;
        return 1;
    }
}

int rear_dequeue()
{
    int x;
    if(head==NULL)
        return -1;
    if(head->next==NULL&&head->prev==NULL)
    {
        x=head->data;
        head=NULL;
        return x;
    }
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    x=temp->data;
    (temp->prev)->next=NULL;
    free(temp);
    top--;
    return x;
}
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

main()
{
    struct node *newnode;
    int q,x,*arr,r,i,a,y;
    FILE *que,*enq,*deq,*log,*fp;
    char c;
    printf("Enter range : ");
    scanf("%d",&r);
    arr=(int*)malloc(r*sizeof(int));
    fp=fopen("C:\\Users\\Roshan Khan\\Documents\\file.txt","w+");
    for(i=0;i<r;i++)
    {
        arr[i]=rand()%(r+1);
        fprintf(fp,"%d ",arr[i]);
    }
    que=fopen("C:\\Users\\Roshan Khan\\Documents\\queue.txt","w+");
    enq=fopen("C:\\Users\\Roshan Khan\\Documents\\enqueue.txt","w+");
    deq=fopen("C:\\Users\\Roshan Khan\\Documents\\dequeue.txt","w+");
    log=fopen("C:\\Users\\Roshan Khan\\Documents\\log.txt","w+");
    i=0;
    while(1)
    {
        printf("Do you want to rear enqueue,front dequeue,front enqueue,rear dequeue or end(1,2,3,4,5)");
        scanf("%d",&a);
        if(a==5)
            break;
        if(a==1)
        {
            if(rear_enqueue(arr[i])==0)
                printf("OVERFLOW\n");
            else
                fprintf(enq,"%d ",arr[i++]);
            fprintf(log,"enqueue ");
        }
        else if(a==2)
        {
            y=front_dequeue();
            if(y==-1)
                printf("UNDERFLOW\n");
            else
                fprintf(deq,"%d ",y);
            fprintf(log,"dequeue ");
        }
        else if(a==3)
        {
            if(front_enqueue(arr[i])==0)
                printf("OVERFLOW\n");
            else
                fprintf(enq,"%d ",arr[i++]);
                fprintf(log,"enqueue ");
        }
        else if(a==4)
        {
            y=rear_dequeue();
            if(y==-1)
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
}
