#include "SortingAlgorithms.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <chrono>
#include "RandomNumbers.h"
using namespace std::chrono;

SortingAlgorithms::SortingAlgorithms(){
}


SortingAlgorithms::~SortingAlgorithms(){

}




void SortingAlgorithms::bubbleSort(double myArray[], bool printing){
  int temp=0;
  for(int i=0; i<Arraysize; i++){
    for (int j=0; j<Arraysize-1; j++){
      if(myArray[j]>myArray[j+1]){
        temp=myArray[j+1];
        myArray[j+1]=myArray[j];
        myArray[j]=temp;
      }
    }
  }
  if (printing==true){
    printArray(myArray);
  }
}





void SortingAlgorithms::selectionSort(double arr[], int n,bool printing){
  int i;
  int j;
  int minIndex;
  double tmp;
  for(i=0; i<n-1;i++){
    minIndex=i;
    for(j=i+1; j<n; j++){
      if(arr[j]<arr[minIndex]){
        minIndex=j;
      }
    }
    if(minIndex!=i){
      tmp=arr[i];
      arr[i]=arr[minIndex];
      arr[minIndex]=tmp;
    }
  }
  if(printing==true){
    printArray(arr);
  }
}





void SortingAlgorithms::insertSort(double arr[], bool printing){
  double temp=0;
  for(int j=1; j<Arraysize; ++j){
  temp=arr[j];
  int k=j;
  while (k>0&&arr[k-1]>=temp){
      arr[k]=arr[k-1];
      --k;
    }
    arr[k]=temp;
  }
  if(printing==true){
    printArray(arr);
  }
}



void SortingAlgorithms:: printArray(double arr[]){
  cout<<endl;
  for(int i=0; i<Arraysize; i++){
    cout<<arr[i]<<endl;
  }
}


// combines array back and sorts it
void SortingAlgorithms:: Merge(double a[], int low, int high, int mid, bool printing)
{
	int leftArrSize=mid-low+1;
  int RightArrSize=high-mid;
  int k;
  int i;
  int j;
  double left[leftArrSize];
  double right[RightArrSize];
	//leftArrSize= low;
  for( i=0;i<leftArrSize;i++)
    {
        left[i]=a[low+i];
    }
  for( j=0;j<RightArrSize;j++)
    {
        right[j]=a[mid+j+1];
    }
    i=0;
    j=0;
  for(k=low;i<leftArrSize&&j<RightArrSize;k++)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i++];
        }

        else
        {
            a[k]=right[j++];
        }
    }
  while(i<leftArrSize)
    {
        a[k++]=left[i++];
    }
  while(j<RightArrSize)
    {
        a[k++]=right[j++];
    }
  number++;
  if(printing==true&&number==Arraysize-1){
    printArray(a);
  }


}

// Splits array.
void SortingAlgorithms::MergeSort(double arr[], int low, int high, bool printing)
{
	int middle;
	if (low < high)
	{
    //finds middle of array so it knows where to split
		middle=(low+high)/2;
		// Split the data into two halfs.
		MergeSort(arr, low, middle, printing);
		MergeSort(arr, middle+1,high, printing);

		// Once the array is split up to individual elements merge is called to combine them back
		Merge(arr, low, high, middle, printing);

	}
}



int main(int argc,char **argv)
{
  SortingAlgorithms sorter;
  RandomNumbers randoms;
  string line;
  int counter=0;
  int index=0;
  int number=0;
  string answers;
  string filename;
  int big;
  while(true){
    cout<<"Would you like to have a file with Random Numbers generated for you (yes/no)?"<<endl;
    cin>>answers;
    if(answers=="yes"){
      cout<<"How many numbers"<<endl;
      cin>>big;
      randoms.createRandom(big);
    }
    cout<<"What is the name of the file you would like to read from?"<<endl;
    cin>>filename;
    ifstream readfile (filename);
    if(readfile.is_open()){
      break;
    }
    else{
      cout<<"File could not be found, please enter another file name"<<endl;
    }
  }
  ifstream readfile (filename);
  getline(readfile, line);
  stringstream numberss(line);
  numberss>>number;
  sorter.Arraysize=number;
  double arr1[number];


  ifstream readfile2 (filename);
  if(readfile2.is_open()){
    while(getline(readfile2, line)){
      if(counter==0){
        counter++;
      }
      else{
        stringstream numbers(line);

        numbers>>number;
        arr1[index]=number;
        index++;
      }
    }
  }
  else{
    cout<<"File could not be found"<<endl;
  }
  bool printing=false;
  string answer="";
  int choice=0;
  double lowTime=0;
  double timer=0;
  while(true){
    cout<<" Would you like the print the results of the sorted array? (yes/no)"<<endl;
    cin>>answer;
    if(answer=="yes"){
      printing=true;
    }
    else{
      printing=false;
    }
    cout<<"Please enter the number of the sorting algorithm you would like to try (1-4)"<<endl;
    cout<<"(1) bubbleSort"<<endl;
    cout<<"(2) selectionSort"<<endl;
    cout<<"(3) insertSort"<<endl;
    cout<<"(4) MergeSort"<<endl;
    cin>>choice;
    if(choice==1 || choice==2 || choice==3 || choice==4 ){
      if(choice == 1){
        auto start = std::chrono::high_resolution_clock::now();
        sorter.bubbleSort(arr1, printing);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time: " << elapsed.count() << " s\n";
      }
      else if(choice == 2){
        auto start = std::chrono::high_resolution_clock::now();
        sorter.selectionSort(arr1,sorter.Arraysize, printing);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time: " << elapsed.count() << " s\n";
      }
      else if(choice == 3){
        auto start = std::chrono::high_resolution_clock::now();
        sorter.insertSort(arr1, printing);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time: " << elapsed.count() << " s\n";
      }
      else if (choice == 4 ){
        auto start = std::chrono::high_resolution_clock::now();
        sorter.MergeSort(arr1,0,sorter.Arraysize-1, printing);
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Elapsed time: " << elapsed.count() << " s\n";
      }
    }
    else{
      cout<<" You did not enter a valid choice "<<endl;
    }
    cout<<"Would you like to try another algorithm (yes/no)?";
    cin>>answer;
    if(answer=="no"){
      break;
    }
  }
}
