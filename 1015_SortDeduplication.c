#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    scanf("%c", &ch); 

    int arr[100000];
    int k=0;
    while (scanf("%d", &arr[k]) != EOF){
        k++;
    }

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if ((ch == 'A' && arr[i] > arr[j]) || (ch == 'D' && arr[i] < arr[j]))
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int uniqueCount = 1; 
    for (int i = 1; i < k; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[uniqueCount++] = arr[i]; 
        }
    }
    printf("%d", arr[0]);
    for (int i = 1; i < uniqueCount; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}