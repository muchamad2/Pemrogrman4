#ifndef HANDLEINPUT_H
#define HANDLEINPUT_H


class HandleInput
{
    public:
        static void keySpecial(int key,int x,int y);
        static void keySpecialUp(int key,int x,int y);
        static HandleInput *Instance(){
            if(sInstance == 0)
                sInstance = new HandleInput;
            return sInstance;
        }
    public:
        static HandleInput *sInstance;
        bool* keySpecialState = new bool[246];
};

#endif // HANDLEINPUT_H
