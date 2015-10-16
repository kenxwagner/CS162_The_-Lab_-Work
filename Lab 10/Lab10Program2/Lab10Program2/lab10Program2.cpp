#include <iostream>
#include <string>
using namespace std;

template <class T>
class Phoneclass
{
	public:
		Phoneclass(T , T , T);

	friend ostream &operator << ( ostream &out, Phoneclass &object);
	/*{  out << "(" <<object.areacode  <<")"<< object.line <<"-"<<object.lastfour<< endl;
       return out;
	}*/
	private:
		T areacode;
		T line;
		T lastfour;
};
template <typename T>
Phoneclass<T>::Phoneclass(T inarea, T inLine, T number )
{
   areacode = inarea;
   line = inLine;
   lastfour = number;
}

    template <class T>
    ostream &operator << ( ostream &out, Phoneclass &object)
	{  out << "(" <<object.areacode  <<")"<< object.line <<"-"<<object.lastfour<< endl;
       return out;
	}

int main()
{   
    Phoneclass<short> phone1(509,547,5116);
    cout << phone1;
	Phoneclass<char *> phone2("509","547","0511");
	cout << phone2;
	Phoneclass<string> phone3("509","627","6446");
	cout << phone3;
	cin.ignore();
	cin.get();
}//end main