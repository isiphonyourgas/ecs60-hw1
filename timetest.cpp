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

int disp_menu();
void menu(string filename);
void RunList(string filename);
void RunCursorList(string filename);
void RunStackAr(string filename);
void RunStackLi(string filename);
void RunQueueAr(string filename);
void RunSkipList(string filename);

int main() {

    string filename = "";

    cout << "Filename >> ";
    getline(cin, filename);

    menu(filename);

}

int disp_menu() {
    int choice;
    while (1) {
        cout << "\n      ADT Menu\n"
                << "0. Quit\n"
                << "1. LinkedList\n"
                << "2. CursorList\n"
                << "3. StackAr\n"
                << "4. StackLi\n"
                << "5. QueueAr\n"
                << "6. SkipList\n";

        cout << "Your choice >> ";
        cin >> choice;
        if (choice > -1 && choice < 7)
            return choice;
        else
            cout << "Your choice is not between 1 and 6.\nPlease try again.\n";
    }
}

void menu(string filename) {
    CPUTimer ct;
    int choice;
    do {
        choice = disp_menu();
        ct.reset();

        switch (choice) {
            case 1: RunList(filename);
                break;
            case 2: RunCursorList(filename);
                break;
            case 3: RunStackAr(filename);
                break;
            case 4: RunStackLi(filename);
                break;
            case 5: RunQueueAr(filename);
                break;
            case 6: RunSkipList(filename);
                break;
        }//switch statement
        cout << "CPU time: " << ct.cur_CPUTime() << endl;
    } while (choice > 0);
}

void RunList(string filename) {
    CursorList <int> list(cursorSpace);
    CursorListItr <int> listItr = list.zeroth();
    ifstream inf;
    char command, line[512];
    int num;

    inf.open(filename.c_str());
    inf.getline(line, 512);

    while (inf >> command >> num) {
        if (command == 'i')
            list.insert(num, listItr);
        else if (command == 'd')
            list.remove(num);
    } //while
    inf.close();

}

void RunCursorList(string filename) {
    CursorList <int> list(cursorSpace);
    CursorListItr <int> listItr = list.zeroth();
    ifstream inf;
    char command, line[512];
    int num;

    inf.open(filename.c_str());
    inf.getline(line, 512);

    while (inf >> command >> num) {
        if (command == 'i')
            list.insert(num, listItr);
        else if (command == 'd')
            list.remove(num);
    } //while
    inf.close();
}

void RunStackAr(string filename) {
    StackAr <int> stack(1000000);
    ifstream inf;
    char command, line[512];
    int num;

    inf.open(filename.c_str());
    inf.getline(line, 512);

    while (inf >> command >> num) {
        if (command == 'i')
            stack.push(num);
        else if (command == 'd')
            stack.pop();
    } //while
    inf.close();
} // RunStackAr()

void RunStackLi(string filename) {
    StackLi<int> stack;
    ifstream inf;
    int num;
    char command, line[512];

    inf.open(filename.c_str());
    inf.getline(line, 512);

    while (inf >> command >> num) {
        if (command == 'i')
            stack.push(num);
        else if (command == 'd')
            stack.pop();
    } //while
    inf.close();
} // RunStackLi()

void RunQueueAr(string filename) {
    Queue<int> queue(1000000);
    ifstream inf;
    int num;
    char command, line[512];

    inf.open(filename.c_str());
    inf.getline(line, 512);

    while (inf >> command >> num) {
        if (command == 'i')
            queue.enqueue(num);
        else if (command == 'd')
            queue.dequeue();
    }
    inf.close();
}

void RunSkipList(string filename) {
    SkipList <int> list(0, 250001);
    ifstream inf;
    int num;
    char command, line[512];

    inf.open(filename.c_str());
    inf.getline(line, 512);

    while (inf >> command >> num) {
        if (command == 'i')
            list.insert(num);
        else if (command == 'd')
            list.deleteNode(num);
    }
    inf.close();
}
