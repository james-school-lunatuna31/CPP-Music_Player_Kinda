#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "MusicPlayer.h"
#include "FileLister.h"
#include <string>
#include <vector>

class UserInterface
{
public:
    UserInterface(const std::string &directoryPath);

    ~UserInterface() = default;

    void displayFileList(const std::vector<std::string> &fileList);

    void processFileSelection(int choice, const std::vector<std::string> &fileList);

    void displayMusicControls();

    void displayMainMenu();

    void displayMusicPlayerMenu();

    int getUserChoice(int min, int max);

    void processControlSelection(int choice);

    void updateDisplay(const MusicPlayer &player);

private:
    void clearScreen();

    FileLister fileLister;
    MusicPlayer musicPlayer;
    void displayPlayerState(const MusicPlayer::State &state, const std::string &fileName);
};

#endif // USERINTERFACE_H
