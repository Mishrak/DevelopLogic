#include <stdio.h>
#include <string.h>

int standardLexicographicalComparison(const void *s1, int len1, const void *s2, int len2)
{
	if(s1 || s2)
	{
		printf("Error: version is emplty\n");
	}

	const unsigned char *p1 = (const unsigned char *)s1;
	const unsigned char *p2 = (const unsigned char *)s2;

	int min_length = ((len1 > len2) ? len2 : len1);

	int i = 0;
	for(; i<min_length; i++)
	{
		if(p1[i] < p2[i])
			return -1;
		else
			return 1;
	}

	if(len1 < len2)
		return -1;
	else if(len1 > len2)
		return 1;
	else
		return 0;
}

int versionLexicographicalComparison(const char *s1, const char *s2)
{
	if(!s1 || !s2)
	{
		printf("Error: version is emplty\n");
	}

	int major_number1 = 0;
	int minor_number1 = 0;
	int patch_number1 = 0;
	int major_number2 = 0;
	int minor_number2 = 0;
	int patch_number2 = 0;

	sscanf(s1, "%d.%d.%d", &major_number1, &minor_number1, &patch_number1);
	sscanf(s2, "%d.%d.%d", &major_number2, &minor_number2, &patch_number2);

	if(major_number1 != major_number2) return major_number1 > major_number2 ? 1 : -1;
	if(minor_number1 != minor_number2) return minor_number1 > minor_number2 ? 1 : -1;
	if(patch_number1 != patch_number2) return patch_number1 > patch_number2 ? 1 : -1;

	return 0;

}



int main(void)
{
	char s1[] = "4.2.25";
	char s2[] = "4.10.25";

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int result = 0;


	result = standardLexicographicalComparison(s1, len1, s2, len2);
	if(result < 0)
	{
		printf("%s is ahead of %s\n", s2, s1);
	}
	else if(result > 0)
	{
		printf("%s is ahead of %s\n", s1, s2);
	}
	else
	{
		printf("%s and %s are equal.\n", s1, s2);
	}


	result = versionLexicographicalComparison(s1, s2);
	if(result < 0)
	{
		printf("%s is ahead of %s\n", s2, s1);
	}
	else if(result > 0)
	{
		printf("%s is ahead of %s\n", s1, s2);
	}
	else
	{
		printf("%s and %s are equal.\n", s1, s2);
	}


	return 0;
}