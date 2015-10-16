//This program uses the write and read functions.
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
void UpdateARecord(fstream &); // function prototype
void Menu();

int main()
{
   // File object used to access file.
  	fstream file;
	int choice;
	Menu();     
	cout<<"Enter a choice"<<endl;
	cin >> choice;
	while (choice >= 1 && choice <= 5)
	{   switch (choice)
		{   case 1:
				CreateABinaryFile(file);
				//int RecSize = sizeof(StudentInfo);
				//cout << "The size of one student record is " <<  RecSize << endl;
				break;
			case 2:

				WriteRecordsToFile(file);
				cout <<"Done writing info.\n";
				break;
			case 3:
				ReadABinaryFile(file);
				break;
			case 4:
				RetrieveARecordfromFile(file);
				break;
			case 5:
				UpdateARecord(file);
			default:
				cout<<"Bye\n";
		}  // end switch
    
	   // system("cls");
		Menu();

		cout<<"Enter a choice"<<endl;
		cin >> choice;
   } // end while

	cin.ignore();
	cin.get();
	return 0;
}

//Function definitions
void Menu()
{
  cout <<"1\tCreate a binary file. "  <<endl;
  cout<<"2\tWrite information to file. " <<endl;
  cout <<"3\tRead information from file." << endl;
  cout <<"4\tRetrieve a record from file." << endl;
  cout <<"5\tUpdate a record." << endl;

  cout <<"6\tExit"<<endl;
}

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
{   binfile.clear();   // needed this if the file has been opened and closed more than once
                         // before this function is called.
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
	 cout <<"What record do you want to retrieve /Enter 1,... etc? " << endl;
	 cin>>recnum;
	 binfile.seekg( (recnum-1) * sizeof(record), ios::beg);
     binfile.read(reinterpret_cast<char *>(&record), 
	               sizeof(record)); 
	
	 cout <<"Student of record # " << recnum <<" contains " << endl;
	 cout << record.fname << " " << record.lname << "  " << record.sid << endl;
	}

	binfile.close();
}

void UpdateARecord(fstream &binfile)
{
    binfile.clear();   // needed this if the file has been opened and closed more than once
                         // before this function is called.
	binfile.open("students.dat", ios::out | ios::in | ios::binary);
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
	 cout <<"What record do you want to update /Enter 1,... etc? " << endl;
	 cin>>recnum;
     binfile.seekg( (recnum-1) * sizeof(record), ios::beg);
     binfile.read(reinterpret_cast<char *>(&record), 
	               sizeof(record)); 
	 cout<<"The following record is found and to be updated .\n";
	 cout <<"Student of record # " << recnum <<" contains " << endl;
	 cout << record.fname << " " << record.lname << "  " << record.sid << endl;
        cin.ignore();
        cout <<"Enter a student's new first name ";
	    cin.getline(record.fname, NAMESIZE);
        cout <<"Enter a student's new last name ";
	    cin.getline(record.lname, NAMESIZE);
	    cout <<"Enter a student's new SID ";
	    cin.getline(record.sid, SIDSIZE);

	 binfile.seekp( (recnum-1) * sizeof(record), ios::beg);

     binfile.write(reinterpret_cast<char *>(&record), 
	               sizeof(record)); 
		 
	}

	binfile.close();

}