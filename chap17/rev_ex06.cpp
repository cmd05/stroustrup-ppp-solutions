/* This  chapter  does  not  say  what  happens  when  you  run  out  of  memory  
using new. That's called memory exhaustion. Find out what happens. You have 
two obvious alternatives: look for documentation, or write a program with 
an  infinite  loop  that  allocates  but  never  deallocates.  Try  both.  Approxi-
mately how much memory did you manage to allocate before failing? */

#include <iostream>

// do not recommend running this if you have important stuff open
// music playing started stuttering for a while :(
int main() {
    int used = 0;
    while(true) {
        int* p = new int[1000];
        used += 4; // can check with breakpoint
    }

    // Operating system keeps track of used memory via virtual memory
    // Program is terminated by operating system
}