#include "MusicPlayer.h"
#include "FileLister.h"
#include "UserInterface.h"
#include <iostream>
#include <filesystem>

int main()
{
    std::string directoryPath = std::filesystem::current_path().string();
    UserInterface ui(directoryPath);

    try
    {
        ui.displayMainMenu();
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred." << std::endl;
        return 2;
    }

    return 0;
}
