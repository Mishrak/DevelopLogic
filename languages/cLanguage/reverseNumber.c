#include "header.h"

/*
int reverseNumber(int n)
{
    int rev = 0;

    while (n != 0)
    {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }

    return rev;
}
*/

bool checkPalindromeNumber(int num)
{
	int reverse_num = 0;

	while(num > reverse_num)
	{
		reverse_num = ((reverse_num * 10) + (num % 10));
		num /= 10;
	}
	return ((num == reverse_num) || (num == reverse_num/10));
}
int main()
{
	int num = 0;
	int reverse_num = 0;
	printf("Enter the number: \n");
	scanf("%d", &num);
	//reverse_num = reverseNumber(num);
	//printf("Number = %d\n", reverse_num);
	if(checkPalindromeNumber(num))
		printf("%d is a palindrome number.\n");
	else
		printf("%d is not a palindrome number.\n");
	return 0;
}