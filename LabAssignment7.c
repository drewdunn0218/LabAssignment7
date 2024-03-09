#include <stdio.h>
#include <stdlib.h>


void selectionSort(int arr[], int n, int counter[97], int *total)
{
    int i, j, min_idx, temp;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
            // Swap the found minimum element with the first element
        counter[arr[i]]++;
        counter[arr[min_idx]]++;
        *total = *total + 1;
        swap(&arr[i], &arr[min_idx]);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n, int counter[97], int *total)
{
    int i, j;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                counter[arr[j]]++;
                counter[arr[j+1]]++;
                *total = *total + 1;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//to count, make an array of the max size and use counter_array[arr[j]]++; use the value as the index
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void printCounter(int array[9], int counter[97])
{
    for(int i = 0; i < 9; i++)
    {
        printf("%d: %d\n", array[i], counter[array[i]]);
    }
}

void reset_counter(int counter[97])
{
    for(int i = 0; i <= 97; i++)
    {
        counter[i] = 0;
    }
}

int main(void)
{
    int length = 9, total = 0;
    int array1A[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2A[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array1B[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2B[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int counter[97];
    reset_counter(counter);
    bubbleSort(array1A, 9, counter, &total);
    printCounter(array1A, counter);
    printf("Total: %d\n", total);
    reset_counter(counter);
    total = 0;
    bubbleSort(array2A, 9, counter, &total);
    printCounter(array2A, counter);
    printf("Total: %d\n", total);
    reset_counter(counter);
    total = 0;
    selectionSort(array1B, 9, counter, &total);
    printCounter(array1B, counter);
    printf("Total: %d\n", total);
    reset_counter(counter);
    total = 0;
    selectionSort(array2B, 9, counter, &total);
    printCounter(array2B, counter);
    printf("Total: %d\n", total);
}

