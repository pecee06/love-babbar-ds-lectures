#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
class Student
{
private:
	string fname;
	string lname;
	string DOB;
	char sex;
	string stream;
public:
	Student();	// Default constructor
	Student(string,string,char);	// Parameterized constructor
	Student(Student&);	// Copy constructor

	string getName();
	void setDOB(string);
	void setStream(string);
	string getDOB();
	string getStream();

	~Student();
};

Student::Student(){}
Student::Student(string fname, string lname, char sex){
	this->fname = fname;
	this->lname = lname;
	this->sex = sex;
}
Student::Student(Student& s){
	this->fname = s.fname;
	this->lname = s.lname;
	this->sex = s.sex;
}

string Student::getName(){
	return this->fname+' '+this->lname;
}
void Student::setDOB(string date){
	this->DOB = date;
}
void Student::setStream(string stream){
	this->stream = stream;
}
string Student::getDOB(){
	return this->DOB;
}
string Student::getStream(){
	return this->stream;
}

Student::~Student(){
	cout<<"Object destroyed\n";
}
*/

class AccHolder;
class Bank
{
	static int banks;

	string branch;
	string address;
	string managerName;
public:
	Bank(string branch, string managerName){
		this->branch = branch;
		this->managerName = managerName;
		Bank::banks++;
	}

	void setAddress(string address){
		this->address = address;
	}
	bool isClient(AccHolder&);

	static int getNoOfBanks(){
		return Bank::banks;
	}
};

int Bank::banks = 0;	// Initialization of static variable

class AccHolder
{
	string name;
	string branch;
	string accNo;	// 11 digits
	string ifsc;	// 4 letter bank abbreviation followed by 7 digits
	float balance;
	const int minBalance;
public:
	AccHolder(string accNo, string ifsc):minBalance(1000){
		this->accNo = accNo;
		this->ifsc = ifsc;
	}
	AccHolder(string name, string accNo, string ifsc):minBalance(1000){
		this->name = name;
		this->accNo = accNo;
		this->ifsc = ifsc;
	}

	void setBranch(string branch){
		this->branch = branch;
	}
	void setBalance(float balance){
		this->balance = balance;
	}
	void deposit(float amount){
		this->balance += amount;
		cout<<amount<<" rupees successfully credited into your account\n";
	}
	void withdraw(float amount){
		if ((this->balance - amount) >= minBalance){
			this->balance -= amount;
			cout<<amount<<" rupees debited from your account\n";
		}
		else{
			cout<<"You don't have sufficient balance in your account to perform this transaction\n";
		}
	}
	float getBalance(){
		return this->balance;
	}

	friend bool Bank::isClient(AccHolder&);
};

bool Bank::isClient(AccHolder& obj){
	if (obj.branch == this->branch){
		return true;
	}
	return false;
}

class Account
{
protected:
	string name;
	string accNo;
	float balance;
public:
	// Setters
	void setName(string name){
		this->name = name;
	}
	void setAccNo(string accNo){
		this->accNo = accNo;
	}
	void setOBalance(float amount){
		this->balance = amount;
	}

	// Getters
	string getName(){
		return this->name;
	}
	string getAccNo(){
		return this->accNo;
	}
	float getBalance(){
		return this->balance;
	}

	// Operations
	void deposit(float amount){
		this->balance += amount;
		cout<<amount<<" rupees successfully credited into your account\n";
	}

	void details(){
		cout<<"Account Holder -> "<<this->name<<endl;
		cout<<"Balance -> "<<this->balance<<" Rs\n";
	}
};

class Savings:public Account
{
	const float interestRate;
public:
	Savings():interestRate(5.5){}

	void withdraw(float amount){
		if (this->balance - amount > 0){
			this->balance -= amount;
			cout<<amount<<" Rs debited from your account\n";
		}
		else{
			cout<<"You don't have sufficient balance for this transaction to happen\n";
		}
	}

	float calcInterest(int t){
		return this->balance*pow((1 + this->interestRate),t);
	}

	// @Override
	void details(){
		cout<<"Account Holder -> "<<this->name<<endl;
		cout<<"Balance -> "<<this->balance<<" Rs\n";
		cout<<"CRI -> "<<this->interestRate<<" %\n";
	}
};

class Current:public Account
{
	const float minBalance;
	float serviceCharge;
public:
	Current():minBalance(1000){
		this->serviceCharge = 0;
	}

	void allotChequeBook(){
		cout<<"Chequebook alloted\n";
	}

	void withdraw(float amount){
		if (this->balance - amount > 0){
			this->balance -= amount;
			cout<<amount<<" Rs debited from your account\n";
			if (this->balance < this->minBalance){
				this->serviceCharge += 200;
				cout<<"You've been fined 200 Rs as your account balance is below the minimum limit for your account\n";
			}
		}
		else{
			cout<<"You don't have sufficient balance for this transaction to happen\n";
		}
	}

	// @Override
	void details(){
		cout<<"Account Holder -> "<<this->name<<endl;
		cout<<"Balance -> "<<this->balance<<" Rs\n";
		cout<<"Minimum Balance -> "<<this->minBalance<<" Rs\n";
		cout<<"Fine -> "<<this->serviceCharge<<" Rs\n";
	}
};

int main()
{
	// Student* s1 = new Student("Priyanshu","Choudhury",'M');
	// cout<<s1->getName()<<endl;
	// delete s1;

	// Student s2("Om","Nigam",'M');
	// s2.setStream("CSE");
	// cout<<s2.getStream()<<endl;

	// Student s3;

	// Student s4(s2);
	// cout<<s4.getName()<<endl;

	// AccHolder obj("Nimish","76521447023","SBIN4566388");
	// obj.setBranch("sbi_mdgr");

	// Bank b1("sbi_mdgr","Rakesh Pandey");
	// Bank b2("hdfc_apr","Alfaaz Ahmed");

	// cout<<b1.isClient(obj)<<endl;
	// cout<<b2.isClient(obj)<<endl;

	// obj.setBalance(2500);
	// obj.withdraw(500);
	// obj.deposit(750);
	// obj.withdraw(2000);
	// cout<<obj.getBalance()<<endl;

	// cout<<Bank::getNoOfBanks()<<endl;

	// Bank* b3 = new Bank("cbi_mdgr","Raveena Kumari");
	// cout<<Bank::getNoOfBanks()<<endl;
	// delete b3;

	Savings acc1;
	Current acc2;

	return 0;
}