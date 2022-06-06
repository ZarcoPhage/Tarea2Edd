#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

using namespace std;

class Keyboard {
    public:
        bool processFile(string inputFile, string outputFile);
        string processLine(string line);
};

#endif
