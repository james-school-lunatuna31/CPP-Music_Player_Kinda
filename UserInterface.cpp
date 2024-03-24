#include "UserInterface.h"
#include "FileLister.h"
#include "MusicPlayer.h"
#include <iostream>
#include <limits>

UserInterface::UserInterface(const std::string &directoryPath) : fileLister(directoryPath), musicPlayer() {}

void UserInterface::displayMainMenu()
{
    auto mp3Files = fileLister.getMp3Files();
    fileLister.sortFilesAlphabetically(mp3Files);

    std::cout << "\nMP3 Files in Directory:\n";
    for (size_t i = 0; i < mp3Files.size(); ++i)
    {
        std::cout << i + 1 << ". " << mp3Files[i] << "\n";
    }
    std::cout << mp3Files.size() + 1 << ". Quit application\n";

    int choice = getUserChoice(1, mp3Files.size() + 1);

    if (choice == mp3Files.size() + 1)
    {
        exit(0);
    }
    else
    {
        musicPlayer.load(mp3Files[choice - 1]);
        std::cout << "\n-----\n";
        displayMusicPlayerMenu();
    }
}

void UserInterface::displayMusicPlayerMenu()
{
    bool back = false;
    while (!back)
    {
        try
        {
            std::cout << "\nNow Playing: " << musicPlayer.getCurrentFileName() << "\n";
            std::cout << (musicPlayer.getState() == MusicPlayer::State::Playing ? "Playing" : "Paused") << "\n\n";
            std::cout << "1) " << (musicPlayer.getState() == MusicPlayer::State::Playing ? "Pause" : "Play") << "\n";
            std::cout << "2) Restart\n";
            std::cout << "3) Go Back\n";
            std::cout << "4) Quit\n";

            int choice = getUserChoice(1, 4);

            switch (choice)
            {
            case 1:
                musicPlayer.togglePlayPause();
                break;
            case 2:
                musicPlayer.restart();
                break;
            case 3:
                back = true;
                break;
            case 4:
                exit(0);
                break;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "An error occurred: " << e.what() << std::endl;
            back = true; // Optionally return to the previous menu or handle the error differently
        }
    }
    std::cout << "\n-----\n";
    displayMainMenu();
}

int UserInterface::getUserChoice(int min, int max)
{
    int choice;
    std::cout << "Enter your choice: ";
    while (!(std::cin >> choice) || choice < min || choice > max)
    {
        std::cout << "Invalid choice. Please enter a number between " << min << " and " << max << ": ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;
}
