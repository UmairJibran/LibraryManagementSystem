#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
bool Flag = 0 , FLAG = 0;

class Books
{
	protected:
		~Books();
		void BookIssue();
		void BookReturn();
		void BookRenew();
		void GetBook();
		int bid,BID1;
		void BooKs(int);
		char BookID[5];
		char BookName[100],BookArthor[100];
		void DisplayBook();
	private:
		void Search(int);
		int STID;
		char StID[10],StName[100],StDept[100],BID[10];
		void PrintRec();
		
};
class Menu:protected Books{
	public:
		void Security();
	protected:
		void Validate();
		void AdminMenu();
		void Selector();
	private:
		int ID,AOp,PIN;
		char pin[10];
		void AdminControls();
};



void Menu::Security(){
	cout << endl << endl << endl;
	cout << "Please Enter your ID  : ";
	cin >> ID;
	cout << "Please Enter your Pin : ";
	int count=0;
	char temp;
	while(true){
		temp=getch();
		if(temp >= '0' && temp <= '9'){
			pin[count] = temp;
			count ++;
			cout << char(249);
		}
		if(temp == '\b' && count >= 1){
			cout << "\b \b";
			count--;
		}
		if(temp == '\r'){
		break;
		}
	}
	PIN = atoi(pin);
	Validate();
}
void Menu::Validate(){
	bool flag=0;
	switch (ID){
		case 8510:{
			if( PIN == 123456)
			flag=1;
			else
			flag=0;
			break;
		}
		default:{
			cout << endl << "ID Not Found or ";
		}
	}
	if (flag){
		cout << endl << setw(40) << "Access Granted";
		getch();
		AdminMenu();
	}
	else{
		system("color E4");
		cout << endl << "Password is Incorrect";
		getch();
		system("color F0");
		Security();
	}
}

