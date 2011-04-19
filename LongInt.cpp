//Jason Wong, Jacob Mederos
 
#include <iostream>
#include <iomanip>
#include "LongInt.h"
#include <string>
#include <cstdlib>

LongIntNode :: LongIntNode ()
{
  forward = NULL;
  backward = NULL;
}

void LongIntNode :: set(int s)
{  content = s;  }

void LongIntNode :: setnext(LongIntNode *ptr)
{  forward = ptr; }

void LongIntNode :: setback(LongIntNode *ptr)
{  backward = ptr; }

int LongIntNode :: get()
{  return content;  }

LongIntNode* LongIntNode :: next()
{   return forward; }

LongIntNode* LongIntNode :: back()
{  return backward; }

LongIntNode :: ~LongIntNode() {}
















//Default Constructor
//Sets everything to 0 and NULL in order for rest of program to work
LongInt :: LongInt () 
{
  head = NULL;
  tail = NULL;
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

  while(c != '\n')
{
  //Recieves from the stream and converts into integer format
  c = input.get();
  s = int(c) - 48;

  //Filters out unwanted chars
  if ((s > -1) && (s < 10))//integer check
    longint.insertBack(s);
}
//Return Statement
  return input;
}//Overloaded >> Insertion Operator


//Overloaded Output Operator
//Reads the first digit of the list and calls itself for further digits
//until the end of the list
ostream &operator << (ostream &output, const LongInt &longint)
{
  LongIntNode *ptr;
//Outputs the content of the list

  ptr = longint.head;
  while(ptr != NULL)
  {
    output << ptr->get();
    ptr = ptr->next();
  }
//Return Statement
  return output;
}//Overloaded << Output Operator


//Overloaded Addition Operator
LongInt &operator + (LongInt &int1, LongInt &int2)
{
//Variable Declarations
  LongIntNode *ptr1, *ptr2, *ptr3;
  LongInt *begin = new LongInt;
  int result = 0;//Sets the result at 0
  bool flag = 0;//Used to carry digits over

//Sets pointers to end of list
  ptr1 = int1.tail;
  ptr2 = int2.tail;

//adds the digits together when still traversing through both lists
  while((ptr1 != NULL) && (ptr2 != NULL))
  {
    

    if(flag == 0)//If there was 1 digits in last node
     result = ptr1->get() + ptr2->get(); 
    else//If there was 2 digits in last node
     result = ptr1->get() + ptr2->get() + 1; 

    //Checks for 2 digits in current node
    if( result > 9)//There is 2 digits
    { flag = 1;
      result = result - 10;
    }
    //There is 1 digit
    else 
      flag = 0;

    begin->insertFront(result);//loads the result
    ptr1 = ptr1->back();//moves pointer back
    ptr2 = ptr2->back();

  }//Traverse both lists

  //If 2nd list reaches the end, continues adding the 1st list
  while(ptr1 != NULL)
  {
    
    result = ptr1->get();

    if(flag == 1)//checks for 2 digits in last node
    {
      result++;
      flag = 0;//reset flag
      if(result >= 10)//Checks for 2 digits in current node
      {
        flag = 1;//sets flag
        result = result - 10;//deletes significant digit
  					   //for next node
      }
    }
    begin->insertFront(result);
    ptr1 = ptr1->back();    
  }//Traverse list 1

//If 1st list reaches end, continues adding 2nd list
  while(ptr2 != NULL)
  {
    result = ptr2->get();
    if(flag == 1)
    {
      result++;
      flag = 0;
      if(result >= 10)
      {
        flag = 1;
        result = result - 10;
      }
    }
    begin->insertFront(result);
    ptr2 = ptr2->back();
  }//Traverse List 1

//If first list had 2 digits in content, creates a new node to hold
//most significant digit
  if(flag == 1)
  {
    begin->insertFront(1);
  }
  
//Return Statement
  return *begin;
}//Overloaded + Addition Operator


//Will Insert a Node at the front
void LongInt :: insertFront(int s)
{
  LongIntNode *ptr;

  if(head == NULL)
  {
    head = new LongIntNode;
    tail = head;
    ptr = head;
  }
  else 
  {
    ptr = head->back();
    ptr = new LongIntNode;
    ptr->setnext(head);
    head = ptr;
  }
  
  ptr->set(s);
    
}

//Will Insert a Node at the Back
void LongInt :: insertBack(int s)
{
  LongIntNode *ptr;
  
  if(tail == NULL)
  {
    tail = new LongIntNode;
    head = tail;
    ptr = tail;
  }
  else
  {
    ptr = tail->next();
    ptr = new LongIntNode;
    ptr->setback(tail);
    tail = ptr;
  }
  
  ptr->set(s);
}

LongInt :: ~LongInt() {}//Destructor

