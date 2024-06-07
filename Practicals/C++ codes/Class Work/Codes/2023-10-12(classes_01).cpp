#include <iostream>

using namespace std;

class CPerson
{

private:

	string mName = "0";
	unsigned int mAge = 0;
	string mNIC = "0";

public:

	void SetName(string name);
	void SetAge(unsigned int age);
	void SetNIC(string NIC);
	string GetName();
	int GetAge();
	string GetNIC();

	CPerson(string name, unsigned int age, string NIC)
	{
		mName = name;
		mAge = age;
		mNIC = NIC;
	}

};

int main()
{

	CPerson* guy = new CPerson("Kasun Dodanwala", 20, "200323511253");

	cout << "Name: " << guy->GetName() << "\n\n";
	cout << "Age: " << guy->GetAge() << "\n\n";
	cout << "NIC: " << guy->GetNIC() << "\n\n";

	delete guy;

	return 0;
}

void CPerson::SetName(string name)
{
	mName = name;
}

void CPerson::SetAge(unsigned int age)
{
	mAge = age;
}

void CPerson::SetNIC(string NIC)
{
	mNIC = NIC;
}

string CPerson::GetName()
{
	return mName;
}

int CPerson::GetAge()
{
	return mAge;
}

string CPerson::GetNIC()
{
	return mNIC;
}