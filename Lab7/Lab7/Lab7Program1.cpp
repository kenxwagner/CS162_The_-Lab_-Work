//This program creates a binary file, writes records to the file,
//retrive a record from the file, and read all records from the the file.
#include <iostream>
#include <fstream>
using namespace std; 

const int NAMESIZE = 25;
const int SIDSIZE = 11;

struct StudentInfo
{	char fname[NAMESIZE];
	char lname[NAMESIZE];
	char sid[SIDSIZE];
};

void CreateABinaryFile(fstream & );  // function prototype
void WriteRecordsToFile(fstream &);  // function prototype
void RetrieveARecordfromFile(fstream &); // function prototype
void ReadABinaryFile(fstream &);  // function prototype

int main()
{
   // File object used to access file.
  	fstream file;
	CreateABinaryFile(file);
	int RecSize = sizeof(StudentInfo);
    cout << "The size of one student record is " <<  RecSize << endl;
    WriteRecordsToFile(file);
	cout <<"Done writing info.\n";
	ReadABinaryFile(file);
	RetrieveARecordfromFile(file);
	cin.ignore();
	cin.get();
	return 0;
}

//Function definitions
void CreateABinaryFile(fstream &binfile )
{
	binfile.open("students.dat", ios::out | ios::binary);
	if (!binfile)
	{
	  cout << "Error opening file.";
	  cin.ignore();
	  cin.get();
	  exit(1);
	}

	binfile.close();

}  // ends CreateABinaryFile

void WriteRecordsToFile(fstream &binfile)
{
   binfile.open("students.dat", ios::out | ios::binary);
	if (!binfile)
	{
	  cout << "Error opening file.";
	  cin.ignore();
	  cin.get();
	  exit(1);
	}
	else
	{ StudentInfo record;
	  char answer = 'Y';
	  
      do
	  { cout <<"Enter a student's first name ";
	    cin.getline(record.fname, NAMESIZE);
        cout <<"Enter a student's last name ";
	    cin.getline(record.lname, NAMESIZE);
	    cout <<"Enter a student's SID ";
	    cin.getline(record.sid, SIDSIZE);
					
        binfile.write(reinterpret_cast<char *>(&record),sizeof(record));
        
		cout << "Do you want to enter another record? ";
		cin >> answer;
		cin.ignore();

	  } while ( answer == 'y' || answer == 'Y');
	}

	binfile.close();
}// ends WriteRecordsToFile

void ReadABinaryFile(fstream &binfile)
{
    binfile.open("students.dat", ios::in | ios::binary);
	if (!binfile)
	{
	  cout << "Error opening file.";
	  cin.ignore();
	  cin.get();
	  exit(1);
	}
	else
	{StudentInfo record;
	 binfile.read(reinterpret_cast<char *>(&record),sizeof(record) );
	 while (! binfile.eof())
	 {  cout << record.fname <<"  " << record.lname <<" "<< record.sid << endl;
	    cout << "\nStrike any key to see the next record.\n";
		cin.get();
	    binfile.read(reinterpret_cast<char *>(&record),sizeof(record) );
	  
	 }  //ends while

	}
	binfile.close();
} // ends ReadABinaryFile

void RetrieveARecordfromFile(fstream &binfile)
{   binfile.clear();   //need this statement if the file has been opened and closed 
                      //more than once before this function is called.
	binfile.open("students.dat", ios::in | ios::binary);
	if (!binfile)
	{
	  cout << "Error opening file.";
	  cin.ignore();
	  cin.get();
	  exit(1);
	}
	else
	{StudentInfo record;
	 int recnum = 0;
	 cout <<"What record do you want to retrieve? " << endl;
	 cin>>recnum;
	 binfile.seekg(recnum * sizeof(record), ios::beg);
     binfile.read(reinterpret_cast<char *>(&record), 
	               sizeof(record)); 
	
	 cout <<"Student of record # " << recnum <<" contains " << endl;
	 cout << record.fname << " " << record.lname << "  " << record.sid << endl;
	}

	binfile.close();
}