#include <iostream>
#include <string>
using namespace std;
class Band  // This is the base class/Parent class
{	public:
       Band( ); // Default constructor.
	   Band(string);
       void DisplayBand();
	   void SetBand();
	private:
	   string BandName;

};
Band::Band(string n2)
{  cout << "In the overloaded constructor of Band class ." << endl;
   BandName= n2;
}

void Band::SetBand()
{  fflush(stdin);
   cout << "Enter a Band name " << endl;
   getline(cin,BandName);
}
void Band::DisplayBand()
{   
	cout << "The band name is " << BandName << endl;
}
Band::Band()
{ cout << "\a\aIn the default constructor of the Band class. "<< endl;
  BandName ="Rush!!";

}

class Beatles : public Band   //  Beattles inherits from the Band class.  
{                               //Beattles is a derived class.
	public:
	    Beatles();
	    Beatles(string, string);  
		void DisplayBand();
	private:
            string frontMan1;

};

void Beatles::DisplayBand()             // added through task # 5
{   
	cout << "The front man is " << frontMan1 << endl;
	Band::DisplayBand();
}
Beatles::Beatles( string n1, string n2)
: Band(n2)
{   cout <<"In the Overloaded constructor of the Beatles class " << endl;
	frontMan1 = n1;

}
Beatles::Beatles()
{  
   cout << "\aIn the default constructor of the Beatles class. " << endl;
   frontMan1 = "John Lennon";
}
void main()
{   
    Beatles  bObject;  //Calls the parent/Band class constructor first , then calls the 
	      //default constructor of the derived class.
    Beatles cObject("Paul Mccartny", "Beatle Specials");
        
    cin.ignore();
    cin.get();
}