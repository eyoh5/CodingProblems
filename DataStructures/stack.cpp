#include <iostream>

#define MAX_STACK_SIZE 10

using namespace std;


class Stack {
private:
	int top=-1;
	int stack[MAX_STACK_SIZE];

public:
	Stack();
	~Stack();
	bool empty();
	bool full();
	int size();
	void push(int d);
	int pop();
};

Stack::Stack() {

}

Stack::~Stack() {

}

bool Stack::empty() {
	return top == -1;
}

bool Stack::full() {
	return top == (MAX_STACK_SIZE - 1);
}

int Stack::size() {
	if (top < 0) return 0;
	else return top+1;
}
	
int Stack::pop() {
	if (empty()) {
		cout << "Stack is empty. Can't pop()\n";
		exit(1);
	}
	else {
		top--;
		return stack[top + 1];
	}

	exit(1);
}

void Stack::push(int d) {
	if (full()) {
		cout << "Stack is full. Can't push()\n";
		exit(1);
	}
	else {
		stack[top + 1] = d;
		top++;
	}
	
}

int main() {

	Stack stack_2;
	cout << "Size of stack_2 : " << stack_2.size() << "\n";
	cout << "Is it empty? " << stack_2.empty() << "\n";
	
	//stack_2.pop();

	for (int i = 0; i < 10; i++) {
		stack_2.push(i);
	}

	cout << "Size of stack_2 : " << stack_2.size()<<"\n";
	cout << "Is it empty? " << stack_2.empty()<<"\n";
	
	for (int i = 0; i < 10; i++) {
		cout << "From stack_2 : " << stack_2.pop() << "\n";
	}

	return 0;
}
