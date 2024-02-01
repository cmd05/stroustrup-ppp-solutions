#include <stdio.h>

// ==> function prototyping

void f(int x); // prototyped (argument is still not type checked)
int h(); // not prototyped
// int h(void); // prototyped (take no arguments)

f(); // error
f("string"); // ok
f(1); // ofcourse ok
f(1,2); // error
h(); // ofcourse ok
h(1,2); // ok
h("string"); // ok
   
// ==> interopability: using c++ lib in c or vice-versa

// cpp: calling C function from C++:
extern "C" double sqrt(double);    // link as a C function
void my_c_plus_plus_fct()
{
          double sr = sqrt(2);
}

// c: call C++ function from C:
extern "C" int call_f(S* p, int i)
{
          return p->f(i);
}

// c: call C++ function from C:
int call_f(S* p, int i);
struct S* make_S(int,const char*); 
void my_c_fct(int i)
{
          struct S* p = make_S(x, "foo");
          int x = call_f(p,i);
          // ...
} 

// ==> OOP principles in C

// 1. Typedef to kind of Shape

struct Shape1 {
          enum Kind { circle, rectangle } kind;
};
void draw(struct Shape1* p)
{
          switch (p->kind) {
          case circle:
                    // draw as circle
                    break;
          case rectangle:
                    // draw as rectangle
                    break;
          }
}

// 2. Pointers to functions

typedef void (*Pfct0)(struct Shape2*); 
typedef void (*Pfct1int)(struct Shape2*,int);
struct Shape2 {
          Pfct0 draw;
          Pfct1int rotate;
};

void draw(struct Shape2* p)
{
          (p->draw)(p);
}
void rotate(struct Shape2* p, int d)
{
          (p->rotate)(p,d);
}

int f(struct Shape2* pp)
{
          draw(pp);
}

// ==> struct tag namespace

struct pair { int x,y; };
pair p1;                      // error: no identifier pair in scope 
struct pair p2;           // OK 
int pair = 7;             // OK: the struct tag pair is not in scope 
struct pair p3;       // OK: the struct tag pair is not hidden by the int 
pair = 8;                 // OK: pair refers to the int 

// alternative: using typedefs
typedef struct { int x,y; } pair;
pair p1 = { 1, 2 };

// In C, names of nested structs are placed in the same scope as the struct in 
// which they are nested. For example:

struct S {
        struct T { // avoid nested structs in C 
            //...
        };
        // ...
};
struct T x;     // OK in C (not in C++) 

// In C, for any type T, void* to T* conversion is implicit (C++ requires explicit casting)
// T* to void* is safe and valid in both C and C++

// ==> enums

enum color { red, blue, green };
int x = green;               // OK in C and C++ 
enum color col = 7;    // OK in C; error in C++ 

enum color x = blue;
++x;           // x becomes green; error in C++ 
++x;           // x becomes 3; error in C++ 

color c2 = blue;                       // error in C: color not in scope; OK in C++ 
enum color c3 = red;             // OK 

// ==> free store

void* malloc(size_t sz);                   /* allocate sz bytes */
void free(void* p);                          /* deallocate the memory pointed to by p */
void* calloc(size_t n, size_t sz);     /* allocate n*sz bytes initialized to 0 */
void* realloc(void* p, size_t sz);   /* reallocate the memory pointed to by p to a space of size sz */
// size_t is unsigned type

struct Pair {
          const char* p;
          int val;
};
struct Pair p2 = {"apple",78};
struct Pair* pp = (struct Pair*) malloc(sizeof(Pair));       /* allocate */
pp->p = "pear";             /* initialize */
pp->val = 42;

// not allowed in C
*pp = {"pear", 42};        /* error: not C or C++98 */

// ==> C style strings or just C strings

// We can compare strings. The equality operator (==) compares pointer values; 
// the standard library function strcmp() compares C-style string values

const char* s1 = "asdf"; // strlen(s1) == 4; "asdf" takes 5 bytes of memory as it includes terminating-zero
const char* s2 = "asdf";
if (s1==s2) {   /* do s1 and s2 point to the same array? */
                         /* (typically not what you want) */
}

if (strcmp(s1,s2)==0) {    /* do s1 and s2 hold the same characters? */
}

int lgt = strlen(s1); // does not include terminating '\0'

// We can copy one C-style string (including the terminating 0) into another
// It is your job to be sure that the target string (array) has enough space to hold the 
// characters from the source. 
strcpy(s1,s2); // s2 into s1

// strncpy, strncat etc. do not include terminating-zero for a c-string `s2` (zero-terminated) if n < strlen(s2) + 1
// used to copy substrings (check sizes of source and destination)

