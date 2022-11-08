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

Node Print(Node* head)
{
	std::cout << "List is: ";
	while (head != NULL)
	{
		std::cout << head->data;
		head = head->link;
	}
	std::cout << "\n";
}

int main()
{
	Node* head = NULL;
	std::cout << "How many numbers" << std::endl;
	int n, i, x;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter a number" << std::endl;
		std::cin >> x;
		InsertAtStart(&head, x);
		Print(head);
	}
}