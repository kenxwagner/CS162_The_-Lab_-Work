// Ken Wagner
#include <iostream>
 #include <string>
using namespace std;

struct  HouseItems
{
   string name;  // Item name
   string room;  // Locatin
   HouseItems( )
   {  cout << "Someone Order a default constructor???  " << endl;
     name = "Blank ";
     room = "Blank ";
   }
   HouseItems(string n, string a )
   {  cout <<"And now someone wants an overloaded constructor. "<< endl;
     name = n;
     room = a;
   }

   void Display(  )
   {
      cout << "Item Name = " << name  << "     Room Location = " << room << endl;
   }
   void more(  )
   {
	  cout << "It's there because you put it there!" << endl;
   }
};

int main( )
{
   HouseItems  myItem1;  
   myItem1.Display();  
   cout << "In a room is Item 1 = " << myItem1.name<< "   Room Location = "<<   myItem1.room << endl; 
   HouseItems  myItem2("Ming Vase  ", " Dining Room");  
   myItem2.Display();  
   cout << "There is Item 2 = " << myItem2.name<< "   Room Location = "<< myItem2.room << endl; 
  HouseItems  houseItemArray[3];  
   for (int i = 0 ; i < 3 ; i++) 

   {     cout << "Enter your household item name,"<< endl;
		 cout << "press enter and then enter it's location followed by enter:" << endl;  
		fflush(stdin);
		getline(cin,houseItemArray[i].name );
		//cin.ignore();
		fflush(stdin);
		getline(cin,houseItemArray[i].room); 
		//cin.ignore();
   
  }

  for (int j = 0; j < 3 ; j++)
  {
	houseItemArray[j].Display();
	cout << endl;
	
  }
    houseItemArray[2].more();
  cin.ignore();
   cin.get( ); // Wait for any character to be entered. This pauses the screen when the program is run.
   return 0;
}
