#include <iostream>

using namespace std;

class CGrandParent
{

private:

    int mGA = 0;

protected:

    int mGB = 0;

public:

    int mGC = 0;

};

class CParent : public CGrandParent
{

private:

    int mPA = 0;

protected:

    int mPB = 0;

public:

    int mPC = 0;
   
};

class CChild : protected CParent
{

private:

    int mCA = 0;

protected:

    int mCB = 0;

public:

    int mCC = 0;
   
};

class CInfant : private CParent
{

private:

    int mIA = 0;

protected:

    int mIB = 0;

public:

    int mIC = 0;
   
};

int main()
{

    CGrandParent okay;
    CParent notOkay;
    CChild kindaOkay;
    CInfant fuckYeah;

    okay.mGC;
    notOkay.mGC;
    notOkay.mPC;
    kindaOkay.mCC;
    kindaOkay.mCC;
    kindaOkay.;

    return 0;

}