#include <iostream>

#include "Tqueue.h"

using namespace std;

int main()
{
    Tqueue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.print();
    q.pop_first();
    q.print();
    cout << q.size() << '\n';
    return 0;
}
