// to perfrom enqueue and dequeue operations 
//header files
#include<stdio.h>
//creating the queue
# define max 50
int queue[max];
int front=0;
int rear=0;
//enqueue function
void enqueue()
{
    if(rear==(max-1))
    {
        printf("queue is full!\n"); // overload case
    }
    else
    {
        int ele;
        printf("enter the element to enqueue :");
        scanf("%d",&ele);
        queue[rear]=ele; //inserting the element
        rear++;
        printf("enqueue successful....\n");
    }
}
//dequeue function
int dequeue()
{
    if(rear==front)
    {
        printf("queue is empty!\n"); //underlfow case
        return 0;
    }
    else
    {   
        printf("element dequeued : %d\n",queue[front]);//element dequeued
        return queue[front++]; //returning the element that is dequeued and increasing the front.
    }
}
//display function
void display()
{
    if(rear== front)
    {
        printf("queue is empty!\n"); //empty queue
    }
    else
    {
        int i=0;
        printf("displaying the elements of the queue:\n"); 
        for (i=front;i<rear;i++) //displaying the elements
        {
            printf("data : %d\n",queue[i]);
        }
    }
}
void main()
{   
    int choice=0;
    while(choice!=4)
    {
        printf("\nmenu:\n1.enqueue\n2.dequeue\n3.display\n4.end\n"); //sisplaying the menu
        printf("enter your choice:"); // taking the choice
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
               enqueue(); //inserting the element
               break;
            case 2:
                dequeue(); //deletiong the element
                break;
            case 3:
                display();//displaying the element
                break;
            case 4:
                 break;
            default:
                printf("invalid input!\n");
        }
    }
    printf("\nTHANK YOU\n"); //printing thanks at the end of the program
}
