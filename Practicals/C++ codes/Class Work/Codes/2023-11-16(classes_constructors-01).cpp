#include <iostream>

using namespace std;

class CPerson
{

private:

	string mName = "";
	int mAge = 0;
	string mAddress = "";

public:

	void SetName(string name);
	void SetAge(int age);
	void SetAddress(string address);
	string GetName();
	int GetAge();
	string GetAddress();
	void PrintDetails();

	CPerson()
	{	
	}

	CPerson(string name, int age, string address)
	{
		mName = name;
		mAge = age;
		mAddress = address;
	}

	CPerson(CPerson& person)
	{
		mName = person.mName;
		mAge = person.mAge;
		mAddress = person.mAddress;
	}

};

int main()
{

	int numberOfPeople = 5;
	CPerson people[numberOfPeople] = {	CPerson("Lakvindu Godamunne", 20, "Gedra ada uda"),
						CPerson("Dinira", 10, "Geyak na"),
						CPerson("Yassit", 8, "Prawn Hub"),
						CPerson("Imeth", 21, "Drug Cartel"),
						CPerson("Kasun", 20, "Homeless")};

	for(int i = 0; i < numberOfPeople; i++)
	{
		people[i].PrintDetails();
		cout << endl;
	}

	return 0;

}

void CPerson::SetName(string name)
{
	mName = name;
}

void CPerson::SetAge(int age)
{
	mAge = age;
}

void CPerson::SetAddress(string address)
{
	mAddress = address;
}

string CPerson::GetName()
{
	return mName;
}

int CPerson::GetAge()
{
	return mAge;
}

string CPerson::GetAddress()
{
	return mAddress;
}

void CPerson::PrintDetails()
{
	cout << "Name: " << mName << endl;
	cout << "Age: " << mAge << endl;
	cout << "Address: " << mAddress << endl; 
}