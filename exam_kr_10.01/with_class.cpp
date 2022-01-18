#include "TKprk.h"

using namespace std;

int main()
{
    ifstream fin("Input.txt");
    vector<string> input;
    while(!fin.eof())
    {
        string t;
        getline(fin, t);
        input.push_back(t);
    }
    TKprk obj(input);
    obj.count_Kprk();
    obj.build_matrix();
    obj.make_output();
    return 0;
}
