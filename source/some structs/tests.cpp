#include <iostream>

#include "Tqueue.h"
#include "Tstack.h"

using namespace std;

int main()
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
