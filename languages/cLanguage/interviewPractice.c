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

/*

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
*/

/*
int countNumberOfDigits(int num)
{
	int count = 1;
	while(num != 0)
	{
		if((num /= 10) != 0)
			++count;
	}
	return count;
}
*/

/*
int findMaxNumber(int *array)
{
	int max = array[0];
	int i = 1;
	int count = 0;
	for(; array[count] != '\0'; ++count);
	printf("Numbers of elements in the array = %d\n", count);
	for(; i < count; i++)
	{
		if(array[i] > max)
			max = array[i];
	}
	return max;
}
*/

/*
void checkForPrimeNumber(int num)
{
	int i = 2;
	for(; i < (num/2); i++)
	{
		if((num % i) == 0)
		{
			printf("%d is not a prime number.\n", num);
			return;
		}
	}
	printf("%d is a prime number.\n", num);
}
*/

int findSecondLargestElementInArray(int *array)
{
	int largest_number = array[0];
	int second_largest_number = largest_number;
	int i = 0;
	int count = 0;

	for(; array[count] != '\0'; ++count);
//	printf("Number of elements in the array = %d\n", count);
	for(; i<count; i++)
	{
//		printf("value of i = %d, array[%d] = %d, largest_number = %d\n", i, i, array[i], largest_number);
		if((array[i] > largest_number))
		{
//			printf("array[%d] = %d : largest_number = %d, second_largest_number = %d\n", i, array[i], largest_number, second_largest_number);
			second_largest_number = largest_number;
			largest_number = array[i];
		}
	}
	return second_largest_number;
}

int main()
{
	int num = 0;

	/*
	printf("Enter the number = ");
	scanf("%d", &num);
	printf("\n");
	*/

	
	int array[10];
	memset(array, 0x00, sizeof(array));
	printf("Enter how many numbers you want to enter: \n");
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		printf("Enter number = ");
		scanf("%d", &array[i]);
		printf("\n");
	}
	
	/*
	int reverse_num = reverseNumber(num);
	printf("Number = %d\n", reverse_num);
	*/

	/*
	if(checkPalindromeNumber(num))
		printf("%d is a palindrome number.\n", num);
	else
		printf("%d is not a palindrome number.\n", num);
	*/

	/*
	printf("Number of Digits = %d\n", countNumberOfDigits(num));
	*/

	/*
	printf("Max Number is %d\n", findMaxNumber(array));
	*/

	/*
	checkForPrimeNumber(num);
	*/

	printf("Second largest element is the array = %d\n", findSecondLargestElementInArray(array));

	return 0;
}