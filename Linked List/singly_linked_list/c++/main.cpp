#include <iostream>

//TEMPLATE FOR NODE
template <typename _type>
class Node
{
public:
	_type data;
	Node *next;

	Node(_type d)
		: data(d), next(nullptr) {}
};

//TEMPLATE FOR LINKED LIST
template <typename _type>
class Linkedlist
{
public:
	Node<_type> *head;
	int count;
	Linkedlist() : count(0)
	{
		head = nullptr;
	}

	//METHOD TO INSERT AT THE START OF THE LIST
	void insert_at_beginning(_type data)
	{
		count++;
		Node<_type> *temp = new Node(data);
		temp->next = head;
		head = temp;
	}

	//METHOD TO INSERT AT THE END OF THE LIST
	void insert_at_end(_type data)
	{
		count++;
		Node<_type> *temp = new Node(data);

		if (is_empty())
		{
			head = temp;
			return;
		}

		Node<_type> *ptr = head;

		while (ptr->next != nullptr)
			ptr = ptr->next;

		ptr->next = temp;
	}

	//METHOD TO INSERT AT ANY ARBITARY LOCATION
	void insert_at(int position, _type data)
	{
		if (position > count + 1 || position < 1)
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}

		count++;

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

		int curr_index = 1;
		position -= 1;
		Node<_type> *temp = head;

		while (curr_index != position)
		{
			curr_index++;
			temp = temp->next;
		}

		Node<_type> *ptr = new Node(data);
		ptr->next = temp->next;
		temp->next = ptr;
	}

	//METHOD TO DELETE THE FIRST NODE
	void delete_from_start()
	{
		if (is_empty())
		{
			std::cout << "Empty list" << std::endl;
			return;
		}

		count--;
		Node<_type> *temp = head;
		head = head->next;
		delete temp;
	}

	//METHOD TO DELETE THE LAST NODE
	void delete_from_end()
	{
		if (is_empty())
		{
			std::cout << "Empty list" << std::endl;
			return;
		}

		count--;

		Node<_type> *temp = head;

		if (count == 1)
		{
			head = head->next;
			delete temp;
			return;
		}

		while (temp->next->next != nullptr)
			temp = temp->next;

		Node<_type> *ptr = temp->next;
		temp->next = nullptr;
		delete ptr;
	}

	//METHOD TO DELETE FROM AN ARBITARY POSITION
	void delete_from_position(int position)
	{
		if (position > count || position < 1)
		{
			std::cout << "Invalid position" << std::endl;
			return;
		}

		count--;

		Node<_type> *temp = head;
		if (position == 1)
		{
			delete_from_start();
			return;
		}
		if (position == count)
		{
			delete_from_end();
			return;
		}

		int curr_index = 1;
		position -= 1;
		while (curr_index != position)
		{
			temp = temp->next;
			curr_index++;
		}

		Node<_type> *ptr = temp->next;
		temp->next = ptr->next;
		delete ptr;
	}

	//METHOD TO GET DATA AT POSITION
	_type get_from_position(int position)
	{
		if (is_empty())
		{
			std::cout << "Empty List" << std::endl;
			return (_type)NULL;
		}

		if (position < 1 || position > count)
		{
			std::cout << "Invalid position." << std::endl;
			return (_type)NULL;
		}
		Node<_type> *temp = head;
		int curr_index = 1;
		while (curr_index != position)
		{
			curr_index++;
			temp = temp->next;
		}

		return temp->data;
	}
	//METHOD RETURN THE NUMBER OF ELEMENTS IN THE LIST
	int size()
	{
		return count;
	}

	//METHOD TO PRINT THE LIST
	void print_list()
	{

		Node<_type> *temp = head;

		while (temp)
		{
			std::cout << temp->data << " --> ";
			temp = temp->next;
		}
		std::cout << "null" << std::endl;
	}

	//METHOD TO CLEAR THE LIST
	void clear_list()
	{
		if (count == 0)
			return;

		Node<_type> *temp = head;

		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
		count = 0;
	}

private:
	// RETURNS IF THE LIST IS EMPTY OR NOT
	bool is_empty()
	{
		return head == nullptr;
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
	std::cout << "+++      10. Get data from position   +++" << std::endl;
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

	Linkedlist<int> L;

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
			L.delete_from_start();
			break;

		case 4:
			L.delete_from_end();
			break;

		case 5:
			L.print_list();
			break;

		case 6:
			std::cout << "The list has " << L.size() << " elements. " << std::endl;
			break;

		case 7:
			std::cout << "Enter the position : ";
			std::cin >> position;
			input_prompt();
			std::cin >> input;
			L.insert_at(position, input);
			break;

		case 8:
			std::cout << "Enter the position : ";
			std::cin >> position;
			L.delete_from_position(position);
			break;

		case 9:
			L.clear_list();
			break;

		case 10:
			std::cout << "Enter the position : ";
			std::cin >> position;
			if (position < 0 || position > L.size())
				std::cout << "Invalid position " << std::endl;
			else
			{
				std::cout
					<< "Element at position "
					<< position
					<< " is "
					<< L.get_from_position(position)
					<< std::endl;
			}

			break;

		case 0:
			exit(0);

		default:
			std::cout << "Not a valid option." << std::endl;
		}
	} while (choice);
}