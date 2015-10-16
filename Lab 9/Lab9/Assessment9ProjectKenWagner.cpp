#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

    template < typename A, typename B > 
		square(A number, B part)
    {
		cout << "try it out" << number << "  " << B part << endl;
	  
    } ;


int main()
{
	char firstChar, secondChar;
	cout << fixed << setprecision(2);
	cout << " square of A*A is "<< square('A', 100) << endl;
	// Get an integer and compute its square.
	cout << "Enter an integer: ";	
	//int i;
	//cin >> i;
	cin >> firstChar;

	//cout << "The square is " <<  square(i);	
	cout << "The square is " <<  square(firstChar, 500);	

	cout << "\nEnter a double: ";
	//double d;
	//cin >> d;	
	cin >> secondChar;
	
	//cout << "The square is " << square(d) << endl;
	cout << "The square is " << square(secondChar, 900) << endl;

	cin.ignore();
	cin.get();
	return 0;
}