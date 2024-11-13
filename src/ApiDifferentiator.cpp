#include "APIDifferentiator.h"
#include "FileHandler.h"
#include <iostream>
#include <fstream>

APIDifferentiator::APIDifferentiator(const std::string& osAPIFilePath) {
    loadOSAPIList(osAPIFilePath);
}

void APIDifferentiator::loadOSAPIList(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string apiName;
    while (file >> apiName) {
        osAPIs.insert(apiName);
    }
}

void APIDifferentiator::processFile(const std::string& sourceFilePath) {
    // Use Clang tooling here to parse the source file and retrieve API function names.
    // For each API, check if it’s in osAPIs or not.
    analyzeAPIUsage();
}

void APIDifferentiator::analyzeAPIUsage() {
    // For each API, check against OS API list
    for (const auto& apiName : userDefinedAPIs) {
        if (isOSAPI(apiName)) {
            apiClassification[apiName] = "OS_API";
        } else if (askUserForAmbiguity(apiName)) {
            apiClassification[apiName] = "Ambiguous";
        } else {
            apiClassification[apiName] = "User_Defined";
        }
    }
}

bool APIDifferentiator::isOSAPI(const std::string& apiName) {
    return osAPIs.find(apiName) != osAPIs.end();
}

bool APIDifferentiator::askUserForAmbiguity(const std::string& apiName) {
    char response;
    std::cout << "Ambiguous API detected: " << apiName << ". Is this OS-specific? (y/n): ";
    std::cin >> response;
    return response == 'y' || response == 'Y';
}

void APIDifferentiator::writeResults(const std::string& outputPath) {
    FileHandler fileHandler;
    fileHandler.writeOutput(outputPath, apiClassification);
}
