#include <iostream>
#include <cstring>  
#include "music.h"
using namespace std;


Music::Music() { 
    artist = new char[100];  
    title = new char[100];     
    publisher = new char[100];
    duration = 0;
    year = 0;
}


Music::Music(char* newartist, int newduration, char* newpublisher, char* newtitle, int newyear) { //contructor with parameters
    artist= new char[100];  // storing memory in new char array. Prevents memory leaks 
    strcpy(artist, newartist); 

    title = new char[100];  
    strcpy(title, newtitle); 

    year = newyear;    
    duration = newduration;  
    publisher = new char[100];  
    strcpy(publisher, newpublisher);
}

Music::~Music() {// destructor so we do not leave any data traces anywhere
    delete[] artist;  
    delete[] title; 
    delete[] publisher; 
}


//getting returns for print or delete

char* Music::getartist() {
    return artist;
}
char* Music::gettitle() {
    return title;  
}

int Music::getInt() {
    return year;  
}



char* Music::getpublisher() {
    return publisher;
}

int Music::getduration() {
    return duration;
}

void Music::print() {
    Media::print();  
    cout << "Artist: " << artist << endl;
    cout << "Title: " << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Year: " << year << endl;
}
