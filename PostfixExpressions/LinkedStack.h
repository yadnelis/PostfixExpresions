#pragma once
#include "UnorderedLinkedList.h"

namespace DataStructures
{
	template <class T>
	class LinkedStack: private DataStructures::UnorderedLinkedList<T>
	{
		public:

		bool isEmptyStack() const;
		//Function to determine whether the stack is empty.
		//Postcondition: Returns true if the stack is empty;
		// otherwise returns false.

		bool isFullStack() const;
		//Function to determine whether the stack is full.
		//Postcondition: Returns false.

		void initializeStack();
		//Function to initialize the stack to an empty state.
		//Postcondition: The stack elements are removed;
		// stackTop = nullptr;

		void push(const T &newItem);
		//Function to add newItem to the stack.
		//Precondition: The stack exists and is not full.
		//Postcondition: The stack is changed and newItem
		// is added to the top of the stack.

		T top() const;
		//Function to return the top element of the stack.
		//Precondition: The stack exists and is not empty.
		//Postcondition: If the stack is empty, the program
		// terminates; otherwise, the top
		// element of the stack is returned.

		void pop();
		//Function to remove the top element of the stack.
		//Precondition: The stack exists and is not empty.
		//Postcondition: The stack is changed and the top
		// element is removed from the stack.

		void print() const;

		private:
		DataStructures::UnorderedLinkedList<T> list;

	};


	template<class T>
	inline bool LinkedStack<T>::isEmptyStack() const
	{
		return this->isEmptyList();
	}

	template<class T>
	inline bool LinkedStack<T>::isFullStack() const
	{
		return false;
	}

	template<class T>
	inline void LinkedStack<T>::initializeStack()
	{
		this->initializeList();
	}

	template<class T>
	inline void LinkedStack<T>::push(const T &newItem)
	{
		this->insertFirst(newItem);
	}

	template<class T>
	inline T LinkedStack<T>::top() const
	{
		return this->first->data;
	}

	template<class T>
	inline void LinkedStack<T>::pop()
	{
		this->deleteNode(this->first->data);
	}

	template<class T>
	inline void LinkedStack<T>::print() const
	{
		this->reversePrint();
	}
}