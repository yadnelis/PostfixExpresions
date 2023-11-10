#pragma once
#include "LinkedList.h"
#include "node.h"
#include <iostream>

namespace DataStructures
{
   template <class T>
   class OrderedLinkedList: public LinkedList<T>
   {
      public:

      bool search(const T &searchItem) const;
      // Function to determine whether searchItem is in the list.
      //    Postcondition: Returns true if searchItem is in the
      //    list, otherwise it returns false.

      void insert(const T &newItem);
      // Function to insert newItem in the list.
      //    Postcondition: newItem is inserted 
      //    at the proper place in the list, 
      //    and this->count is incremented by 1.

      void insertFirst(const T &newItem);
      // Function to insert newItem in the list.
      // Because the resulting list must be sorted, newItem is
      // inserted at the proper place in the list.
      // This function uses the function insert to insert newItem.
      //    Postcondition: this->first points to the new list, newItem is
      //    inserted at the proper place in the list,
      //    and this->count is incremented by 1.

      void insertLast(const T &newItem);
      // Function to insert newItem in the list.
      // Because the resulting list must be sorted, newItem is
      // inserted at the proper place in the list.
      // This function uses the function insert to insert newItem.
      //    Postcondition: this->first points to the new list, newItem is
      //    inserted at the proper place in the list,
      //    and this->count is incremented by 1.

      void deleteNode(const T &deleteItem);
      // Function to delete deleteItem from the list.
      //    Postcondition: If found, the node containing
      //    deleteItem is deleted from the list
      //    and this->count is decremented by 1.
      //    If deleteItem is not in the list, an
      //    appropriate message is printed.
   };

   template<class T>
   bool OrderedLinkedList<T>::search(const T &searchItem) const
   {
      Node<T> *current = this->first;
      bool found = false;

      while(current != nullptr && !found)
      {
         if(current->data == searchItem)
            found = true;
         else
            current = current->link;
      }
      return found;
   }

   template<class T>
   void OrderedLinkedList<T>::insert(const T &newItem)
   {
      Node<T> *current;
      Node<T> *trailCurrent;
      Node<T> *newNode;

      newNode = new Node<T>;
      newNode->data = newItem;
      newNode->link = nullptr;

      if(this->isEmptyList())
      {
         this->first = newNode;
         this->last = newNode;
         this->count++;
      }
      else // Traverese the list, until proper position is found
      {
         current = this->first;
         trailCurrent = nullptr;

         // Traverese the list until current is above or equal to newItem
         // List is in ascending order
         while(current != nullptr && current->data >= newItem) 
         {
            trailCurrent = current;
            current = current->link;
         }

         if(current == this->first) 
         {
            newNode->link = this->first;
            this->first = newNode;
            this->count++;
         }
         else
         {
            trailCurrent->link = newNode;
            newNode->link = current;

            if(current == nullptr)
               this->last = newNode;

            this->count++;
         }
      }
   }

   template<class T>
   void OrderedLinkedList<T>::insertFirst(const T &newItem)
   {
      insert(newItem);
   }

   template<class T>
   void OrderedLinkedList<T>::insertLast(const T &newItem)
   {
      insert(newItem);
   }

   template<class T>
   void OrderedLinkedList<T>::deleteNode(const T &deleteItem)
   {
      Node<T> *current;
      Node<T> *trailCurrent;
      bool found;

      if(this->isEmptyList())
         throw std::invalid_argument("Cannot delete from an empty list.");

      current = this->first;
      trailCurrent = nullptr;
      found = false;

      while(current != nullptr && !found) 
      {
         if(current->data == deleteItem)
            found = true;
         else
         {
            trailCurrent = current;
            current = current->link;
         }
      }

      if(!found)
         throw std::invalid_argument("Item to be deleted is not in the list.");

      // If deleteItem is first, point first to the second item before deleteing
      if(this->first == current) 
      {
         this->first = this->first->link;
         if(this->first == nullptr)
            this->last = nullptr;

         delete current;
      }
      else
      {
         trailCurrent->link = current->link;

         //if deleteitem is last, make sure last is pointg to the element before last
         if(current == this->last) 
            this->last = trailCurrent;

         delete current;
      }
      this->count--;
   }
}

