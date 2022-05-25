#include <stdio.h>
#include <stdbool.h>

// aligned to 4 bytes
struct TrivialStruct {
    char character; // 1 byte
    // 3 bytes of padding to align the int
    int integer; // 4 bytes
};

union TrivialUnion {
    char character; //1 byte
    int integer; // 4 bytes
};

/*
let mut guy: Option<i32>;
*/
template<typename T>
struct Option {
    bool is_set; // 1 byte
    // padding for T if any
    T value; // however big T is
};

/*
enum EnumGuy {
    A(i64),
    B(Option<i32>)
}

let guy = EnumGuy::A(10);
match guy {
    EnumGuy::A(a) => {} // checks if variant is 0
    EnumGuy::B(b) => {} // checks if variant is 1
}

// in C
EnumGuy guy = {
    .variant = 0, // EnumGuy::A,
    .a = 10,
};
switch guy.variant {
    case 0: { /* do things with a * } break;
    case 1: { /* do things with b * } break;
}
*/
struct EnumGuy {
    int variant; // 0 if A, 1 if B
    union {
        int a;          // 4 bytes flat
        Option<int> b;  // 8 bytes flat
    }; // a and b share the same memory
};

template<typename T>
struct Vec {
    T *memory; // 8 bytes; points to where the memory for the elements is
    int len; // 4 bytes; how many elements there are right now
    int capacity; // 4 bytes; how many elements the current memory can fit
};

int main() {
    // Building blocks:
    int integer;                    // 4 bytes flat buffer | abcd
    float real;                     // 4 bytes flat buffer | abcd
    bool logical;                   // 1 byte flat buffer  | a
    char character_or_byte;         // 1 byte flat buffer
    TrivialStruct a_struct;         // 8 bytes flat buffer
    TrivialUnion a_union;           // 4 bytes flat buffer

    //a_union.integer = 0xafafafaf;
    //printf("%x   %x\n", a_union.integer, (int)a_union.character);
}