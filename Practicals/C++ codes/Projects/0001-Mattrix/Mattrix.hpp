#pragma once
#ifndef MATTIX
#define MATTRIX
#include <ostream>

class Mattrix
{

private:

	double** mppMattrix = nullptr;
	unsigned int mRows = 0;
	unsigned int mCols = 0;

	void CheckAndSetRowsAndCols(unsigned int& noOfRowsOrCols, const std::string& kRowsOrCols);
	void AllocateSpace();

public:

	friend std::ostream& operator<<(std::ostream& cout, Mattrix* pMattrix);
	friend std::ostream& operator<<(std::ostream& cout, const Mattrix& kMattrix);
	friend Mattrix operator*(const Mattrix& kMattrix1, const Mattrix& kMattrix2);
	friend Mattrix operator+(const Mattrix& kMattrix1, const Mattrix& kMattrix2);

	void operator=(const Mattrix& kOriginal);
	void SetRows(const unsigned int& kRows);
	void SetCols(const unsigned int& kCols);
	int GetRows();
	int GetCols();
	void PopulateMattrix();
	void UpdateMattrix();

	Mattrix();
	Mattrix(const unsigned int& kRows, const unsigned int& kCols);
	Mattrix(const Mattrix& kOriginal);
	Mattrix(const unsigned int& kRows, const unsigned int& kCols, double** ppMattrix);

	~Mattrix();

};
#endif