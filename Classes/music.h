#ifndef MUSIC
#define MUSIC// header guards 
#include <iostream>
#include "media.h"//child of media

class Music : public Media{
    public:
    Music();
     Music(char* artist, int duration, char* publisher, char* title, int year);  // Parameterized constructor
    ~Music();  // destructor
    
    //defining variables
     char* artist;
    int duration;
    char* publisher; 
    char* title;
    int year;

    virtual char* getartist();
    virtual char* gettitle();
    virtual int getInt();  
    virtual char* getpublisher();
    virtual int getduration();
    virtual void print();

};


#endif
