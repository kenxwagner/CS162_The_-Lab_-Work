//Lab5KenWagner
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getSales(double *, int);
double totalSales(double *, int);

int main()
{
  const int QUARTERS = 4;
  double sales[QUARTERS];

  // Get the sales data for all quarters.
  getSales(sales, QUARTERS);
  
  // Set the numeric output formatting.
  cout << setprecision(2);
  cout << fixed << showpoint;
  
  // Display the total sales for the year.
  cout << "The total sales for the year are $";
  cout << totalSales(sales, QUARTERS) << endl;
  cin.ignore();
  cin.get();
  return 0;
}

void getSales(double *array, int size)
{
  for (int count = 0; count < size; count++)
  {
    cout << "Enter the sales figure for quarter ";
    cout << (count + 1) << ": ";
    cin >> array[count];
  }
}

double totalSales(double *array, int size)
{
   double sum = 0.0;

   for (int count = 0; count < size; count++)
   {
     sum += *array;
     array++;
   }
   return sum;
}
