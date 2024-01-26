#include <iostream>
#include <math.h>
#include <errno.h>
 
void show_errno()
{
    const char *err_info = "unknown error";
    
    switch (errno) {
    case EDOM:
        err_info = "domain error";
        break;
    case EILSEQ:
        err_info = "illegal sequence";
        break;
    case ERANGE:
        err_info = "range error";
        break;
    case 0:
        err_info = "no error";
    }

    std::cout << err_info << " occured\n";
}
 
int main()
{
    errno = 0;
    const double not_a_number = std::log(-1.0);
    std::cout << not_a_number << '\n';

    errno = 0;
    1.0/0.0;
    show_errno();
 
    errno = 0;
    acos(+1.1);
    show_errno();
 
    errno = 0;
    log(0.0);
    show_errno();
 
    errno = 0;
    sin(0.0);
    show_errno();
}