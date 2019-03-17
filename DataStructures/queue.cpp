#include <iostream>

#define MAX_QUEUE_SIZE 10

using namespace std;


class Queue {
private:
	int _queue[MAX_QUEUE_SIZE];
	int rear=0;
	int head=0;
public:
	Queue();
	~Queue();
	bool empty();
	bool full();
	void pop();
	int front();
	int back();
	void push(int d);
	int size();
};

Queue::Queue() {

}

Queue::~Queue() {}

bool Queue::empty() {
	return rear == head;
}

bool Queue::full() {
	return ( (rear + 1) % MAX_QUEUE_SIZE) == head;
}

void Queue::pop() {
	if (empty()) {
		cout << "Queue is empty. Can't pop()\n";
		exit(0);
	}

	head = (head+1) % MAX_QUEUE_SIZE;
}

int Queue::front() {
	if (empty()) {
		cout << "Queue is empty. Can't front()\n";
		exit(0);
	}

	return _queue[head];
}

int Queue::back() {
	if (empty()) {
		cout << " Queue is empty. Can't back()\n";
		exit(0);
	}

	return _queue[(rear-1) % MAX_QUEUE_SIZE];
}

void Queue::push(int d){
	if (full()) {
		cout << "Queue is full. Can't push()\n";
		exit(0);
	}

	_queue[(rear++) % MAX_QUEUE_SIZE] = d;

}

int Queue::size() {
	if (empty()) return 0;

	return (rear > head ? rear - head : MAX_QUEUE_SIZE - head + rear);
}


int main() {

	Queue q;

	cout << "Queue size is " << q.size() <<"\n";
	cout << "Is it empty ? " << q.empty() << "\n";

	for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) { // queue의 경우 rear가 마지막 원소 다음 비어있는 공간을 가리켜야 해서 MAX_QUEUE_SIZE-1 이 최대 큐 사이즈.
		q.push(i);
		cout << "Now Q's back is " << q.back() << "\n";
	}

	cout << "Queue size is " << q.size() << "\n";
	cout << "Is it empty ?" << q.empty() << "\n";

	for (int i = 0; i < MAX_QUEUE_SIZE - 1; i++) {
		cout<<"From q. : "<< q.front()<<"\n";
		q.pop();
	}

	return 0;
}



