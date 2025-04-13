#include <stdio.h>
#include <stdlib.h>

int findGCD(int x, int y)
{
    int remainder = 0, quotient = 0;

    do
    {
        quotient = (x / y);
        remainder = (x % y);
        if(remainder == 0)
        {
            break;
        }
        else
        {
            x = y;
            y = remainder;
        }
    } while(remainder != 0);

    return y;
}

int main(int argc, char **argv)
{
    int x = 0, y = 0, gcd_value = 0;
    x = atoi(argv[1]);
    y = atoi(argv[2]);

    gcd_value = findGCD(x, y);
    printf("Final Answer = %d\n", gcd_value);
    return 0;
}