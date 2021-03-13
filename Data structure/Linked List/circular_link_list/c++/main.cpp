#include <iostream>

#define INPUT_DATA std::cout << "Enter the data : "
#define INPUT_POSITION std::cout << "Enter the position : "

template <typename _type>
class Node
{
public:
	_type data;
	Node<_type> *next;
	Node(_type d)
		: data(d), next(nullptr) {}
};

template <typename _type>
class circularLL
{
public:
	Node<_type> *head;
	int count;

	circularLL() : head(nullptr), count(0) {}

	//METHOD TO INSERT AT BEGINNING
	void insert_at_beginning(_type data)
	{
		count++;

		Node<_type> *new_node = new Node(data);
		if (head == nullptr)
		{
			head = new_node;
			new_node->next = head;
			return;
		}

		Node<_type> *ptr = head;
		while (ptr->next != head)
		{
			ptr = ptr->next;
		}
		new_node->next = head;
		ptr->next = new_node;
		head = new_node;
	}

	//METHOD TO INSERT AT END
	void insert_at_end(_type data)
	{
		count++;

		Node<_type> *new_node = new Node(data);
		if (head == nullptr)
		{
			head = new_node;
			new_node->next = head;
			return;
		}

		Node<_type> *ptr = head;
		while (ptr->next != head)
		{
			ptr = ptr->next;
		}
		new_node->next = head;
		ptr->next = new_node;
	}

	//METHOD TO INSERT AT A GIVEN POSITION
	void insert_at_position(int position, _type data)
	{
		if (position < 1 || position > count + 1)
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}

		if (position == 1)
		{
			insert_at_beginning(data);
			return;
		}
		if (position == count + 1)
		{
			insert_at_end(data);
			return;
		}

		int index = 1;
		Node<_type> *ptr = head;
		Node<_type> *new_node = new Node(data);
		while (index + 1 != position)
		{
			index++;
			ptr = ptr->next;
		}

		new_node->next = ptr->next;
		ptr->next = new_node;
		count++;
	}
	//METHOD TO DELETE FROM BEGINNING
	void delete_from_beginning()
	{
		if (count == 0)
		{
			std::cout << "Empty list." << std::endl;
			return;
		}

		count--;
		Node<_type> *ptr = head;
		if (count == 0)
		{
			head = nullptr;
			delete ptr;
			return;
		}

		while (ptr->next != head)
			ptr = ptr->next;

		ptr->next = head->next;
		head->next = nullptr;
		delete head;
		head = ptr->next;
	}

	//METHOD TO DELETE FROM END
	void delete_from_end()
	{
		if (count == 0)
		{
			std::cout << "Empty list." << std::endl;
			return;
		}

		count--;
		Node<_type> *ptr = head;
		if (count == 0)
		{
			head = nullptr;
			delete ptr;
			return;
		}

		while (ptr->next->next != head)
			ptr = ptr->next;

		Node<_type> *temp = ptr->next;
		ptr->next = head;
		temp->next = nullptr;
		delete temp;
	}

	//METHOD TO DELETE FROM A GIVEN POSITION
	void delete_from_position(int position)
	{
		if (position < 1 || position > count)
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}

		if (position == 1)
		{
			delete_from_beginning();
			return;
		}
		if (position == count)
		{
			delete_from_end();
			return;
		}

		int index = 1;
		Node<_type> *ptr = head;

		while (index + 1 != position)
		{
			index++;
			ptr = ptr->next;
		}

		Node<_type> *temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
		count--;
	}
	//METHOD TO PRINT THE LIST
	void print_list()
	{
		if (count == 0)
		{
			std::cout << "empty List." << std ::endl;
			return;
		}

		Node<_type> *ptr = head;
		std::cout << ptr->data << " -> ";
		while (ptr->next != head)
		{
			ptr = ptr->next;
			std::cout << ptr->data << " -> ";
		}
	}
};

void interface()
{
	std::cout << std::endl;
	std::cout << "***********************************" << std::endl;
	std::cout << "*	    1.Insert at beginning       *" << std::endl;
	std::cout << "*	    2.Insert at end             *" << std::endl;
	std::cout << "*	    3.Insert at position        *" << std::endl;
	std::cout << "*	    4.Delete from beginning     *" << std::endl;
	std::cout << "*	    5.Delete from end           *" << std::endl;
	std::cout << "*	    6.Delete from position      *" << std::endl;
	std::cout << "*	    7.Print list                *" << std::endl;
	std::cout << "*	    8.Exit                      *" << std::endl;
	std::cout << "***********************************" << std::endl;
}
int main()
{

	circularLL<int> L;

	int choice;
	int input;
	int position;

	while (true)
	{
		interface();
		std::cout << "Enter your choice : ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			INPUT_DATA;
			std::cin >> input;
			L.insert_at_beginning(input);
			break;
		case 2:
			INPUT_DATA;
			std::cin >> input;
			L.insert_at_end(input);
			break;
		case 3:
			INPUT_POSITION;
			std::cin >> position;
			INPUT_DATA;
			std::cin >> input;
			L.insert_at_position(position, input);
			break;
		case 4:
			L.delete_from_beginning();
			break;
		case 5:
			L.delete_from_end();
			break;
		case 6:
			INPUT_POSITION;
			std::cin >> position;
			L.delete_from_position(position);
			break;
		case 7:
			L.print_list();
			break;
		case 8:
			exit(0);
		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}
}