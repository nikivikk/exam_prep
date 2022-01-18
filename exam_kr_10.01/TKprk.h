#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class TKprk {
private:
    int amount_num = 0;
    int amount_Kprk = 0;
    vector <int> num;
    vector <int> Kprk;
    vector <vector<int>> Matr;
    int reverse(int a);
    int bubble_sort(int a);
    bool check(int a);
    vector <int> num_to_vector(int a);
public:
    TKprk() { cout << "\n< TKprk object has been created at " << this << " >\n"; };
    TKprk(int a);
    TKprk(vector <string> input);
    void add_number(int a);
    void count_Kprk();
    void build_matrix();
    void sort_matrix();
    void print_matrix();
    void make_output();
    
    friend std::ostream &operator<<(std::ostream &os, TKprk const &m);
    
    ~TKprk() { cout << "\n< TKprk object has been deleted at " << this << " >\n"; };
};
