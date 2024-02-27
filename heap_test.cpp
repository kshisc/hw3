#include <iostream>
#include "heap.h"
using namespace std;

int main(){
  // Heap<string,less<string>> h1(3);
  // h1.push("banana");
  // h1.push("apple");
  // h1.push("carrot");
  // h1.push("dragonfruit");
  // h1.push("eggnog");
  // cout << h1.size() << endl;
  // cout << h1.top() << endl;
  // h1.pop();
  // cout << "popped" << endl;
  // cout << h1.top() << endl;
  // h1.pop();
  // cout << h1.top() << endl;
  // h1.pop();
  // h1.pop();

  Heap<int> minHeap(5); // Create a 3-ary min-heap
  minHeap.push(5);
  minHeap.push(1);
  minHeap.push(3);
  minHeap.push(4);
  minHeap.push(2);
  minHeap.push(6);
  minHeap.push(7);

  cout << minHeap.top() << endl; 
	minHeap.pop();
  cout << minHeap.top() << endl; 
	minHeap.pop();
  cout << minHeap.top() << endl; 
	minHeap.pop();
  cout << minHeap.top() << endl;
	minHeap.pop();
  cout << minHeap.top() << endl;
	minHeap.pop();
	cout << minHeap.top() << endl;
	minHeap.pop();
	cout << minHeap.top() << endl;
	minHeap.pop();

  // for(int i=0;i<minHeap.vec_.size();i++){
  //   cout << minHeap.vec_[i] << endl;
  // }

  return 0;
}