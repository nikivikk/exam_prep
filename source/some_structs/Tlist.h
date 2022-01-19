#pragma once

#include <iostream>

using namespace std;

template <class T>
struct lNode
{
    T data;
    lNode* prev = nullptr;
    lNode* next = nullptr;
};

template <class T>
class Tlist {
    struct lNode<T>* Tail;
    struct lNode<T>* Head;
    int amount = 0;
    void raise_error(string e);
public:
    Tlist();
    ~Tlist();
    Tlist(const Tlist& t);
    void push_front(T data);
    void push_back(T data);
    void insert(int pos, T data);
    void pop_first();
    void pop_last();
    T front();
    T back();
    int size();
    void resize(int sz);
    void resize(int sz, T elem);
    void clear();
    bool isEmpty();
    void print();
    
//    friend std::ostream& operator<<(std::ostream &os, Tlist<T> const &m);
};

template<typename T>
void Tlist<T>::raise_error(string e) { cout << ">>> < Tlist_error > : " << e << '\n'; }

template<typename T>
Tlist<T>::Tlist() { cout << "made a list at " << this << '\n'; }
template<typename T>
Tlist<T>::~Tlist()
{
    lNode<T>* temp = new lNode<T>;
    while (Head != Tail->next)
    {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
    cout << "deleted a list at " << this << '\n';
}
template<typename T>
Tlist<T>::Tlist(const Tlist& t)
{
    Head = Tail = nullptr;
    lNode<T>* temp = new lNode<T>;
    temp = t.Head;
    while (temp != nullptr)
    {
        push(temp->data);
        temp = temp->next;
    }
}

template<typename T>
int Tlist<T>::size()
{
    int sz = 0;
    lNode<T>* temp = Head;
    while (temp != Tail->next)
    {
        temp = temp->next;
        sz++;
    }
    return sz;
}

template<typename T>
bool Tlist<T>::isEmpty()
{
    return (Head == nullptr);
}

template<typename T>
void Tlist<T>::clear()
{
    lNode<T>* temp = new lNode<T>;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
}

template<typename T>
void Tlist<T>::push_back(T data)
{
    lNode<T>* temp = new lNode<T>;
    temp->data = data;

    if (Head == nullptr)
    {
        Head = temp;
        Tail = Head;
    }
    else if (Tail == nullptr)
    {
        Tail = temp;
        Tail->prev = Head;
        Head->next = Tail;
    }
    else
    {
        Tail->next = temp;
        temp->prev = Tail;
        Tail = temp;
    }
}

template<typename T>
void Tlist<T>::push_front(T data)
{
    lNode<T>* temp = new lNode<T>;
    temp->data = data;

    if (Head == nullptr)
    {
        Head = temp;
        Tail = Head;
    }
    else if (Tail == nullptr)
    {
        Tail = temp;
        Tail->prev = Head;
        Head->next = Tail;
    }
    else
    {
        temp->next = Head;
        Head->prev = temp;
        Head = temp;
    }
}

template<typename T>
void Tlist<T>::insert(int pos, T data)
{
    lNode<T> *to_add = new lNode<T>;
    lNode<T> *left = new lNode<T>;
    lNode<T> *right = new lNode<T>;
    right = Head;
    to_add->data = data;
    
    if (pos > size())
    {
        raise_error("pos os too big");
        return;
    }
    
    if (pos == 0)
    {
        push_front(data);
        return;
    }
    if (pos == size())
    {
        push_back(data);
        return;
    }
    
    int t = 0;
    while (t < pos)
    {
        left = right;
        right = right->next;
        t++;
    }
    
    left->next = to_add;
    right->prev = to_add;
    to_add->prev = left;
    to_add->next = right;
}

template<typename T>
void Tlist<T>::pop_first()
{
    if (Head == nullptr)
        raise_error("list is empty. ABORTED");
    else if (Tail == nullptr)
    {
        Head = nullptr;
        raise_error("list is empty. ABORTED");
    }
    else
    {
        lNode<T>* temp = Head;
        Head = Head->next;
        delete temp;
    }
}
template<typename T>
void Tlist<T>::pop_last()
{
    if (Tail == nullptr)
        raise_error("list is empty. ABORTED");
    else if (Head == nullptr)
    {
        Tail = nullptr;
        raise_error("list is empty. ABORTED");
    }
    else
    {
        lNode<T>* temp = new lNode<T>;
        temp = Tail;
        Tail = Tail->prev;
        delete temp;
    }
}

template<typename T>
T Tlist<T>::front()
{
    if (Head == nullptr)
        raise_error("missing first element. ABORTED");
    else
        return Head->data;
    return NULL;
}
template<typename T>
T Tlist<T>::back()
{
    if (Tail == nullptr)
        raise_error("missing last element. ABORTED");
    else
        return Tail->data;
    return NULL;
}

template<typename T>
void Tlist<T>::resize(int sz)
{
    int t_sz = size();
    if (t_sz < sz)
        while (t_sz < sz)
        {
            push_back(NULL);
            t_sz++;
        }
    else
        while (t_sz > sz)
        {
            pop_last();
            t_sz--;
        }
}
template<typename T>
void Tlist<T>::resize(int sz, T elem)
{
    int t_sz = size();
    if (t_sz < sz)
        while (t_sz < sz)
        {
            push_back(elem);
            t_sz++;
        }
    else
        while (t_sz > sz)
        {
            pop_last();
            t_sz--;
        }
}

template<typename T>
void Tlist<T>::print()
{
    lNode<T>* temp = new lNode<T>;
    temp = Head;
    cout << "<Tlist object at " << this << "> : [ ";
    while (temp != Tail->next)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "]\n";
}

//template<typename T>
//std::ostream& operator<<(std::ostream &os, Tlist<T> const &m)
//{
//    lNode<T>* temp = new lNode<T>;
//    temp = m.Head;
//    os << "<Tlist object at " << &m << "> : [ ";
//    while (temp != nullptr)
//    {
//        os << temp->data << ' ';
//        temp = temp->next;
//    }
//    os << "]\n";
//    return os;
//}
