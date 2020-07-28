//							Created Stacks using classes

#include <iostream>
#include <string>
using namespace std;

struct Node {
	string data;
	Node* next;
};
class Stack
{
public:
	bool valid_braces(string braces,Stack s);
	string pop();
	string top();
	bool Empty();
	string Display();
	void push(char data);
	Stack();
	~Stack(); // To make sure there is no memory
private:
	Node* top1 = NULL;
};
bool Stack::valid_braces(string braces,Stack s)
{
	Node* temp;
	string x;
	for (int i = 0; i < braces.length(); i++)
	{
		if (braces[i] == '{' || braces[i] == '(' || braces[i] == '[')
		{
			s.push(braces[i]);
			continue;
		}
		switch (braces[i])
		{
		case ')':
			x = s.top();
			s.pop();
			if (x != "(")
				return false;
			break;
		case '}':
			x = s.top();
			s.pop();
			if (x != "{")
				return false;
			break;
		case ']':
			x = s.top();
			s.pop();
			if (x != "]")
				return false;
			break;
		}
		return(s.Empty());
	}
}
bool Stack::Empty() // To check wheteher top node is empty
{
	return top1 == NULL;

}
string Stack::Display()
{
	string result;
	Node* temp = top1;
	result = "\n(TOP) -> ";
	while (temp != NULL)
	{
		result += temp->data + " -> ";
		temp = temp->next;
	}
	result += "(END)\n";
	return result;
}
string Stack::top()
{
	if (!Empty()) {
		string value = top1->data;
		value += " is on the top.\n";
		return value;
	}
	else
		cout << "There is nothing on the top.\n";
}
string Stack::pop()
{
	if (!Empty()) {
		string result = top1->data;
		Node* oldtop = top1;
		top1 = oldtop->next;
		delete oldtop;
		result += " deleted..\n";
		return result;
	}
	else
		cout << "There is nothing to delete.\n";
}
void Stack::push(char data)
{

	Node* temp = new Node;
	temp->data = data;
	temp->next = top1;
	top1 = temp;
}

Stack::Stack()
{
	// initializing a constructor
}
Stack::~Stack()
{
	// initializing a deconstructor
	if (top1 == NULL)
		cout << "Nothing to clean up!\n";
	else
		cout << "Deleting everything...\n";
}

int main()
{
	Stack* s = new Stack();
	string braces = "{[]]}";
	cout << s->valid_braces(braces,*s);
}
