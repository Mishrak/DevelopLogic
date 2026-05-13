#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool my_rotateString(char *s1, char *s2)
{
	int len = strlen(s1);
	if(len != strlen(s2))
		return false;
	if(len == 0)
		return true;

	int i=0;
	int j=0;

	for(; i<len; i++)
	{
		bool match = true;
		for(j=0; j<len; j++)
		{
			if(s1[(i+j)%len] != s2[j])
			{
				match = false;
				break;
			}
		}
		if(match)
			return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	if(my_rotateString(argv[1], argv[2]))
		printf("String rotation is possible\n");
	else
		printf("String rotation is not possible\n");
	return 0;
}