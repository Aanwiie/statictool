#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <map>

class FileHandler {
public:
    void writeOutput(const std::string& filePath, const std::map<std::string, std::string>& apiClassification);
};

#endif // FILEHANDLER_H
