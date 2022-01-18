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
//std::ostream &operator<<(std::ostream &os, myClass const &obj) {
//    return os << obj.any;
//}
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void raise_error(string e) { printf("\n\t\"presets.h\" : ERROR : %s\n", e.c_str()); }

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
