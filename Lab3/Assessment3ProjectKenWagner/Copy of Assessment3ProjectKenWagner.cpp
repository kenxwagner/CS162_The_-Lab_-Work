//Assessment3ProjectKenWagner.cpp
#include <iostream>
#include <string>
using namespace std;
//Date class definition
class Date
{ public:
	  Date(short d= 1, short m = 1, short y = 1900);//Default constructor with default values.
      Date(Date &);// copy constructor. 
      void printDate();// function prototype;
  private:
 	short day, month, year;
};  

// Date Member funtion definitions
Date::Date( short d,short m, short y)
{ cout <<"In the date default constructor." << endl;
  day = d;
  month = m;
  year = y;

}
Date::Date(Date &inDateObject)
{  cout <<"In the date copy constructor." << endl;
   day = inDateObject.day;
   month = inDateObject.month;
   year = inDateObject.year;
}
void Date::printDate()
{ cout << day << "/"<<month <<"/" << year << endl;
}

//Student class definition.
class Student
{ public:
       Student(string, string , Date, Date);   //default constructor with default values.
	 
 private:
   Date  completionDate;
   Date  entryDate;
   string name;
   string sid;
};    
//Student member function definitions 
Student::Student(string n, string s, Date d1, Date d2)
         : completionDate(d1), entryDate(d2)  //LINE 1
{ 
	cout <<" In the student constructor ."<< endl;
  name = n;
  sid = s;
  cout <<"Student's name and SID are " << name << "  " << sid << endl;
  cout <<"Completion date: " ;
  completionDate.printDate();   //LINE 2
  cout <<"Entry date: " ;
  entryDate.printDate();    //LINE 3
}

int main( )
{
	Date startDateObject(20,9,2005);  //LINE4
	Date endDateObject(6,15,2008); //LINE 5
	Student("John Jackson","8300-56-1999",startDateObject,endDateObject ); //LINE 6

  system("pause");
}