void Menu::AdminMenu(){
	system ("cls");
	cout << setw(50) << "Welcome To Admin Menu";
	cout << endl << endl << setw(20) << "Select Any Option from the Menu";
	cout << endl << "1. Book Issue";
	cout << endl << "2. Book Renew";
	cout << endl << "3. Book Return";
	cout << endl << "4. Admin Controls";
	cout << endl << "9. Log Out"; 
	cout << endl << "0. Exit";
	cout << endl;
	
	cin >> AOp;
	
	if (AOp == 9){
		system ("cls");
		cout << setw(50) << "Welcome To Students Library" << endl
			 << setw(56) << "Session Expired Please Log in again";
		Security();
	}
	else if(AOp ==0 ){
		system("cls");
		cout << endl << endl << endl << setw(60) << "Good Bye" << endl
			 << setw(67) << " Thanks for Stopping by.";
		getch();
		exit(0);
	}
	else
		Selector();
}
void Menu::Selector(){
	switch (AOp){
		case 1:{
			system ( "cls" );
			cout << setw(50) << "BOOK ISSUE MENU";
			BookIssue();
			break;
		}
		case 2:{
			system ( "cls" );
			cout << setw(50) << "BOOK RENEW MENU";
			BookRenew();
			break;
		}
		case 3:{
			system ( "cls" );
			cout << setw(50) << "BOOK RETURN MENU";
			BookReturn();
			break;
		}
		case 4:{
			system ( "cls" );
			cout << setw(50) << "ADMIN CONTROLS";
			AdminControls();
			break;
		}
		default:{
			system ("cls");
			cerr << setw(50) << "Your Entry is invalid";
			getch();
			AdminMenu();
		}
	}
}
void Menu::AdminControls(){
	ifstream Book("Books.txt");
	cout << "Please Enter" << endl
		 << "1. to Add Student" << endl
		 << "2. to Add Book" << endl
		 << "Any Other Key to Exit" << endl;
	int OP;
	cin >> OP;
	switch( OP ){
		case 1:{
				int SIDa,SIDc;
				char StNamea[100],StDepta[100],Temp[5];
				char IDa[50];
				system ("cls");
				ReTryS:
				ifstream Student("Students.txt");
			if (Student.is_open()){
				bool FLAG1 = 0;
				cout << "Enter your Student ID To Get Added to DataBase: ";
				cin >> SIDa;
				while(Student >> IDa >> StNamea >> StDepta >> Temp){
					SIDc = atoi(IDa);
					if (SIDa == SIDc){
						FLAG1 = 1;
						break;
					}
					else
					FLAG1 = 0;
				}
				if( FLAG1 == 1){
					Student.close();
					cout << "Please Enter Your ID, this ID already exists" << endl;
					goto ReTryS;
				}
				else{
				cin.ignore();
				cout << endl << "Enter Your Name: ";
				cin.getline(StNamea,100);
				for(int i=0 ; i < 100 ; i++){
					if ( StNamea[i] ==  ' ')
						StNamea[i] = '_';
				}
				cout << endl << "Enter Your Department: ";
				cin >> StDepta;
				for(int i=0 ; i < 100 ; i++){
					if ( StDepta[i] == ' ')
						StDepta[i] = '_';
				}
				ofstream StA("Students.txt",ios::app);
				if(StA.is_open()){
					StA << '\n' << SIDa << char(0) << StNamea << char(0) << StDepta << char(0) << '0';
					StA.close();
				}
				else{
				cout << "Failed To Open" << endl
					 << "Program will now close.";
				getch();
				exit(0); 
				}
				Student.close();
				cout << setw(50) << "Student Added!";
				getch();
			}
		}
			else{
			cerr << "Fail to Open File."
				 << "We are going to Exit the Program";
			getch();
			exit(0);
			}
			break;
	}	
		case 2:{
			if (Book.is_open()){
				int BIDa,BIDc;
				char BNamea[100],BAra[100];
				char IDa[50];
				ReTryB:
				cout << "Enter a BOOK ID To Get Added to DataBase: ";
				cin >> BIDa;
				while(Book >> IDa >> BNamea >> BAra){
					BIDc = atoi(IDa);
					if (BIDa == BIDc){
						cout << "This Book ID Already Exists Please Enter Unique Book ID" << endl;
						goto ReTryB;
					}
				}
				cin.ignore();
				cout << endl << "Enter Book Name: ";
				cin.getline(BNamea,100);
				for(int i=0 ; i < 100 ; i++){
					if ( BNamea[i] ==  ' ')
						BNamea[i] = '_';
				}
				cout << endl << "Enter Book Arthor: ";
				cin >> BAra;
				for(int i=0 ; i < 100 ; i++){
					if ( BAra[i] == ' ')
						BAra[i] = '_';
					}
				ofstream StA("Books.txt",ios::app);
				if(StA.is_open()){
					StA << '\n' << BIDa << char(0) << BNamea << char(0) << BAra;
					StA.close();
				}
				else{
				cout << "Failed To Open" << endl
					 << "Program will now close.";
				getch();
				exit(0); 
				}
				Book.close();
				cout << setw(50) << "Book Added!";
				getch();
			}
			else{
			cerr << "Fail to Open File."
				 << "We are going to Exit the Program";
			getch();
			exit(0);
			}
			break;
		}
		default:{
			exit(0);
			break;
		}
	}
	AdminMenu();
}
void Books::BookIssue(){
	int SID;
	cout << endl << "Enter Your Student ID: ";
	cin >> SID;
	Search(SID);
	if(BID1>0){
		cout << endl << "Please Return this Book First ";
		cout << endl;
	}
	else{
		getch();
		GetBook();
		cout << "Do you want to lend this book(y/n): ";
		char yn;
		Again:
		cin >> yn;
		if(yn == 'y' || yn == 'Y'){
			cout << "You hace succesfully lend " << BookName << 
				  endl << "Please Return it within 20 Days" << endl << endl << endl;
		}
		else if(yn == 'N' || yn == 'n'){
			goto SET;
		}
		else{
			cout << "Your Entry is invalid Please Enter Y for Yes or N for No: ";
			goto Again;
		}
	}
	SET:
	REDO:
	cout << endl << endl << "Enter 0. to Exit or" << endl;
	cout << "Press 1. for Book Issue Menu" << endl
		 << "Press 2. for Book ReNew" << endl
		 << "Press 3. for Book Return" << endl;
	int _;
	cin >> _;
	if( _ == 0){
		system("cls");
		cout << endl << endl << endl << setw(50) << "Good Bye" << endl
			 << setw(57) << " Thanks for Stopping by.";
		getch();
		exit(0);
	}
	else{
		switch(_){
			case 1:{
				system("cls");
				cout << setw(50) << "BOOK ISSUE MENU";
				BookIssue();
				break;
			}
			case 2:{
				system("cls");
				cout << setw(50) << "BOOK RENEW MENU";
				BookRenew();
				break;
			}
			case 3:{
				system("cls");
				cout << setw(50) << "BOOK RETURN MENU";
				BookReturn();
				break;
			}
			default:{
				cout << "INVALID PARAMETERS";
				goto REDO;
				getch();
				system("cls");
				break;
			}
		}
	}
}
void Books::BooKs(int a){
	bool flag = 0;
	ReOpen:
	ifstream MyBook( "Books.txt" );
	if(MyBook.is_open()){
		while(MyBook >> BookID >> BookName >> BookArthor){
			flag = 0;
			for(int i = 0 ; i < 101 ; i++){
				if(BookName[i] == '_')
					BookName[i] = ' ';
				if(BookArthor[i] == '_')
					BookArthor[i] = ' ';
			}
			bid = atoi(BookID);
			if(a == bid){
				flag = 1;
				MyBook.close();
				break;
			}
		}
		MyBook.close();
	}
	else{
		cerr << "Error Opening File!" << endl;
		cout << "Enter 0 to exit or 1 to try again." << endl;
		int to;
		cin >> to;
		if(to == 1)
		goto ReOpen;
		else
		exit(0);
	}
	if(flag == 1){
		DisplayBook();
	}
	else if(flag == 0){
		 if(FLAG == 1){
			cout << "Book Not Found " << endl
				 << "Please Enter Correct Book ID Again: ";
			int temp;
			cin >> temp;
			BooKs(temp);
		}
	}
}
void Books::Search(int ID){
	Start:
	bool flag=0;
	ifstream MyFile("Students.txt");
	if(MyFile.is_open()){
		while(MyFile >> StID >> StName >> StDept >> BID){
			Flag = 0;
			for(int i = 0 ; i < 101 ; i++){
			if(StName[i] == '_')
				StName[i] = ' ';
			if(StDept[i] == '_')
				StDept[i] = ' ';
			}
			STID = atoi(StID);
			BID1 = atoi(BID);
			if(STID == ID){
				flag = 1;
				break;
			}
		}
		MyFile.close();
	}
	else
	cerr << "Error Opening file!";
	if(flag == 1)
	PrintRec();
	else{
		cout << "Entry Not Found Press Enter to Search again" << endl;
		getch();
		system("cls");
		cout << "Re-Enter Your Student ID: ";
		cin >> ID;
		goto Start;
		
	}
}
void Books::PrintRec(){
	system("cls");
	cout << "Student ID is: ";
	cout << STID << endl ;
	cout << "Student Name is: ";
	cout << StName << endl;
	cout << "Student Dept : ";
	cout << StDept << endl;
	cout << "You have Lend: ";
	if(BID1>0){
		Flag = 1;
		BooKs(BID1);
	}
				
	else
	cout << "Nothing" << endl;
	
}
void Books::DisplayBook(){
	cout << endl;
	cout << "  Book ID: ";
	cout << BookID << endl;
	cout << "  Book Name: ";
	cout << BookName << endl;
	cout << "  Book Arthor: ";
	cout << BookArthor << endl;
}
void Books::BookRenew(){
	int ID;
	cout << endl << "Enter Your ID: ";
	cin >> ID;
	Search(ID);
	if(Flag == 1){
	cout << endl << "How Many Days you want to add to your Return Date? ";
	int Days;
	cin >> Days;
	cout << Days << " Days have been Added to your Return date." << endl;
	}
	else
	cout << "You haven't Lend any Book :)." << endl;
	REDO:
	cout << endl << "Enter 0. to Exit or" << endl;
	cout << "Press 1. for Book Issue Menu" << endl
		 << "Press 2. for Book ReNew" << endl
		 << "Press 3. for Book Return" << endl;
	int _;
	cin >> _;
	if( _ == 0){
		system("cls");
		cout << endl << endl << endl << setw(50) << "Good Bye" << endl
			 << setw(57) << " Thanks for Stopping by.";
		getch();
		exit(0);
	}
	else{
		switch(_){
			case 1:{
				system("cls");
				cout << setw(50) << "BOOK ISSUE MENU";
				BookIssue();
				break;
			}
			case 2:{
				system("cls");
				cout << setw(50) << "BOOK RENEW MENU";
				BookRenew();
				break;
			}
			case 3:{
				system("cls");
				cout << setw(50) << "BOOK RETURN MENU";
				BookReturn();
				break;
			}
			default:{
				cout << "INVALID PARAMETERS";
				goto REDO;
				getch();
				system("cls");
				break;
			}
		}
	}
}
void Books::BookReturn(){
	int ID;
	cout << endl << "Enter Your ID: ";
	cin >> ID;
	Search(ID);
	if(Flag == 1){
		cout << "Do you want to Return?(y/n) ";
		char yn;
		ReTry:
		cin >> yn;
		if(yn == 'y' || yn == 'Y'){
			cout << "THANK YOU FOR RETURNING OUR BOOK" << endl;
		}
		else if(yn == 'n' || yn == 'N'){
			cout << "Please Return The Book on Time." << endl;
			goto REDO; 
		}
		else{
			cout << "Please Enter a Valid Input(y/n): ";
			goto ReTry;
		}
	}
	else
	cout << "You haven't Lend any Book :)." << endl;
	REDO:
	cout << endl 
		 << "Enter 0. to Exit or" << endl;
	cout << "Press 1. for Book Issue Menu" << endl
		 << "Press 2. for Book ReNew" << endl
		 << "Press 3. for Book Return" << endl;
	int _;
	cin >> _;
	if( _ == 0){
		system("cls");
		cout << endl << endl << endl << setw(50) << "Good Bye" << endl
			 << setw(57) << " Thanks for Stopping by.";
		getch();
		exit(0);
	}
	else{
		switch(_){
			case 1:{
				system("cls");
				cout << setw(50) << "BOOK ISSUE MENU";
				BookIssue();
				break;
			}
			case 2:{
				system("cls");
				cout << setw(50) << "BOOK RENEW MENU";
				BookRenew();
				break;
			}
			case 3:{
				system("cls");
				cout << setw(50) << "BOOK RETURN MENU";
				BookReturn();
				break;
			}
			default:{
				cout << "INVALID PARAMETERS";
				goto REDO;
				getch();
				system("cls");
				break;
			}
		}
	}
}
void Books::GetBook(){
	FLAG = 1;
	cout << setw(50) << "BOOK SEARCH" ;
	cout << endl << "Enter Unique Book ID: ";
	int A;
	cin >> A;
	BooKs(A);
	FLAG = 0; 
}
Books::~Books(){
	cout << endl <<"Good Bye!";
}

int main(){
	system("color F0");
	cout << setw(50) << "Welcome To Students Library";
	
	Menu Library;
	Library.Security();
	getch();
	return 0;
}

