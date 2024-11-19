#include <iostream>
#include <cstring>  
#include "movie.h" // access to movie.h variables 
using namespace std;


Movie::Movie() { //implementing movie variables 
    director = new char[100];  
    title = new char[100];      
    rating = 0;
    duration = 0;
    year = 0;
}

Movie::Movie(char* newdirector, int newduration, int newrating, char* newtitle, int newyear) {
    director = new char[100]; //since this is a char pointer we are making sure we store the memory properly  
    strcpy(director, newdirector);  

    title = new char[100];  
    strcpy(title, newtitle);  

    year = newyear;   
    rating = newrating; 
    duration = newduration;  
}

Movie::~Movie() { //Destructor to delete any memory 
    delete[] director;
    delete[] title;
    
}

//getting the variable returns 
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


//use parent print function but making it different by using child variables 
void Movie::print() {
    Media::print();  
    cout << "Director: " << director << endl;
    cout << "Rating: " << rating << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Year: " << year << endl;
}

