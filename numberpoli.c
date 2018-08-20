#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArray(int length)
{
    int value, min, max,i;
    int *array = malloc(length * sizeof(int));
    printf("Inserisci range min per l'array: ");
    scanf("%i", &min);
    printf("Inserisci range max per l'array: ");
    scanf("%i", &max);
    for (i = 0; i < length; i++)
    {
        value = rand() % (max + 1 - min) + min;
        array[i] = value;
    }
    return array;
}

int checkPos(int* array, int length){
    int  max=0,count=0,i;
    for (i=0; i < length; i++){
        if (*(array+i)>0){
            count += 1;
        }else{
            if (count > max){
                max = count;
            }

                count = 0;
        }
    }
    if (count > max){
                max = count;
            }
    
    return max;
}

int main()
{

    int seq, length,i;
    int* arr;
    srand(time(NULL));

    printf("Quanto vuoi che sia lungo l'array?: ");
    scanf("%i", &length);
    arr = createArray(length);
    for (i = 0 ; i < length; i++){
        printf ("%i ", *(arr+i));
    }
    printf ("\n");
    seq = checkPos(arr, length);
    printf ("la seq max e': %i\n", seq);

    return 0;
}