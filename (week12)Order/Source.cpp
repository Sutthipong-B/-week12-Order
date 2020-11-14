#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int* arr, int size);
void printArray(int* arr, int size);

int sortMin(int* num1, int* num2);
int sortMax(int* num1, int* num2);

void sort(int* arr, int size, int (*compare)(int*, int*));

int main()
{
    int arr[MAX_SIZE];
    int size;

    printf("Enter amount of number (array size): ");
    scanf_s("%d", &size);
    printf("Enter elements in array: ");
    inputArray(arr, size);

    printf("\nMin to Max: ");
    sort(arr, size, sortMin);
    printArray(arr, size);

    printf("\nMax to Min: ");
    sort(arr, size, sortMax);
    printArray(arr, size);

    return 0;
}

void inputArray(int* arr, int size)
{
    int* arrEnd = (arr + size - 1);
    while (arr <= arrEnd)
    {
        scanf_s("%d", arr++);
    }
}

void printArray(int* arr, int size)
{
    int* arrEnd = (arr + size - 1);
    while (arr <= arrEnd)
    {
        printf("%d ", *(arr++));
    }
}

int sortMin(int* num1, int* num2)
{
    return (*num1) - (*num2);
}

int sortMax(int* num1, int* num2)
{
    return (*num2) - (*num1);
}

void sort(int* arr, int size, int (*compare)(int*, int*))
{
    int* arrEnd = (arr + size - 1);
    int* curElement = arr;
    int* elemSorting;
    while (curElement <= arrEnd)
    {
        elemSorting = curElement;
        while (elemSorting <= arrEnd)
        {
            if (compare(curElement, elemSorting) > 0)
            {
                *curElement ^= *elemSorting;
                *elemSorting ^= *curElement;
                *curElement ^= *elemSorting;
            }
            elemSorting++;
        }
        curElement++;
    }
}