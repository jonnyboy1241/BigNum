#include "BigNum.h"

namespace BigNum
{
    // Prints the errorState
    void BigNum::printError()
    {
        switch(this->errorState)
        {
            case NUMBER_OVERFLOW:
                std::cout << "NUMBER_OVERFLOW" << std::endl;
                break;

            case NUMBER_UNDERFLOW:
                std::cout << "NUMBER_UNDERFLOW" << std::endl;
                break;

            case INVALID_NUM:
                std::cout << "INVALID_NUM" << std::endl;
                break;

            case INPUT_TOO_LARGE:
                std::cout << "INPUT_TOO_LARGE" << std::endl;
                break;

            default:
                std::cout << "GENERAL_ERROR" << std::endl;
                break;
        }
    }

    // Print the number
    void BigNum::printNum()
    {
        int iterator = NUM_MAX_BOUND;

        while(iterator > 0 && this->num[iterator] == 0)
            iterator--;

        for(; iterator >= 0; iterator--)
        {
            std::cout << (int)this->num[iterator];
        }
    }
}
