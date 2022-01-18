#pragma once

#include <fstream>
#include <sstream>

using namespace std;

// функция переводит все что угодно(почти) в строку(std::string)
template<typename T> std::string to_string(const T &t)
{
  return (std::stringstream()<<t).str();
}

// - - - - - - - - штуки чтобы выводить вектор через iostream и fstream- - - - - - -
// vector<int> v = {1, 2, 3};
// cout << v; // <- теперь работает!
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
template <typename T>
std::ofstream& operator <<(std::ofstream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - перегрузка вывода в консоль и в файл для класса - - - - - - - - -
// > > > class.h
//friend std::ostream &operator<<(std::ostream &os, TKprk const &m);
// > > > class.cpp
//std::ostream& operator<<(std::ostream &os, TKprk const &m)
//{
//    os << "Числа : ";
//    for (int i : m.num)
//        os << i << ' ';
//    os << '\n';
//    return os;
//}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void raise_error(string e) { printf("\n\t\"presets.h\" : ERROR : %s\n", e.c_str()); }

// функция считывает весь файл в векторный массив строк
// auto file_input = ReadFromFile("input.txt");
vector<string> ReadFromFile(string filename)
{
    vector<string> input;
    ifstream fin(filename);
    if (!fin.good())
        raise_error("file was not found");
    else
        while (!fin.eof())
        {
            string t;
            getline(fin, t);
            input.push_back(t);
        }
    return input;
}

// добавить разделение строк
