#ifndef MOVIE // header guards. Helps names and definitions not get mixed up 
#define MOVIE

#include <iostream>
#include "media.h"  

class Movie : public Media { // child function
public:
    Movie(); 
    Movie(char* director, int duration, int rating, char* title, int year);  // Parameterized constructor
    ~Movie();  // destructor 
    
    //defining variables used by chil d

    char* director;
    int duration;
    int rating;
    char* title;
    int year;
    
    //making methods for the child
    //needs to be virtual 

     char* getdirector();
     char* gettitle();
     int getInt();  
     int getrating();
     int getduration();
     void print();
};

#endif
