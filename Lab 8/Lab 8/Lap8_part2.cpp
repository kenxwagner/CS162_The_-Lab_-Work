/*This program illustrates three classes: base class and two derived classes and
each class has one common member function, displayID().

In the main program, there is one function,PrintID(), that has a parameter 
as an object of the base class. The function uses the parameter to call
the common member function, displayID().    

Three objects of the classes are instantiated in the main. 
Each one is passsed to the function PrintID.
However, the object passed is recognized as a based class object due to
the type of the parameter.

Rules:
   1. Use the keyword virtual in front of a function prototype in the base class.
      When define the virtual function, the keyword virtual is not needed.
      Optional: The keyword virtual is not needed for derived class member functions.
   2. You have more than one virtual function.
   3. You can create objects of any classes: base and/or derived classes.
   4. An abstract class contains a pure virtual function.
      A pure virtual function is initialized to 0 at the declaration statement.
	  For example: virtual void displayID() = 0; 
   5. You cannot instantiate an object of the abstract class.

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
		virtual void displayID() = 0;   // pure virtual function. This makes the Animal class
		                                   // an Abstract class.
		virtual  int numlegs();
		virtual ~Animal()
		{
             cout <<"Virtual destructor " << endl;
		}
	private:
		string who;
};

 void Animal::displayID()
		{ cout<< who << endl;
		}
int Animal::numlegs()
{  
	return 0;
}
class Cat :public  Animal
{   
	public:
		Cat()
		{ me ="I am a CAT!!!";
		}
	   ~Cat()
		{
             cout <<"Virtual destructor in Cat " << endl;
		}
		  void displayID(); 
		  int numlegs();

	private:
		string me;
};  // end class

		void Cat::displayID()
		{ cout<< me << endl;
		}
		int Cat::numlegs()
		{
               return 4;
		}


class Bird :public  Animal
{   
	public:
		Bird()
		{ me ="I am a Bird!!!";
		}

		~Bird()
		{
             cout <<"Virtual destructor in Bird ." << endl;
		}
		 void displayID(); 
		 int numlegs();

	private:
		string me;
};

		void Bird::displayID() 
		{ cout<< me << endl;
		}
		int Bird::numlegs()
		{
             return 2;
		}

class Dog :public  Animal   // Base class public members become private the Dog class.
{   
	public:
		Dog()
		{ me ="I am a DOG!!!";
		}
		~Dog()
		{
             cout <<"Virtual destructor in Dog ." << endl;
		}
		 void displayID(); 
		 int numlegs();

	private:
		string me;
};

		void Dog::displayID() 
		{ cout<< me << endl;
		}

		int Dog::numlegs()
		{ return 4;
		}
//A regular function for the main.

void PrintID( Animal &);  // function prototype


int main()
{  //Process Animal

	//Animal anyThing;
 


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
	cout << "Legs = " << object.numlegs()<< endl;
}



