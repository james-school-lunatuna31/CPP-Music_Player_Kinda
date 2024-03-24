#ifndef FILELISTER_H
#define FILELISTER_H

#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class FileLister
{
public:
    FileLister(const std::string &directoryPath);
    ~FileLister();
    std::vector<std::string> getMp3Files();
    void sortFilesAlphabetically(std::vector<std::string> &fileList);
    void processEntry(const fs::directory_entry &entry, std::vector<std::string> &mp3Files);
    bool isMp3File(const std::string &filePath);

private:
    std::string directoryPath;
};

#endif // FILELISTER_H
