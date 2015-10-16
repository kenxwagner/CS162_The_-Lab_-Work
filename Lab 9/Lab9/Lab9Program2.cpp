#include <string>
#include <iostream>
using namespace std;

// Template for minimum of an array.
template <class T>
T maximum(T arr[ ], int size)
{ cout << "The original array contains ";
  for (int i=0;i<size;i++)
	   cout << arr[i]<< " " ;
  cout << endl;

  T largest = arr[0];
  for (int k = 1; k < size; k++)
  {
    if (arr[k] > largest)
      largest = arr[k];
  }
  return largest;
}
template <class T>
T minimum(T arr[ ], int size)
{ cout << "The original array contains ";
  for (int i=0;i<size;i++)
	   cout << arr[i]<< " " ;
  cout << endl;

  T smallest = arr[0];
  for (int k = 1; k < size; k++)
  {
    if (arr[k] < smallest)
      smallest = arr[k];
  }
  return smallest;
}
int main()
{
  // The compiler creates int minimum(int [], int)
  // when you pass an array of int.
  int arr1[] = {9, 8, 6, 10, -1};

  cout << "\nThe maximum number is " << maximum(arr1, 5)
       << endl;
 
  
  // The compiler creates string minimum(string [], int)
  // when you pass an array of string.
  string arr2[] = {"Cow", "Cat", "Bird", "Dog", "Elephant"};
  cout << "\nThe largest string is " << maximum(arr2, 5)
       << endl;
  
  cout << "\nThe smallest number is " << minimum(arr1, 5)
       << endl;
  cout << "\nThe smallest string is " << minimum(arr2, 5)
       << endl;


  cin.ignore();
  cin.get();
  return 0;
}