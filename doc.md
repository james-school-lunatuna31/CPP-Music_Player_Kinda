Tasks:

1. Condcut research into C++

I watched probably a hundred videos on how to do basic C++ stuff (links below). I
also spent an egregious amount of time trying to get SFML to work with this so I could
actually play audio.....sad face :(

Time spent: 10 hours

2. Development (Planning)

After I figured out that I wanted to make a music player and watching the videos, I spent
a lot of time reading about structure and since I was very familiar with OOP, I wanted to make it as
easy to understand each functionality seperately. This is why I have a file lister rather than just
doing that function inside the other classes. I mainly did this for education, but it was nice having a breakdown. I realized that I wanted to have the following functions
List / Access File system
Receive and handle user input
Play (sort of) Music
Driver

This naturally led to the development of these classes later on.

Time Spent: 6 hours (mainly in studying my old projects)

3. Development

The development of this project was quite difficult and I went through several versions, but I settled on the bare minimum functionality that a music player should have. I inititally started with things much more bloated, but after hacking out everything but the minimalist version, I was left with this.

Time Spent: 5 hours

4. ...

This is when I deceided to try and have it actually play music. This is when this project exploded.
I started with SFML a pretty standard library. When I couldn't get it installed, I went to CMake and couldn't figure that out. Then it led into my project not compiling at all. At the end of the day, I had to get help to just have a basic script to compile it. That script was

> g++.exe -fdiagnostics-color=always -g "C:\Users\james\OneDrive\encrypted storage\APCS-CPP\CPP-Music\main.cpp" "C:\Users\james\OneDrive\encrypted storage\APCS-CPP\CPP-Music\UserInterface.cpp" "C:\Users\james\OneDrive\encrypted storage\APCS-CPP\CPP-Music\MusicPlayer.cpp" "C:\Users\james\OneDrive\encrypted storage\APCS-CPP\CPP-Music\FileLister.cpp" -o "C:\Users\james\OneDrive\encrypted storage\APCS-CPP\CPP-Music\main.exe"

I admit, this is not as bad as the SFML stuff, but learning how to compile and do anything...man

Time spent: 15 hours (I spent an entire day on this).
