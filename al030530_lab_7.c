#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 9

void fillArray(int ** numArr);
void printArray(int * numArr);
void bubbleSort(int * numArr, int * ptr, int n);

//Fills empty array with numbers from assignment
void fillArray(int ** numArr)
{
  if (*numArr != NULL)
  {  
    (*numArr)[0] = 97;
    (*numArr)[1] = 16;
    (*numArr)[2] = 45;
    (*numArr)[3] = 63;
    (*numArr)[4] = 13;
    (*numArr)[5] = 22;
    (*numArr)[6] = 7;
    (*numArr)[7] = 58;
    (*numArr)[8] = 72;
  }
}

//Prints the Array
void printArray(int * numArr)
{
  printf("\n");
  for (int i = 0; i < MAXSIZE; i++)
    {
      printf("%d\n", numArr[i]);
    }
}

//Bubble sort algorithm (stops iterating after array is sorted)
void bubbleSort(int * numArr, int * ptr, int n)
{
  int tmp, counter;
  if ((sizeof(numArr))/(sizeof(numArr[0])) > 1)
  {
    counter = 0;
    for (int i = 0; i < n-1; i++)
      {
        if (numArr[i] > numArr[i+1])
        {
          tmp = numArr[i];
          numArr[i] = numArr[i+1];
          numArr[i+1] = tmp;
          counter++;
        }
      }
    *ptr += 1;
    printf("Iteration #%d has %d swaps\n", (*ptr), counter);
    
    if (counter != 0)
    {
      bubbleSort(numArr, ptr, n-1);
    } 
  }

}


int main(void) {

  int * numArr = (int *)malloc(MAXSIZE * sizeof(int));
  int * ptr = (int *)malloc(sizeof(int));
  *ptr = 0;

  fillArray(&numArr);
  //printArray(numArr);

  bubbleSort(numArr, ptr, MAXSIZE);
  printArray(numArr);
  
  return 0;
}