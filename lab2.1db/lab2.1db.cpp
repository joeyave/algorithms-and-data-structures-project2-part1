// lab2.1db.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream readfile("db.txt");
	if (!readfile.is_open()) return 1;

	Node* list = new Node();

	std::string temp;
	while (std::getline(readfile, temp))
	{
		list->push(temp);
	}

	std::cout << "***** Before formatting. *****" << std::endl;
	list->print();

	Node* a = NULL;
	Node* b = NULL;
	list->alternating_split(&a, &b);
	std::cout << std::endl << "List 1 after formatting." << std::endl;
	list->print(a);
	std::cout << std::endl << "List 2 after formatting." << std::endl;
	list->print(b);
}






	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started: 
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
