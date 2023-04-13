
//implement a stack using array and develop functions to perform push and pop 
#include<stdio.h>
//function to push elements in the stack
void push(int *p,int *top,int size)
{
     if(*top==(size-1))
     {
         printf("\nThis is a case of overflow\n"); //printing the stack is full
     }
     else
     {   
        int element;
        printf("\nenter the element to push:");//taking input to be pushed
        scanf("%d",&element);
        (*top)++;
        p[*top]=element;
     }
}
//function to pop an element from the stack
void pop(int *p,int *top)
{  
    if((*top) ==-1)
    {
        printf("\nthis is a case of stack underflow\n");//printing the stack is empty
    }
    else
    {
        printf("\nthe element poped = %d\n",p[*top]);//printing the poped element
        (*top)--;
    }
}
//to display the elements of the stack
void display(int*p,int top) 
{   
    if (top==-1)
    {
        printf("\nstack is empty\n");//checking if the stack is empty or not
    }
    else
    {   printf("\ndisplaying the elements:\n");
        for(int i=(top);i>=0;i--)
        {
            printf("element : %d\n",p[i]);//printing the elements of the stack
        }
    }
}
void main()
{
    int size;
    printf("enter the max size of the stack :"); //inputing the size of the array
    scanf("%d",&size);
    int stack[size];
    int top=-1;
    int choice=0;
    while(choice!=4) //to run operations repeatedly
    { printf("\nmenu:\n1.push\n2.pop\n3.display\n4.end\nplease enter your choice:");
      scanf("%d",&choice); //asking user for the choice of operation
      switch(choice)
      {
            case 1:
                push(stack,(&top),size);
                break;
            case 2:
                pop(stack,(&top));
                break;
            case 3:
                display(stack,top);
            case 4:
                 break;
            default:
                 break;
       }
    }
}