//program to evaluate both prefix and postfix expression 
#include<stdio.h>
#include<string.h>
#define n 50
int push(char* stack, int* top, char element) 
{
    (*top)++;
    stack[*top] = element; // add the element to the top of the stack
    return 1; // successful push
}
// pop function
int pop(char* stack, int* top) 
{
    if((*top) == -1) 
    {
        printf("stackunderflow");
        return 0; // stack underflow
    } 
    else
    {
         int i;
         i=(stack[(*top)]-48); //storing the element being poped
        (*top)--; // remove the top element from the stack
        return i; // successful pop
    }
}
//function to evaluate
void evaluate(char ele,char*stack,int* top)
{
    int c,a,b; //variables used for calculation inside the switch case below
    switch (ele)
        {
                case '+':
                     a=pop(stack,top);
                     b=pop(stack,top);
                     c=a+b;
                     push(stack,top,c+48);
                     break;
                case '-':
                     a=pop(stack,top);
                     b=pop(stack,top);
                     c=b-a;
                     push(stack,top,c+48);
                     break;
                case '*':
                     a=pop(stack,top);
                     b=pop(stack,top);
                     c=b*a;
                     push(stack,top,c+48);
                     break;
                case '/':
                     a=pop(stack,top);
                     b=pop(stack,top);
                     if(a==0)
                     {
                        printf("cannot divide by 0");
                     }
                     else
                     {
                     c=b/a;
                     push(stack,top,c+48);
                     }
                     break;
                default:
                    push(stack,top,ele); //incase of operand
                    break;
        }
}
int main()
{   
    int i;
    int top=-1; //top of the stack
    char exp[n];
    int choice=0;
    while(choice!=3)
    {
        printf("menu:\n1.prefix\n2.postfix\n3.end\n");
        printf("choose the type of expression you wish to evaluate: ");
        scanf(" %d",&choice);
        if(choice!=3)
        {
            printf("enter you expression");//taking the expression as input
            scanf(" %s",exp);
            printf("entered expression: %s\n",exp); //printing the entered string
            char stack[strlen(exp)]; //creating stack
            switch(choice)
            {
                case 1:
                    for (i=((strlen(exp))-1);i>=0;i--) //calculating the expression
                    {
                        evaluate(exp[i],stack,&top);
                    }
                    break;
                case 2: 
                    for (i=0;i<((strlen(exp)));i++) //calculating the expression
                    {
                    evaluate(exp[i],stack,&top);
                    }
                    break;
                default:
                    printf("invalid choice!\n");
            }
            printf("final answer=%d\n\n",pop(stack,&top));
            }
    }
}

