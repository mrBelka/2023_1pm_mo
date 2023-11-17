#include <iostream>

//
#pragma pack(1)
struct Node
{
	int data;
	Node* next;
};
#pragma pack()

void Add(Node*& root, int data)
{
	if (root == nullptr)
	{
		root = new Node;
		root->data = data;
		root->next = nullptr;
		return;
	}
	Node* p = new Node;
	p->data = data;
	p->next = root->next;
	root->next = p;
}

void AddBack(Node* root, int data)
{
	Node* q = root;
	while (q->next != nullptr)
	{
		q = q->next;
	}

	Add(q, data);
}

void Print(Node* root)
{
	std::cout << "===" << std::endl;
	Node* p = root;
	while (p != nullptr)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
	std::cout << "===" << std::endl;
}

Node* DeleteByValue(Node* root, int value)
{
	Node* q = root;
	Node* p = root->next;
	while (p != nullptr)
	{
		if (p->data == value)
		{
			q->next = p->next;
			Node* tmp = p;
			p = p->next;
			delete tmp;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
}

void DuplicateByValue(Node* root, int value)
{
	Node* p = root;
	while (p != nullptr)
	{
		if (p->data == value)
		{
			Add(p, value);
			p = p->next;
		}
		p = p->next;
	}
}

void Free(Node*& root)
{
	Node* p = root;
	while (p != nullptr)
	{
		Node* q = p->next;
		delete p;
		p = q;
	}
	root = nullptr;
}

int main()
{
	Node* root = nullptr;

	Add(root, 1);
	Add(root, 3);
	Add(root, 5);
	Add(root, 4);

	//Print(root);

	//DeleteByValue(root, 4);

	Print(root);

	DuplicateByValue(root, 5);

	Print(root);



	Free(root);

	return 0;
}