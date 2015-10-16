#include <iostream>
#include <string>
using namespace std;
class CollectionMovie  // This is the base class/Parent class
{	public:
       CollectionMovie( ); // Default constructor.
	   CollectionMovie(string);
       void DisplayCollectionMovie();
	   void SetCollectionMovie();
	private:
	   string CollectionMovieName;

};
CollectionMovie::CollectionMovie(string n2)
{  cout << "In the overloaded constructor of CollectionMovie class ." << endl;
   CollectionMovieName= n2;
}

void CollectionMovie::SetCollectionMovie()
{  fflush(stdin);
   cout << "Enter a CollectionMovie name " << endl;
   getline(cin,CollectionMovieName);
}
void CollectionMovie::DisplayCollectionMovie()
{   
	cout << "The CollectionMovie name is " << CollectionMovieName << endl;
}
CollectionMovie::CollectionMovie()
{ cout << "\a\aIn the default constructor of the CollectionMovie class. "<< endl;
  CollectionMovieName ="Aliens!!";

}

class Movie : public CollectionMovie   //  Movie inherits from the CollectionMovie class.  
{                               //Movie is a derived class.
	public:
	    Movie();
	    Movie(string, string);  
		void DisplayCollectionMovie();
	private:
            string leadActor1;

};

void Movie::DisplayCollectionMovie()             // added through task # 5
{   
	cout << "The Lead is " << leadActor1 << endl;
	CollectionMovie::DisplayCollectionMovie();
}


Movie::Movie( string n1, string n2)
: CollectionMovie(n2)
{   cout <<"In the Overloaded constructor of the Movie class " << endl;
	leadActor1 = n1;

}
Movie::Movie()
{  
   cout << "\aIn the default constructor of the Movie class. " << endl;
   leadActor1 = " Who cares? ";
}
void main()
{   
    Movie  bObject;  //Calls the parent/CollectionMovie class constructor first , then calls the 
	      //default constructor of the derived class.
    Movie cObject("Starring", "Movie Specials");
        
    cin.ignore();
    cin.get();
}