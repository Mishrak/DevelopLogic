#include <stdio.h>

int linearSearch(int *arr, int element)
{
    int length = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < length ; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int main (int argc, char **argv)
{
    int num = 0;
    int array[10] = {0};
    printf("Enter the number of Element in an array.\n");
    scanf("%d", &num);
    if(num > 10)
    {
        printf("Error: Array can not be larger than 10 elements.\n");
        return -1;
    }

    for(int i = 0; i < num; i++)
    {
        printf("\nEnter array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf("Enter the Element to be found.\n");
    scanf("%d", &num);

    int element_found = linearSearch(&array[0], num);
    if(element_found >= 0)
        printf("lenearSearch result = %d index\n", element_found);
    else
        printf("element not found.\n");

    return 0;
}