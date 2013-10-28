#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int getChars(ifstream *inFile)
{
   char c;
   int count = 0;
   
   inFile->clear();
   inFile->seekg(0, ios::beg);
   while(inFile->good())
   {
       c = inFile->get();
       if(c >= 65 && c <= 90 || c >= 97 && c <= 122){  
            count++;
       } 
   }
   
   return count;
}

int getNumbers(ifstream *inFile)
{
    char c;
    int count = 0;
    
    inFile->clear(); 
    inFile->seekg(0, ios::beg);
    while(inFile->good())
    {
      c = inFile->get();
      if(c >= 48 && c <= 57){
           count++;
      }                                        
    }
    return count;
}


int getWords(ifstream *inFile)
{
    char c;
    int count = 0;
    
    inFile->clear();
    inFile->seekg(0, ios::beg);
    while(inFile->good())
    {
      c = inFile->get();
      if(c == ' ')
           count++;
    }
    return count;
}

int getSymbols(ifstream *inFile)
{
    char c;
    int count = 0;
    
    inFile->clear();
    inFile->seekg(0, ios::beg);
    while(inFile->good())
    {
      c = inFile->get();
      if(c >= 33 && c <= 47 || c >= 91 && c <= 96)
           count++;
    }
    
    return count;
}


void addWords(ifstream *inFile,vector<string>& popWords)
{
    string str;
    
    inFile->clear();
    inFile->seekg(0, ios::beg);
    
    while(*inFile >> str)
    {
      popWords.push_back(str);    
    }
}



int main()
{
    string line;
    ifstream *file;
    std::vector<string> popWords;
    
    file = new ifstream("test2.txt");
    
    
    if(file->is_open())
    {
       
       file->close();
    }
    else 
         cout<<"Unable to open file";
 
 
         //wait for system input to close the command line
          system("Pause");
          return 0;   
};
