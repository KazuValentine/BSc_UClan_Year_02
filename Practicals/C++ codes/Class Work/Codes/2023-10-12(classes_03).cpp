#include <iostream>

using namespace std;

class CCounter
{
	
private:

	int mNumber = 0;

public:

	int GetNumberAndIncrement();
	int GetNumberAndDecrement();


};

int main()
{

	CCounter* a = new CCounter;
	CCounter* b = new CCounter;

	for(int i = 0; i <= 100; i++)
	{
		cout << a->GetNumberAndIncrement() << " | " << b->GetNumberAndDecrement() << endl << endl;
	}

	return 0;

}

int CCounter::GetNumberAndIncrement()
{
	return mNumber++;
}

int CCounter::GetNumberAndDecrement()
{
	return mNumber--;
}