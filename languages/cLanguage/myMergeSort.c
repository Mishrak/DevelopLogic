#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    int i = 0;
    for(; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int aux[], int left, int mid, int right)
{
    int i = 0;

    for(i = left; i<=right; i++)
    {
        aux[i] = arr[i];
    }

    i = left;
    int j = mid+1;
    int k = left;

    while((i <= mid) && (j <= right))
    {
        if(aux[i] <= aux[j])
        {
            arr[k++] = aux[i++];
        }
        else
        {
            arr[k++] = aux[j++];
        }
    }

    while(i <= mid)
    {
        arr[k++] = aux[i++];
    }
}

void myMergeSort(int arr[], int aux[], int left, int right)
{
    if(left >= right)
        return;

    int mid = left + (right - left)/2;

    myMergeSort(arr, aux, left, mid);
    myMergeSort(arr, aux, mid + 1, right);

    merge(arr, aux, left, mid, right);

}

int main(int argc, char *argv[])
{
    int arr[] = {5, 10, 25, 2, 1, 50, 80, 35, 16, 12, 48, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *aux = (int *)malloc(size * sizeof(int));
    if(aux == NULL)
    {
        printf("Error allocating memeory\n");
        return -1;
    }

    printf("Before sorting = ");
    printArray(arr, size);
    myMergeSort(arr, aux, 0, size - 1);
    printf("After sorting = ");
    printArray(arr, size);

    if(aux != NULL)
    {
        free(aux);
    }
    return 0;
}