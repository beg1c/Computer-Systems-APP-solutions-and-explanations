/* 
2.72 You are given the task of writing a function that will copy an integer val into a buffer buf, but it should do so only if enough space is available
in the buffer. Here is the code you write:
    
    Copy integer into buffer if space is available
    WARNING: The following code is buggy

    void copy_int(int val, void *buf, int maxbytes) {
        if (maxbytes-sizeof(val) >= 0)
            memcpy(buf, (void *) &val, sizeof(val));
    }

This code makes use of the library function memcpy. Although its use is a bit artificial here, where we simply want to copy an int, it illustrates an 
approach commonly used to copy larger data structures. You carefully test the code and discover that it always copies the value to the buffer, even
when maxbytes is to small.

A. Explain why the condittional test in the code always succeeds. Hint: The sizeof operator returns a value of type size_t.
B. Show how you can rewrite the conditional test to make it work properly. 
*/
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes >= (int) sizeof(val)) {
        memcpy(buf, (void *) &val, sizeof(val));
    }
}

/* 
A. The sizeof operator returns a value of type size_t, which is unsigned. maxbytes-sizeof will result in a size_t value, which if unsigned, 
is always >= 0.

B. We can compare maxbytes >= sizeof(val), or even better we can cast sizeof(val) to integer. That way if someone inputs maxbytes as negative number,
test won't succeed. If we only used maxbytes >= sizeof(val) and someone set maxbytes to -1, it would evaluate to UNSIGNED_MAX >= sizeof(val).
*/