// This is legal in C but not in C++. In C++, a string literal is a constant, an im-
// mutable value

char* p = "asdf";
p[2] = 'x';

// The C strchr() has a similar but even harder-to-spot problem. Consider:

// this code runs in c
char* strchr(const char* s, int c);   /* find c in constant s (not C++) */
const char aa[ ]  = "asdf";                /* aa is an array of constants */
char* q = strchr(aa, 'd');                     /* finds 'd' */
*q = 'x';                                                 /* change 'd' in aa to 'x' */

// Again, this is illegal in C and C++, but C compilers can't catch it. Sometimes this 
// is referred to as transmutation: it turns consts into non-consts, violating reasonable 
// assumptions about code

// ==> Byte Operations

/* copy n bytes from s2 to s1 (like strcpy): */
void* memcpy(void* s1, const void* s2, size_t n); 
/* copy n bytes from s2 to s1 ( [s1:s1+n) may overlap with [s2:s2+n) ): */
void* memmove(void* s1, const void* s2, size_t n);
/* compare n bytes from s2 to s1 (like strcmp): */
int memcmp(const void* s1, const void* s2, size_t n);
/* find c (converted to an unsigned char) in the first n bytes of s: */
void* memchr(const void* s, int c, size_t n);
/* copy c (converted to an unsigned char)
          into each of the first n bytes that s points to: */
void* memset(void* s, int c, size_t n);

void f(char c, ...) { // take a char, "and optionally more arguments"

}

// ==> Output

void f1(double d, char* s, int i, char ch)
{
          printf("double %g string %s int %d char %c\n", d, s, i, ch);
}

// ==> Input

int scanf(const char* format, ...);    /* read from stdin using a format */ // UNSAFE: scanf()
int getchar(void);                                   /* get a char from stdin */
int getc(FILE* stream);                       /* get a char from stream */
char* gets(char* s);                            /* get characters from stdin */ // UNSAFE: gets()

// BUFFER OVERFLOW
char a[12];
gets(a);           /* read into char array pointed to by a until a ’\n’ is input */

// safer
char buf[20];
scanf("%19s",buf);

// ==> FILE I/O

FILE *fopen(const char* filename, const char* mode); 
int fclose(FILE *stream)

void f(const char* fn, const char* fn2)
{
    FILE* fi = fopen(fn, "r");              /* open fn for reading */ 
    FILE* fo = fopen(fn2, "w");             /* open fn2 for writing */

    if (fi == 0) error("failed to open input file");
    if (fo == 0) error("failed to open output file");

    /* read from file using stdio input functions, e.g., getc() */
    /* write to file using stdio output functions, e.g., fprintf() */

    fclose(fo); 
    fclose(fi);
}


// ==> Constants

const int max = 30;
const int x;      /* const not initialized: OK in C (error in C++) */
void f(int v)
{
          int a1[max];   /* error: array bound not a constant (OK in C++) */
                                   /* (max is not allowed in a constant expression!) */
          int a2[x];       /* error: array bound not a constant */
          switch (v) {
          case 1:
                    /* . . . */
                    break;
          case max:     /* error: case label not a constant (OK in C++) */
                    /* . . . */
                    break;
          }
}

// ==> Macros

#define ALLOC(T,n) ((T*)malloc(sizeof(T)*n))
                            // avoid likely errors such as:
                            // double* p = malloc(sizeof(int)*10); // (using sizeof(int) for double*)

// Tip: Don’t pass an argument with a side-effect to a macro

#define ALLOC(T,n) (error_var = (T*)malloc(sizeof(T)*n), \
                                        (error_var==0)\
                                        ?(error("memory allocation failure"),0)\
                                        :error_var)

// Syntax macros: strongly recommended against

// Conditional compilation

#define WINDOWS

#ifdef WINDOWS
          #include "my_windows_header.h"
#else
          #include "my_linux_header.h"
#endif

// The #ifdef WINDOWS test doesn’t care what WINDOWS is defined to be; it just 
// tests that it is defined

#ifdef __cplusplus
          // in C++
#else
          /* in C */
#endif

// an include guard, is commonly used to prevent a 
// header file from being #included twice

/* my_windows_header.h: */
#ifndef MY_WINDOWS_HEADER
#define MY_WINDOWS_HEADER
          /* here is the header information */
#endif

// ==> Freeing resources "owned" inside struct

typedef struct Person
{
    char * firstname , *last surName;
}   Person;

Person *ptrobj = malloc(sizeof(Person)); // memory allocation for struct
ptrobj->firstname = malloc(n); // memory allocation for firstname
ptrobj->surName = malloc(m); // memory allocation for surName

// ...

free(ptrobj->surName); // free members first then object
free(ptrobj->firstname);
free(ptrobj);
