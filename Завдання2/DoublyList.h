#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class DoublyList {
private:
	Node* head;
	Node* tail;
public:
	DoublyList() {
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void addHead(int value) {
		Node* newNode = new Node(value);

		if (isEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
	}
	void addTail(int value) {
		Node* newNode = new Node(value);
		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void print() {
		if (isEmpty()) {
			cout << "List is null." << endl;
			return;
		}
		Node* current = head;
		cout << "L:";
		while (current != nullptr) {
			cout << current->data;
			if (current->next != nullptr)
				cout << " <-> ";

			current = current->next;

		}
		cout << endl;
	}

	void printReverse() {
		if (isEmpty()) {
			cout << "List is null." << endl;
			return;
		}

		Node* current = tail;
		cout << "Reversed list.";
		while (current != nullptr){
			cout << current->data;
			if (current->prev != nullptr)
				cout << " <->";

			current = current->prev;
		}
		cout << endl;
	}

	int length() {
		int count = 0;
		Node* current = head;

		while (current != nullptr) {
			count++;
			current = current->next;
		}
		return count;
	}

	void insertAfterFirst(int value) {
		if (isEmpty()) {
			cout << "You can't insert E, because the list is null.";
			return;
		}
		Node* newNode = new Node(value);
		if (head == tail) {
			newNode->prev = head;
			newNode->next = nullptr;
			head->next = newNode;
			tail = newNode;
			return;
		}
		Node* second = head->next;
		newNode->prev = head;
		newNode->next = second;
		head->next = newNode;
		second->prev = newNode;
	}

	int findMax() {
		if (isEmpty()) {
			cout << "List is null." << endl;
			
		}
		int maxValue = head->data;
		Node* current = head->next;
		while (current != nullptr) {
			if (current->data > maxValue) {
				maxValue = current->data;
			}
			current = current->next;
		}
		return maxValue;
	}

	void append(DoublyList& other) {
		if (other.isEmpty()) {
			return;
		}
		if (isEmpty()) {
			head = other.head;
			tail = other.tail;
		}
		else {
			tail->next = other.head;
			other.head->prev = tail;
			tail = other.tail;
		}
		other.head = nullptr;
		other.tail = nullptr;
	}

	Node* getHead() { return head; }
	Node* getTail() { return tail; }

	void clear() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
		tail = nullptr;
	}

	~DoublyList() { clear(); }
};