#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// - - - - - - - - - - -
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
template <typename T>
std::ofstream& operator <<(std::ofstream& foutput, const std::vector<T>& data)
{
    for (const T& x : data)
        foutput << x << " ";
    return foutput;
}
// - - - - - - - - - - -

bool check(int a) {
    if (a < 1000 || a > 9999)
        return false;
    if (a % 10 != a / 10 - a / 100 * 10
     || a % 10 != a / 100 - a / 1000 * 10
     || a % 10 != a / 1000)
        return true;
    return false;
}

pair<int, int> make_sorted(int a) {
    string t = to_string(a);
    sort(t.begin(), t.end());
    a = stoi(t);
    sort(t.rbegin(), t.rend());
    return { a, stoi(t) };
}

bool comparator(vector <int> a, vector <int> b) {
    return (a[0] < b[0]);
}

int main()
{
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    queue <int> q;
    char s[80];
    vector <int> chetyre;
        
    while (!fin.eof())
    {
        fin.getline(s, 80);
        char* pch = strtok(s, " ,.:;"); 

        while (pch != NULL)
        {
            q.push(stoi(pch));
            if (check(q.back()))
                chetyre.push_back(q.back());
            pch = strtok(NULL, " ,.;:");
        }
    }
    
    fout << "\tЧисла\n";
    while (!q.empty())
    {
        fout << q.back() << ' ';
        q.pop();
    }
    fout << '\n';
    
    vector <vector <int>> Matr;
    for (auto tmp_num : chetyre)
    {
        vector <int> t;
        t.push_back(0);
        t.push_back(tmp_num);
        int num = tmp_num;
        while (num != 6174)
        {
            auto temp = make_sorted(num);
            t.push_back(temp.second);
            t.push_back(temp.first);
            num = temp.second - temp.first;
            t.push_back(num);
            t[0] += 1;
        }
        Matr.push_back(t);
    }
    
    fout << "\tМатрица Matr\n";
    for (auto i : Matr)
        fout << i << '\n';
        
    sort(Matr.begin(), Matr.end(), comparator);
    fout << "\tМатрица Matr упорядоченная по возрастанию значений первого столбца\n";
    for (auto i : Matr)
        fout << i << '\n';
        
    return 0;
} 
