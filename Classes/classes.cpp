/*
Name: Aleena Shaik 
Date: 11/15/2024
Purpose: Create classes to store media databases so the user could interact
with the program by adding, searching, or deleting media data. 
Sources used: 
My sister
My brother 
Diya's media files 
Videos:
https://www.youtube.com/watch?v=rJlJ8qqVm3k
Galbraith's videos 

Websites:
https://www.w3schools.com/cpp/cpp_classes.asp
https://stackoverflow.com/questions/33695534/basic-c-inheritance
https://cplusplus.com/forum/beginner/135636/ 





*/#include <iostream>
#include <vector>
#include <cstring>
#include "video.h"  // Including the child classes
#include "music.h"
#include "movie.h"
#include "media.h"
using namespace std; 

void addMedia(vector<Media*>& MediaDataBase) { //adds Media based on selected Media 
    int mediatype; //input media type from user 
    cout << "What type of Media do you want to add?" << endl;
    cout << "1 for Movie" << endl;
    cout << "2 for Music" << endl;
    cout << "3 for Video Games" << endl;
    cin >> mediatype;
    cin.ignore();  
    if (mediatype == 1) {  // Movie
    // storing info through these variables 
        char director[100], title[100], publisher[100];
        int duration, rating, year;

    // asking the information to store 
        cout << "Enter director name: ";
        cin.getline(director, 100);
        cout << "Enter title: ";
        cin.getline(title, 100);
        cout << "Enter publisher: ";
        cin.getline(publisher, 100);
        cout << "Enter duration (min): ";
        cin >> duration;
         cin.ignore(); 
        cout << "Enter rating (1-5): ";
        cin >> rating;
         cin.ignore(); 
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();  
        //storing information in selected Media 
        MediaDataBase.push_back(new Movie(director, duration, rating, title, year));

    } else if (mediatype == 2) {  // Music
        char artist[100], title[100], publisher[100];
        int duration, year;

        cout << "Enter artist name: ";
        cin.getline(artist, 100);
        cout << "Enter title: ";
        cin.getline(title, 100);
        cout << "Enter publisher: ";
        cin.getline(publisher, 100);
        cout << "Enter duration (min): ";
        cin >> duration;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();  

        MediaDataBase.push_back(new Music(artist, duration, publisher, title, year));

    } else if (mediatype == 3) {  // Video Game
        char title[100], publisher[100];
        int rating, year;

        cout << "Enter title: ";
        cin.getline(title, 100);
        cout << "Enter publisher: ";
        cin.getline(publisher, 100);
        cout << "Enter rating (1-5): ";
        cin >> rating;
        cout << "Enter year: ";
        cin >> year;
        cin.ignore();  

        MediaDataBase.push_back(new Video(rating, publisher, title, year));
    } else {
        cout << "Please pick a number between 1-3" << endl;
    }
}

void searchMedia(vector<Media*> & MediaDataBase){ // search Media 
    char searchInput[100]; 
    int searchNumInput; 
    int searchType; 
    
    cout<< "Do you want to search media by title or year?" << endl; 
    cout<<"If you want to search by title press 1 otherwise press 2 for year"<<endl;
    cin>>searchType;
    cin.ignore();
    if (searchType == 1){
      cout<<"Enter title:"<<endl; 
      cin.getline(searchInput, 100);
      
      for(int i =0; i <MediaDataBase.size(); i++){
         if (strcmp(searchInput, MediaDataBase[i]->gettitle()) == 0) {
         MediaDataBase[i]->print();
}
      }
      
        
    }else if (searchType ==2){
      cout<<"Enter year:"<<endl; 
      cin>>searchNumInput; 
      for (int i = 0; i < MediaDataBase.size(); i++) {
        if (MediaDataBase[i]->getInt() == searchNumInput) {
            MediaDataBase[i]->print();
        }
      
    }
  
    
    }
  
    
    
}

void deleteMedia(vector<Media*> & MediaDataBase){
    //ask whether year or title
    //search using getTitle
    //if it matches - call the destructor on that media
    //
     char searchInput[100]; 
    int searchNumInput; 
    int searchType;
    char confirmDelete;
    
    cout<< "Do you want to delete media by title or year?" << endl; 
    cout<<"If you want to delete by title press 1 otherwise press 2 for year"<<endl;
    cin>>searchType;
    cin.ignore();
    if (searchType == 1){
cout<<"Enter title:"<<endl; 
      cin.getline(searchInput, 100);      
      for(int i =0; i <MediaDataBase.size(); i++){
        if (strcmp(searchInput, MediaDataBase[i]->gettitle()) == 0) {
         MediaDataBase[i]->print();


	 cout<<"Are you sure you want to delete the media above. Press y for yes or n for no"<<endl;
	 cin>>confirmDelete;
	 cin.ignore();
	 if (confirmDelete == 'y'){
	   
	 }else if (confirmDelete == 'n'){
	   cout<<"Deletion is cancelled"<<endl;
	 }else{
	   cout<<"Invalid input. Deletion is cancelled"<<endl;
	 }
}
      }
      
        
    }else if (searchType ==2){
      cout<<"Enter year:"<<endl; 
      cin>>searchNumInput; 
      for (int i = 0; i < MediaDataBase.size(); i++) {
        if (MediaDataBase[i]->getInt() == searchNumInput) {
            MediaDataBase[i]->print();
        }
      
    }
  
    
    }
  
    
    
}
int main()
{
  //declaring variables used by main function. Main function runs the implementation of the code 
    vector<Media*> MediaDataBase; 
    char input[50];
    char add[]="ADD";
    char search[]= "SEARCH";
    char del[]= "DELETE";
    char quit[]= "QUIT";
    bool stillPlaying = true; 
    
        cout<<"Type the command words: ADD, SEARCH, DELETE, QUIT to interact with media database"<<endl; 

    int j; 
    while (stillPlaying == true){ // while loop until user types QUIT
        cin.getline(input, 50, '\n');
        if (strcmp(input, add)==0){// implementing vector function based on user input
            addMedia(MediaDataBase);
        }else if (strcmp(input, search)==0){
            searchMedia(MediaDataBase);
        }else if(strcmp(input, del)==0){
            deleteMedia(MediaDataBase);
        }else if (strcmp(input, quit)==0){
            stillPlaying = false; 
        }
    }
    return 0;
}
