#pragma once
#include <iostream>

class Time {
public:
  // Конструкторы
  Time();
  Time(short int hours, short int minutes);
  Time(int totalMinutes);

  // Вывод времени в формате ЧЧ:ММ
  void print() const;

  // Унарные операторы:
  Time& operator++();        // префиксный: ++t
  Time operator++(int);      // постфиксный: t++
  Time& operator--();        // префиксный: --t
  Time operator--(int);      // постфиксный: t--

  // Приведение типов
  operator int() const;              // неявное → общее число минут
  explicit operator bool() const;    // явное → true, если время ≠ 00:00

  // Бинарные сравнения с целым числом (минутами)
  bool operator<(int minutes) const;  
  bool operator>(int minutes) const;  

  // Вычитание времени 
  Time operator-(const Time& other) const;

private:
  short int hours_;
  short int minutes_;

  // Нормализация времени в диапазон [00:00, 23:59]
  void normalize();
};