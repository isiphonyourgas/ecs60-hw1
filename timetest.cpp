// Jason Wong, Jacob Mederos

#include <iostream>
#include <fstream>
#include <string>
#include "CPUTimer.h"
#include "dsexceptions.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList2.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "vector.h"
#include "SkipList.h"

vector<CursorNode <int> > cursorSpace;

using namespace std;

void disp_menu();
void menu(string filename);
void RunList(string filename);
void RunCursorList(string filename);
void RunStackAr(string filename);
void RunStackLi(string filename);
void RunQueueAr(string filename);
void RunSkipList(string filename);

int main()
{

  string filename = "";;

  cout << "Filename >> ";
  getline(cin, filename);
  
  menu(filename);

}

void disp_menu()
{
  cout << "\n      ADT Menu\n"
  << "0. Quit\n"
  << "1. LinkedList\n"
  << "2. CursorList\n"
  << "3. StackAr\n"
  << "4. StackLi\n"
  << "5. QueueAr\n"
  << "6. SkipList\n";
}

void menu(string filename)
{
  int choice;
  CPUTimer ct;
  do
  {
    ct.reset();
    disp_menu();
    cout << "Your choice >> ";
    cin >> choice;
    //clock reset
    switch(choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
    }//switch statement
    cout << "CPU time: "<< ct.cur_CPUTime()  << endl;  
  } while (choice > 0);
}

void RunList(string filename)
{
  //Variable Declarations
  ifstream file;
  char operation;
  int amount;
  file.open( filename ios::in )//Opens file

  //if the file does not exist.
  if( !p )
  {
    cout << "There is no file " << filename << "." << endl;
    break;
  }
//Reads until the file is end of file
  while(!file.eof())
  {
    operation = file.get();//Reads the first char which is i or d to determine
                           //operation needed
    if( operation == 'i' )//If insert operation
    {
  
    } else {//If delete operation
  
    }
  }
  file.close();//Closes file
}

void RunCursorList(string filename)
{

}

void RunStackAr(string filename)
{

}

void RunStackLi(string filename)
{

}

void RunQueueAr(string filename)
{

}

void RunSkipList(string filename)
{

}
