#include <iostream>

using namespace std;

class CUser
{

private:

	string mFirstName = "";
	string mLastName = "";
	unsigned int mAge = 0;
	string mAddress = "";


public:

	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetAge(unsigned int age);
	void SetAddress(string address);
	string GetFirstName();
	string GetLastName();
	int GetAge();
	string GetAddress();

	friend ostream& operator<<(ostream& cout, CUser& user);
	friend ostream& operator<<(ostream& cout, CUser* user);

	CUser()
	{
		mFirstName = "not set";
		mLastName = "not set";
		mAge = 0;
		mAddress = "not set";
	}

	CUser(string firstName, string lastName, unsigned int age, string address)
	{
		mFirstName = firstName;
		mLastName = lastName;
		mAge = age;
		mAddress = address;
	}

};

int main()
{

	CUser* user1 = new CUser("Kasun", "Dodanwala", 20, "Homeless");
	CUser user2("Ubetatta", "Pagaya", 45, "Also Homeless");

	cout << user1 << endl << user2 << endl;

	return 0;

}

void CUser::SetFirstName(string firstName)
{
	mFirstName = firstName;
}

void CUser::SetLastName(string lastName)
{
	mLastName = lastName;
}

void CUser::SetAge(unsigned int age)
{
	mAge = age;
}

void CUser::SetAddress(string address)
{
	mAddress = address;
}

string CUser::GetFirstName()
{
	return mFirstName;
}

string CUser::GetLastName()
{
	return mLastName;
}

int CUser::GetAge()
{
	return mAge;
}

string CUser::GetAddress()
{
	return mAddress;
}

ostream& operator<<(ostream& cout, CUser& user)
{
	cout << "First Name: " << user.mFirstName << endl;
	cout << "Last Name: " << user.mLastName << endl;
	cout << "Age: " << user.mAge << endl;
	cout << "Address: " << user.mAddress << endl;
	return cout;
}

ostream& operator<<(ostream& cout, CUser* user)
{
	cout << "First Name: " << user->mFirstName << endl;
	cout << "Last Name: " << user->mLastName << endl;
	cout << "Age: " << user->mAge << endl;
	cout << "Address: " << user->mAddress << endl;
	return cout;
}
