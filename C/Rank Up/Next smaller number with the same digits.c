#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(char* arr, int start, int end) 
{
    while (start < end) 
    {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

long long next_smaller_number(unsigned long long n)
{
    char numStr[21];
    sprintf(numStr, "%llu", n);
    int len = strlen(numStr);

    // Traverse the number from right to left to find the first digit that is larger than its next digit
    int i;
    for (i = len - 1; i > 0; i--)
        if (numStr[i - 1] > numStr[i])
            break;

    // If no such digit is found, return -1
    if (i == 0)
        return -1;

    // Find the largest digit to the right of numStr[i-1] that is smaller than numStr[i-1]
    int j;
    for (j = len - 1; j >= i; j--)
        if (numStr[j] < numStr[i - 1])
            break;

    swap(&numStr[i - 1], &numStr[j]);
    reverse(numStr, i, len - 1);
  
    unsigned long long result = strtoull(numStr, NULL, 10);
    if (numStr[0] == '0')
        return -1;

    return result;
}
