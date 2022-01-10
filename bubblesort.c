#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size);

int bubblesort(int* x, int size){
    int n = size;
    int i = 0;
    int counter = 0;
    for(i = 0; i < n; ++i){
        int a = 0;
        int b = 1;
        while(b<n){
            if(x[a]>x[b]){
                int v1 = x[a];
                int v2 = x[b];
                x[a] = v2;
                x[b] = v1;
                ++counter;
            }
            ++a, ++b;
        }
    }

    return counter;

}

int main () {
    int x[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};

    int size = sizeof(x)/sizeof(x[0]);

    int operations = bubblesort(x, size);
    
    printf("array = {");
    for(int i = 0; i<size; ++i){
        printf("%d, ", x[i]);
    }
    printf("}\n");

    printf("counter = %d\n", operations);
    return 0;
}