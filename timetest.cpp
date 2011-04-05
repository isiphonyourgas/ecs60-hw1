// Jason Wong, Jacob Mederos

#include <iostream>
#include <fstream>
#include <string>

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
  do
  {
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
    cout << "CPU time: " << endl;  
  } while (choice > 0);
}

void RunList(string filename)
{

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
