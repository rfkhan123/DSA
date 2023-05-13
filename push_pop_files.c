#include<stdio.h>

int top=-1,r;
int array[1000];

void push1(int x)
{
    if (top == r - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        top = top + 1;
        array[top] = x;
    }
}

int pop1()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        return array[top--];
    }
}

main()
{
    FILE *fp,*pop,*push,*log,*stack,*fp1;
    int i,*arr,a,x,y,*arr2,k;
    char c;
    printf("Enter range");
    scanf("%d",&r);
    arr=(int*)malloc(r*sizeof(int));
    arr2=(int*)malloc(r*sizeof(int));
    fp=fopen("C:\\Users\\Roshan Khan\\Desktop\\file.txt","w+");
    fp1=fp;
    for(i=0;i<r;i++)
    {
        arr[i]=rand()%(r+1);
    fprintf(fp,"%d ",arr[i]);
    }
    stack=fopen("C:\\Users\\Roshan Khan\\Desktop\\stack.txt","w+");
    push=fopen("C:\\Users\\Roshan Khan\\Desktop\\push.txt","w+");
    pop=fopen("C:\\Users\\Roshan Khan\\Desktop\\pop.txt","w+");
    log=fopen("C:\\Users\\Roshan Khan\\Desktop\\log.txt","w+");
    i=k=0;
    while(1)
    {
        printf("Do you want to push,pop or end(1,2 or 3)");
        scanf("%d",&a);
        if(a==3)
            break;
        if(a==1)
        {
            push1(arr[i]);
            x=arr[i++];
            fprintf(push,"%d ",x);
            fprintf(log,"push() ");
        }
        else if(a==2)
        {
            x=pop1();
            fprintf(pop,"%d ",x);
            fprintf(log,"pop() ");
        }
    }
    for(i=0;i<=top;i++)
        fprintf(stack,"%d ",array[i]);
    fclose(fp);
    fclose(push);
    fclose(pop);
    fclose(log);
    fclose(stack);
}
