#include<stdio.h>
#include<string.h>
// push function
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
        return 0; // stack underflow (if closing bracket is entered first) - invalid expression case
    } 
    else
    {
        (*top)--; // remove the top element from the stack
        return 1; // successful pop
    }
}

// match the 2 consecutive brackets 
int match(char ele, char* stack, int top)
 {   
    if (top == -1)
     {
        return 0; // stack is empty, so no match
    }
    switch(ele) 
    {
        case ')':
            if(stack[top] == '(') 
            {
                return 1; // valid
            } 
            else 
            {
                return 0; // invalid
            }
            break;
        case '}':
            if(stack[top] == '{') 
            {
                return 1; // valid
            } 
            else 
            {
                return 0; // invalid
            }
            break;
        case ']':
            if(stack[top] == '[') 
            {
                return 1; // valid
            } 
            else 
            {
                return 0; // invalid
            }
            break;
    }
}

// check the expression
int check(char* exp) 
{
    // create a stack with the size of the string
    char stack[strlen(exp)];
    int top = -1;
    int i, check_ = 0; // check_ = 1 - valid & check_ = 0 - invalid, check_ is used to check the case of stack underflow
    for(i = 0; i < strlen(exp); i++) 
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') 
        {
            push(stack, &top, exp[i]); // push opening brackets onto the stack
        } 
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') 
        {   
            if(match(exp[i], stack, top)) 
            { // check if closing bracket matches with the top of the stack
                check_ = pop(stack, &top); // remove the top element from the stack
                if(check_ == 0) 
                {
                    break;
                }
            } 
            else 
            {   
                check_ = 0;
                break;
            }
        }
    }

    // check the final state of the stack and the result of the checks
    if(check_ == 0) 
    {
        printf("Not a valid expression\n");
    } 
    else 
    {
        if(top == -1) 
        {
            printf("Valid expression\n");
        } 
        else 
        {
            printf("Not a valid expression\n");
        }
    }
    printf("\n");
}
void main()
{   
    //creating the string with variable size  
        int size=0,i=0; //i-iteration variable
        printf("\nenter the size of your expression [no of characters]:");
        scanf("%d",&size);
        char exp[size+1];
        //inputing the string expression
        printf("enter your expression of brackets : ");
        for (i=0;i<(size);i++)
        {
            scanf(" %c",&exp[i]);
        }
        exp[(size)]='\0'; // to make string from array - string is an array with '\0' as the last element 
        printf("expression entered is %s\n",exp);//printing the entered expression
        check(exp);   //checking the expression
}

