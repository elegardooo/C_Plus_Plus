#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
	int _size;
public:
	List() : head(nullptr), tail(nullptr) { _size = 0; };
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
		_size++;
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
		_size--;
	}
	T peek()
	{
		if (head != nullptr)
			return head->data;
		return NULL;
	}
	Node<T>* peek_head()
	{
		if (_size <= 0)
		{
			throw std::string("List is empty");
		}
		return head;
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
		_size++;
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
		_size--;
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
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	int size()
	{
		return _size;
	}
};