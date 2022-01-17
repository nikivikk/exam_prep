#include <iostream>

#include "all_sorts.cpp"

using namespace std;

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}

int main()
{
    vector<int> v = {2, 1, 3, 4, 7, 6, 2, 5};
    int a[] = {4, 3, 5, 2, 6, 8, 5};
    
    heap_sort(v, v.size());
    cout << v;
    
//    cout << t;
    
    return 0;
}
