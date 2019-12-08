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
    a = ((double) rand() / (RAND_MAX))*size;
    myfile<<a<<endl;
  }
  myfile.close();


}
