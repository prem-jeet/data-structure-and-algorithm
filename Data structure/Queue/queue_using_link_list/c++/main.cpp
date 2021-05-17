#include <iostream>
#include <list>
#include <string>

class _queue
{
	std::list<int> arr;

public:
	_queue() {}

	// Push back
	void enQueue(int data)
	{
		arr.push_back(data);
	}

	// pop front
	int deQueue()
	{
		if (arr.empty())
		{
			std::cout << "Empty Queue." << std::endl;
			return -1;
		}

		int result = *arr.begin();
		arr.pop_front();
		return result;
	}

	// check if empty
	bool empty()
	{
		return arr.empty();
	}

	// return size
	int size()
	{
		return arr.size();
	}

	// returns front element
	int front()
	{
		if (arr.empty())
		{
			std::cout << "Empty Queue." << std::endl;
			return -1;
		}

		int result = *arr.begin();
		return result;
	}

	// return back element
	int back()
	{
		if (arr.empty())
		{
			std::cout << "Empty Queue." << std::endl;
			return -1;
		}

		int result = *arr.rbegin();
		return result;
	}

	// print the queue
	void print()
	{
		if (arr.empty())
		{
			std::cout << "Empty Queue." << std::endl;
			return;
		}

		for (auto x : arr)
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{

	_queue q;

	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.print(); // 1 2 3

	q.deQueue();
	q.deQueue();
	q.enQueue(4);
	q.print(); // 3 4

	std::cout << "There are "
			  << q.size()
			  << " elements in the queue."
			  << std::endl; // There are 2 elemts int he queue.

	std::cout << q.front()
			  << " is in front"
			  << std::endl; // 3 is in front

	std::cout << q.back()
			  << " is at back"
			  << std::endl; // 4 is at back

	std::cout << "Empty list : "
			  << (q.empty() ? std::string("True") : std::string("False"))
			  << std::endl; // Empty list :: FAlse

	q.deQueue();
	q.deQueue();
	q.print(); // Empty queue

	std::cout << "There are "
			  << q.size()
			  << " elements in the queue."
			  << std::endl; // There are 0 elemts int he queue.

	std::cout << "Empty list : "
			  << (q.empty() ? std::string("True") : std::string("False"))
			  << std::endl; // Empty list :: True

	exit(0);
}