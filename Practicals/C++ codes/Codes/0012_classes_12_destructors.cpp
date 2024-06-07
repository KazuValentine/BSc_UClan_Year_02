#include <iostream>

using namespace std;

class CBook
{

private:

	string mTitle = "";
	string mAuthor = "";
	int* mRates = nullptr;
	int mRatesCounter = 0;

public:

	void SetTitle(string& title);
	void SetAuthor(string& author);
	void SetRates(int* rates);
	void SetRatesCounter(int& ratesCounter);
	string GetTitle();
	string GetAuthor();

	friend ostream& operator<<(ostream& cout, CBook& book);
	friend ostream& operator<<(ostream& cout, CBook* book);

	CBook()
	{
		mTitle = "not set";
		mAuthor = "not set";
		mRates = nullptr;
		mRatesCounter = 0;
	}

	CBook(string title, string author, int* rates, int ratesCounter)
	{
		mTitle = title;
		mAuthor = author;
		mRates = rates;
		mRatesCounter = ratesCounter;
	}

	~CBook()
	{
		delete [] mRates;
		mRates = nullptr;
	}

};

int main()
{
	
	const int ARRAY_TWO_SIZE = 10;
	int arrayOne[] = {1, 2, 3, 10, 9, 8, 7, 6, 5, 4};
	int* arrayTwo = new int[ARRAY_TWO_SIZE];

	for(int i = 0; i < ARRAY_TWO_SIZE; i++)
	{
		arrayTwo[i] = 10 + i;
	}

	CBook seggs("Brutal Seggs", "Ubetatta", arrayOne, sizeof(arrayOne) / sizeof(arrayOne[0]));
	CBook* fuck = new CBook("Fucking Hell", "Jesus Fucking Christ", arrayTwo, ARRAY_TWO_SIZE);

	cout << seggs << endl << fuck << endl;

	return 0;
}

void CBook::SetTitle(string& title)
{
	mTitle = title;
}

void CBook::SetAuthor(string& author)
{
	mAuthor = author;
}

void CBook::SetRates(int* rates)
{
	mRates = rates;
}

void CBook::SetRatesCounter(int& ratesCounter)
{
	mRatesCounter = ratesCounter;
}

string CBook::GetTitle()
{
	return mTitle;
}

string CBook::GetAuthor()
{
	return mAuthor;
}

ostream& operator<<(ostream& cout, CBook& book)
{
	cout << "Title: " << book.mTitle << endl;
	cout << "Author: " << book.mAuthor << endl;
	cout << "Rates: ";
	for(int i = 0; i < book.mRatesCounter; i++)
	{
		cout << book.mRates[i];
		if(i != book.mRatesCounter - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	return cout;
}

ostream& operator<<(ostream& cout, CBook* book)
{
	cout << "Title: " << book->mTitle << endl;
	cout << "Author: " << book->mAuthor << endl;
	cout << "Rates: ";
	for(int i = 0; i < book->mRatesCounter; i++)
	{
		cout << book->mRates[i];
		if(i != book->mRatesCounter - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
	return cout;
}