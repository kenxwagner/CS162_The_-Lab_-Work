//Lab5Task1.cpp
//Ken Wagner
#include <iostream>
using namespace std;

int main()
{
	int  * Ptr = 0;  // pointer variable declaration.
	int  Number = 155;
	Ptr = &Number;  // The address of Number is assigned to the pointer variable Ptr.
	cout << &Ptr  << endl;
	cout << &Number << endl;
	cout << long( &Ptr) << endl;
	cout << long(&Number) << endl;
	cout << *Ptr  << endl;  // displays 155 
	*Ptr = 255;
	cout << Number << endl;  // displays 255.
	*Ptr  += 355;
	cout << Number << endl;  // displays 610.


	return 0;
}