#include<iostream>

using std::cout;
using std::endl;

class Node
{
public:
	Node(int v, Node* p, Node* n)
	{
		value = v;
		prevNode = p;
		nextNode = n;
	}

	int getValue() {
		return value;
	}
	void setNext(Node* n)
	{
		nextNode = n;
	}

	void setPrev(Node* p)
	{
		prevNode = p;
	}

	Node* getNext()
	{
		return nextNode;
	}

	Node* getPrev()
	{
		return prevNode;
	}
private:
	int value;
	Node* prevNode, * nextNode;

};

class DoublyLink
{
public:
	DoublyLink()
	{
		head = tail = nullptr;
	}
	~DoublyLink();
	void clear();
	void addBack(int);
	void printForward();
	void printBackward();
	void addFront(int);
	void removeFront();
	void removeBack();
	int size();
	bool empty() {
		return (head == nullptr);
	}

private:
	Node *head, *tail;
};

int main()
{
	DoublyLink list;
	for (int i = 1; i <= 10; i++) list.addBack(2 * i);
	cout << "Original List:\n";
	list.printForward();
	cout << "Size = " << list.size() << endl;

	cout << "\nAfter callin removeFront twice:\n";
	list.removeFront();
	list.removeFront();
	list.printForward();
	cout << "Size = " << list.size() << endl;

	cout << "\nAfter callin removeBack twice:\n";
	list.removeBack();
	list.removeBack();
	list.printForward();
	cout << "Size = " << list.size() << endl;
	
	cout << "\nAfter callin addFront twice:\n";
	list.addFront(90);
	list.addFront(30);
	list.printForward();
	cout << "Size = " << list.size() << endl;

	
	return 0;
}

DoublyLink::~DoublyLink() {
	while (head != tail) {
		Node* n = head->getNext();
		delete head;
		head = n;
	}
}

void DoublyLink::addBack(int v)
{
	if (tail != nullptr) {
		//create new node
		Node* newTail = new Node(v,tail, nullptr);
		tail->setNext(newTail);
		tail = newTail;
	}
	else {
		head = tail = new Node(v, nullptr, nullptr);
	}
}

void DoublyLink::printForward()
{
	if (empty()) return;
	Node* n = head;
	while (n != nullptr)
	{
		cout << n->getValue() << " ==> ";
		n = n->getNext();
	}
	cout << endl;
}

void DoublyLink::printBackward()
{
	if (empty()) return;
	Node* n = tail;
	while (n != nullptr)
	{
		cout << n->getValue() << " ==> ";
		n = n->getPrev();
	}

	cout << endl;
}

void DoublyLink::addFront(int v) {
	//create new head
	if (!empty()) {
		Node* newHead = new Node(v, nullptr, head);
		head->setPrev(newHead);
		head = newHead;
	}
	else {
		head=tail = new Node(v, nullptr, nullptr);
	}
}

void DoublyLink::removeFront() {
	
	

	if (head!=tail)
	{
		//create new head
		Node* newHead = head->getNext();
		delete head;
		newHead->setPrev(nullptr);

		head = newHead;
	}
	else {
		head = tail = nullptr;
	}
}

int DoublyLink::size()
{
	if (empty()) return 0;

	int s = 0;
	Node* n = head;
	while (n != nullptr) {
		n = n->getNext();
		s++;
	}

	return s;
}

void DoublyLink::removeBack() {
	if (tail != head) {
		//create new tail
		Node* newTail = tail->getPrev();
		delete tail;
		newTail->setNext(nullptr);
		tail = newTail;
	}
	else {
		head = tail = nullptr;
	}
}

void DoublyLink::clear() {
	
	while (!empty()) {
		removeFront();
	}
}
