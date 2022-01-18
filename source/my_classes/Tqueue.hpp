#include <iostream>

using namespace std;

template <class T>
class Tqueue {
    struct Node
    {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };
    struct Node* Tail;
    struct Node* Head;
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
};

template<typename T>
void Tqueue<T>::raise_error(string e) { cout << ">>> < Tqueue_error > : " << e << '\n'; }

template<typename T>
Tqueue<T>::Tqueue() { cout << "made a queue at " << this << '\n'; }
template<typename T>
Tqueue<T>::~Tqueue()
{
    Node* temp = new Node;
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
    Node* temp = new Node;
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
    Node* temp = Head;
    while (temp != nullptr)
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
    Node* temp = new Node;
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
    Node* temp = new Node;
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
        Head = nullptr;
    else
    {
        Node* temp = Head;
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
    Node* temp = new Node;
    temp = Head;
    cout << "<Tqueue object at " << this << "> : [ ";
    while (temp != nullptr)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "]\n";
}
