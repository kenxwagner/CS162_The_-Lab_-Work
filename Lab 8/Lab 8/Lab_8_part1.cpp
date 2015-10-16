/*This program illustrates three classes: base class and two derived classes and
each class has one common member function, displayID().

In the main program, there is one function,PrintID(), that has a parameter 
as an object of the base class. The function uses the parameter to call
the common member function, displayID().    

Three objects of the classes are instantiated in the main. 
Each one is passsed to the function PrintID.
However, the object passed is recognized as a based class object due to
the type of the parameter.

As a result, the object passed will call the member function displayID() 
of the based class even the object passed is not a base-class object.
Only the displayID() of the base class is binded at compiled time due to inheritance.
This is called static binding. This program DOES NOT illustrate "polymorphism".
*/

#include <iostream>
#include <string>
using namespace std;
class Animal
{
	public:
		 Animal()
		{ who ="Not Human";
		}
		void displayID(); 
		
	private:
		string who;
};

void Animal::displayID()
{ cout<< who << endl;
}

class Cat :public  Animal
{   
	public:
		Cat()
		{ me ="I am a CAT!!!";
		}
		 void displayID(); 
		
	private:
		string me;
};

void Cat::displayID()
{ cout<< me << endl;
}

class Dog :public  Animal
{   
	public:
		Dog()
		{ me ="I am a DOG!!!";
		}
		void displayID(); 
		

	private:
		string me;
};

void Dog::displayID() 
{ cout<< me << endl;
}
//A regular function for the main.

void PrintID( Animal &);  // function prototype

int main()
{  //Process Animal
  Animal anyThing;
  PrintID(anyThing);
  
  //Process a cat
  Cat  catObj;

  PrintID(catObj);  // call the PrintID that calls a member function displayID.
  
 //Process a dog
  Dog  dogObj;
  
  PrintID(dogObj);
  
  cin.ignore();
  cin.get();
  return 0;
}

void PrintID( Animal &object)  // function definition
{
    object.displayID();
}
 
/*  Output:
Not Human
Not Human
Not Human
Press any key to continue . . .
*/
