//to perform insertion, deletion, linear search, traversal and updation on an array
#include<stdio.h>
void traversal(int*,int*);
void linear_search(int*,int*);
void insertion(int*,int*,int);
void updation(int*,int*);
void deletion(int*,int*);
void main()
{
  int num=0,i=0,choice=0,num_copy; //variable declaration
  printf("enter the size of the array :"); //input the size of the array that the user wants to create
  scanf("%d",&num);
  int array[(num +10)]; //limition only 10 extra elements can be inserted to the input size of the array
  //entering elements into the array
  num_copy=num+10; //creating the copy of the actual size of the array to set exception while insertion
  printf("creating array :\n");
  for(i=0;i<num;i++)
  {   
      printf("enter the element array[%d] :",i);
      scanf("%d",&array[i]);

  }  
  while(choice !=6)
  {
      printf("\nMENU OF OPERATIONS :\n");
      printf("1.traversal\n2.linear search\n3.insertion\n4.updation\n5.deletion\n6.END\n");//dispalying different operations
      printf("ENTER YOUR CHOICE : ");
      scanf("%d",&choice);
      switch(choice)
      {
            case 1:
            traversal(array,&num);
            break;
            case 2:
            linear_search(array,&num);
            break;
            case 3:
            insertion(array,&num,num_copy);
            break;
            case 4:
            updation(array,&num);
            break;
            case 5:
            deletion(array,&num);
            break;
            case 6:
            break;
            default:
            printf("invalid choice!\n"); //if the no input by the user is not in the list of menu
      }
      
  }
  
  }
  //User defines functions.....................................................................
 //function for traversal
  void traversal(int *array,int*num)
  {
      printf("\ntraversal:\nprinting the array:\n");
      for(int i=0;i<(*num);i++)
      {
            printf("array[%d]=%d\n",i,array[i]); //printing the elements of the array
      }
  }
 //function for linear search
  void linear_search(int*array, int* num)
{
      printf("\nsearch:\n");
      int element_search;
      printf("enter the element to be searched :");   //input element to search
      scanf("%d",&element_search);
      for(int i=0;i<(*num);i++)
      {
            if(array[i]==element_search) //checking for the element
            {
                  printf("element %d is found at the index %d\n",element_search,i);
                  break;
            }
            else if(i==((*num)-1)) //if element is not found in the given array
            {
                  printf("element not found\n");
            }
      }
}
  //function for insertion
  void insertion(int *array,int* num,int num_copy)
 {    //elements can only be inserted from 0  to one index ahead of the index till were the elements have already been
      if ((*num)<num_copy)
      {
            printf("\ninsertion:\n");
            int element_insert,index_insert,i;
            printf("enter the element to be inserted: "); //input the element for insertion
            scanf("%d",&element_insert);
            printf("enter the index where you want to insert : "); //input index where to insert
            scanf("%d",&index_insert);
            if(index_insert<=(*num))
            {
                  (*num)++;
                  for(i=((*num)-1);i>=index_insert;i--)//insering element
                  {
                        array[i]=array[i-1];
                        if(i==index_insert)
                        {
                              array[i]=element_insert;
                        }
                  }
                  printf("element inserted sucessfully.\n");
                  printf("\narray after insertion:\n");
                  for(i=0;i<(*num);i++)//printing after insertion
                  {   
                        printf("array[%d]=%d\n",i,array[i]);
                  }
            }
            else
            {     
                  //if the user inserts the element on an index which is greater than the number of elements in the array but in range of the size of the array
                  printf("\nsorry! element can not be inserted at this index right now\n>>>>you need to fill the previous indexes before entering values in this index\n");
            }
      }
      else
      {
            printf("\nsize exceeded\n") ; //if the user enter more elements even after the whole array is filled 
      }
}
  //function for updation
  void updation(int *array,int* num)
{
      printf("\nupdation:\n");
      int element_update,index_update,i;
      printf("\nenter the updated element: ");//input the element
      scanf("%d",&element_update);
      printf("enter the index where you want to update :");//index where to input
      scanf("%d",&index_update);
      for(i=0;i<(*num);i++) //algorithm for updation
      {
            if(i==index_update)
            {
                  array[i]=element_update; //setting the updated element
                  break;
            }
      }
      printf("element updated sucessfully:\n");
      printf("\narray after updation:\n"); //printing array after updation
      for(i=0;i<(*num);i++)
      {
            printf("array[%d]=%d\n",i,array[i]);
      }
      
}
  //function for deletion
  void deletion(int *array,int* num)
  {  if((*num)>0) 
     {
            printf("\ndeletion:\n");
            int index_delete,i;
            printf("enter the index where you want to delete : ");
            scanf("%d",&index_delete); //input the index where to delete
            if(index_delete<(*num))
            {
                  (*num)--;
                  for(i=index_delete;i<(*num);i++) //program for deletion
                  {
                        array[i]=array[i+1];  
                  }
                  printf("element deleted sucessfully:\n");
                  printf("\narray after deletion:\n"); //printing the array after deletion
                  for(i=0;i<(*num);i++)
                  {
                        printf("array[%d]=%d\n",i,array[i]);
                  }
            }
            else
            {
                  printf("sorry! index is not defined"); //if the index entered by the user is not filled yet
            }
     }
     else
     {
            printf("array is empty"); //if the array is empty
     }
  }