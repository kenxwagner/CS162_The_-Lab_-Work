#ifndef H_Test
#define H_Test

template<class T>
class TestArray
{ public:
	TestArray(T *, int);
	void Display();
    ~TestArray();
  private:
	T  *arrayList;
	int size;

};
//Class template member function definitions
template <class T>
TestArray<T>::TestArray(T *inputArray, int insize)
{    if (insize > 0)
            size = insize;
  	 arrayList  = new T[size];
	 for (int i= 0; i < size; i++)
		  arrayList[i] = inputArray[i];
         
}

template <class T>
void TestArray<T>::Display()
{    cout << " The data member arrayList of the object at address " << this << endl;
cout << " contains the following array elements:\n ";
   	 for (int i= 0; i < size; i++)
		cout << arrayList[i] << "  " ;
	 cout <<"\n";
}

template <class T>
TestArray<T>::~TestArray()
{    
  	 delete [] arrayList;
         
}

#endif