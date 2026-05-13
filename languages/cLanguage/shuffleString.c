#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_shuffle(const char *s1, const int *indices, int sizeofIndices)
{
	if((s1 == NULL) || (sizeofIndices == 0))
		return NULL;

	int i = 0;
	int len = strlen(s1);
	char *result = (char *)malloc(len + 1);
	if(result)
	{
		for(; i<sizeofIndices; i++)
		{
			int temp = indices[i];
			if((temp < 0) || (temp > len))
			{
				printf("index %d in indices array is outof boundry.\n", i);
				free(result);
				return NULL;
			}
			result[temp] = s1[i];
		}
		result[i] = '\0';
	}
	return result;
}

int main(int argc, char *argv[])
{
	const int indices[] = {4,5,6,7,0,1,2,3};
	const char *s1 = "efghabcd";

	char *result = my_shuffle(s1, indices, (sizeof(indices) / sizeof(indices[0])));
	printf("Shuffled String = %s\n", result);
	free(result);
	return 0;
}