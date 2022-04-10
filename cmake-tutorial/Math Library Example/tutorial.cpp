#ifdef USE_MYMATH
    #include "MathFunctions.h"
#endif
#include <cmath>
#include <iostream>
#include <string>
#include "TutorialConfig.h"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
				<< Tutorial_VERSION_MINOR << std::endl;

		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		return 1;
	}

	// convert input to double
	const double input = std::stod(argv[1]);

    // calculate square root
    #ifdef USE_MYMATH
        const double outputValue = mysqrt(input);
    #else
        const double outputValue = mysqrt(input);
    #endif

	std::cout << "The square root of " << input << " is " << outputValue
			<< std::endl;
	return 0;
}