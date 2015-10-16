//Assessment3ProjectKenWagner.cpp
#include <iostream>
#include <string>
using namespace std;
//Person class definition
class Person
{ public:
	  Person(int a);//Default constructor with default values.
      Person(Person &);// copy constructor. 
      void printPerson();// function prototype;
  private:
 	int car;
};  

// Person Member funtion definitions
Person::Person(int a)
{ cout <<"In the Person default constructor." << endl;
  car = a;
}
Person::Person(Person &inPersonObject)
{  cout <<"In the Person copy constructor." << endl;
   car = inPersonObject.car;   
}
void Person::printPerson()
{ cout << car << endl;
}

//Job class definition.
class Job
{ public:
       Job(string);   //default constructor with default values.
	 
 private:
   string name;   
};    
//Job member function definitions 
Job::Job(string n)
{ 
	cout <<" In the Job constructor ."<< endl;
  name = n;
  cout <<"Job's name " << name << endl;
  cout <<"Completion Person: " ;
  
}

int main( )
{
	Person startPersonObject(145712);  //LINE4
	Person endPersonObject(98578); //LINE 5
	Job("Programmer"); //LINE 6

  system("pause");
}