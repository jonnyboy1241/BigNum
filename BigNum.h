#ifndef BIG_NUM_H
#define BIG_NUM_H

#include <string>

namespace BigNum
{
    #define VALID               0x00
    #define NUMBER_OVERFLOW     0x01
    #define NUMBER_UNDERFLOW    0x02
    #define INVALID_NUM         0x03
    #define INPUT_TOO_LARGE     0x04

    #define NUM_MAX_BOUND       499
    #define MAX_NUM_SIZE        500

    class BigNum
    {
    protected:
        unsigned char num[500];     // This variable will hold the number
        unsigned short errorState;

    public:

        // Constructors
        BigNum();
        BigNum(const char value[]);
        BigNum(std::string value);

        void printNum();
        void printError();

        // Unary increment and decrement ++, -- (prefix and postfix)
        // Arithmetic operators +, -, *, /,%
        BigNum operator + (BigNum const &value);

        // Releational operators: <, <=, >, >=, ==, !=
        bool operator == (BigNum const &value);
        bool operator != (BigNum const &value);
        // bool operator >= (BigNum const &value);
        // bool operator <= (BigNum const &value);
        // bool operator > (BigNum const &value);
        // bool operator < (BigNum const &value);

    };
}

#endif  // BIG_NUM_H
