#pragma once

#include <iostream>

using namespace std;

template <class T>
struct dNode
{
    T data;
    dNode* prev = nullptr;
    dNode* next = nullptr;
};

template <class T>
class Tdeque {
    struct dNode<T>* Tail;
    struct dNode<T>* Head;
    int amount = 0;
    void raise_error(string e);
public:
    Tdeque();
    ~Tdeque();
    Tdeque(const Tdeque& t);
    void push_front(T data);
    void push_back(T data);
    void pop_first();
    void pop_last();
    T front();
    T back();
    int size();
    void clear();
    bool isEmpty();
    void print();
    
//    friend std::ostream& operator<<(std::ostream &os, Tdeque<T> const &m);
};

template<typename T>
void Tdeque<T>::raise_error(string e) { cout << ">>> < Tdeque_error > : " << e << '\n'; }

template<typename T>
Tdeque<T>::Tdeque() { cout << "made a deque at " << this << '\n'; }
template<typename T>
Tdeque<T>::~Tdeque()
{
    dNode<T>* temp = new dNode<T>;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
    cout << "deleted a deque at " << this << '\n';
}
template<typename T>
Tdeque<T>::Tdeque(const Tdeque& t)
{
    Head = Tail = nullptr;
    dNode<T>* temp = new dNode<T>;
    temp = t.Head;
    while (temp != nullptr)
    {
        push(temp->data);
        temp = temp->next;
    }
}

template<typename T>
int Tdeque<T>::size()
{
    int sz = 0;
    dNode<T>* temp = Head;
    while (temp != Tail)
    {
        temp = temp->next;
        sz++;
    }
    return sz;
}

template<typename T>
bool Tdeque<T>::isEmpty()
{
    return (Head == nullptr);
}

template<typename T>
void Tdeque<T>::clear()
{
    dNode<T>* temp = new dNode<T>;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
}

template<typename T>
void Tdeque<T>::push_back(T data)
{
    dNode<T>* temp = new dNode<T>;
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
void Tdeque<T>::push_front(T data)
{
    dNode<T>* temp = new dNode<T>;
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
void Tdeque<T>::pop_first()
{
    if (Head == nullptr)
        raise_error("deque is empty. ABORTED");
    else if (Tail == nullptr)
    {
        Head = nullptr;
        raise_error("deque is empty. ABORTED");
    }
    else
    {
        dNode<T>* temp = Head;
        Head = Head->next;
        delete temp;
    }
}
template<typename T>
void Tdeque<T>::pop_last()
{
    if (Tail == nullptr)
        raise_error("deque is empty. ABORTED");
    else if (Head == nullptr)
    {
        Tail = nullptr;
        raise_error("deque is empty. ABORTED");
    }
    else
    {
        dNode<T>* temp = new dNode<T>;
        temp = Tail;
        Tail = Tail->prev;
        delete temp;
    }
}

template<typename T>
T Tdeque<T>::front()
{
    if (Head == nullptr)
        raise_error("missing first element. ABORTED");
    else
        return Head->data;
    return NULL;
}
template<typename T>
T Tdeque<T>::back()
{
    if (Tail == nullptr)
        raise_error("missing last element. ABORTED");
    else
        return Tail->data;
    return NULL;
}

template<typename T>
void Tdeque<T>::print()
{
    dNode<T>* temp = new dNode<T>;
    temp = Head;
    cout << "<Tdeque object at " << this << "> : [ ";
    while (temp != Tail)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "]\n";
}

//template<typename T>
//std::ostream& operator<<(std::ostream &os, Tdeque<T> const &m)
//{
//    dNode<T>* temp = new dNode<T>;
//    temp = m.Head;
////    os << "<Tdeque object at " << &m << "> : [ ";
//    while (temp != Tail)
//    {
//        os << temp->data << ' ';
//        temp = temp->next;
//    }
//    os << "]\n";
//    return os;
//}
