#pragma once

struct Node {
	int data;
	Node* prev;
	Node* next;

	Node(int value) {
		data = value;
		prev = nullptr;
		next = nullptr;
	}
};