#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char my_reverse_string(char *s1, int left, int right)
{
	while(left < right)
	{
		char temp = s1[left];
		s1[left] = s1[right];
		s1[right] = temp;
		left++;
		right--;
	}
}

char *my_strrevII(char *s1, int num)
{
	int len = strlen(s1);
	if((s1 == NULL) || (num < 0))
		return NULL;
	if(len < num)
	{
		printf("Error: Length of the string is smaller than the number provided.\n");
		return NULL;
	}
	if(num == 0)
		return s1;

	int i = 0;
	for(; i<len; i+=2*num)
	{
		int left = i;
		int right = i + num - 1;

		my_reverse_string(s1, left, right);
	}
	return s1;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <string> <number>\n", argv[0]);
		exit(0);
	}
	else
	{
		int num = atoi(argv[2]);
		char *result = my_strrevII(argv[1], num);
		printf("reversed string = %s\n", result);
		//free(result);
	}
	return 0;
}