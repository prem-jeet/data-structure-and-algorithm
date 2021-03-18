#include <iostream>

#define INPUT std::cout << "enter the data : "

class Node
{
public:
	int data;
	Node *diff;
	Node(int d) : data(d), diff(NULL) {}
};

class diffList
{
public:
	Node *head;
	Node *tail;
	diffList() : tail(nullptr), head(nullptr) {}

	//METHOD RETURNS POINTER TO BEGINNING OF THE LIST
	Node *begin()
	{
		return head;
	}

	//METHOD RETURNS A POINTER TO THE END OF THE LIST
	Node *end()
	{
		return tail;
	}

	//METHOD TO INSERT AT BEGINNING
	void insert_at_beginning(int data)
	{
		Node *new_node = new Node(data);

		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
			return;
		}

		_insert(head, data);
	}

	//METHOD TO INSERT AT END
	void insert_at_end(int data)
	{
		Node *new_node = new Node(data);

		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
			return;
		}

		_insert(tail, data);
	}

	//METHOD TO DELETE FROM BEGINNING
	void delete_from_beginning()
	{
		if (!head)
		{
			std::cout << "Empty list." << std::endl;
			return;
		}

		if (!head->diff)
		{
			delete head;
			head = tail = NULL;
		}

		_delete(head);
	}

	//METHOD TO DELETE FROM END
	void delete_from_end()
	{
		if (!tail)
		{
			std::cout << "Empty list." << std::endl;
			return;
		}

		if (!tail->diff)
		{
			delete head;
			head = tail = NULL;
		}

		_delete(tail);
	}
	//METHOD TO PRINT THE LIST IF NO POINTER IS GIVEN
	void print_list()
	{
		_print_list(head);
	}

	//METHOD TO PRINT THE LIST IF SOME POINTER IS PASSED
	void print_list(Node *ptr)
	{
		_print_list(ptr);
	}

private:
	//INSERT METHOD
	void _insert(Node *(&ptr), int data)
	{
		Node *new_node = new Node(data);

		new_node->diff = ptr;
		ptr->diff = XOR(ptr->diff, new_node);
		ptr = new_node;
	}

	//DELETE METHOD
	void _delete(Node *(&ptr))
	{
		Node *temp = ptr;
		ptr = ptr->diff;
		ptr->diff = XOR(ptr->diff, temp);
		delete temp;
	}

	//METHOD PRINTS THE LIST
	void _print_list(Node *ptr)
	{
		if (!ptr)
		{
			std::cout << "Empty list" << std::endl;
			return;
		}
		Node *prev = NULL;
		Node *curr = ptr;

		while (curr)
		{
			std::cout << curr->data << "->";
			curr = XOR(prev, curr->diff);
			prev = ptr;
			ptr = curr;
		}

		std::cout << std::endl;
	}

	//XOR METHOD RETURNS ADDRESS OF THE NEXT NODE
	Node *XOR(Node *a, Node *b)
	{
		return reinterpret_cast<Node *>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
	}
};

void interface()
{
	std::cout << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "++   1. Insert at beginnning   ++" << std::endl;
	std::cout << "++   2. Insert at end          ++" << std::endl;
	std::cout << "++   3. Delete from beginning  ++" << std::endl;
	std::cout << "++   4. Delete from end        ++" << std::endl;
	std::cout << "++   5. Print list             ++" << std::endl;
	std::cout << "++   6. Print reverse list     ++" << std::endl;
	std::cout << "++   0.Exit                    ++" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
}

int main()
{

	diffList L;

	int choice;

	while (true)
	{
		interface();
		std::cout << "\nEnter Your choice : ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int data;
			INPUT;
			std::cin >> data;
			L.insert_at_beginning(data);
		}
		break;

		case 2:
		{
			int data;
			INPUT;
			std::cin >> data;
			L.insert_at_end(data);
		}
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
			L.print_list(L.end());
			break;

		case 0:
			exit(0);

		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}
	exit(0);
}