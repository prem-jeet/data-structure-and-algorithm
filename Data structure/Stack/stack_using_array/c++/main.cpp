#include <iostream>
#include <string>

void interface();
int input(std::string);

template <typename Type, int n>
class Stack
{
public:
	int capacity;
	int top;
	Type arr[n];

	Stack()
		: capacity(n), top(-1) {}

	//PUSH function for insertion
	void push(Type data)
	{
		if (isFull())
		{
			std::cout << "Stack is full." << std::endl;
			return;
		}

		arr[++top] = data;
	}

	//POP function for deletion
	Type pop()
	{
		if (isEmpty())
		{
			std::cout << "Stack is Empty" << std::endl;
			return 0;
		}

		Type temp = arr[top--];
		return temp;
	}

	//PRINT function to print contents of the stack
	void print()
	{
		if (isEmpty())
		{
			std::cout << "Stack is Empty" << std::endl;
			return;
		}

		for (int i = top; i > -1; i--)
		{
			std::cout << arr[i] << std::endl;
		}
	}

	// PEEK function returns the top element
	Type peek()
	{
		if (isEmpty())
		{
			std::cout << "stack is empty." << std::endl;
			return 0;
		}

		return arr[top];
	}

	//EMPTY function checks is the stack is empty
	bool empty()
	{

		return isEmpty();
	}

	//Size function returns the number of elements in the stack
	int size()
	{
		return top + 1;
	}

private:
	bool isEmpty()
	{
		return (top == -1);
	}

	bool isFull()
	{
		return (top == capacity - 1);
	}
};

int main()
{

	Stack<int, 4> s;

	while (true)
	{
		interface();

		int choice = input("enter your choice : ");

		switch (choice)
		{
		case 1:
		{
			int data = input("Enter the data : ");
			s.push(data);
		}
		break;

		case 2:
		{
			int data = s.pop();
			std::cout << "Popped " << data << std::endl;
		}
		break;

		case 3:
		{
			int data = s.peek();
			std::cout << "Top of the stack conmtains " << data << std::endl;
		}
		break;

		case 4:
		{
			int size = s.size();
			std::cout << "The stack containes " << size << " items." << std::endl;
		}
		break;

		case 5:
		{
			s.empty() ? std::cout << "True" : std::cout << "False";
			std::cout << std::endl;
		}
		break;

		case 6:
			s.print();
			break;
		case 7:
			exit(0);

		default:
			std::cout << "Invalid choice" << std::endl;
			break;
		}
	}
}

void interface()
{
	std::cout << "------------------" << std::endl;
	std::cout << "    1. Push       " << std::endl;
	std::cout << "    2. Pop        " << std::endl;
	std::cout << "    3. Peek       " << std::endl;
	std::cout << "    4. Size       " << std::endl;
	std::cout << "    5. Is Empty   " << std::endl;
	std::cout << "    6. Print      " << std::endl;
	std::cout << "    7. Exit       " << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << std::endl;
}

int input(std::string s)
{
	int temp;
	std::cout << s;
	std::cin >> temp;
	return temp;
}
