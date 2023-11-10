#pragma once
#include "Node.h"

namespace DataStructures
{
   template <class T>
   class LinkedListIterator
   {
      public:
      LinkedListIterator();
      //Default constructor
      //Postcondition: current = nullptr;

      LinkedListIterator(Node<T> *ptr);
      //Constructor with a parameter.
      //Postcondition: current = ptr;

      T operator*();
      //Function to overload the dereferencing operator *.
      //Postcondition: Returns the info contained in the Node.

      LinkedListIterator<T> operator++();
      //Overload the pre-increment operator.
      //Postcondition: The iterator is advanced to the next
      // Node.

      bool operator==(const LinkedListIterator<T> &right) const;
      //Overload the equality operator.
      //Postcondition: Returns true if this iterator is equal to
      // the iterator specified by right,
      // otherwise it returns false.

      bool operator!=(const LinkedListIterator<T> &right) const;
      //Overload the not equal to operator.
      //Postcondition: Returns true if this iterator is not equal
      // to the iterator specified by right,
      // otherwise it returns false.

      private:
      Node<T> *current;
      //pointer to point to the current
      //Node in the linked list
   };

   template <class T>
   LinkedListIterator<T>::LinkedListIterator()
   {
      current = nullptr;
   }

   template <class T>
   LinkedListIterator<T>::LinkedListIterator(Node<T> *ptr)
   {
      current = ptr;
   }

   template <class T>
   T LinkedListIterator<T>::operator*()
   {
      return current->data;
   }

   template <class T>
   LinkedListIterator<T> LinkedListIterator<T>::operator++()
   {
      current = current->link;
      return *this;
   }

   template <class T>
   bool LinkedListIterator<T>::operator==(const LinkedListIterator<T> &right) const
   {
      return (current == right.current);
   }

   template <class T>
   bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T> &right) const
   {
      return (current != right.current);
   }
}



