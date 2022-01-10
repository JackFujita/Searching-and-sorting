
all: buildall runall clean

buildall:
	gcc binarysearch.c -o binarysearch
	gcc bubblesort.c -o bubblesort
	gcc dynamicallyallocatedstacks.c -o das
	gcc insertionsort.c -o insertionsort
	gcc shellsort.c -o shellsort -lm

runall:
	./binarysearch
	./bubblesort
	./das
	./insertionsort
	./shellsort

clean:
	rm -f *.o
