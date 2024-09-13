/*Name: Aleena Shaik
  Date: 09/13/24
  Purpose: Input a sentence from the user. Lower any Upper case and remove any punctuation. flip the sentence and check whether it matches unflipped version. Output if it is a Palindrome or not a Palindrome.
 */
#include <iostream>
#include <cstring>


int main()
{
  // Setting up variabels
  char str1 [81];
    char str2 [81];
    std:: cin.getline (str1, 80);
    int str1length = strlen(str1);
    // Change upper case to lower case using the ascii chart
    
   for (int i = 0; i < str1length; i++){
       if(str1[i] >=65 && str1[i] <= 90){
          str1[i]= str1[i]+32;
          
       
       }
   }
   
   // int counter to keep track of the number of letters without punctuation and spaces
   int counter = 0;

   //Removes punctuation and spaces as everything is ignored besides lower case
   for (int i = 0; i < str1length; i ++){
       if (std::isalpha(str1[i])){
           str1[counter] = str1[i];
           counter++;
           
       }
   }
   str1[counter] = '\0'; // adding the null character at the end before flipping 
   

   strcpy(str2, str1); // copying array 1 to array 2 to flip 
   // flips the sentence
 for (int k = 1; k <= counter; k++){
     
     str2[k-1] = str1[counter-k];
      
  }
 str2[counter] = '\0';  // adding the null character after flipping
   
  
 

  //Output if it is a palindrome or not a palindrome 
  
  if (strcmp(str1,str2)==0){
      std::cout<<"Palindrome";
  }else{
      std::cout<<"No Palindrome";
  }
  
      
  
  
    return 0;
}
# Palindrome
