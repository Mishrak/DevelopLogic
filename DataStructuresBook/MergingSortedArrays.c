#include <stdio.h>
void formArrays(int *array1, int *array2, int *length1, int *length2)
{
    printf("Enter the number of elements in array1 = \n");
    scanf("%d", length1);

    for(int i = 0; i < *length1; i++)
    {
        printf("array1[%d] = ", i);
        scanf("%d", &array1[i]);
    }
    printf("\n");

    printf("Enter the number of elements in array2 = \n");
    scanf("%d", length2);

    for(int i = 0; i < *length2; i++)
    {
        printf("array2[%d] = ", i);
        scanf("%d", &array2[i]);
    }
    printf("\n");
}

void dumpAllOtherElements(int *input_array, int *output_array, int current_index, int total_length, int i)
{
    while(current_index < total_length)
    {
        output_array[i] = input_array[current_index];
        i++;
        current_index++;
    }
}

void mergeArrays(int *array1, int *array2, int *array3, int length1, int length2, int *length3)
{
    *length3 = length1 + length2;
    int a = 0;
    int b = 0;
    for(int i = 0; i < *length3; i++)
    {
        if(array1[a] <= array2[b])
        {
            array3[i] = array1[a];
            a++;
            if(a == length1)
            {
                dumpAllOtherElements(array2, array3, b, length2, ++i);
                break;
            }
        }
        else
        {
            array3[i] = array2[b];
            b++;
            if(b == length2)
            {
                dumpAllOtherElements(array1, array3, a, length1, ++i);
                break;
            }
        }
    }
}

void printMergedArray(int *array3, int length3)
{
    printf("Merged Array = { ");
    for (int i =0; i < length3; i++)
    {
        printf("%d ", array3[i]);
    }
    printf("}\n");
}
int main(int argc, char **argv)
{
    int array1[10] = {0};
    int array2[10] = {0};
    int array3[20] = {0};
    int length1 = 0;
    int length2 = 0;
    int length3 = 0;
    formArrays(array1, array2, &length1, &length2);
    mergeArrays(array1, array2, array3, length1, length2, &length3);
    printMergedArray(array3, length3);
}