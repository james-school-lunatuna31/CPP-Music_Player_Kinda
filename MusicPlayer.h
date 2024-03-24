#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <string>

class MusicPlayer
{
public:
    enum class State // Using an enum makes things faster
    {
        Playing,
        Paused,
        Stopped
    };

    MusicPlayer();
    ~MusicPlayer();
    void load(const std::string &filePath);
    void togglePlayPause();
    void restart();
    void stop();
    State getState() const;
    std::string getCurrentFileName() const;

private:
    std::string currentFilePath;
    State currentState;
};

#endif // MUSICPLAYER_H
