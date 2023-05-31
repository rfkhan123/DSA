#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct
{
    int q[SIZE];
    int front,rear,index;
} queue;

void insertRandomNumbers(int arr[100],int size,FILE *fp);
int full(queue dq);
int empty(queue dq);
void QueueFile(queue *dq,FILE *fp);
void insertRear(queue *dq,int arr[100],FILE *Qfp,FILE *enqfp,FILE *opfp);
void deleteFront(queue *dq,FILE *Qfp,FILE *deqfp,FILE *opfp);

int main()
{
    int arr[100];
    int choice1;
    int rangeOfRandomNum;
    queue dq;
    dq.front = 0;
    dq.rear = -1;
    dq.index = 0;
    FILE *ifp =fopen("C:\\Users\\Roshan Khan\\Desktop\\queue.txt","a");
    FILE *enqfp = fopen ("C:\\Users\\Roshan Khan\\Desktop\\enq.txt","a");
    FILE *deqfp = fopen("C:\\Users\\Roshan Khan\\Desktop\\deq.txt","a");
    FILE *opfp = fopen("C:\\Users\\Roshan Khan\\Desktop\\log.txt","a");
    FILE *Qfp;
    printf("Enter range of random numbers:\n");
    scanf("%d",&rangeOfRandomNum);
    insertRandomNumbers(arr,rangeOfRandomNum,ifp);

    for(int i = 0 ; i < 5; i++)
    {
        printf("Enter 1-Inserting element\n2-Deleting element\n");
        scanf("%d",&choice1);
        if(choice1 == 1)
        {
            if(full(dq))
            {
                printf("Queue full\n");
            }
            else
            {
                insertRear(&dq,arr,Qfp,enqfp,opfp);
            }
        }
        else
        {
            if(empty(dq))
            {
                printf("Queue Empty\n");
            }
            else
            {
                deleteFront(&dq,Qfp,deqfp,opfp);
            }
        }
    }
    fclose(enqfp);
    fclose(deqfp);
    fclose(opfp);

    return 0;





}

void insertRandomNumbers(int arr[100],int size,FILE *fp)
{
    int randNum;
    for(int i = 0 ; i<size; i++)
    {
        randNum= rand()%size;
        arr[i] = randNum;
        fprintf(fp,"%d ",randNum);
    }
    fclose(fp);
}

int full(queue dq)
{
    return(dq.rear == SIZE-1);
}

int empty(queue dq)
{
    return(dq.front > dq.rear);
}

void insertRear(queue *dq,int arr[100],FILE *Qfp,FILE *enqfp,FILE *opfp)
{
    int num = arr[dq->index];
    dq->rear = dq->rear + 1;
    dq->q[dq->rear] = num;
    dq->index = dq->index + 1;
    QueueFile(dq,Qfp);
    fprintf(enqfp,"%d ",num);
    fprintf(opfp,"%s","insertRear ");

}
void deleteFront(queue *dq,FILE *Qfp,FILE *deqfp,FILE *opfp)
{
    int data = dq->q[dq->front];
    dq->front = dq->front + 1;
    QueueFile(dq,Qfp);
    fprintf(deqfp,"%d ",data);
    fprintf(opfp,"%s","deleteFront ");
}
void QueueFile(queue *dq,FILE *fp)
{
    fp = fopen("Queue.txt","w");
    for(int i = dq->front ; i <=dq->rear ; i++)
    {
        int queueData = dq->q[i];
        fprintf(fp,"%d ",queueData);
    }
    fclose(fp);
}

