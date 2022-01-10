#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort(int* x, int size);


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)){
    int count = 0;
    //find what H value to start at
    int *HG_start = h_gaps;
    float half = size/2;
    for(int i = 0; i<20;i++){
        if(*HG_start<=half||*HG_start==1){
            break;
        }
        HG_start++;
    }

    for(;*HG_start>=1; HG_start++){

        int length, sub_length, i, j;

        //allocate mem

        double dbl_size = (double)size;
        double dbl_HG_start = (double)*HG_start;

        sub_length = floor(dbl_size/dbl_HG_start);
        length = ceil(dbl_size/sub_length)+1;

        //allocate memory based on the sizes of the sub arrays
        int** arr = (int**)malloc(length*sizeof(int*));
        for (i=0; i < length; i++){
            arr[i] = (int*)malloc(sub_length*sizeof(int));
        }

        //now we have to put values for these things into the sub arrays

        int *p0 = array;
        int *pa = p0;
        int *pf = p0 + size - 1; 
        int n;

        //in the first sub array[0], we have the pointer at 0, the pointer at 0+(H+1), and the pointer at 0+2(H+1) ... the pointer at 0+n(H+1)
        //therefore
        for(i=0; i<length; i++){

            pa = &array[i];
            for(n=1, j=0;pa<=pf;n++, j++){
                //make the sub array with pointer at pa, then add pa+H+1 stuff
                arr[i][j] = *pa;
                int add = (*HG_start+1);
                pa = pa + add;
                
            }
            sub_length = j;

            count += subsort(arr[i], sub_length);

            //then put it back in the original array
            for(n=0, j=0;&array[i+n*(*HG_start+1)]<=pf;n++, j++){
                int index = i+n*(*HG_start+1);
                if(index>size){
                    break;
                }
                array[index] = arr[i][j];
            }

        }

        for (i = 0; i < length; i++){
            free(arr[i]);
        }

        free(arr);

        if(*HG_start==1){
            break;
        }

    }


    //final h value of 0

    count += subsort(array,size);

    return count;
}

int bubblesort(int* x, int size) {
    int temp;
    int swaps = 0;
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}


int main () {
    int array[] = {135, 529, 81, 54, 46, 605, 47, 793, 278, 323, 306, 430, 973, 286, 712, 962, 461, 81, 57,
325, 711, 995, 833, 222, 284, 293, 153, 224, 126, 643, 425, 400, 420, 309, 831, 6, 496, 347, 185, 583};

    int size = sizeof(array)/sizeof(array[0]);

    int h_gaps[] = {701,301,132,57,23,10,4,1};


    int count = shellsort(array, size, h_gaps, &bubblesort);
    printf("count: %d\n", count);
    
    for(int i =0;i<size;i++){
        printf("%d,", array[i]);
    }
    
    return 0;
}