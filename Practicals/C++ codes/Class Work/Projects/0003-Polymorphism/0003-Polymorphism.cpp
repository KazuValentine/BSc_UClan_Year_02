#include <iostream>
#include "aaa.hpp"
#include "bbb.hpp"
#include "ccc.hpp"
#include "ddd.hpp"
#include "eee.hpp"
#include "fff.hpp"
#include "ggg.hpp"

int main()
{
    aaa* array[] = {new aaa, new bbb, new ccc,
                    new ddd, new eee, new fff,
                    new ggg};
    for (int i = 0; i < 7; i++)
    {
        array[i]->Print();
        delete array[i];
    }
    return 0;
}
