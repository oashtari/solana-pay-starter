#include <stdio.h>

// TODO: Rust Options in C

struct String {
    char *buffer;
    size_t length;
};

// fn make_string(length: usize) -> String {
struct String make_string(size_t length) {
    /*
    let result = String {
        buffer = allocate_memory(length),
        length = length
    };
    */
    struct String result;
    result.buffer = malloc(length);
    result.length = length;
    return result;
}

void free_string(struct String string) {
    free(string.buffer);
}



// &str
struct str {
    char *buffer;
    size_t length;
};

struct str make_str(String string) {
    struct str result;
    result = string.buffer;
    result = string.length;
    return result;
}








void foo() {
    int bar = 123;
}

int main() {
    int number = 0x0a0b0c0d; // 4 bytes, lives in memory
    char *number_ptr = (char*)&number; // address of `number`
    char **number_ptr_ptr = &number_ptr;
    
    // let number_ptr: &char;
    
    printf("Size of number in memory:     %zu\n", sizeof(number));
    printf("Size of number_ptr in memory: %zu\n", sizeof(number_ptr));
    printf("Number:                       %d\n", number);
    printf("Address of the number:        %p\n", number_ptr);
    printf("Address of the number_ptr:    %p\n", number_ptr_ptr);
    printf("Bytes number is composed of:  %x %x %x %x\n",
        (int)number_ptr[0], (int)number_ptr[1], (int)number_ptr[2],
        (int)number_ptr[3]);

    // 2^32 == 4 GB
    // 2^64 == a lot GB (pointers are 8 bytes or 64 bits)

    foo();
    foo();

    /*

    The stack:
        - slice of memory preallocated at program startup
        - the stack pointer moves back and forth as you call and exit
            functions by the size of that function's local (stack) variables
        - limitations:
            - limited size, if you try to get too much space you get a
                stack overflow
            - generally everything has to be fixed size known at compile
                time as opposed to run time

    */
    
    return 0;
}


// https://godbolt.org/