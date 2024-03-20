#include <iostream>

long long int Fibonacci( int num )
{
    long long int prev = 1;
    long long int current = 1;
    for( int i = 2; i < num; i++ )
    {
        current += prev;
        prev = current - prev;
    }
    return current;
}

int main()
{
    for( int i = 1; i <= 50; i++ )
    {
        std::cout << Fibonacci( i ) << ", ";
        if( i % 5 == 0 )
            std::cout << '\n';
    }
    return 0;
}
