#include"MyList.h"
#include<iostream>
using namespace std;
int main()
{
	MyStruct * myStruct = nullptr;
	CMyList * myList = new CMyList();
	myList->Create();
	myList->PrintList();
}