#pragma once

#include <iostream>

using namespace std;

template <class T>
struct qNode
{
    T data;
    qNode* prev = nullptr;
    qNode* next = nullptr;
};

template <class T>
class Tqueue {
    struct qNode<T>* Tail;
    struct qNode<T>* Head;
    int amount = 0;
    void raise_error(string e);
public:
    Tqueue();
    ~Tqueue();
    Tqueue(const Tqueue& t);
    void push(T data);
    void pop_first();
    T front();
    T back();
    int size();
    void clear();
    bool isEmpty();
    void print();
    
//    friend std::ostream& operator<<(std::ostream &os, Tqueue<T> const &m);
};

template<typename T>
void Tqueue<T>::raise_error(string e) { cout << ">>> < Tqueue_error > : " << e << '\n'; }

template<typename T>
Tqueue<T>::Tqueue() { cout << "made a queue at " << this << '\n'; }
template<typename T>
Tqueue<T>::~Tqueue()
{
    qNode<T>* temp = new qNode<T>;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
    cout << "deleted a queue at " << this << '\n';
}
template<typename T>
Tqueue<T>::Tqueue(const Tqueue& t)
{
    Head = Tail = nullptr;
    qNode<T>* temp = new qNode<T>;
    temp = t.Head;
    while (temp != nullptr)
    {
        push(temp->data);
        temp = temp->next;
    }
}

template<typename T>
int Tqueue<T>::size()
{
    int sz = 0;
    qNode<T>* temp = Head;
    while (temp != Tail)
    {
        temp = temp->next;
        sz++;
    }
    return sz;
}

template<typename T>
bool Tqueue<T>::isEmpty()
{
    return (Head == nullptr);
}

template<typename T>
void Tqueue<T>::clear()
{
    qNode<T>* temp = new qNode<T>;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->next;
        delete temp;
    }
}

template<typename T>
void Tqueue<T>::push(T data)
{
    qNode<T>* temp = new qNode<T>;
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
void Tqueue<T>::pop_first()
{
    if (Head == nullptr)
        raise_error("queue is empty. ABORTED");
    else if (Tail == nullptr)
    {
        Head = nullptr;
        raise_error("queue is empty. ABORTED");
    }
    else
    {
        qNode<T>* temp = Head;
        Head = Head->next;
        delete temp;
    }
}

template<typename T>
T Tqueue<T>::front()
{
    if (Head == nullptr)
        raise_error("missing first element. ABORTED");
    else
        return Head->data;
    return NULL;
}
template<typename T>
T Tqueue<T>::back()
{
    if (Tail == nullptr)
        raise_error("missing last element. ABORTED");
    else
        return Tail->data;
    return NULL;
}

template<typename T>
void Tqueue<T>::print()
{
    qNode<T>* temp = new qNode<T>;
    temp = Head;
    cout << "<Tqueue object at " << this << "> : [ ";
    while (temp != Tail)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "]\n";
}

//template<typename T>
//std::ostream& operator<<(std::ostream &os, Tqueue<T> const &m)
//{
//    qNode<T>* temp = new qNode<T>;
//    temp = m.Head;
////    os << "<Tqueue object at " << &m << "> : [ ";
//    while (temp != nullptr)
//    {
//        os << temp->data << ' ';
//        temp = temp->next;
//    }
//    os << "]\n";
//    return os;
//}
