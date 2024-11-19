#include <iostream>
#include <cstring>  
#include "movie.h"
using namespace std;


Movie::Movie() {
    director = new char[100];  
    title = new char[100];      
    rating = 0;
    duration = 0;
    year = 0;
}

Movie::Movie(char* newdirector, int newduration, int newrating, char* newtitle, int newyear) {
    director = new char[100];  
    strcpy(director, newdirector);  

    title = new char[100];  
    strcpy(title, newtitle);  

    year = newyear;   
    rating = newrating; 
    duration = newduration;  
}

Movie::~Movie() {
    delete[] director;
    delete[] title;
    
}


char* Movie::getdirector() {
    return director;
}


int Movie::getrating() {
    return rating;
}
char* Movie::gettitle() {
    return title;  
}


int Movie::getInt() {
    return year;  
}



int Movie::getduration() {
    return duration;
}



void Movie::print() {
    Media::print();  
    cout << "Director: " << director << endl;
    cout << "Rating: " << rating << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Year: " << year << endl;
}
