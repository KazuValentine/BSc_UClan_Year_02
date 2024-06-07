#include <iostream>

using namespace std;

class CAccount
{

private:

	string mName = "0";
	double mBalance = 0;
	string mType = "0";

public:

	void DepositMoney(double amount);
	void SetName(string name);
	void SetType(string type);
	string GetType();
	string GetName();
	double GetBalance();
	void Withdraw(double amount);
	
	CAccount(string name, string type)
	{
		mName = name;
		mType = type;
	}

};

int main()
{

	CAccount* bankAcc = new CAccount("Kasun Dodanwala", "Savings");

	bankAcc->DepositMoney(123.65);
	cout << "Balance: " << bankAcc->GetBalance() << endl;
	bankAcc->Withdraw(100);
	cout << "Now Balance: " << bankAcc->GetBalance() << endl;
	cout << "Type: " << bankAcc->GetType() << endl;
	cout << "Name: " << bankAcc->GetName() << endl;

	return 0;

}

void CAccount::DepositMoney(double amount)
{
	mBalance += amount;
}

void CAccount::SetName(string name)
{
	mName = name;
}

void CAccount::SetType(string type)
{
	mType = type;
}

string CAccount::GetType()
{
	return mType;
}

string CAccount::GetName()
{
	return mName;
}

double CAccount::GetBalance()
{
	return mBalance;
}

void CAccount::Withdraw(double amount)
{
	mBalance -= amount;
}
