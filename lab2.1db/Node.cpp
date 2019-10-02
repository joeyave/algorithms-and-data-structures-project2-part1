#include "Node.h"
#include <iostream>
#include <cassert>

void Node::push(std::string surname)
{
	Node* temp = new Node();
	temp->surname = surname;
	temp->next = head;

	Node* trav = head;
	if (head)
	{
		while (trav->next != head)
			trav = trav->next;
		trav->next = temp;
	}
	else
		temp->next = temp;

	head = temp;
}

void Node::print()
{
	Node* trav = head;
	if (head)
	{
		do
		{
			std::cout << trav->surname << std::endl;
			trav = trav->next;
		} while (trav != head);
	}
}

void Node::print(Node* head)
{
	Node* trav = head;
	if (head)
	{
		while (trav)
		{
			std::cout << trav->surname << std::endl;
			trav = trav->next;
		} 
	}
}

void Node::alternating_split(Node** a_ref, Node** b_ref)
{
	Node* a_trav = head;
	Node* b_trav = head->next;
	do
	{
		Node* a_temp = new Node();
		a_temp->surname = a_trav->surname;
		a_temp->next = NULL;

		if (!*a_ref)
			*a_ref = a_temp;
		else
		{
			Node* trav = *a_ref;
			while (trav->next)
				trav = trav->next;

			trav->next = a_temp;
		}
		a_trav = a_trav->next->next;

		Node* b_temp = new Node();
		b_temp->surname = b_trav->surname;
		b_temp->next = NULL;

		if (!*b_ref)
			*b_ref = b_temp;
		else
		{
			Node* trav = *b_ref;
			while (trav->next)
				trav = trav->next;

			trav->next = b_temp;
		}
		b_trav = b_trav->next->next;
	} while (a_trav != head && b_trav != head->next);
}