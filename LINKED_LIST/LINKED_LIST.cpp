//Time Complexity O(n)
#include<iostream>

struct Node
{
	int data; //Linked List of Integers
	Node* link; 
};

Node* head;

void InsertAtStart(int data)
{
	Node* temp = new Node; //malloc returns void pointer, so we type case to Node*
	temp->data = data;
	temp->link = head;
	head = temp;
}

void Print()
{
	Node* temp = head;
	std::cout << "List is: ";
	while (temp != NULL)
	{
		std::cout << temp->data;
		temp = temp->link;
	}
	std::cout << "\n";
}

int main()
{
	head = NULL;
	std::cout << "How many numbers" << std::endl;
	int n, i, x;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter a number" << std::endl;
		std::cin >> x;
		InsertAtStart(x);
		Print();
	}
}