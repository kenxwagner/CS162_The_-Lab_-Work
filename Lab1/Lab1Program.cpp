#include <iostream>
#include <string>
using namespace std;

struct  EmailAddressBook
{
   string name;
   string emailAddress;
   EmailAddressBook( )
   {  cout << "The default constructor is called " << endl;
     name = "Blank ";
     emailAddress = "Blank ";
   }
   EmailAddressBook(string n, string a )
   {  cout <<"In the overloaded constructor. "<< endl;
     name = n;
     emailAddress = a;
   }

   void Display(  )
   {
      cout << "Name = " << name  << "Email address = " << emailAddress << endl;
   }
   
};

int main( )
{
   EmailAddressBook  myAssociate1;  // LINE 1
  // myAssociate1.Display();  // LINE 2
  // cout << " In the main ,Name1 = " << myAssociate1.name<< "Email address 1= "<< myAssociate1.emailAddress << endl; // LINE 3
  // EmailAddressBook  myAssociate2("Jack Smith", "jsmith@msn.com");  // LINE 4
  // myAssociate2.Display();  // LINE 5
  // cout << " In the main ,Name 2 = " << myAssociate2.name<< "Email address 2= "<< myAssociate2.emailAddress << endl; // LINE 6
   EmailAddressBook  myAssociateArray[3];  // LINE 7
   for (int i = 0 ; i < 3 ; i++)  // LINE 8
   {     cout << "Enter your associate name  and his/her email address # " << i + 1 << endl;  // LINE 9
		getline(cin,myAssociateArray[i].name );

   //cin >>  >>myAssociateArray[i].emailAddress ; // LINE 10
  }

  for (int j = 0; j < 3 ; j++)
  {
	myAssociateArray[j].Display();
  }

  cin.ignore();
   cin.get( ); // Wait for any character to be entered. This pauses the screen when the program is run.
   return 0;
}
