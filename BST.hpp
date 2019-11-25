#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"
#include <sstream>

template <typename T>

class BST 
{
public:
	BST()
	{
		head = NULL;
	}

	

	Node<T>* find(Node<T>* curr, T data) {
		if (curr->getData() == data)
			return curr;

		if (data < curr->getData())
		{
			if (curr->getLeft() == NULL) {
				return curr;
			}
			curr = curr->getLeft();
			return find(curr, data);
		}

		else 
		{
			if (curr->getRight() == NULL) {
				return curr;
			}
			curr = curr->getRight();
			return find(curr, data);
		}


	}

	void insert(T data)
	{

		C++;
		if (head == NULL)
		{
			head = new Node<T>(data);
			return;
		}

		Node<T>* temp = find(head, data);
		if (data < temp->getData())
		{
			temp->setLeft(new Node<T>(data));
			return;
		}

		else
		{
			temp->setRight(new Node<T>(data));
			return;
		}
	}

	int count()
	{
		return C;
	}


	bool contains(T data)
	{
		Node<T>* temp = find(head, data);
		if (temp->getData() == data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
	
	/*std::string search(T data) 
	{
		int found = 0;
		Node<T>* temp;
		temp = head;
		if (temp->getData()== data)
		{
			here << "Found: root(" << temp->getData() << ")";
			found = 1;
		}
		else 
		{
			if (temp->getData() > data) //left
			{
				temp = find(temp, data);
				here << "->left(" << temp->getData() << ")";
				nothere << "->left(" << temp->getData() << ")";
				found = 1;
			}
			else if (temp->getData() < data) 
			{
				temp = find(temp, data);
				here << "->right(" << temp->getData() << ")";
				nothere << "->right(" << temp->getData() << ")";
				found = 1;
			}
			if(contains(data))
			{
				return here.str();
			}
			else 
			{
				return nothere.str();
			}
		}


	}*/
	std::string search(T data)
	{
		std::cout << "SEARCH==================================" << std::endl;
		int found = 0;
		int notfound = 0;
		Node<T>* temp;
		temp = head;

		if (temp->getData() == data)
		{
			std::cout << "ROOT-------------------------------" << std::endl;
			here << "Found: " << "root(" << temp->getData() << ")";
			nothere << "Found: " << "root(" << temp->getData() << ")";
			found = 1;
		}
		else {
			if (temp->getData() > data) //left bit
			{
				temp = find(temp, data);
				here << "->left(" << temp->getData() << ")";
				nothere << "->left(" << temp->getData() << ")";
				found = 1;
			}
			else if (temp->getData() < data) //right bit
			{
				temp = find(temp, data);
				here << "->right(" << temp->getData() << ")";
				nothere << "->left(" << temp->getData() << ")";
				found = 1;
			}
		}
		if (contains(data))
		{
			std::cout << "PRINT" << std::endl;
			return here.str();
		}
		else
		{
			return nothere.str();
		}
	}


private:
	int C = 0;
	Node<T>* head;
	std::stringstream nothere;
	std::stringstream here;
	std::string path;
	
};


#endif
