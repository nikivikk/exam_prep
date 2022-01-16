#include "TKprk.h"
using namespace std;
bool check(int a) {
    if (a < 1000 ||  a>9999) {
        return false;
    }
    int b = a;
    int a1 = b % 10;
    b /= 10;
    int a2 = b % 10;
    b /= 10;
    int a3 = b % 10;
    b /= 10;
    int a4 = b;
    if (a1 != a2  || a1 != a3 || a1 != a4) {
        return true;
    }
    else {
        return false;
    }
}
pair<int, int> Sort(int a) {
    vector < int > c;
    while (a != 0) {
        c.push_back(a % 10);
        a /= 10;
    }
    sort(c.begin(), c.end());
    for (auto item : c) {
        a = a * 10 + item;
    }
    int b = c[3] * 1000 + c[2] * 100 + c[1] * 10 + c[0];
    return { a, b};
}
bool comparator(vector <int> a, vector <int> b) {
    if (a[0] < b[0])
        return 1;
    else 
        return 0;
}
int main() {
    ifstream fin("Input.txt");
    ofstream fout("Output.txt");
    queue <int> q;
    char s[80];
    vector <int> chetyre;
    while (!fin.eof()) {
        fin.getline(s, 80);
        char* pch = strtok(s, " ,.:;"); 

        while (pch != NULL)
        {
            q.push(stoi(pch));
            if (check(q.back())) {
                chetyre.push_back(q.back());
            }
            pch = strtok(NULL, " ,.;:");
        }
    }
    vector <vector <int>> Matr;
    for (int i = 0; i < chetyre.size(); i++) {
        vector <int> t;
        t.push_back(0);
        t.push_back(chetyre[i]);
        int num = chetyre[i];
        while (num != 6174) {
            pair <int, int> temp = Sort(num);
            t.push_back(temp.second);
            t.push_back(temp.first);
            num = temp.second - temp.first;
            t.push_back(num);
            t[0] = t[0] + 1;
        }
        Matr.push_back(t);
    }
    sort(Matr.begin(), Matr.end(), comparator);
    for (int i = 0; i < Matr.size(); i++) {
        for (int j = 0; j < Matr[i].size(); j++) {
            fout << Matr[i][j] << '\t';
        }
        fout << '\n';
    }
    return 0;
} 

