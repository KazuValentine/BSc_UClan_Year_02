using System;

namespace mattrix
{
    class Mattrix
    {

        private double[,] mppMattrix = null;
        private int mRows = 0;
        private int mCols = 0;

        private void CheckAndSetRowsAndCols( unsigned int& noOfRowsOrCols, const std::string& kRowsOrCols );
        private void AllocateSpaceToMattrix();

    public:

        friend std::ostream& operator<<( std::ostream& cout, Mattrix* pMattrix );
        friend std::ostream& operator<<( std::ostream& cout, const Mattrix& kMattrix );
        friend Mattrix operator*( const Mattrix& kMattrix1, const Mattrix& kMattrix2 );
        friend Mattrix operator+( const Mattrix& kMattrix1, const Mattrix& kMattrix2 );
        void operator=( const Mattrix& kOriginal );
        void SetRows( const unsigned int& kRows );
        void SetCols( const unsigned int& kCols);
        int GetRows();
        int GetCols();
        void PopulateMattrix();
        void UpdateMattrix();

        Mattrix()
        {
            mppMattrix = nullptr;
            mRows = 0;
            mCols = 0;
        }

        Mattrix( const unsigned int& kRows, const unsigned int& kCols )
        {
            mRows = kRows;
            mCols = kCols;
        }

        Mattrix( const Mattrix& kOriginal )
        {
            mRows = kOriginal.mRows;
            mCols = kOriginal.mCols;
            mppMattrix = new double*[mRows];
            for( int i = 0; i < mRows; i++ )
            {
                mppMattrix[i] = new double[mCols];
                for( int j = 0; j < mCols; j++ )
                {
                    mppMattrix[i][j] = kOriginal.mppMattrix[i][j];
                }
            }
        }

        Mattrix( const unsigned int& kRows, const unsigned int& kCols, double** ppMattrix )
        {
            mRows = kRows;
            mCols = kCols;
            mppMattrix = new double*[mRows];
            for( int i = 0; i < mRows; i++ )
            {
                mppMattrix[i] = new double[mCols];
                for( int j = 0; j < mCols; j++ )
                {
                    mppMattrix[i][j] = ppMattrix[i][j];
                }
            }
        }

        ~Mattrix()
        {
            for ( int i = 0; i < mRows; i++ )
            {
                delete [] mppMattrix[i];
            }
            delete [] mppMattrix;
            mppMattrix = nullptr;
        }

    };
}