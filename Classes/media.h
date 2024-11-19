#ifndef MEDIA
#define MEDIA

#include <iostream>
#include <cstring>

class Media {
public:
    Media();  
    char* title;
    int year;
    Media(char* title, int year); 

    virtual char* gettitle();  
    virtual int getInt();      
    virtual void print();      

};

#endif
