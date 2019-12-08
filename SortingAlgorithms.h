#include <iostream>
using namespace std;
class SortingAlgorithms{
public:
  SortingAlgorithms();
  ~SortingAlgorithms();
  //selectionSort-finds the smallest number repeatedly
  void selectionSort(double arr[], int n, bool printing);
  //bubble sort- swaps adjeacent index if they are in the wrong order
  void bubbleSort(double myArray[],bool printing);
  //insert sort- sorts one item at a time moving it to the left until the value to the left is smaller than it
  void insertSort(double arr[], bool printing);
  //prints array when user prompts to
  void printArray(double arr[]);
  //Combines separated arrays and compares them so they are in the right order once they are all split up
  void Merge(double a[], int low, int high, int mid, bool printing);
  //splits up arrays using recursion
  void MergeSort(double a[], int low, int high, bool printing);
  int Arraysize;
  int counter=0;
  int number=0;
};
