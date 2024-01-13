#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class List
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List() : head(nullptr), tail(nullptr) {};
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
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

	class Iterator
	{
		Node<T>* current;
	public:
		Iterator(Node<T>* start) : current(start) {};

		T& operator*() const {
			return (current->data);
		}

		Iterator& operator++() {
			current = current->next;
			return *this;
		}

		Iterator operator+(int offset) const {
			Iterator result = *this;
			for (int i = 0; i < offset; i++) {
				if (result.current == nullptr)
					break;
				result.current = result.current->next;
			}
			return result;
		}

		bool operator==(const Iterator& other) const {
			return current == other.current;
		}

		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}
	};

	Iterator begin() const {
		return Iterator(head);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}

	template <typename Predicate>
	Iterator search(Iterator begin, Iterator end, Predicate condition) {
		while (begin != end) {
			if (condition(*begin)) {
				return begin;
			}
			++begin;
		}
		return end;
	}

	template <typename Predicate>
	void sort(Iterator begin, Iterator end, Predicate condition) {
		bool swapped;
		do {
			swapped = false;
			for (Iterator it = begin; it != end && it + 1 != end; ++it) {
				Iterator nextIt = it + 1;
				if (condition(*it, *nextIt)) {
					std::swap(*it, *nextIt);
					swapped = true;
				}
			}
		} while (swapped);
	}
};