#include "FileLister.h"
#include <algorithm>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

FileLister::FileLister(const std::string &directoryPath) : directoryPath(directoryPath) {}

FileLister::~FileLister() {}

std::vector<std::string> FileLister::getMp3Files()
{
    std::vector<std::string> mp3Files;
    try
    {
        for (const auto &entry : fs::directory_iterator(this->directoryPath))
        {
            processEntry(entry, mp3Files);
        }
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Filesystem error: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Standard exception: " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "Unknown error occurred.\n";
    }
    return mp3Files;
}

void FileLister::processEntry(const fs::directory_entry &entry, std::vector<std::string> &mp3Files)
{
    if (entry.is_regular_file())
    {
        std::string filePath = entry.path().string();
        if (isMp3File(filePath))
        {
            mp3Files.push_back(entry.path().filename().string());
        }
    }
}

bool FileLister::isMp3File(const std::string &filePath)
{
    return filePath.size() >= 4 && filePath.substr(filePath.size() - 4) == ".mp3";
}

void FileLister::sortFilesAlphabetically(std::vector<std::string> &fileList)
{
    std::sort(fileList.begin(), fileList.end());
}
