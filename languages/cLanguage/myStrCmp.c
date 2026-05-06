#include <stdio.h>

int myStrcmp(const char *s1, const char *s2)
{
	while((*s1 || *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <string1> <string2>\n", argv[0]);
		return -1;
	}
	int result = myStrcmp(argv[1], argv[2]);
	if(result == 0)
	{
		printf("%s and %s are same.\n", argv[1], argv[2]);
	}
	else
	{
		printf("%d: %s and %s are different.\n", result, argv[1], argv[2]);
	}
	return 0;
}