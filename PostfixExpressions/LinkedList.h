#pragma once
#pragma once
#include "Node.h"
#include "LinkedListIterator.h"

namespace DataStructures
{
   template <class T> class LinkedList
   {
      public:
      LinkedList();
      // Initializes the list to an empty state.
      //    Postcondition: first = nullptr, last = nullptr,
      //    count = 0;

      LinkedList(const LinkedList<T> &otherList);
      // copy constructor

      ~LinkedList();
      // Deletes all the Nodes from the list.
      //    Postcondition: The list object is destroyed.

      const LinkedList<T> &operator=(const LinkedList<T> &);
      // Overload the assignment operator.

      bool operator!=(const LinkedList<T> &);
      // Overload the not-equal operator.

      bool operator==(const LinkedList<T> &);
      // Overload the equals operator.

      bool isEmptyList() const;
      // Function to determine whether the list is empty.
      //    Postcondition: Returns true if the list is empty,
      //    otherwise it returns false.

      void print() const;
      // Function to output the data contained in each Node.

      void reversePrint(Node<T>* current = nullptr) const;
      // Function to output the data in reverse order. 

      int length() const;
      // Function to return the number of Nodes in the list.

      void initializeList();
      // Initialize the list to an empty state.
      //    Postcondition: first = nullptr, last = nullptr,
      //    count = 0;

      void destroyList();
      // Function to delete all the Nodes from the list.
      //    Postcondition: first = nullptr, last = nullptr,
      //    count = 0;

      T front() const;
      // Function to return the first element of the list.
      //    Precondition: The list must exist and must not be empty.
      //    Postcondition: If the list is empty, the program
      //    terminates; otherwise, the first
      //    element of the list is returned.

      T back() const;
      // Function to return the last element of the list.
      //    Precondition: The list must exist and must not be empty.
      //    Postcondition: If the list is empty, the program
      //    terminates; otherwise, the last
      //    element of the list is returned.

      virtual bool search(const T &searchItem) const = 0;
      // Function to determine whether searchItem is in the list.
      //    Postcondition: Returns true if searchItem is in the
      //    list, otherwise the value false is
      //    returned.

      virtual void insertFirst(const T &newItem) = 0;
      // Function to insert newItem at the beginning of the list.
      //    Postcondition: first points to the newItem, newItem is
      //    inserted at the beginning of the list,
      //    and count is incremented by 1.

      virtual void insertLast(const T &newItem) = 0;
      // Function to insert newItem at the end of the list.
      //    Postcondition: last points to the newItem, newItem
      //    is inserted at the end of the list,
      //    and count is incremented by 1.

      virtual void deleteNode(const T &deleteItem) = 0;
      // Function to delete deleteItem from the list.
      //    Postcondition: If found, the Node containing
      //    deleteItem is deleted from the list 
      //    and count is decremented by 1.

      LinkedListIterator<T> begin();
      // Function to return an iterator at the begining of
      // the linked list.
      //    Postcondition: Returns an iterator such that current
      //    is set to first.

      LinkedListIterator<T> end();
      // Function to return an iterator one element past the
      // last element of the linked list.
      //    Postcondition: Returns an iterator such that current
      //    is set to nullptr.



      protected:
      int count;      //Stores the number of elements in the list
      Node<T> *first; //pointer to the first Node of the list
      Node<T> *last;  //pointer to the last Node of the list

      private:
      void copyList(const LinkedList<T> &otherList);
      // Function to make a copy of otherList.
      //    Postcondition: A copy of otherList is created and
      //    assigned to this list.
   };

   template<class T>
   LinkedList<T>::LinkedList()
   {
      first = nullptr;
      last = nullptr;
      count = 0;
   }

   template<class T>
   LinkedList<T>::LinkedList(const LinkedList<T> &otherList)
   {
      copyList(otherList);
   }

   template<class T>
   LinkedList<T>::~LinkedList()
   {
      destroyList();
   }

   template<class T>
   const LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &otherList)
   {
      if(*this != otherList)
         copyList(otherList);
      return *this;
   }

   template<class T>
   bool LinkedList<T>::operator!=(const LinkedList<T> &otherList)
   {
      return (this != &otherList);
   }

   template<class T>
   bool LinkedList<T>::operator==(const LinkedList<T> &otherList)
   {
      return (this == &otherList);
   }

   template<class T>
   bool LinkedList<T>::isEmptyList() const
   {
      return first == nullptr;
   }

   template<class T>
   void LinkedList<T>::print() const
   {
      Node<T> *current;
      current = first;
      while(current != nullptr)
      {
         std::cout << current->data << " ";
         current = current->link;
      }
   }

   template<class T>
   void LinkedList<T>::reversePrint(Node<T> *current) const
   {
      if (current == nullptr ) 
         current = first;

      if(current != last) //Base case : current = last
         reversePrint(current->link);

      std::cout << current->data << " ";
   }

   template<class T>
   int LinkedList<T>::length() const
   {
      return count;
   }

   template <class T>
   void LinkedList<T>::initializeList()
   {
      destroyList();
   }

   template<class T>
   void LinkedList<T>::destroyList()
   {
      Node<T> *temp;
      while(first != nullptr)
      {
         temp = first;
         first = first->link;
         delete temp;
      }
      last = nullptr;
      first = nullptr;
      count = 0;
   }

   template<class T>
   T LinkedList<T>::front() const
   {
      if(first == nullptr)
         throw std::invalid_argument("There is no element at the front of the list.");
      else
         return first->data;
   }

   template<class T>
   T LinkedList<T>::back() const
   {
      if(last == nullptr)
         throw std::invalid_argument("There is no element at the back of the list.");
      else
         return last->data;
   }

   template<class T>
   LinkedListIterator<T> LinkedList<T>::begin()
   {
      return LinkedListIterator<T>(first);
   }

   template<class T>
   LinkedListIterator<T> LinkedList<T>::end()
   {
      return LinkedListIterator<T>(nullptr);
   }

   template<class T>
   void LinkedList<T>::copyList(const LinkedList<T> &otherList)
   {
      Node<T> *newNode;
      Node<T> *current; //current will traverse the other list

      if(!isEmptyList())
         destroyList();

      if(otherList.isEmptyList())
      {
         first = nullptr;
         last = nullptr;
         count = 0;
      }
      else
      {
         first = new Node<T>;
         first->data = otherList.first->data;
         first->link = nullptr;
         last = first;
         count = otherList.count;

         //starts traversing at seccond Node
         current = otherList.first->link;
         while(current != nullptr)
         {
            // Copy the data of the other list's item into new memory (newNode)
            newNode = new Node<T>;
            newNode->data = current->data;
            newNode->link = nullptr;

            // The current last Node's link will point to the new Node
            // Then the class member last pointer will point to the new Node
            last->link = newNode;
            last = newNode;

            current = current->link;
         }
      }
   }
}