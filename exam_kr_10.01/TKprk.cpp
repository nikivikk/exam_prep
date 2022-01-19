#include "TKprk.h"
using namespace std;
void TKprk::add_number(int a)
{
    num.push_back(a);
    amount_num++;
}
int TKprk::bubble_sort(int a)
{
    string v = to_string(a);
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v.size() - i - 1; j++)
                if (v[j] > v[j + 1])
                    swap(v[j], v[j + 1]);
    return stoi(v);
}
int TKprk::reverse(int a)
{
    int reverse = 0, rem;
    while(a != 0)
    {
        rem = a % 10;
        reverse = reverse * 10 + rem;
        a /= 10;
    }
    return reverse;
}
bool TKprk::check(int a)
{
    if (a < 1000 || a > 9999)
        return false;
    int b = a;
    int a1 = b % 10;
    b /= 10;
    int a2 = b % 10;
    b /= 10;
    int a3 = b % 10;
    b /= 10;
    int a4 = b;
    if (a1 != a2 || a1 != a3 || a1 != a4)
        return true;
    else
        return false;
}
void TKprk:: count_Kprk() {
    for (int item : num)
        if (check(item)) {
            Kprk.push_back(item);
            amount_Kprk++;
        }
}
TKprk::TKprk(vector<string> input)
{
    string delimiters = " ,.:;";
    for (string s : input)
    {
        string t = "";
        for (char c : s)
            if (delimiters.find(c) != string::npos)
            {
                if (t != "")
                    num.push_back(stoi(t));
                t = "";
            }
            else
                t += c;
        if (t != "")
            num.push_back(stoi(t));
    }
}
vector<int> TKprk::num_to_vector(int a)
{
    vector <int> ma;
    ma.push_back(0);
    ma.push_back(a);
    while (a != 6174)
    {
        int b = bubble_sort(a);
        a = reverse(b);
        while (a < 1000) a *= 10;
        ma.push_back(a);
        ma.push_back(b);
        a -= b;
        ma.push_back(a);
        ma[0] += 1;
    }
    return ma;
}
void TKprk::build_matrix()
{
    for (int item : Kprk)
        Matr.push_back(num_to_vector(item));
}
void TKprk::print_matrix()
{
    for (auto i : Matr)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
}

bool comparator(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
void TKprk::sort_matrix()
{
    sort(Matr.begin(), Matr.end(), comparator);
}

void TKprk::make_output()
{
    ofstream fout("Output.txt");
    fout << "Числа\n";
    for (int i : num)
        fout << i << ' ';
    fout << "\nМатрица Matr\n";
    for (vector<int> i: Matr)
    {
        for (int j : i)
            fout << j << '\t';
        fout << '\n';
    }
    sort_matrix();
    fout << "\nМатрица Matr упорядоченная по возрастанию значений первого столбца\n";
    for (vector<int> i: Matr)
    {
        for (int j : i)
            fout << j << '\t';
        fout << '\n';
    }
}

std::ostream& operator<<(std::ostream &os, TKprk const &m)
{
    os << "Числа : ";
    for (int i : m.num)
        os << i << ' ';
    os << '\n';
    return os;
}

TKprk TKprk::operator=(TKprk &t)
{
    TKprk new_obj;
    new_obj.num = t.num;
    new_obj.Kprk = t.Kprk;
    new_obj.Matr = t.Matr;
    return new_obj;
}

int TKprk::operator[](int i)
{
    return Kprk[i];
}
