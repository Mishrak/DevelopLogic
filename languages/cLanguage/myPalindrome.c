#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isPalindrome(const char *s1)
{
	int left = 0;
	int right = strlen(s1) - 1;

	while(left < right)
	{
		if(isalnum((unsigned char)s1[left]) == 0)
		{
			left++;
			continue;
		}
		if(isalnum((unsigned char)s1[right]) == 0)
		{
			right--;
			continue;
		}

		if((tolower((unsigned char)s1[left])) != tolower((unsigned char)s1[right]))
			return -1;

		left++;
		right--;
	}
	return 0;

}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return -1;
	}

	int result = 0;
	result = isPalindrome(argv[1]);
	if(result != 0)
	{
		printf("%s is not a palindrome string\n", argv[1]);
	}
	else
	{
		printf("%s is a palindrome string\n", argv[1]);
	}
	return 0;
}