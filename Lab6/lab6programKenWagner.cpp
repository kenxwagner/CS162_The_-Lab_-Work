// Lab6Program
// Ken Wagner

#include <iostream>
using namespace std;

class Fractionclass
{     friend istream &operator >> (istream &,Fractionclass & );  // function prototype
	
    public:
		Fractionclass();  // default construtor
        Fractionclass operator + (Fractionclass );  // function prototype.
		bool operator < (Fractionclass); // function prototype.
	private:
       int numerator;
	   int demominator;

};
Fractionclass::Fractionclass()
{
	numerator = 0;
	demominator = 0;
}

 istream &operator >> (istream &input ,Fractionclass &object)
{cout << "In the operator >> function " << endl;
  input >> object.numerator;
  input >> object.demominator;
  return input;
}

 Fractionclass Fractionclass::operator +(Fractionclass rightobject  )
 {   cout << "Right object passed/ its numerator is " << rightobject.numerator << endl;
     cout << "Right object passed/ its denominator is " << rightobject.demominator << endl;

	 Fractionclass tempobject;
     tempobject.numerator = ((this->numerator * rightobject.demominator) + 
		                  (this->demominator*rightobject.numerator));
	 tempobject.demominator = (this->demominator*rightobject.demominator);

	 cout << tempobject.numerator <<"/" << tempobject.demominator << endl;
	return tempobject;
 }

 bool Fractionclass::operator <(Fractionclass rightobject  )
 {  cout <<"In the operator <  member function "<< endl;
    if ( this->numerator == rightobject.numerator && this->demominator == rightobject.demominator)
          return  true;
	else
		  return false;
 }
int main()
{ 
  Fractionclass fraction1, fraction2,fraction3, fraction4;
  cout << "Enter a numerator and a demominator for fraction1 : " << endl;
  cin >> fraction1;
  cout << "Enter a numerator and a demominator for fraction2 : " << endl;
  cin >> fraction2;
  // cout << fraction1;   //To be able to do this, you need to overload the insertion << operator.
                          //Hints: The function is similar to operator >> friend function.  
                          //Use the ostream instead the istream. Use the <<  instead of >> 
                         //in the function body.The function should display the fraction in
                         //numerator / demomonator  format.  For example if fraction1 contains 
                         // 2 as its numerator and 3 as its demominator, then the output is 2/3.  
 //cout << fraction2;  
  fraction3 = fraction1 + fraction2;
  //cout << fraction3;   // If fraction1 contains 2/3 and fraction2 contains 1/5 then 
                         // fraction3 contains 13/15.

  //fraction4 = fraction1 - fraction2;
  //cout << fraction4;

  if (fraction1 < fraction2)
      cout << "Fraction1 is less than fraction2." << endl;
  else
       cout << "Fraction1 is not less than fraction2." << endl;


  cin.ignore();
  cin.get();

}