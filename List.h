#ifndef LIST_H
#define LIST_H

#include "Participant.h"

template<class T>
class List
{
  class Node
  {
    public:
      T data;
      Node* next;
  };

  public:
    List();
    ~List();
    List<T>& operator+=(T element);
    void convertToArray(T* arr,int& size);
  private:
    Node* head;
};

template <class T> 
List<T>::List() : head(nullptr) { }

template <class T> 
List<T>::~List()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T> List<T>& List<T>::operator+=(T element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    if(head == nullptr){
      head = newNode;
    }else{
      Node* lastNode = head;
      while(lastNode->next != nullptr){
        lastNode = lastNode->next;
      }
      lastNode->next = newNode;
    }
    return *this;
}
template<class T> void  List<T>::convertToArray(T* arr,int& size){
  Node* current=head;
  int index = 0;
  while (current!=nullptr)
  {
    arr[index] = current->data;
    current = current->next;
    index++;
  }
  size=index;
}



#endif
