#include <iostream>
using namespace std;

bool isOdd(int n)
{
    int andN = n & 1;
    return andN == 1;
}

int getIthBit(int number, int position)
{
    int mask = 1 << (position - 1);
    int ithBit = (number & mask) > 0 ? 1 : 0;
    return ithBit;
}

int clearIthBit(int number, int position)
{
    int mask = ~(1 << (position - 1));
    return number & mask;
}

int setIthBit(int number, int position, int newVal)
{
    int numberAfterClearingNthBit = clearIthBit(number, position);
    int mask = newVal << (position - 1);
    return numberAfterClearingNthBit | mask;
}

int clearLastIthBits(int number, int i)
{
    int mask = ((~0) << i);
    return number & mask;
}

int clearBitsInRange(int number, int i, int j)
{
    int maskAfterJ = ((~0) << (j + 1));
    int maskBeforeI = (1 << i) - 1;
    int mask = maskAfterJ | maskBeforeI;
    return number & mask;
}

bool divisibleByTwo(int num) {
    int withOne = num&1;
    return withOne==0;
}

bool divisibleByFour(int num) {
    bool isDivisibleByTwo = divisibleByTwo(num);
    if(!isDivisibleByTwo) return false;
    int afterDivisionWithTwo = num/2;
    bool againDivisibleByTwo = divisibleByTwo(afterDivisionWithTwo);
    return againDivisibleByTwo;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    /*
        SET PROBLEMS
        1. DETERMINE IF A GIVEN NUMBER IS ODD OR EVEN

            int n;
            cin >> n;
            bool isOddNumber = isOdd(n);
            cout << n;
            cout << (isOddNumber ? " is Odd." : " is Even.") << endl;
        2. GET iTh Bit of a given number.

            int number, position;
            cin >> number >> position;
            cout << getIthBit(number, position) << endl;
        3. SET iTh Bit of a given number:
            int number, position, value;
            cin >> number >> position >> value;
            cout << setIthBit(number, position, value) << endl;

        4. Clear last Ith Bit bit:
            int number, position;
            cin >> number >> position;
            cout << clearLastIthBits(number, position) << endl;

        5. Clear Bits in the range (i,j):

            int number, i, j;
            cin >> number >> i >> j;
            cout << clearBitsInRange(number, i, j) << endl;

    */

   int i;
   cin >> i;
   bool isDivisibleByFour = divisibleByFour(i);
   cout<< "Is Divisible By 4 = "<<isDivisibleByFour<<endl;

    return 0;
}