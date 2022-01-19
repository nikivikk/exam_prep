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
    cout << obj;
    
    obj.count_Kprk();
    obj.build_matrix();
    obj.make_output();
    
    cout << "making new class : ";
    TKprk new_obj = obj;
    cout << new_obj;
    cout << "\nперегрузка [] : " << new_obj[0];
    
    return 0;
}
