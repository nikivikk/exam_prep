#include <iostream>

#include "Tlist.h"
#include "Tdeque.h"
#include "Tqueue.h"
#include "Tstack.h"

using namespace std;

int mai2n()
{
    Tstack<int> st;
    st.push(234);
    st.push(345);
    cout << st.size() << ' ' << st.top() << '\n';
    cout << st.top() << '\n';
    st.push(12);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}

int mainnn()
{
    Tqueue<int> q;
    q.push(12);
    q.push(23);
    q.print();
    q.pop_first();
    q.print();
    q.pop_first();
    q.pop_first();
    q.pop_first();
//    cout << q;
    return 0;
}

int maihn()
{
    Tdeque<int> d;
    d.push_front(13);
    d.print();
    d.push_front(122);
    d.push_back(12);
    d.push_back(1);
    d.print();
    cout << '\n' << d.size() << '\n';
    d.pop_last();
    d.print();
    d.pop_first();
    d.pop_last();
    d.pop_last();
    d.pop_last();
    d.pop_last();
    d.pop_last();
    d.pop_last();
    d.pop_last();
    return 0;
}

int main()
{
    Tlist<int> l;
    l.push_back(12);
    l.push_back(16);
    l.push_back(15);
    l.push_back(14);
    l.push_back(13);
    l.print();
    cout << '\n' << l.size() << '\n';
    l.resize(7);
    cout << '\n' << l.size() << '\n';
    l.print();
    l.insert(l.size(), 3);
    l.print();
    return 0;
}
