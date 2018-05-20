#ifndef HANDLEINPUT_H
#define HANDLEINPUT_H


class HandleInput
{
public:
    //fungsi untuk special key seperti arrow, f1, home ,dll.
    static void keySpecial(int key,int x,int y);
    static void keySpecialUp(int key,int x,int y);
    //fungsi untuk normal key  seperti a,b,enter , dll.
    static void keyboardKey(unsigned char key,int x,int y);
    static void keyboardKeyUp(unsigned char key,int x,int y);
    //fungsi untuk pembuatan instance handleinput
    static HandleInput *Instance()
    {
        if(sInstance == 0)
            sInstance = new HandleInput;
        return sInstance;
    }
public:
    static HandleInput *sInstance;
    bool* keySpecialState = new bool[246];
    bool* keyStates = new bool[256];
};

#endif // HANDLEINPUT_H
