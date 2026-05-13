#include <stdio.h>
#include <string.h>

const char *my_strrev(char *s1)
{
	if(!s1 || !*s1)
		return s1;

	int i = 0;
	int j = strlen(s1) - 1;
	char temp = '\0';

	while(i < j)
	{
		temp = s1[j];
		s1[j] = s1[i];
		s1[i] = temp;
		i++;
		j--;
	}
	return s1;
}

int main(int argc, char *argv[])
{
	const char *stringRev = my_strrev(argv[1]);
	printf("Reversed String = %s\n", stringRev);	
	return 0;
}