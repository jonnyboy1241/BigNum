#include <iostream>
#include <string>

#include "BigNum.h"

int main()
{
    BigNum::BigNum one("123"), two("877");

    (one + two).printNum();
    std::cout << std::endl;

    return 0;
}
