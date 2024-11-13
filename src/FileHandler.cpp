#include "FileHandler.h"
#include <fstream>

void FileHandler::writeOutput(const std::string& filePath, const std::map<std::string, std::string>& apiClassification) {
    std::ofstream file(filePath);
    file << "OS API's\tUser-Defined API's\tAmbiguous API's\n";

    for (const auto& [apiName, category] : apiClassification) {
        if (category == "OS_API") {
            file << apiName << "\t\t\t\n";
        } else if (category == "User_Defined") {
            file << "\t" << apiName << "\t\n";
        } else if (category == "Ambiguous") {
            file << "\t\t" << apiName << "\n";
        }
    }
}
