#include <iostream>
using namespace std;
#include "Lab10Program1Header.h"

const int SIZE = 5;

int main()
{	
	double yourArray[SIZE] = { 1.1 ,2.1,3.1,4.1,5.1  };
	char charArray[SIZE] = {'a','b','c','d','e'  };
	int myArray[SIZE] = { 1, 6, 8, 2, 7 };
	cout <<"Passing an int array to a constructor of the TestArray class \n";
	
    
	TestArray <int> ObjectList1( myArray,SIZE);
	ObjectList1.Display();
	TestArray <double> ObjectList2( yourArray,SIZE);
	ObjectList2.Display();
	TestArray <char> ObjectList3( charArray,SIZE);
	ObjectList3.Display();

	cin.ignore();
	cin.get();
	return 0;
}