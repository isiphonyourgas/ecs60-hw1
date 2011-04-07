//Jason Wong, Jacob Mederos

#include <iostream>
#include <iomanip>
#include "LongInt.h"
#include <string>
#include <cstdlib>

//Default Constructor
//Sets everything to 0 and NULL in order for rest of program to work
LongInt :: LongInt () 
{
  content = 0;
  next = NULL;
  back = NULL;
}

//Overloaded insertion operator
//This functions loads by reading each individual char from the stream
//and stores it in a List of digits
istream &operator >> (istream &input, LongInt &longint)
{
  //Variable Declarations
  char c;
  int s;
  LongInt *ptr;
  ptr = &longint;

  //Recieves from the stream and converts into integer format
  c = input.get();
  s = int(c) - 48;

  //Filters out unwanted chars
  if ((s > -1) && (s < 10))//integer check
  {
    longint.content = s;//loads the content
    longint.next = new LongInt;//creates next LongInt Object
    ((longint.next)->back) = &longint;//Sets back pointer
    input >> *(longint.next);//Continues to next digit input
  } else { //If didn't pass check, remove excess LongInt object
    ptr = longint.back;//moves pointer back
    free(ptr->next);//frees excess object
    ptr->next = NULL;//Nulls next pointer for running the down the list
  } 

//Sets the back pointer in the first node to not NULL for overloaded +
  if(longint.back == NULL)
  { 
    longint.back = new LongInt;
  }


//Return Statement
  return input;
}//Overloaded >> Insertion Operator


//Overloaded Output Operator
//Reads the first digit of the list and calls itself for further digits
//until the end of the list
ostream &operator << (ostream &output, const LongInt &longint)
{

//Outputs the content of the list
  output << longint.content;

//Checks to see if it is the end of the list and if it doesn, makes a
//recurssive call
  if (longint.next != NULL)
  {
    output << *(longint.next);
  }

//Return Statement
  return output;
}//Overloaded << Output Operator


//Overloaded Addition Operator
LongInt &operator + (LongInt &int1, LongInt &int2)
{
//Variable Declarations
  LongInt *ptr1, *ptr2, *ptr3;
  LongInt *begin = NULL;
  int result = 0;//Sets the result at 0
  bool flag = 0;//Used to carry digits over

//Sets pointers
  ptr1 = &int1;
  ptr2 = &int2;

//traverses to the end of the list
  while(ptr1->next != NULL)
  { ptr1 = ptr1->next; }
  while(ptr2->next != NULL)
  { ptr2 = ptr2->next; }

//adds the digits together when still traversing through both lists
  while((ptr1->back != NULL) && (ptr2->back != NULL))
  {
    ptr3 = new LongInt;//Creates new node
    ptr3->next = begin;//Sets next pointer on current node being added

    if(flag == 0)//If there was 1 digits in last node
     result = ptr1->content + ptr2->content; 
    else//If there was 2 digits in last node
     result = ptr1->content + ptr2->content + 1; 

//Checks for 2 digits in current node
    if( result > 9)//There is 2 digits
    { flag = 1;
      result = result - 10;
    }
//There is 1 digit
    else 
      flag = 0;

//Scoots pointer back 1 node
    ptr1 = ptr1->back;
    ptr2 = ptr2->back;

//Loads the content of the node
    ptr3->content = result;
    begin = ptr3;//Sets beginning of the list
    ptr3 = ptr3->back;//Prepares to add node behind current node for a
		      //more significant digit
  }//Traverse both lists

//If 2nd list reaches the end, continues adding the 1st list
  while(ptr1->back != NULL)
  {
    ptr3 = new LongInt;
    ptr3->next = begin;
    ptr3->content = ptr1->content;
    if(flag == 1)//checks for 2 digits in last node
    {
      (ptr3->content)++;//increment current node
      flag = 0;//reset flag
      if(ptr3->content >= 10)//Checks for 2 digits in current node
      {
        flag = 1;//sets flag
        ptr3->content = ptr3->content - 10;//deletes significant digit
  					   //for next node
      }
    }
    ptr1 = ptr1->back;
    begin = ptr3;
    ptr3 = ptr3->back;
  }//Traverse list 2

//If 1st list reaches end, continues adding 2nd list
  while(ptr2->back != NULL)
  {
    ptr3 = new LongInt;
    ptr3->next = begin;
    ptr3->content = ptr2->content;
    if(flag == 1)
    {
      (ptr3->content)++;
      flag = 0;
      if(ptr3->content >= 10)
      {
        flag = 1;
        ptr3->content = ptr3->content - 10;
      }
    }
    ptr2 = ptr2->back;
    begin = ptr3;
    ptr3 = ptr3->back;
  }//Traverse List 1

//If first list had 2 digits in content, creates a new node to hold
//most significant digit
  if(flag == 1)
  {
    ptr3 = new LongInt;
    ptr3->next = begin;
    ptr3->content = 1;
    begin = ptr3;
  }
  
//Return Statement
  return *begin;
}//Overloaded + Addition Operator


LongInt :: ~LongInt() {}//Destructor

