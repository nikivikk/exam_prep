#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// - - - - - - Содержание - - - - - -
// bool isPrime(n)
// int Fibonacci(n);
// bool isPalindrome("asdd");
// int NOD(a, b);
// int NumberOfDigits(n);
// int ReverseNumber(n);
// bool isArmstrong(n);

// Проверяет является ли число простым
bool isPrime(long long int n, long long int i = 2)
{
    if (i > sqrt(n))return true;
    return n % i ? isPrime(n, ++i) : false;
}

// Считает n-ое число Фибоначчи
int Fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

// Проверяет является ли строка палиндромом
bool isPalindrome(string s)
{
    string k;
    for (auto c : s)
        k = c + k;
    if (s == k)
        return true;
    else
        return false;
}

// Находит НОД двух чисел
int NOD(int x, int y)
{
    if (x % y == 0)
        return y;
    if (y % x == 0)
        return x;
    if (x > y)
        return NOD(x % y, y);
    return NOD(x, y % x);
}

// Возвращает количество цифр числа
int NumberOfDigits(int n, int counter = 0)
{
    if (n == 0)
    {
        if (counter == 0)
            return 1;
        else
            return counter;
    }
    else
    {
        n = n / 10;
        counter++;
        NumberOfDigits(n, counter);
    }
    return 0; // у меня ругается но оно тут не надо
}

// Возвращает перевернутое число
int ReverseNumber(int x)
{
    int num = NumberOfDigits(x), i = 0, sum = 0;

    while (i != num)
    {
        sum = sum * 10 + x % 10;
        x /= 10;
        i++;
    }
    return sum;
}

// Функция проверяет является ли передаваемое число числом Армстронга
bool isArmstrong(long a)
{
      long k, c, chislo = a;
      long double m, t, k1;
      m = 0; k = 0;
      k1 = NumberOfDigits(a);
      k = k1 + 1;
      for (int p = 1; p < k + 1; ++p)
      {
          c = chislo % 10;
          chislo = (chislo - c) / 10;
          t = pow(c, k1);
          m += t;
      }
      if (m == a)
          return true;
      else
          return false;
}
