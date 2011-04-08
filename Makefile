LongInt.out : LongIntMain.o LongInt.o
	g++ -o LongInt.out LongIntMain.o LongInt.o

LongIntMain.o : LongIntMain.cpp LongInt.h
	g++ -c LongIntMain.cpp

LongInt.o : LongInt.cpp LongInt.h
	g++ -c LongInt.cpp

time:	timetest.cpp LinkedList.cpp StackAr.cpp CursorList2.cpp QueueAr.cpp StackLi.cpp vector.cpp SkipList.cpp
	g++ -Wall timetest.cpp LinkedList.cpp StackAr.cpp CursorList2.cpp QueueAr.cpp StackLi.cpp vector.cpp SkipList.cpp
