/* 
2.76 The library function calloc has the following declaration: 

    void *calloc(size_t nmemb, size_t size);

According to the library documentation, "The calloc function allocates memory for an array of nmemb elements of size bytes each. The
memory is set to zero. If nmemb or size is zero, then calloc returns NULL." Write an implementation of calloc that performs the
allocation by a call to malloc and sets the memory to zero via memset. Your code should not have any vulnerabilities due to arithmetic
overflow, and it should work correctly regardless of the number of bits used to represent data of type size_t.

As a reference, function malloc and memset have the following declarations:
    void *malloc(size_t size);
    void *memset(void *s, int c, size_t n);
*/
#include <stdlib.h>
#include <stdio.h>

void* alt_calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t buffer_size = nmemb * size;

    if (buffer_size/nmemb == size) {
        void* pointer = malloc(buffer_size);
        memset(pointer, 0, buffer_size);
        return pointer;
    }

    return NULL;
}

/* 
Because calloc returns NULL when nmemb or size is zero, we can test input at the start of the function and return NULL in those cases.
Malloc functions allocates a block of memory with the specified size. We need to allocate enough memory for an array of nmemb elements of 
size bytes each. Therefore we create buffer_size = nmemb * size. We can create a conditional test for x = a * b overflow like x / a == b 
or in our case: buffer_size/nmemb == size. We then call malloc to return us a pointer to the beginning of allocated memory. 
Memset functions starts at location 'void *s' and sets memory to 'int c' value for 'size_t n' places. In our case, we are filling memory with 
zeroes for buffer_size places.
At the end we either return NULL if overflow happened, or pointer to memory location. 
*/