
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string name, pass, email, contact, DOB, fname, lname;
void registration();
void login();
void logon(string,string);
int main();
void flighttime();
void price();

void registration(){
	char continu;
	cout<<"********Registration Page*********"<<endl;
	fstream reg;
	reg.open("database.txt", ios::app);
	if (!reg)
	cout<<"File not found";
	else{
		cout<<"Enter User Name (No Spaces Allowed): "<<endl;
		cin>>name;
		cout<<"Enter First Name: "<<endl;
		cin>>fname;
		cout<<"Enter Last Name: "<<endl;
		cin>>lname;
		cout<<"Enter Date of Bith (e.g 27-05-2002): "<<endl;
		cin>>DOB;
		cout<<"Enter Email: "<<endl;
		cin>>email;
		cout<<"Enter Contact No: "<<endl;
		cin>>contact;
		cout<<"Enter the Passsword (No Spaces Allowed): "<<endl;
		cin>>pass;
		system("cls");
		cout<<"Registration Succesfull\n"<<endl;
		reg<<name<<" "<<pass<<" "<<fname<<" "<<lname<<" "<<DOB<<" "<<email<<" "<<contact<<endl;
		reg.close();
	}
	cin.ignore(100,'\n');
	cout<<"Press Enter To Continue";
	cin.get(continu);
}


void login(){
	system("cls");
	char continu;
	cout<<"******Login Page*******"<<endl;
	string name1,pass1;
	fstream log;
	int count=0;
	log.open("database.txt", ios::in);
	if (!log)
	cout<<"File not found!!";
	else{
		cout<<"Enter Your Username(No spaces allowed): "<<endl;
		cin>>name1;
		cout<<"Enter Your Password(No spaces allowed): "<<endl;
		cin>>pass1;
		system("cls");
		log>>name>>pass>>fname>>lname>>DOB>>email>>contact;
		while(!log.eof()){
		if (name1==name && pass1==pass){
			cout<<"Login Successfull\n"<<endl;
			count++;
			break;
		}
		else
		log>>name>>pass>>DOB>>email>>contact;	
		}
	}
		log.close();
		if (count==0){
			cout<<"Login Unsuccessfull!!\n";
			cin.ignore(100,'\n');
			cout<<"Press Enter To Continue";
			cin.get(continu);
		}
		else if (count==1){
			cin.ignore(100,'\n');
	        cout<<"Press Enter To Continue";
	        cin.get(continu);
			logon(fname,lname);
		}
}


void logon(string fname,string lname){
	system("cls");
	char dec1,continu;
	while(dec1!='4'){
	cout<<"******Welcome "<<fname<<" "<<lname<<"*******"<<endl;
	cout<<" 1.Buy A New Ticket\n 2.Cancel Your Ticket\n 3.Back Menu\n "; 
	cin>>dec1;
	system("cls");
	if(dec1=='1')
		cout<<"Ticket Purchased Successfully\n\n";
	else if(dec1=='2')
		cout<<"Your Ticket has been cancelled\n\n";
	else if(dec1=='3')
		main();
	cin.ignore(100,'\n');
	cout<<"Press Enter To Continue";
	cin.get(continu);
	system("cls");
	}
}


void flighttime(){
	system("cls");
	string line;
	int count=0;
	char continu;
	fstream flight;
	flight.open("flights.txt", ios::in);
	if(!flight)
	cout<<"File not Found";
	else{
		cout<<"************ Flight Timings **************"<<endl;
		while(!flight.eof()){
			getline(flight,line);
			cout<<line<<endl;
		}
	}
	cin.ignore(100,'\n');
	cout<<"\nPress Enter To Continue";
	cin.get(continu);
	flight.close();
}


void price(){
	system("cls");
	char continu;
	cout<<"********** Flight Prices ************"<<endl;
	cout<<"Economy.......60000 Rupees"<<endl;
	cout<<"Buisness......100000 Rupees"<<endl;
	cout<<"VIP...........140000 Rupees"<<endl;
	cout<<"Private Jet........1000000 Rupees"<<endl<<endl;
	cin.ignore(100,'\n');
	cout<<"Press Enter To Continue";
	cin.get(continu);
}

int main(){
	system("cls");
	char dec;
	while (dec!='5'){
		system("cls");
		cout<<"Enter the what you want to do: \n1.Register \n2.Login \n3.Flight Timings \n4.Flight Prices \n5.Exit \n";
		cin>>dec;
		if(dec=='1'){
		system("cls");
		registration();}
		else if (dec=='2'){
		system("cls");
		login();}
		else if (dec=='3'){
		system("cls");
		flighttime();}
		else if (dec=='4'){
		system("cls");
		price();}
		else if (dec=='5'){
		system("cls");
		cout<<"Program Closed";
		return 0;
		}
	}
	return 0;	
}
