//Time Complexity O(n)
#include<iostream>

struct Node
{
	int data; //Linked List of Integers
	Node* link; 
};

void InsertAtStart(Node** pointerToHead, int data)
{
	Node* temp = new Node; //malloc returns void pointer, so we type case to Node*
	temp->data = data;
	temp->link = *pointerToHead; //remember to dereference
	*pointerToHead = temp;
}

void Insert(Node** head, int data, int position)
{
	Node* temp1 = new Node;
	temp1->data = data;
	temp1->link = NULL;
	if (position == 1) {
		temp1->link = *head;
		*head = temp1;
		return;
	}
	Node* temp2 = *head;
	for (int i = 0; i < position-2; i++) {
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
}

void Print(Node* head)
{
	std::cout << "List is: ";
	while (head != NULL)
	{
		std::cout << head->data << " ";
		head = head->link;
	}
	std::cout << "\n";
}

void ListCount(Node* head)
{
	int count = 1;
	Node* temp;
	temp = head->link;
	while (temp != NULL) {
		temp = temp->link;
		count++;
	}
	std::cout << "The list is " << count << " elements long." << std::endl;
}

int main()
{
	Node* head = NULL;
	int n, x, j;

	std::cout << "The list currently has no data." << std::endl;
	std::cout << "Enter a number into the list: ";
	std::cin >> x;
	Insert(&head, x, 1); //List name, Data, Position
	Print(head);

	while (1)
	{
		std::cout << "Enter a new number into the list: ";
		std::cin >> x;
		std::cout << "What index in the list?: ";
		std::cin >> j;
		//InsertAtStart(&head, x);

		Insert(&head, x, j); //List name, Data, Position
		ListCount(head);
		Print(head);
	}
}