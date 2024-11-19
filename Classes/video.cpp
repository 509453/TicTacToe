#include <iostream>
#include <cstring>  
#include "video.h"
using namespace std;

Video::Video() {
    title = new char[100];      
    publisher = new char[100]; 
    rating = 0; 
    year = 0;
     
}

Video::Video(int newrating, char* newpublisher, char* newtitle, int newyear) {//constructor with parameters
    title = new char[100];  
    strcpy(title, newtitle); 
    publisher = new char[100];  
    strcpy(publisher, newpublisher); //storing memory in new string 

    rating = newrating;  
    year = newyear;      
}

Video::~Video() {// Destructor 
    delete[] title; 
    delete[] publisher; 
}
//getting returns
char* Video::gettitle() {
    return title; 
}

char* Video::getpublisher() {
    return publisher;  
}

int Video::getInt() {
    return year;  
}

int Video::getrating() {
    return rating;  
}

// Printing
void Video::print() {
   
    Media::print();  
    cout << "Title: " << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Rating: " << rating << endl;
    cout << "Year: " << year << endl;
}
