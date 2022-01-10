#include <stdio.h>
#include <assert.h>
#include <math.h>


int binsearch(int* x, int y, int size);

int binsearch(int* x, int y, int size) {
    int a = 0;
    int b = size-1;
    int count = 0;
    while(1==1){
        int m = floor((a+b)/2);
        count ++;
        if(x[m]==y||x[a]==y||x[b]==y){
            return count;
        }else if(x[m]<y && y<x[size-1]){
            a = m + 1;
        }else if(x[m]>y && y>x[0]){
            b = m - 1;
        }else{
            return -1;
        }if(a==m || b==m){
            return -1;
        }
    }
}


int main () {

    int x[] = {22, 25, 37, 42, 56, 56, 60, 69, 73, 75, 94, 109, 129, 132, 134, 148, 160, 168, 168, 169, 172,
177, 235, 238, 240, 263, 272, 274, 291, 303, 305, 309, 310, 311, 312, 317, 327, 332, 336, 341, 347,
358, 359, 373, 387, 389, 392, 404, 425, 428, 431, 438, 444, 481, 490, 491, 496, 503, 506, 511, 521,
554, 554, 555, 559, 565, 572, 580, 587, 587, 617, 642, 643, 660, 681, 684, 697, 712, 726, 726, 739,
757, 761, 775, 790, 826, 828, 832, 853, 865, 886, 886, 888, 901, 918, 937, 945, 952, 971, 974};
    int y = 506;
    int size = sizeof(x)/sizeof(x[0]);

    int examinations = binsearch(x,y,size);
    printf("examinations %d\n ", examinations);

    
    return 0;
}