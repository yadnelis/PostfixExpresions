#pragma once
#include "LinkedList.h"
#include <iostream>


namespace DataStructures
{

   template <class T>
   class UnorderedLinkedList: public LinkedList<T>
   {
      public:
      bool search(const T &searchItem) const;
      // Function to determine whether searchItem is in the list.
      //    Postcondition: Returns true if searchItem is in the
      //    list, otherwise the value false is
      //    returned.

      void insertFirst(const T &newItem);
      // Function to insert newItem at the beginning of the list.
      //    Postcondition: this->first points to the new list, newItem is
      //    inserted at the beginning of the list,
      //    this->last points to the this->last node in the
      //    list, and this->count is incremented by 1.

      void insertLast(const T &newItem);
      // Function to insert newItem at the end of the list.
      //    Postcondition: this->first points to the new list, newItem
      //    is inserted at the end of the list,

      void deleteNode(const T &deleteItem);
      // Function to delete deleteItem from the list.
      //    Postcondition: If found, the node containing
      //    deleteItem is deleted from the list.
      //    this->first points to the this->first node, this->last
      //    points to the this->last node of the updated
      //    list, and this->count is decremented by 1.
   };


   template<class T>
   bool UnorderedLinkedList<T>::search(const T &searchItem) const
   {
      Node<T> *current;
      bool found = false;

      current = this->first;
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
   void UnorderedLinkedList<T>::insertFirst(const T &newItem)
   {
      Node<T> *newNode;
      newNode = new Node<T>;
      newNode->data = newItem;
      newNode->link = this->first;
      this->first = newNode;

      this->count++;
      if(this->last == nullptr) // If there is only one item in the list
         this->last = newNode;
   }

   template<class T>
   void UnorderedLinkedList<T>::insertLast(const T &newItem)
   {
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
      else
      {
         // Insert node after last, then shift 
         // last to point to newNode
         this->last->link = newNode;
         this->last = newNode;
         this->count++;
      }
   }

   template<class T>
   void UnorderedLinkedList<T>::deleteNode(const T &deleteItem)
   {
      Node<T> *current;
      Node<T> *trailCurrent;

      if(this->isEmptyList())
         throw std::invalid_argument("Cannot delete from an empty list.");


      if(this->first->data == deleteItem) // Case 1 : deleteItem is the first element
      {
         current = this->first;
         this->first = this->first->link;
         this->count--;

         // List only has one node
         if(this->first == nullptr)
            this->last = nullptr;

         delete current;
      }
      else // Find item in the list
      {
         bool found = false;
         current = this->first->link;
         trailCurrent = this->first;

         while(current != nullptr && !found)
         {
            if(current->data != deleteItem)
            {
               trailCurrent = current;
               current = current->link;
            }
            else
               found = true;
         }
         // Case : deleteItem is not on the list
         if(!found)
            throw std::invalid_argument("Item to be deleted is not in the list");

         // Case : deleteItem was found
         trailCurrent->link = current->link;
         this->count--;

         // Case : deleteItem is the last element
         if(this->last == current)
            this->last = trailCurrent;

         delete current;
      }
   }
}