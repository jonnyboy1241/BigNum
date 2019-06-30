// This file includes the operator overloading for BigNum
#include <string>
#include <iostream>

#include "BigNum.h"

namespace BigNum
{
    // BigNum Relational Operators (boolean/logical statements)
    bool BigNum::operator == (BigNum const &value)
    {
        // If there is any error states, just return false and print a warning statement
        if (this->errorState || value.errorState)
        {
            std::cout << "THERE IS AN ERROR STATE IN THIS OPERATION. RETURNING FALSE." << std::endl;
            return false;
        }

        for(int i = 0; i <= NUM_MAX_BOUND; i++)
            if(this->num[i] != value.num[i])
                return false;

        return true;
    }

    bool BigNum::operator != (BigNum const &value)
    {
        return !(*this == value);
    }

    BigNum BigNum::operator + (BigNum const &value)
    {
        BigNum ret;

        // If there is any error states, just return false and print a warning statement
        if (this->errorState || value.errorState)
        {
            std::cout << "THERE IS AN ERROR STATE IN THIS OPERATION. RETURNING ZERO." << std::endl;
            return ret;
        }


        // Add together
        for(int i = 0; i < MAX_NUM_SIZE; i++)
        {
            ret.num[i] = this->num[i] + value.num[i];
        }

        for(int i = 0; i < NUM_MAX_BOUND; i++)
        {
            if(ret.num[i] > 9)
            {
                ret.num[i + 1] += 1;
                ret.num[i] -= 10;
            }
        }

        // Integer overflow
        if(ret.num[NUM_MAX_BOUND] > 9)
        {
            ret.errorState = NUMBER_OVERFLOW;
            ret.printError();
        }

        return ret;
    }
}
