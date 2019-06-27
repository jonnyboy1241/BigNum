#include <iostream>
#include <string>

#include "BigNum.h"

int main()
{
    std::string str;

    do
    {
        std::getline(std::cin, str);
        if(!str.compare("end"))
            break;
        BigNum::BigNum bn(str);
        bn.printNum();
    }
    while( 1 );

    std::cout << "Press any key to continue . . . " << std::endl;
    getchar();
    return 0;
}
