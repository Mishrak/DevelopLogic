#include <stdio.h>

char *my_strrev(char *s1)
{
	if(!s1 || !*s1)
		return NULL;

	char *start = s1;
	char *end = s1;
	char temp = '\0';

	while(*end)
	{
		end++;
	}
	end--;

	while(start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}

	return s1;
}

int main(int argc, char *argv[])
{
	const char *stringRev = my_strrev(argv[1]);
	printf("Reversed String = %s\n", stringRev);	
	return 0;
}