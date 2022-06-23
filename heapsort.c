#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define MAX 7
int hSize=MAX;
int A[MAX]={6,7,0,10,4,5,8};
int temp; //DON'T TAKE GLOBAL i
 int largest;


int L(int i)	
{
    return 2*(i)+1; 	//THIS FORMULA WAS INCORRECT
}
int R(int i)
{
    return 2*(i)+2; //THIS WAS ALSO INCORRECT
}

void MAX_heapify(int i)
{
   
    int l=L(i);
    int r=R(i);
    //printf("left=%d right=%d\n",l,r);
    
    if(l<=hSize&&A[l]>A[i])
         largest=l;
    else largest=i;
    if(r<=hSize&&A[r]>A[largest])
        largest=r;
    //printf("largest=%d",largest);
    if (largest!=i)
    {
    	//printf("swapped...%d and %d",i,largest);
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        MAX_heapify(largest);
    }
//getchar();
}

void print()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
}
void buildHeap()
{
	int i;
	hSize=MAX-1;
    for(i=((MAX)/2-1);i>=0;i--)	//AS YOU ARE USING ARRAY YOU HAVE TO INVOKE MAX_heapify TILL 0 INDEX
    {
    	printf("maxhaapifyig at %d\n",i);
    	MAX_heapify(i);
    	print();
    	//getchar();
	}
        
    
}
void HeapSort()
{
	int i;
	printf("\nbefore build heap:\n");
    print();
    //getchar();
    buildHeap();
    printf("\nafter build heap:\n");
    print();
    //getchar();
for (i=MAX-1;i>=1;i--)
{

    temp=A[0];
    A[0]=A[i];
    A[i]=temp;
    hSize--;
    MAX_heapify(0);
}
}


main()
{
	int i;
    clock_t s,e;
	int ch,time_taken;
	printf("Heap sort\n");
    printf("Time taken for %d elements\n",MAX);


   /* printf("Select input method\n1.Random\t2.sorted\t3.reverse sorted\t4.Exit\nEnter Choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1: for(i=0; i<MAX; i++)
                    A[i]=rand()%MAX;

    			break;
    	case 2: for(i=0; i<MAX; i++)
                    A[i]=i;
    			break;
    	case 3: for(i=0; i<MAX; i++)
                    A[i]=MAX-i;
    			break;
        case 4:exit(1);
                break;
    	default:
    			printf("\ninvalied input");

	}
*/
    s = clock();
    HeapSort();
    e = clock();
    time_taken=e-s;
//checking if array is sorted or not
        printf("\n\n");
      for(i=0;i<MAX;i++)
    printf("%d\t",A[i]);
    printf("\ntime_taken=%d\n",time_taken);


}
