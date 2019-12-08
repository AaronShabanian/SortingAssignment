#include <iostream>
#include <fstream>
#include "RandomNumbers.h"
using namespace std;
RandomNumbers::RandomNumbers(){

}
RandomNumbers::~RandomNumbers(){

}
void RandomNumbers::createRandom(int size){
  string filenames;
  cout<<"What is the name of the file"<<endl;
  cin>>filenames;
  ofstream myfile(filenames);
  myfile<<size<<endl;
  int a;
  for(int i=0; i<size; i++){
    //creates a list of random numbers from 0-to the size of the list the user specified
    a = ((double) rand() / (RAND_MAX))*size;
    myfile<<a<<endl;
  }
  myfile.close();


}
