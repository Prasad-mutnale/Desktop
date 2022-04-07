#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
void BubbleSort(int *arr)
{
    int i,j,temp;
    for(i=0;i<SIZE-1;i++)
    {
           for(j=SIZE-1;j>=i+1;j--)
            {
                if(arr[j] > arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
    }
}
void main()
{
    clock_t s,e;
    float time_taken;
    int a[SIZE],n;
    for(n=0; n<SIZE; n++)
    {
        a[n]=rand() % 100;
    }
    printf("Unsorted Order\n");
    for(n=0; n<SIZE; n++)
    {
        printf("%d\t",a[n]);
    }
    s=clock();
    BubbleSort(a);
    e=clock();
    printf("Sorted order\n");
    for(n=0; n<SIZE; n++)
    {
        printf("%d\t",a[n]);
    }
    time_taken=(float)(e-s);
    printf("Time taken=%f",time_taken);
}
