#include "APIDifferentiator.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source_file.cpp>" << std::endl;
        return 1;
    }

    APIDifferentiator differentiator("includes/OS_API_List.txt");
    differentiator.processFile(argv[1]);
    differentiator.writeResults("output/api_differentiation_result.txt");

    std::cout << "API differentiation complete. Results written to output/api_differentiation_result.txt." << std::endl;
    return 0;
}
