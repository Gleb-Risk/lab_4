#include "Time.h"

Time::Time() : hours_(0), minutes_(0) {}

Time::Time(short int h, short int m) {
  hours_ = h;
  minutes_ = m;
  normalize();
}

Time::Time(int totalMinutes) {
  totalMinutes %= 1440;
  if (totalMinutes < 0) totalMinutes += 1440;
  hours_ = static_cast<short int>(totalMinutes / 60);
  minutes_ = static_cast<short int>(totalMinutes % 60);
}

void Time::print() const {
  std::cout << (hours_ < 10 ? "0" : "") << hours_;
  std::cout << ":" << (minutes_ < 10 ? "0" : "") << minutes_;
}

void Time::normalize() {
  int total = hours_ * 60 + minutes_;
  total %= 1440;
  if (total < 0) total += 1440;
  hours_ = static_cast<short int>(total / 60);
  minutes_ = static_cast<short int>(total % 60);
}

// ++t: добавить 1 минуту
Time& Time::operator++() {
  minutes_++;
  if (minutes_ == 60) {
    minutes_ = 0;
    hours_ = (hours_ + 1) % 24;
  }
  return *this;
}

// t++: вернуть копию, затем добавить 1 минуту
Time Time::operator++(int) {
  Time temp = *this;
  ++(*this);
  return temp;
}

// --t: вычесть 1 минуту
Time& Time::operator--() {
  minutes_--;
  if (minutes_ < 0) {
    minutes_ = 59;
    hours_ = (hours_ - 1 + 24) % 24;
  }
  return *this;
}

// t--: вернуть копию, затем вычесть 1 минуту
Time Time::operator--(int) {
  Time temp = *this;
  --(*this);
  return temp;
}

// Неявное приведение к int: общее число минут
Time::operator int() const {
  return hours_ * 60 + minutes_;
}

// Явное приведение к bool: true, если время не 00:00
Time::operator bool() const {
  return hours_ != 0 or minutes_ != 0;
}

// Сравнение: время < N минут?
bool Time::operator<(int minutes) const {
  return static_cast<int>(*this) < minutes;
}

// Сравнение: время > N минут?
bool Time::operator>(int minutes) const {
  return static_cast<int>(*this) > minutes;
}

// Вычитание
Time Time::operator-(const Time& other) const {
  int thisTotal = hours_ * 60 + minutes_;
  int otherTotal = other.hours_ * 60 + other.minutes_;
  return Time(thisTotal - otherTotal);
}