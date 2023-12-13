#pragma once
#include <iostream>
#include "Node.h"
#include "Exceptions.h"

template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List() : head(nullptr), tail(nullptr) {};
	~List()
	{
		std::cout << "List destructor " << std::endl;
		//Node<T>* tmp = head;
		while (head != NULL)
		{
			Node<T>* next = head->next;
			delete head;
			head = next;
		}
	}
	void push(const T& value)
	{
		Node<T>* tmp = new Node<T>(value);
		if (head == nullptr)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tmp->next = head;
			head = tmp;
		}
	}
	void pop()
	{
		if (head != nullptr)
		{
			Node<T>* temp = head;
			head = head->next;
			if (head == nullptr)
				tail = nullptr;
			delete temp;
		}
	}
	T peek()
	{
		if (head != nullptr)
			return head->data;
		return NULL;
	}
	void push_back(const T& value)
	{
		Node<T>* tmp = new Node<T>(value);
		if (tail == nullptr)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	void pop_back()
	{
		if (head != nullptr)
		{
			if (head == tail)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				Node<T>* tmp = head;
				while (tmp->next != tail)
				{
					tmp = tmp->next;
				}
				delete tail;
				tail = tmp;
				tail->next = nullptr;
			}
		}
	}
	T peek_back()
	{
		if (tail != nullptr)
			return tail->data;
		return NULL;
	}
	void print()
	{
		Node<T>* tmp = head;
		while (tmp != nullptr)
		{
			std::cout << tmp->data << " ";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}

	bool isEmpty() const 
	{
		return head == nullptr;
	}
};