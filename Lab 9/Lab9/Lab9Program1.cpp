#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Template definition for square function.
template <typename T>
T square(T number)
{
	return number * number;
}

int main()
{
	char firstChar, secondChar;
	cout << fixed << setprecision(2);
	cout << " square of A*A is "<< square('A') << endl;
	// Get an integer and compute its square.
	cout << "Enter an integer: ";	
	//int i;
	//cin >> i;
	cin >> firstChar;

	//cout << "The square is " <<  square(i);	
	cout << "The square is " <<  square(firstChar);	

	cout << "\nEnter a double: ";
	//double d;
	//cin >> d;	
	cin >> secondChar;
	
	//cout << "The square is " << square(d) << endl;
	cout << "The square is " << square(secondChar) << endl;

	cin.ignore();
	cin.get();
	return 0;
}