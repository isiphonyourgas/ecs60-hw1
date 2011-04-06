//Jason Wong, Jacob Mederos

#include <iostream>
#include <iomanip>
#include "LongInt.h"

LongInt :: LongInt () 
{
  content = 0;
}

istream &operator >> (istream &input, LongInt &longint)
{
  input >> setw(9) >> longint.content;
  //input >> longint.next();
  return input;
}

ostream &operator << (ostream &output, const LongInt &longint)
{
  output << longint.content;
  return output;
}
LongInt :: ~LongInt() {}
