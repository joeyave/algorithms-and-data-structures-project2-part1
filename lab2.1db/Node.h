#pragma once
#include <cstddef>
#include <string>

class Node
{
private:
	Node* head = NULL;
public:
	std::string surname;
	Node* next;

	void push(std::string surname);
	void print();
	void print(Node* head);
	void alternating_split(Node** a_ref, Node** b_ref);
};

