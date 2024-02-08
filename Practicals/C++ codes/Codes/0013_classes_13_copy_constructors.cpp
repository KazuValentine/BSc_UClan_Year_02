#include <iostream>
#include <string>

using namespace std;

class CMattrix
{

private:

	double** mpMattrix = nullptr;
	unsigned int mRows = 0;
	unsigned int mCols = 0;

	void CheckAndSetRowsAndCols(unsigned int& noOfRowsOrCols, const string& rowsOrCols);
	void AllocateSpaceToMattrix();

public:

	friend ostream& operator<<(ostream& cout, CMattrix* mattrix);
	friend ostream& operator<<(ostream& cout, const CMattrix& mattrix);
	friend CMattrix operator*(const CMattrix& mattrix1, const CMattrix& mattrix2);
	void SetRows(unsigned int rows);
	void SetCols(unsigned int cols);
	int GetRows();
	int GetCols();
	void PopulateMattrix();
	void UpdateMattrix();

	CMattrix()
	{
		mpMattrix = nullptr;
		mRows = 0;
		mCols = 0;
	}

	CMattrix(const unsigned int& rows, const unsigned int& cols)
	{
		mRows = rows;
		mCols = cols;
	}

	CMattrix(const CMattrix& original)
	{
		mRows = original.mRows;
		mCols = original.mCols;
		mpMattrix = new double*[mRows];
		for(int i = 0; i < mRows; i++)
		{
			mpMattrix[i] = new double[mCols];
			for(int j = 0; j < mCols; j++)
			{
				mpMattrix[i][j] = original.mpMattrix[i][j];
			}
		}
	}

	CMattrix(const unsigned int& rows, const unsigned int& cols, double** mattrix)
	{
		mRows = rows;
		mCols = cols;
		mpMattrix = new double*[mRows];
		for(int i = 0; i < mRows; i++)
		{
			mpMattrix[i] = new double[mCols];
			for(int j = 0; j < mCols; j++)
			{
				mpMattrix[i][j] = mattrix[i][j];
			}
		}
	}

	~CMattrix()
	{
		for (int i = 0; i < mRows; i++)
		{
			delete[] mpMattrix[i];
		}
		delete[] mpMattrix;
		mpMattrix = nullptr;
	}

};

int main()
{

	CMattrix mattrix1(2, 3);
	CMattrix mattrix2(3, 4);
	mattrix1.PopulateMattrix();
	mattrix2.PopulateMattrix();

	CMattrix mattrix3 = mattrix1 * mattrix2;

	cout << mattrix3;

	return 0;

}

ostream& operator<<(ostream& cout, CMattrix* mattrix)
{
	for (int i = 0; i < mattrix->mRows; i++)
	{
		for(int j = 0; j < mattrix->mCols; j++)
		{
			cout << mattrix->mpMattrix[i][j];

			if(j == mattrix->mCols - 1)
			{
				continue;
			}
			cout << ", ";
		}

		if(i == mattrix->mRows - 1)
		{
			continue;
		}
		cout << endl;
	}
	return cout;
}

ostream& operator<<(ostream& cout, const CMattrix& mattrix)
{
	for (int i = 0; i < mattrix.mRows; i++)
	{
		for(int j = 0; j < mattrix.mCols; j++)
		{
			cout << mattrix.mpMattrix[i][j];

			if(j == mattrix.mCols - 1)
			{
				continue;
			}
			cout << ", ";
		}

		if(i == mattrix.mRows - 1)
		{
			continue;
		}
		cout << endl;
	}
	return cout;
}

CMattrix operator*(const CMattrix& mattrix1, const CMattrix& mattrix2)
{
	CMattrix newMatrix(mattrix1.mRows, mattrix2.mCols);
	newMatrix.AllocateSpaceToMattrix();

	for(int i = 0; i < mattrix1.mRows; i++)
	{
		for(int j = 0; j < mattrix2.mCols; j++)
		{
			for(int k = 0; k < mattrix1.mCols; k++)
			{
				newMatrix.mpMattrix[i][j] += mattrix1.mpMattrix[i][k] * mattrix2.mpMattrix[k][j]; 
			}
		}
	}
	return newMatrix;
}

void CMattrix::SetRows(unsigned int rows)
{
	mRows = rows;
}

void CMattrix::SetCols(unsigned int cols)
{
	mCols = cols;
}

void CMattrix::CheckAndSetRowsAndCols(unsigned int& noOfRowsOrCols, const string& rowsOrCols)
{
	while(noOfRowsOrCols <= 0)
	{
		string input = "";
		cout << rowsOrCols << ": ";
		getline(cin, input);
		noOfRowsOrCols = stoi(input);
		if(noOfRowsOrCols <= 0)
		{
			cout << "Wrong Input" << endl;
		}
	}
}

int CMattrix::GetRows()
{
	return mRows;
}

int CMattrix::GetCols()
{
	return mCols;
}

void CMattrix::PopulateMattrix()
{
	if(mpMattrix != nullptr)
	{
		UpdateMattrix();
		return;
	}
	CheckAndSetRowsAndCols(mRows, "Rows");
	CheckAndSetRowsAndCols(mCols, "Cols");
	AllocateSpaceToMattrix();

	for(int i = 0; i < mRows; i++)
	{
		for(int j = 0; j < mCols; j++)
		{
			cout << "Row " << i + 1 << " Col " << j + 1 << " : ";
			cin >> mpMattrix[i][j];
		}
	}
}

void CMattrix::UpdateMattrix()
{
	if(mpMattrix == nullptr)
	{
		PopulateMattrix();
		return;
	}
	for(int i = 0; i < mRows; i++)
	{
		for(int j = 0; j < mCols; j++)
		{
			cout << "Row " << i + 1 << " Col " << j + 1 << " : ";
			cin >> mpMattrix[i][j];
		}
	}
}

void CMattrix::AllocateSpaceToMattrix()
{
	mpMattrix = new double*[mRows];
	for(int i = 0; i < mRows; i++)
	{
		mpMattrix[i] = new double[mCols];
		for(int j = 0; j < mCols; j++)
		{
			mpMattrix[i][j] = 0;
		}
		
	}
}