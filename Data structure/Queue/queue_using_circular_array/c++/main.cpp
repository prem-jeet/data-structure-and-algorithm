#include <iostream>

template <int n>
class _queue
{

	int _front, _rare;
	int arr[n];

public:
	_queue() : _front(-1), _rare(-1) {}

	// function for insertion
	void enQueue(int data)
	{
		if (isFull())
		{
			std::cout << "Queue is full." << std::endl;
			return;
		}

		if (_rare == -1)
		{ // if the list is empty
			_front++;
			arr[++_rare] = data;
			return;
		}

		_rare++;
		_rare %= n;
		arr[_rare] = data;
	}

	// function for deletion
	int deQueue()
	{
		if (isEmpty())
		{
			std::cout << "Empty Queue." << std::endl;
			return 0;
		}

		int temp = arr[_front];

		if (_front == _rare)
		{ // if only one element
			_front = -1;
			_rare = -1;
			return temp;
		}

		_front += 1; // increment _front
		_front %= n; // do modulo to form a circle
		return temp;
	}

	// for to retrive the _front element
	int front()
	{
		if (isEmpty())
		{
			std::cout << "Empty Queue." << std::endl;
			return 0;
		}

		return arr[front];
	}

	// function to retrive the _rare element
	int rare()
	{
		if (isEmpty())
		{
			std::cout << "Empty Queue." << std::endl;
			return 0;
		}

		return arr[rare];
	}

	// function to get the size of the queue
	int size()
	{
		if (isEmpty())
		{
			return 0;
		}

		if (_front <= _rare)
		{
			return _rare - _front + 1;
		}

		return (_rare + 1) + (n - _front);
	}

	// function to print the queue
	void print()
	{
		if (isEmpty())
		{
			std::cout << "Empty queue." << std::endl;
			return;
		}

		for (int i = _front; i != _rare;)
		{
			std::cout << arr[i] << " ";
			i++;
			i %= n;
		}
		std::cout << arr[_rare] << std::endl;
	}

	// function to check if the queue is empty
	int empty()
	{
		return isEmpty();
	}

private:
	bool isEmpty()
	{
		return (_front == -1) && (_rare == -1);
	}

	bool isFull()
	{

		return (_front == ((_rare + 1) % n));
	}
};

int main()
{

	_queue<4> Q;

	Q.enQueue(1);
	Q.enQueue(2);
	Q.enQueue(3);
	Q.enQueue(4);
	Q.print();							// 1 2 3 4
	Q.enQueue(5);						// Full
	std::cout << Q.size() << std::endl; // 4;

	Q.deQueue();
	Q.deQueue();
	Q.print(); // 3 4
	std::cout << Q.size() << std::endl;

	Q.enQueue(5);
	Q.enQueue(6);
	Q.print();							// 3 4 5 6
	std::cout << Q.size() << std::endl; // 4

	exit(0);
}