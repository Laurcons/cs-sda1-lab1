#pragma once
//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -111111

class Stack
{
private:
	TElem* arr;
	size_t capacity;
	size_t size;
	
public:

	//constructor
	Stack();
	
	//pushes an element to the top of the Stack
	void push(TElem e);
	
	//returns the element from the top of the Stack
	//throws exception if the stack is empty
	TElem top() const;
	   
	//removes and returns the element from the top of the Stack
	//throws exception if the stack is empty
	TElem pop();
	   
	//checks if the stack is empty
	bool isEmpty() const;

	// lab LIVE assignment
	// returns and removes one occurrence of the minimum element from the Stack (assume that the
	//  elements are integer numbers)
	// throws an exception if the Stack is empty
	TElem popMinimum();
	
	//destructor
	~Stack();
};

