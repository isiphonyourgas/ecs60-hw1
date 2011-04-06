//Jason Wong, Jacob Mederos

#include <iostream>
#include <iomanip>
#include "LongInt.h"
#include <string>
#include <cstdlib>

LongInt :: LongInt () 
{
  content = 0;
  next = NULL;
  back = NULL;
}

istream &operator >> (istream &input, LongInt &longint)
{
  char c;
  LongInt *ptr;
  ptr = &longint;
  c = input.get();
  longint.content = int(c) - 48;
  //cout << longint.content << endl;;
  if (input.peek() != '\n')
  {
    longint.next = new LongInt;
    ((longint.next)->back) = &longint;
    input >> *(longint.next);
  }
  if(longint.back == NULL)
  { 
    longint.back = new LongInt;
  }
  return input;
}

ostream &operator << (ostream &output, const LongInt &longint)
{
  output << longint.content;
  if (longint.next != NULL)
  {
    output << *(longint.next);
  }
  return output;
}

LongInt &operator + (LongInt &int1, LongInt &int2)
{
  LongInt *ptr1, *ptr2, *ptr3;
  LongInt *begin = NULL;
  int result = 0;
  bool flag = 0;
  ptr1 = &int1;
  ptr2 = &int2;
  //traverses to the end of the list
  while(ptr1->next != NULL)
  { ptr1 = ptr1->next; }
  while(ptr2->next != NULL)
  { ptr2 = ptr2->next; }
  while((ptr1->back != NULL) && (ptr2->back != NULL))
  {
    ptr3 = new LongInt;
    ptr3->next = begin;
    if(flag == 0)
    { result = ptr1->content + ptr2->content; }
    else
    { result = ptr1->content + ptr2->content + 1; }
    if( result > 9)
    { flag = 1;
      result = result - 10;
    }
    else 
      {flag = 0; }
    ptr1 = ptr1->back;
    ptr2 = ptr2->back;
    ptr3->content = result;
    begin = ptr3;
    ptr3 = ptr3->back;
  }
  if(ptr1->back == NULL)
  {
    
  } else {
    if(ptr2->back == NULL)
    {

    }
  }
//cout << begin->content << (begin->next)->content << endl;
  //while((ptr1->back != NULL) && (ptr2->back != NULL));
  //cout << result;
  return *begin;
}

void LongInt :: setback( LongInt input)
{
  back = &input;
}
LongInt :: ~LongInt() {}

