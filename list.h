#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template <typename Type>
class List {
private:
    struct Node {
        Type element;
        Node *previous;
        Node *next;

        Node(Type element1, Node *previous1 = nullptr, Node *next1 = nullptr) {
            this->element = element1;
            this->previous = previous1;
            this->next = next1;
        }
    };

public:
    class Const_Iterator {
    protected:
        Node *ptr;
        Const_Iterator(Node *node) { this->ptr = node; }
    public:
        Const_Iterator() { this->ptr = nullptr; }
        Type operator*() { return ptr->element; }
        Const_Iterator operator++() {
            Const_Iterator copyy(ptr);
            ptr = ptr->next;
            return copyy;
        }
        Const_Iterator operator++(int) {
            ptr = ptr->next;
            return *this;
        }
        Const_Iterator operator--() {
            Const_Iterator copyy(ptr);
            ptr = ptr->previous;
            return copyy;
        }
        Const_Iterator operator--(int) {
            ptr = ptr->previous;
            return *this;
        }
        friend bool operator==(Const_Iterator it1, Const_Iterator it2) {
            return it1.ptr == it2.ptr;
        }
        friend bool operator!=(Const_Iterator it1, Const_Iterator it2) {
            return !(it1 == it2);
        }
        friend class List<Type>;
    };

    class Iterator: public Const_Iterator {
    public:
        Iterator(Node *node): Const_Iterator(node) {}
        Type& operator*() {
            return this->ptr->element;
        }
        Iterator operator++() {
            Iterator copyy(this->ptr);
            this->ptr = this->ptr->next;
            return copyy;
        }
        Iterator operator++(int) {
            this->ptr = this->ptr->next;
            return *this;
        }
        Iterator operator--() {
            Iterator copyy(this->ptr);
            this->ptr = this->ptr->previous;
            return copyy;
        }
        Iterator operator--(int) {
            this->ptr = this->ptr->previous;
            return *this;
        }
        friend class List<Type>;
    };

private:
    Node *head;
    Node *tail;
    int numberOfElements;
    void init();

public:
    List() { init(); }
    List(int n, Type value = Type()) {
        init();
        for(int i = 0; i < n; i++) {
            PushBack(value);
        }
    }
    List(const List<Type> &copyy);
    List(const List<Type> &&copyy);
    ~List();
    List<Type>& operator=(const List<Type> &rhs);
    Iterator Begin() { return head->next; }
    Iterator End() { return tail; }
    Const_Iterator Begin() const { return head->next; }
    Const_Iterator End() const { return tail; }
    Iterator Insert(Iterator position, const Type value);
    void PushBack(Type value) { Insert(tail, value); }
    void PushFront(Type value) { Insert(head->next, value); }
    Iterator Erase(Iterator position);
    void PopFront() { Erase(head->next); }
    void PopBack() { Erase(tail->previous); }
    int Size() { return numberOfElements; }
    bool Empty() const { return numberOfElements == 0; }
    void Clear() { while(!Empty()) PopBack(); }
};

#include "list.cpp"

#endif // LIST_H_INCLUDED
