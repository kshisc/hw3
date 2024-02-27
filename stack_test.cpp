#include <iostream>
#include "stack.h"
using namespace std;

int main(){
	Stack<int> myStack;
	myStack.push(5);
	myStack.push(6);
	cout << myStack.empty() << endl; //no
	cout << myStack.size() << endl; //2
	cout << myStack.top() << endl; //6

	myStack.pop();
	myStack.pop();
	cout << myStack.empty() << endl; //yes
	cout << myStack.size() << endl; //0
	cout << myStack.top() << endl; //empty stack
}