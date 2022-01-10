#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int isEmpty (const long *start, const long *end);
void push (long **start, long **end, long value);

int isEmpty (const long *start, const long *end){
    if(start==end||start==NULL||end==NULL){
        return 1;
    }
    return 0;

}

void push (long **start, long **end, long value){
    if(isEmpty(*start,*end)){
        *start = (long*)malloc(sizeof(long));
        **start = value;
        *end = *start +1;
    }
    else{
        long len = *end-*start;
        *start = (long*)realloc(*start, (len+1)*sizeof(long));
        **end = value;
        *end = *end+1;
        
    }

}

void printStack(long **start, long **end) {
    printf("Stack --> [ ");
    if (!isEmpty(*start, *end)) {
        for (int i = 0; *start + i < *end; i++) {
            printf("%ld ", (*start)[i]);
        }
    } 
    printf("]\n");
}

int main () {
    printf("Starting...\n");
    long *start = NULL;
    long *stop = NULL;
    printStack(&start, &stop);
    push(&start, &stop, 1L);
    printStack(&start, &stop);
    push(&start, &stop, 2L);
    printStack(&start, &stop);
    push(&start, &stop, 3L);
    printStack(&start, &stop);
    push(&start, &stop, 4L);
    printStack(&start, &stop);
    push(&start, &stop, 5L);
    printStack(&start, &stop);
    
}