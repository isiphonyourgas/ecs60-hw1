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
  char c;
  c = input.get();
  longint.content = int(c) - 48;
  //cout << longint.content << endl;;
  if (input.peek() != '\n')
  {
    longint.next = new LongInt;
    input >> *(longint.next);
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
LongInt :: ~LongInt() {}
