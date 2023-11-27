#include "list.h"

template <typename Type>
void List<Type>::init() {
    numberOfElements = 0;
    head = new Node(Type{});
    tail = new Node(Type{}, head);
    head->next = tail;
}

template <typename Type>
typename List<Type>::Iterator List<Type>::Insert(Iterator position, const Type value) {
    Node *neww = new Node(value, position.ptr->previous, position.ptr);
    position.ptr->previous->next = neww;
    position.ptr->previous = neww;
    numberOfElements++;
    return neww;
}

template <typename Type>
typename List<Type>::Iterator List<Type>::Erase(Iterator position) {
    Iterator toReturn(position.ptr->next);
    toReturn.ptr->previous = position.ptr->previous;
    position.ptr->previous->next = toReturn.ptr;
    delete position.ptr;
    numberOfElements--;
    return toReturn;
}

template <typename Type>
List<Type>::List(const List<Type> &copyy) {
   init();
   for(auto it = copyy.Begin(); it != copyy.End(); it++)
        PushBack(*it);
}

template <typename Type>
List<Type>& List<Type>::operator=(const List<Type> &rhs) {
    if(this == &rhs)
        return *this;
    Clear();
    for(auto it = rhs.Begin(); it != rhs.End(); it++)
        PushBack(*it);
    return *this;
}

template <typename Type>
List<Type>::~List() {
    Clear();
    delete head;
    delete tail;
}

template <typename Type>
List<Type>::List(const List<Type> &&copyy) {
  head = copyy.head;
  tail = copyy.tail;
  numberOfElements = copyy.numberOfElements;

  copyy.head = nullptr;
  copyy.tail = nullptr;
  copyy.numberOfElements = 0;
}
