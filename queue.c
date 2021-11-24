
#include <stdio.h>
#include <stdlib.h>

#define MAX 5    //Maximum number of elements that can be stored

int front=-1, rear=-1, queue[MAX];
void enqueue();
void dequeue();
void display();

int main()
{
        int ch;

        while(1) //infinite loop, will end when choice will be 4
        {
                printf("\n** Queue Menu **");
                printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
                printf("\n\nEnter your choice(1-4):");
                scanf("%d",&ch);

                switch(ch)
                {
                case 1: enqueue();
                        break;
                case 2: dequeue();
                        break;
                case 3: display();
                        break;
                case 4: exit(0);

                default: printf("\nWrong Choice!!");
                }
        }
}

void enqueue()
{
        int val;
        printf("\nEnter element to enqueue: ");
        scanf("%d", &val);
        if(rear==MAX-1)
        {
                printf("\nQueue is full!!");
        }
        else if(rear==-1)
        {
            
            rear=rear+1;
            front=front+1;
            queue[rear]=val;
        }
        else
        {
              rear=rear+1;
              queue[rear]=val;  
        }
}

void dequeue()
{
        int val;

        if(rear==-1)
                printf("\nQueue is empty!!");
        else if(front==rear)
        {
            printf("\nDeleted element is %d",queue[front]);
            rear=-1;
            front=-1;
        }
        else{
            printf("\nDeleted element is %d",queue[front]);
            front=front+1;
        }

}

void display()
{
    int i;
    if(rear==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nQueue is ...\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
