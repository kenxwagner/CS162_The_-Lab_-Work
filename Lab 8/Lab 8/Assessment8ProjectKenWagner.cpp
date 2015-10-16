//Assessment8Project
//Ken Wagner
#include <iostream>
#include <string>
using namespace std;
class Car
{
	public:
		 Car()
		{ who ="Not Human";
		}
		virtual void displayID() = 0;   // pure virtual function. This makes the Car class
		                                   // an Abstract class.
		virtual  int numWheels();
		virtual ~Car()
		{
             cout <<"Virtual destructor " << endl;
		}
	private:
		string who;
};

 void Car::displayID()
		{ cout<< who << endl;
		}
int Car::numWheels()
{  
	return 0;
}
class Ford :public  Car
{   
	public:
		Ford()
		{ me ="I am a Ford!!!";
		}
	   ~Ford()
		{
             cout <<"Virtual destructor in Ford " << endl;
		}
		  void displayID(); 
		  int numWheels();

	private:
		string me;
};  // end class

		void Ford::displayID()
		{ cout<< me << endl;
		}
		int Ford::numWheels()
		{
               return 4;
		}


class Bike :public  Car
{   
	public:
		Bike()
		{ me ="I am a Bike!!!";
		}
		~Bike()
		{
             cout <<"Virtual destructor in Bike ." << endl;
		}
		 void displayID(); 
		 int numWheels();

	private:
		string me;
};
		void Bike::displayID() 
		{ cout<< me << endl;
		}
		int Bike::numWheels()
		{
             return 2;
		}

class Chevy :public  Car   // Base class public members become private the Chevy class.
{   
	public:
		Chevy()
		{ me ="I am a Chevy!!!";
		}
		~Chevy()
		{
             cout <<"Virtual destructor in Chevy ." << endl;
		}
		 void displayID(); 
		 int numWheels();

	private:
		string me;
};

		void Chevy::displayID() 
		{ cout<< me << endl;
		}

		int Chevy::numWheels()
		{ return 4;
		}
//A regular function for the main.
void PrintID( Car &);  // function prototype

int main()
{  //Car
  //Process a Ford
  Ford  FordObj;

  PrintID(FordObj);  // call PrintID and member function displayID.
 
 //Process a Chevy
  Chevy  ChevyObj;
  PrintID(ChevyObj);
  
 cin.ignore();
 cin.get();
  return 0;
}

void PrintID( Car &object)  // function definition
{
    object.displayID();
	cout << "Wheels = " << object.numWheels()<< endl;
}



