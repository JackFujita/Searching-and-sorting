#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int insertionsort(int* x, int size, int (*compare)(int a, int b));
int ascending (int a, int b);
int descending (int a, int b);
void swap (int* num1, int* num2);

int insertionsort(int* x, int size, int (*compare)(int a, int b)){
    int count = 0;
    int i,j,k;
    for(i=1; i<size; i++){
        count++;
        j=i;
        while(j>0&&compare(x[j-1],x[j])==true){
            bool comp = compare(x[j-1],x[j]);
            if(comp==true){
                swap(&x[j-1],&x[j]);
            }
            j--;
            if(j>0){
                count++;
            }
        }
    }
    return count;
}

int ascending (int a, int b){
    //are the elements out of order?
    if(a>b){
        return true;
    }
    else{
        return false;
    }

}

int descending (int a, int b){
    //are the elements out of order?
    if(a<b){
        return true;
    }
    else{
        return false;
    }

}

void swap (int* num1, int* num2){
    int x = *num1;
    *num1 = *num2;
    *num2 = x;
}


int main () {
    int arr[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};

    int size = sizeof(arr)/sizeof(arr[0]);

    int examinations = insertionsort(arr, size, &ascending);

    printf("examinations = %d \n", examinations);


    for(int i=0; i<size; i++){
        printf("%d, ", arr[i]);
    }


    return 0;
}