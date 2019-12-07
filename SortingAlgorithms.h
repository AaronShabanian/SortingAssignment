#include <iostream>
using namespace std;
class SortingAlgorithms{
public:
  SortingAlgorithms();
  ~SortingAlgorithms();
  //selectionSort
  void selectionSort(double arr[], int n, bool printing);
  //bubble sort
  void bubbleSort(double myArray[],bool printing);
  //insert sort
  void insertSort(double arr[], bool printing);
  //prints array when user prompts to
  void printArray(double arr[]);
  //Combines separated arrays once they are all split up
  void Merge(double a[], int low, int high, int mid, bool printing);
  //splits up arrays using recursion
  void MergeSort(double a[], int low, int high, bool printing);
  int Arraysize;
  int counter=0;
};
