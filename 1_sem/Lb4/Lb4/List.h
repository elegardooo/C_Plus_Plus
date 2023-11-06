#pragma once

template <typename T>
class Node
{
public:
	T data;
	Node *next;
	Node(const T &value) : data(value), next(nullptr) {};

};

template <typename T>
class List
{
private:
	Node<T> *head;
	Node<T> *tail;
public:
	List() : head(nullptr), tail(nullptr) {};
	void push(const T &value)
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
};