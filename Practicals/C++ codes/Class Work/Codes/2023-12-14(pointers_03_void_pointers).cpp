#include <iostream>

void DerefPtr( void* ptr, std::string type );

int main()
{

	int numOne = 10;
	float numTwo = 5.23;
	int* pNumOne = &numOne;
	float* pNumTwo = &numTwo;
	DerefPtr( pNumOne, "int" );
	DerefPtr( pNumTwo, "float" );

	return 0;

}

void DerefPtr( void* ptr, std::string type )
{
	if( type == "int" )
	{
		int* newPtr = ( int* )ptr;
		std::cout << *newPtr << std::endl;
	}
	else if (type == "float" )
	{
		float* newPtr = ( float* )ptr;
		std::cout << *newPtr << std::endl;
	}
}