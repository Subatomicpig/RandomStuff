#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;


//the main purpose of this program is to read text data and parse it into a excel file
//with error stats 




//reads a string from the file to parse data
string readString(ifstream *file)
{
       string line;
       
       file->clear();
       file->seekg(0,ios::beg);
       
       if(file->good())
       {
         getline(*file,line);
       }
       
       return line;
}



//total the number of readings working with vector 
int numOfReadings(vector<string> readings)
{
    int totalReadings = 0;
    string line;
    string toFind = "cab";
    
   
    //iterate through a vector
    for(std::vector<string>::iterator it = readings.begin(); it != readings.end(); ++it)
    {
      line = *it;
      if(line.find(toFind) != std::string::npos)
      {
        totalReadings++;
      }                   
    }
   
    
    return totalReadings;
}

//reads the file can store into array or vector for easier access
void readFile(ifstream *file,map<int, string> &data)
{
    string line;
    int key = 0;
    
    //point to the top of the file to start reading
    file->clear();
    file->seekg(0,ios::beg);
    
    while(file->good())
    {
       getline(*file,line);
       data[key] = line;
       key++;
    }    
}

void printMap(map<int,string> data)
{
     map<int, string>::iterator it;
     for(it = data.begin(); it != data.end(); it++)
     {
            
     }
           
     
}




int main()
{
    //will eventually use this to type in the filename
    string line;
    int nReadings = 0;
    ifstream *file;
    
    //vector to store the stats will adjust accordingly
    std::vector<string> readings;
    
    //map with key: index data:string
    map<int,string> Data;
    
    
    //open a text file
    file = new ifstream("test2.txt");
    
    
    
    if(file->is_open())
    {
       readFile(file,Data);
       printMap(Data);
       file->close();
    }
    else 
         cout<<"Unable to open file";
 
 
         //wait for system input to close the command line
          system("Pause");
          return 0;   
};
