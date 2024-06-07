using mattrix;

std::ostream& operator<<( std::ostream& cout, Mattrix* pMattrix )
{
	for ( int i = 0; i < pMattrix->mRows; i++ )
	{
		for( int j = 0; j < pMattrix->mCols; j++ )
		{
			cout << pMattrix->mppMattrix[i][j];

			if( j == pMattrix->mCols - 1 )
			{
				continue;
			}
			cout << ", ";
		}

		if( i == pMattrix->mRows - 1 )
		{
			continue;
		}
		cout << std::endl;
	}
	return cout;
}

std::ostream& operator<<( std::ostream& cout, const Mattrix& kMattrix )
{
	for ( int i = 0; i < kMattrix.mRows; i++ )
	{
		for( int j = 0; j < kMattrix.mCols; j++ )
		{
			cout << kMattrix.mppMattrix[i][j];

			if( j == kMattrix.mCols - 1 )
			{
				continue;
			}
			cout << ", ";
		}

		if( i == kMattrix.mRows - 1 )
		{
			continue;
		}
		cout << std::endl;
	}
	return cout;
}

Mattrix operator*( const Mattrix& kMattrix1, const Mattrix& kMattrix2 )
{
	Mattrix newMatrix( kMattrix1.mRows, kMattrix2.mCols );
	newMatrix.AllocateSpaceToMattrix();

	for( int i = 0; i < kMattrix1.mRows; i++ )
	{
		for( int j = 0; j < kMattrix2.mCols; j++ )
		{
			for( int k = 0; k < kMattrix1.mCols; k++ )
			{
				newMatrix.mppMattrix[i][j] += kMattrix1.mppMattrix[i][k] * kMattrix2.mppMattrix[k][j]; 
			}
		}
	}
	return newMatrix;
}

Mattrix operator+( const Mattrix& kMattrix1, const Mattrix& kMattrix2 )
{
	Mattrix newMatrix( kMattrix1.mRows, kMattrix1.mCols );
	newMatrix.AllocateSpaceToMattrix();

	for( int i = 0; i < newMatrix.mRows; i++ )
	{
		for( int j = 0; j < newMatrix.mCols; j++ )
		{
			newMatrix.mppMattrix[i][j] = kMattrix1.mppMattrix[i][j] + kMattrix2.mppMattrix[i][j];
		}
	}
	return newMatrix;
}

void Mattrix::operator=( const Mattrix& kOriginal )
{
	if( mRows != kOriginal.mRows || mCols != kOriginal.mCols || mppMattrix == nullptr )
	{
		if( mppMattrix != nullptr )
		{
			for ( int i = 0; i < mRows; i++ )
			{
				delete [] mppMattrix[i];
			}
			delete [] mppMattrix;
			mppMattrix = nullptr;
		}
		mRows = kOriginal.mRows;
		mCols = kOriginal.mCols;
		mppMattrix = new double*[mRows];
		for( int i = 0; i < mRows; i++ )
		{
			mppMattrix[i] = new double[mCols];
		}
	}
	for( int i = 0; i < mRows; i++ )
	{
		for( int j = 0; j < mCols; j++ )
		{
			mppMattrix[i][j] = kOriginal.mppMattrix[i][j];
		}
	}

}

void Mattrix::SetRows( const unsigned int& kRows )
{
	mRows = kRows;
}

void Mattrix::SetCols( const unsigned int& kCols )
{
	mCols = kCols;
}

void Mattrix::CheckAndSetRowsAndCols( unsigned int& noOfRowsOrCols, const std::string& kRowsOrCols )
{
	while( noOfRowsOrCols <= 0 )
	{
		std::string input = "";
		std::cout << kRowsOrCols << ": ";
		std::getline( std::cin, input );
		noOfRowsOrCols = stoi( input );
		if( noOfRowsOrCols <= 0 )
		{
			std::cout << "Wrong Input" << std::endl;
		}
	}
}

int Mattrix::GetRows()
{
	return mRows;
}

int Mattrix::GetCols()
{
	return mCols;
}

void Mattrix::PopulateMattrix()
{
	if( mppMattrix != nullptr )
	{
		UpdateMattrix();
		return;
	}
	CheckAndSetRowsAndCols( mRows, "Rows" );
	CheckAndSetRowsAndCols( mCols, "Cols" );
	AllocateSpaceToMattrix();

	for( int i = 0; i < mRows; i++ )
	{
		for( int j = 0; j < mCols; j++ )
		{
			std::cout << "Row " << i + 1 << " Col " << j + 1 << " : ";
			std::cin >> mppMattrix[i][j];
		}
	}
}

void Mattrix::UpdateMattrix()
{
	if( mppMattrix == nullptr )
	{
		PopulateMattrix();
		return;
	}
	for( int i = 0; i < mRows; i++ )
	{
		for( int j = 0; j < mCols; j++ )
		{
			std::cout << "Row " << i + 1 << " Col " << j + 1 << " : ";
			std::cin >> mppMattrix[i][j];
		}
	}
}

void Mattrix::AllocateSpaceToMattrix()
{
	mppMattrix = new double*[mRows];
	for( int i = 0; i < mRows; i++ )
	{
		mppMattrix[i] = new double[mCols];
		for( int j = 0; j < mCols; j++ )
		{
			mppMattrix[i][j] = 0;
		}
		
	}
}