#ifndef VIDEO
#define VIDEO//header guard 
#include <iostream>
#include "media.h"// child of media

class Video : public Media{// declaring video as child of media
    public:
    Video(); 
     Video( int rating, char* publisher, char* title, int year);  // Parameterized constructor
    ~Video(); //destructor
    //declaration of variables 
    int rating;
    char* publisher; 
    char* title;
    int year;
    
    
    //virtual variables to make it so that the parent is able to print out these variabless

   
    virtual char* gettitle();
    virtual int getInt();  
    virtual char* getpublisher();
    virtual int getrating();
    virtual void print();

};


#endif
