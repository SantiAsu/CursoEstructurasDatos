#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int binarySearch(const vector<int>& arr, int target){
  int left=0; int right=arr.size()-1;

  while(left<=right){
    int mid = (left+right)/2;
    if(arr[mid]==target){
      return 1;
    }
    else if(arr[mid]<target){
      left = mid+1;
    }
    else if(arr[mid]>target){
      right = mid-1;
    }
  }
  return 0;
}

int primeraAparicion(const vector<int>& arr, int target) {
  int left=0; int right=arr.size()-1, result = -1;

  while(left<=right){
    int mid = (left+right)/2;
    if(arr[mid]==target){
      result = mid;
      right = mid-1;
    }
    else if(arr[mid]<target){
      left = mid+1;
    }
    else if(arr[mid]>target){
      right = mid-1;
    }
  }
  return result+1;
}

int ultimaAparicion(const vector<int>& arr, int target) {
  int left=0; int right=arr.size()-1, result = -1;

  while(left<=right){
    int mid = (left+right)/2;
    if(arr[mid]==target){
      result = mid;
      left = mid+1;
    }
    else if(arr[mid]<target){
      left = mid+1;
    }
    else if(arr[mid]>target){
      right = mid-1;
    }
  }
  return result+1;
}

int main() {
  std::vector<int> arr = {1, 3, 5, 5, 5, 5, 7, 9, 11, 13, 15};
  int target = 5;

  if(binarySearch(arr, target)){
    cout<<"Elemento encontrado"<<endl;
  }else{
    cout<<"Elemento no encontrado"<<endl;
  }
  cout<<"Elemento primera aparicion: "<<primeraAparicion(arr,target)<<endl;
  cout<<"Elemento ultima aparicion: "<< ultimaAparicion(arr,target)<<endl;
}