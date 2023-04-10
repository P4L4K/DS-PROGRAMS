//to perform insertion, deletion, linear search, traversal and updation on an array
#include<stdio.h>
void traversal(int*,int*);
void linear_search(int*,int*);
void insertion(int*,int*);
void updation(int*,int*);
void deletion(int*,int*);
void main()
{
  int num=0,i=0,choice=0;
  printf("enter the size of the array :");
  scanf("%d",&num);
  int array[(num)]; //limition or error: at inserstion, size is same but able to print more indexes ?
  //entering elements into the array
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
            insertion(array,&num);
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
            printf("invalid choice!\n");
      }
      
  }
  //checking for error....[not part of the program].............................................
  {
      printf("\nnum=%d\n",num); 
      int a;
      int b;
      a=sizeof(array);
      b=sizeof(int);
      printf("\nsize =%d\n \n",(a/b));
      for (i=0;i<num;i++)
            {
                  printf("array[%d]=%d\n",i,array[i]);
            }
  }
  //.....................................................................
}
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
  void insertion(int *array,int* num)
 {    
      printf("\ninsertion:\n");
      int element_insert,index_insert,i;
      printf("enter the element to be inserted: ");
      scanf("%d",&element_insert);
      printf("enter the index where you want to insert : ");
      scanf("%d",&index_insert);
      (*num)++;
      for(i=((*num)-1);i>=index_insert;i--)
      {
            array[i]=array[i-1];
            if(i==index_insert)
            {
                  array[i]=element_insert;
            }
      }
      
      printf("element inserted sucessfully.\n");
      printf("\narray after insertion:\n");
      for(i=0;i<(*num);i++)
      {
            printf("array[%d]=%d\n",i,array[i]);
      }
}
  //function for updation
  void updation(int *array,int* num)
{
      printf("\nupdation:\n");
      int element_update,index_update,i;
      printf("\nenter the updated element: ");
      scanf("%d",&element_update);
      printf("enter the index where you want to update :");
      scanf("%d",&index_update);
      for(i=0;i<(*num);i++)
      {
            if(i==index_update)
            {
                  array[i]=element_update;
                  break;
            }
      }
      printf("element updated sucessfully:\n");
      printf("\narray after updation:\n");
      for(i=0;i<(*num);i++)
      {
            printf("array[%d]=%d\n",i,array[i]);
      }
      
}
  //function for deletion
  void deletion(int *array,int* num)
  {
      printf("\ndeletion:\n");
      int index_delete,i;
      printf("enter the index where you want to delete : ");
      scanf("%d",&index_delete);
      (*num)--;
      for(i=index_delete;i<(*num);i++)
      {
            array[i]=array[i+1];
      }
      printf("element deleted sucessfully:\n");
      printf("\narray after deletion:\n");
      for(i=0;i<(*num);i++)
      {
            printf("array[%d]=%d\n",i,array[i]);
      }
  }