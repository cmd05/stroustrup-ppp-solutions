/* Find a pair of values so that the pre-condition of this version of
area holds, but the post-condition doesn't. */

// area(INT_MAX, INT_MAX) will not throw on precondition check but will for post condition check due to integer overflow causing wrapping of values (i.e area becomes -ve)