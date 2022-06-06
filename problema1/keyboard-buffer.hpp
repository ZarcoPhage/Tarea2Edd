#ifndef KEYBOARD_BUFFER_HPP
#define KEYBOARD_BUFFER_HPP

using namespace std;

class KeyboardBufferNode {
    public:
        char value;    
        KeyboardBufferNode *previous;
        KeyboardBufferNode *next;
        KeyboardBufferNode(char value);
};

class KeyboardBuffer {
    private:
        unsigned int len;
        KeyboardBufferNode *head;
        KeyboardBufferNode *tail;
        KeyboardBufferNode *cursor;
        void init();
    public:
        KeyboardBuffer();
        ~KeyboardBuffer();
        void clean();
        void append(char c);
        void home();
        void end();
        void left();
        void right();
        string str();
};

#endif
