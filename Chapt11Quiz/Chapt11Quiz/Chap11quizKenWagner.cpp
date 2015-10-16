// Ken Wagner
#include <iostream>
using namespace std;

// House and HouseAddress, and these two classes must be related 
// Each class should contain one constructor 
// and one member function and 
// two private members


// Base class.
class House
{
private:
	int stories;
	int price;
public:
	House()
	{ cout << "Let's use a House constructor.\n"; }
	void print();
};

class HouseAddress : public House
{
private:
	int address;
	int phone;
public:
	HouseAddress() // Constuctor
	{ cout << "Let's use a HouseAddress constructor.\n"; }
	void print();
};

int main()
{
	
	cout << "We will now create a House object.\n";
	House object;
	cout << "We will now create a HouseAddress object.\n";
	cout << "The end.\n";

	return 0;
}