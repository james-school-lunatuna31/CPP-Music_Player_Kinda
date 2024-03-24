#include "MusicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer() : currentState(State::Stopped) {}

MusicPlayer::~MusicPlayer()
{
}

void MusicPlayer::load(const std::string &filePath)
{
    std::cout << "Loaded file: " << filePath << std::endl;
    currentFilePath = filePath;
    currentState = State::Stopped;
}

void MusicPlayer::togglePlayPause()
{
    switch (currentState) // switch is faster than if
    {
    case State::Playing:
        currentState = State::Paused;
        std::cout << "Music paused." << std::endl;
        break;
    case State::Paused:
    case State::Stopped:
        currentState = State::Playing;
        std::cout << "Music playing." << std::endl;
        break;
    }
}

void MusicPlayer::restart()
{
    if (!currentFilePath.empty())
    {
        currentState = State::Playing;
        std::cout << "Music restarted." << std::endl;
    }
}

void MusicPlayer::stop()
{
    currentState = State::Stopped;
    std::cout << "Music stopped." << std::endl;
}

MusicPlayer::State MusicPlayer::getState() const
{
    return currentState;
}

std::string MusicPlayer::getCurrentFileName() const
{
    return currentFilePath;
}
