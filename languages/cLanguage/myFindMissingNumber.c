#include <stdio.h>

int findMissingNumber(int arr[], int size)
{
	int left = 0;
	int right = size - 1;

	if(arr[size - 1] == size)
		return -1;

	if(arr[0] != 1)
		return 1;

	while(left < right)
	{
		int mid = left + (right - left)/2;

		if(arr[mid] == mid + 1)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left+1;
}

int main(int argc, char *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);

	int missing_number = 0;
	missing_number = findMissingNumber(arr, size);
	printf("Missing number from the array = %d\n", missing_number);
	
	return 0;
}