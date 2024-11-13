#ifndef APIDIFFERENTIATOR_H
#define APIDIFFERENTIATOR_H

#include <string>
#include <vector>
#include <set>
#include <map>

class APIDifferentiator {
public:
    APIDifferentiator(const std::string& osAPIFilePath);
    void processFile(const std::string& sourceFilePath);
    void writeResults(const std::string& outputPath);

private:
    void loadOSAPIList(const std::string& filePath);
    void analyzeAPIUsage();
    bool isOSAPI(const std::string& apiName);
    bool askUserForAmbiguity(const std::string& apiName);

    std::set<std::string> osAPIs;
    std::vector<std::string> userDefinedAPIs;
    std::map<std::string, std::string> apiClassification;
};

#endif // APIDIFFERENTIATOR_H
