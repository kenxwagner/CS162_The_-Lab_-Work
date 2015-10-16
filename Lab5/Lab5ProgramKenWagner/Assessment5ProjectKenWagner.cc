// This program totals and averages the sales figures for
// any number of days. The figures are stored in a 
// dynamically allocated array.
#include <iostream>
#include <iomanip>
using namespace std;

class MyClass {
private:
	int a;
public:
	int b;
};

int main()
{
	int a=1, b=1, c;
	c = a+b;
	double *sales,       // To dynamically allocate an array
	       totalSales = 0.0,  // Accumulator
			 average;      // To hold average sales
	int numDays,         // To hold number of days of sales
       count;           // Counter variable

   // Get number of days of sales.
	cout << "How many days of sales figures do you wish ";
	cout << "to process? ";
	cin >> numDays;
	
	// Dynamically allocate an array large enough
	// to hold that many days of sales amounts.
	sales = new double[numDays];  // Allocate memory

	// Get the sales figures for each day.
	cout << "Enter the sales figures below.\n";
	for (count = 0; count < numDays; count++)
	{
		cout << "Day " << (count + 1) << ": ";
		cin >> sales[count];
	}
	
	// Calculate the total sales.
	for (count = 0; count < numDays; count++)
	{
		totalSales += sales[count];
	}

	// Calculate the average sales per day.
	average = totalSales / numDays;

	// Display the results.
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n\nTotal Sales: $" << totalSales << endl;
	cout << "Average Sales: $" << average << endl;

	// Free dynamically allocated memory.

	delete [] sales;
	sales = 0;

        cin.ignore();
        cin.get();
	return 0;
}