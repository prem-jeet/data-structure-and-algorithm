#include <iostream>

template <typename _type>
class Node
{
public:
	_type data;
	Node<_type> *next;
	Node<_type> *prev;
	Node(_type data)
		: data(data), next(nullptr), prev(nullptr) {}
};

template <typename _type>
class doublyLL
{
public:
	Node<_type> *head;
	Node<_type> *tail;
	int count;
	doublyLL() : head(nullptr), tail(nullptr), count(0) {}

	// METHOD TO INSERT AT BEGINNING
	void insert_at_beginning(_type data)
	{
		Node<_type> *new_node = new Node(data);

		count++;
		if (count == 1)
		{
			head = new_node;
			tail = new_node;
			return;
		}

		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}

	// METHOD TO INSERT AT END
	void insert_at_end(_type data)
	{
		Node<_type> *new_node = new Node(data);

		count++;
		if (count == 1)
		{
			head = new_node;
			tail = new_node;
			return;
		}

		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}

	// METHOD TO INSERT AT A GIVEN POSITION
	void insert_at_position(int position, _type data)
	{
		if (position < 0 || position > count + 1)
		{
			std::cout << "Invalid Position" << std::endl;
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

		count++;
		int index = 1;
		Node<_type> *ptr = head;
		Node<_type> *new_node = new Node(data);

		while (index != position)
		{
			index++;
			ptr = ptr->next;
		}

		new_node->next = ptr;
		new_node->prev = ptr->prev;
		ptr->prev = new_node;
		new_node->prev->next = new_node;
	}

	// METHOD TO DELETE FFROM BEGINNING
	void delete_from_beginning()
	{
		if (count == 0)
		{
			std::cout << "List is empty" << std::endl;
			return;
		}
		Node<_type> *ptr = head;
		count--;
		if (count == 0)
		{
			head = tail = nullptr;
			delete ptr;
			return;
		}

		head = head->next;
		head->prev = nullptr;
		delete ptr;
	}

	// METHOD TO DELETE FROM END
	void delete_from_end()
	{
		if (count == 0)
		{
			std::cout << "List is empty" << std::endl;
			return;
		}
		Node<_type> *ptr = tail;
		count--;
		if (count == 0)
		{
			head = tail = nullptr;
			delete ptr;
			return;
		}

		tail = tail->prev;
		tail->next = nullptr;
		delete ptr;
	}

	// METHOD TO DELETE FROM A GIVEN POSITION
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

		Node<_type> *ptr = head;
		int index = 1;
		while (index != position)
		{
			index++;
			ptr = ptr->next;
		}
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		delete ptr;
		count--;
	}

	// METHOD TO PRINT THE LIST
	void print_list()
	{
		Node<_type> *ptr = head;
		while (ptr)
		{
			std::cout << ptr->data << " <--> ";
			ptr = ptr->next;
		}
		std::cout << "null" << std::endl;
	}
	// METHOD RETURNS THE SIZE OF THE LIST
	int list_size()
	{
		return count;
	}

	// METHOD CLEARS THE LIST
	void clear_list()
	{
		Node<_type> *ptr = head;
		while (ptr)
		{
			head = head->next;
			delete ptr;
			ptr = head;
		}
		count = 0;
	}
};

void interface()
{
	std::cout << std::endl
			  << std::endl;
	std::cout << "++++++++  LINKED LIST INTERFACE  ++++++++" << std::endl;
	std::cout << "+++                                   +++" << std::endl;
	std::cout << "+++       1. Insert at start          +++" << std::endl;
	std::cout << "+++       2. Insert at end            +++" << std::endl;
	std::cout << "+++       3. Delete from beginning    +++" << std::endl;
	std::cout << "+++       4. Delete from end          +++" << std::endl;
	std::cout << "+++       5. Print list               +++" << std::endl;
	std::cout << "+++       6. print size of list       +++" << std::endl;
	std::cout << "+++       7. Insert at position       +++" << std::endl;
	std::cout << "+++       8. Delete from position     +++" << std::endl;
	std::cout << "+++       9. Clear list               +++" << std::endl;
	std::cout << "+++       0. Quit                     +++" << std::endl;
	std::cout << "+++                                   +++" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

void input_prompt()
{
	std::cout << "Enter the data to be inserted : ";
}

int main()
{

	int choice;
	int input;
	int position;

	doublyLL<int> L;

	do
	{
		interface();

		std::cout << "Enter your choice : ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case 1:

			input_prompt();
			std::cin >> input;
			L.insert_at_beginning(input);
			break;

		case 2:
			input_prompt();
			std::cin >> input;
			L.insert_at_end(input);
			break;

		case 3:
			L.delete_from_beginning();
			break;

		case 4:
			L.delete_from_end();
			break;

		case 5:
			L.print_list();
			break;

		case 6:
			std::cout << "The list has " << L.list_size() << " elements. " << std::endl;
			break;

		case 7:
			std::cout << "Enter the position : ";
			std::cin >> position;
			input_prompt();
			std::cin >> input;
			L.insert_at_position(position, input);
			break;

		case 8:
			std::cout << "Enter the position : ";
			std::cin >> position;
			L.delete_from_position(position);
			break;

		case 9:
			L.clear_list();
			break;

		case 0:
			exit(0);

		default:
			std::cout << "Not a valid option." << std::endl;
		}
	} while (true);
}