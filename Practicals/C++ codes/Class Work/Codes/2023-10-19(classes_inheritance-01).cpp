#include <iostream>

using namespace std;

class CPerson
{

private:

	string mName = "";
	unsigned int mAge = 0;
	string mAddress = "";

public:

	void SetName(string name);
	void SetAge(unsigned int age);
	void SetAddress(string address);
	string GetName();
	int GetAge();
	string GetAddress();

	virtual void PrintDetails() = 0;

	CPerson(string name, unsigned int age, string address)
	{
		mName = name;
		mAge = age;
		mAddress = address;
	}

};

class CStudent : public CPerson
{
	
private:

	string mStudentID = "";	

public:

	void SetStudentID(string SID);
	string GetStudentID();
	void PrintDetails();

	CStudent(string name, unsigned int age, string address, string SID) : CPerson(name, age, address)
	{
		mStudentID = SID;
	}

};

class CLecturer : public CPerson
{
	
private:

	string mLecturerID = "";	

public:

	void SetLecturerID(string SID);
	string GetLecturerID();
	void PrintDetails();

	CLecturer(string name, unsigned int age, string address, string lecturerID) : CPerson(name, age, address)
	{
		mLecturerID = lecturerID;
	}

};

int main()
{

	CPerson* student = new CStudent("Kasun", 20, "BrutalSeggs", "3000745");
	CPerson* lecturer = new CLecturer("Jinapala", 45, "NoSeggs", "456987");

	student->PrintDetails();
	cout << endl;
	lecturer->PrintDetails();
	cout << endl;

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

void CStudent::SetStudentID(string SID)
{
	mStudentID = SID;
}

string CStudent::GetStudentID()
{
	return mStudentID;
}

void CLecturer::SetLecturerID(string lecturerID)
{
	mLecturerID = lecturerID;
}

string CLecturer::GetLecturerID()
{
	return mLecturerID;
}

void CStudent::PrintDetails()
{
	cout << "Name: " << GetName() << endl;
	cout << "Age: " << GetAge() << endl;
	cout << "Address: " << GetAddress() << endl;
	cout << "Student ID: " << GetStudentID() << endl;
}


void CLecturer::PrintDetails()
{
	cout << "Name: " << GetName() << endl;
	cout << "Age: " << GetAge() << endl;
	cout << "Address: " << GetAddress() << endl;
	cout << "Lecturer ID: " << GetLecturerID() << endl;
}
