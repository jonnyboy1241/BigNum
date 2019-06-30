// This file includes all of the different constructors for BigNum
#include <cstring>
#include <iostream>

#include "BigNum.h"

namespace BigNum
{

    // This constructor sets to 0
    BigNum::BigNum()
    {
        this->errorState = false;
        memset(this->num, 0x00, 500);
    }

    // Specify the initialized value
    // This constructor is used when the value is initialized like:
    // BigNum::BigNum("123");
    BigNum::BigNum(const char value[])
    {
        int size;
        size = strlen(value);

        memset(this->num, 0x00, 500);

        // Test for invalid characters
        for(int i = 0; i < size; i++)
        {
            if(value[i] > '9' || value[i] < '0')
            {
                this->errorState = INVALID_NUM;
                this->printError();
                return;
            }
        }

        // If the size of the input is too large
        if(size > 500)
        {
            this->errorState = INPUT_TOO_LARGE;
            this->printError();
            return;
        }

        int iterator = 0;

        // Set the value
        for(int i = size - 1; i >= 0; i--)
        {
            this->num[iterator++] = (unsigned char)(value[i] - '0');
        }

        this->errorState = false;
    }

    // This constructor is used when the value is passed in the function
    // as a std::string
    BigNum::BigNum(std::string value)
    {
        int size;
        size = value.size();

        memset(this->num, 0x00, 500);

        // Test for invalid characters
        for(int i = 0; i < size; i++)
        {
            if(value.at(i) > '9' || value.at(i) < '0')
            {
                this->errorState = INVALID_NUM;
                this->printError();
                return;
            }
        }

        // If the size of the input is too large
        if(size > 500)
        {
            this->errorState = INPUT_TOO_LARGE;
            this->printError();
            return;
        }

        int iterator = 0;

        // Set the value
        for(int i = size - 1; i >= 0; i--)
        {
            this->num[iterator++] = (unsigned char)(value[i] - '0');
        }

        this->errorState = false;
    }
}
