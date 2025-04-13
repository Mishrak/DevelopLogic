#include <stdio.h>

void formAnArray(int *array, int *length)
{
    printf("Enter the number of elements in an array.\n");
    scanf("%d", length);
    for(int i = 0; i < *length; i++)
    {
        printf("array[%d] = ", i);
        scanf("%d", &array[i]);
    }
}

void printAnArray(int *array, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

void deleteAnElementFromAnArray(int *array, int *length)
{
    int element = 0;
    int i = 0;
    printf("Enter an element that you want to delete form an array.\n");
    scanf("%d", &element);
    for(i = 0; i < *length; i++)
    {
        if(array[i] == element)
        {
            while( i < *length)
            {
                array[i] = array[i+1];
                i++;
                *length -= 1;
            }
            break;
        }
    }
}

int main(int argc, char **argv)
{
    int array[30] = {0};
    int length = 0;
    formAnArray(array, &length);
    deleteAnElementFromAnArray(array, &length);
    printAnArray(array, length);
}