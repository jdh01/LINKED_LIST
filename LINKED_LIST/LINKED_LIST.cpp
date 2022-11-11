#include<iostream>

struct Node
{
	int data; //Linked List of Integers
	Node* link; 
};

void InsertAtStart(Node** pointerToHead, int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->link = *pointerToHead; //remember to dereference
	*pointerToHead = temp;
}

Node* Insert(Node** head, int data, int position)
{
	Node* temp1 = new Node;
	temp1->data = data;
	temp1->link = NULL;
	if (position == 1) {
		temp1->link = *head;
		*head = temp1;
		return *head;
	}
	Node* temp2 = *head;
	for (int i = 0; i < position-2; i++) {
		temp2 = temp2->link;
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
}

void Delete(Node* head, int position)
{
	Node* temp1 = head;
	if (position == 1) //Case of deleting the head
	{
		head = temp1->link;
		delete temp1;
		return;
	}
	
	temp1 = head->link;
	for (int i = 0; i < position - 2; i++)
	{
		temp1 = temp1->link;
	}
	Node* temp2 = temp1->link;
	temp1->link = temp2 ->link;
	delete temp2;
}

void IterativePrint(Node* head)
{
	std::cout << "List is: ";
	while (head != NULL)
	{
		std::cout << head->data << " ";
		head = head->link;
	}
	std::cout << "\n";
}

void RecursivePrint(Node* head)
{
	if (head == NULL) 
		return;
	std::cout << head->data << " ";
	RecursivePrint(head->link);
}

void ReverseRecursivePrint(Node* head)
{
	if (head == NULL) 
		return;
	ReverseRecursivePrint(head->link);
	std::cout << head->data << " ";
}

void ListCount(Node* head)
{
	std::cout << "\n";
	int count = 1;
	Node* temp;
	temp = head->link;
	while (temp != NULL) {
		temp = temp->link;
		count++;
	}
	std::cout << "The list is " << count << " elements long." << std::endl;
}

Node* IterativeReverse(Node** head)
{
	Node* prev, *current, *next;
	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	*head = prev;
	return *head;
}

void RecursiveReverse(Node** head, Node* headcpy)
{
	if (headcpy->link == NULL)
	{
		*head = headcpy;
		return;
	}
	RecursiveReverse(head, headcpy->link);
	Node* q = headcpy->link;
	q->link = headcpy;
	headcpy->link = NULL;
}

int main()
{
	Node* head = NULL;
	int n, x, j;

	//std::cout << "The list currently has no data." << std::endl;
	//std::cout << "Enter a number into the list: ";
	//std::cin >> x;
	Insert(&head, 1, 1); //List name, Data, Position
	//Print(head);

	//std::cout << "Enter a new number into the list: ";
	//std::cin >> x;
	//std::cout << "What index in the list?: ";
	//std::cin >> j;
	////InsertAtStart(&head, x);

	Insert(&head, 2, 2); //List name, Data, Position
	Insert(&head, 3, 3); //List name, Data, Position
	Insert(&head, 4, 4); //List name, Data, Position
	Insert(&head, 5, 5); //List name, Data, Position
	Insert(&head, 6, 6); //List name, Data, Position
	Insert(&head, 7, 7); //List name, Data, Position

	IterativePrint(head);

	std::cout << "List is: ";
	RecursivePrint(head);
	std::cout << "\n";

	std::cout << "List printed in reverse is : ";
	ReverseRecursivePrint(head);
	std::cout << "\n";

	//ListCount(head);
	std::cout << "[INFO] List has been iteratively reversed.";
	IterativeReverse(&head);
	std::cout << "\n";

	IterativePrint(head);
	//Delete(head, 1); //Counting from 0
	std::cout << "[INFO] List has been recursively reversed.";
	RecursiveReverse(&head, head);
	std::cout << "\n";
	IterativePrint(head);
	std::cin.get();
}