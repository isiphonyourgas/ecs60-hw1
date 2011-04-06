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
}

istream &operator >> (istream &input, LongInt &longint)
{
  string temp = "";
  char c;
  int i;
  input.readsome(temp, 8);
  cout << temp;
  if (input.peek() != '\n')
  {
    longint.next = new LongInt;
    input >> *(longint.next);
  }
  return input;
}

ostream &operator << (ostream &output, const LongInt &longint)
{
  if (longint.next != NULL)
  {
   // output << longint.content;
   // output << *(longint.next);
  } else { cout << "NULL";}
  return output;
}
LongInt :: ~LongInt() {}
