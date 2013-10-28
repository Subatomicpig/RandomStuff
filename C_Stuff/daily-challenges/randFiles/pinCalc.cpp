/**************************************************************************

This is a free to use program created by ryan wright it calculates the pin 
code of a node based off the mac address.


**************************************************************************/
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;






int hexToInt(string hex)
{
  int convertedHex  = 0;
  std::stringstream ss;
  ss << std::hex << hex;
  ss >> convertedHex;
  
  return convertedHex;
}


int main()
{
  
  const int tp16 = 65536;
  const int tp8 = 256; 

  string macAddress;

  const int k0 = 55210;
  const int k1 = 55767;
  const int k2 = 58911;
  const int k3 = 24327;
  const int k4 = 34601;
  const int k5 = 58876;
  const int k6 = 15670;
  
  int done = 0;
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  int temp = 0;
  int temp2 = 0;

  cout<<"Enter mac Address"<<endl;
  cin>>macAddress;

  //step one complete turn into a decimal number
  done = hexToInt(macAddress);
  
  //figure out num 1
  num1 = done / tp16;


  //figure out num 2 
  temp = done / tp8;
  num2 = temp % tp8;

  //figure out num 3
  num3 = done % tp8;


  //calcuate the pin 
  temp = k0 * ( num1 + k4);
  temp2 = temp % 65536;
  temp = temp2 * ( num2 + k5);
  temp2 = temp % 65536;
  temp = temp2 * ( num3 + k6);
  temp2 = temp % 65536;
  temp = temp2 + num1 * k1;
  temp2 = temp % 65536;
  temp = temp2 + num2 * k2;
  temp2 = temp % 65536;
  temp = temp2 + num3 * k3;
  temp2 = temp % 65536;
  temp = temp2 % 10000;



  cout<<"Your Pin is:"<<temp<<endl;
  
  system("pause");

  return 0;
}
