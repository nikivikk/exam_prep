#include <iostream>

using namespace std;

template <class T>
struct link {
public:
    T info;
    link* next;
};

template <class T>
class Tstack {
public:
    link<T>* head;
    Tstack();
    ~Tstack();
    bool empty();
    void pop();
    void push(T n);
    int size();
    int top();
};

template <class T>
Tstack<T>::Tstack() { head = NULL; cout << "Stack is created." << endl; }
template <class T>
Tstack<T>::~Tstack() { cout << "Die young." << endl; }

template <class T>
bool Tstack<T>::empty()
{
  return (head == NULL);
}

template <class T>
void Tstack<T>::pop()
{
    link<T>* temp = head;
    if (!empty())
    {
        head = head->next;
        delete temp;
    }
    else
        cout << "Stack is empty." << endl;
}

template <class T>
void Tstack<T>::push(T n)
{
    link<T>* temp = head;
    if (!empty())
    {
        link<T>* temp;
        temp = new link<T>;
        temp->info = n;
        temp->next = head;
        head = temp;
    }
    else
    {
        head = new link<T>;
        head->next = NULL;
        head->info = n;
    }
}

template <class T>
int Tstack<T>::size()
{
    link<T>* temp = head;
    int ssize = 0;
    while (temp != NULL)
    {
        ssize++;
        temp = temp->next;
    }
  return ssize;
}

template <class T>
int Tstack<T>::top() {
    if (!empty())
      return head->info;
    else
        cout << "Stack is empty." << endl;
  return 0;
}
