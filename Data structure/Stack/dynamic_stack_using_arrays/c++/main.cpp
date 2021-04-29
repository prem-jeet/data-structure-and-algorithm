#include <iostream>
#include <list>
#include <string>

//function declaration
void interface();
int input(std::string);

template <typename Type>
class stack
{
private:
	std::list<Type> arr;
	int top;

public:
	stack() : top(-1) {} // contructor

	// INSERTION FUNCTION
	void push(Type data)
	{
		arr.push_back(data);
		top++;
	}

	// DELETION FUNCTION
	Type pop()
	{
		if (isEmpty())
		{
			std::cout << "Stack is Empty " << std::endl;
			return 0;
		}

		Type temp = *(arr.rbegin());
		arr.pop_back();
		top--;
		return temp;
	}

	// PEEK GIVES THE TOP ELEMENT
	Type peek()
	{
		if (isEmpty())
		{
			std::cout << "Stack is Empty " << std::endl;
			return 0;
		}

		std::list<int>::iterator it = arr.end();
		return *(it--);
	}

	// PRINTS THE STACK
	void print()
	{
		if (isEmpty())
		{
			std::cout << "stack is empty." << std::endl;
			return;
		}

		std::list<int>::reverse_iterator rit = arr.rbegin();

		while (rit != arr.rend())
		{
			std::cout << *rit << std::endl;
			rit++;
		}
	}

	// GIVES THE SIZE OF THE STACK
	int size()
	{
		return top + 1;
	}

	// RETURNS IF THE STACK IS EMPTY OR NOT
	bool empty()
	{
		return isEmpty();
	}

private:
	isEmpty()
	{
		return top == -1;
	}
};

int main()
{

	stack<int> s;

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
