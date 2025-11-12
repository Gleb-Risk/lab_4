#include "Time.h"
#include <iostream>


void ClearInput() {
  std::cin.clear();
  std::cin.ignore(10000, '\n');
}

short InputHours() {
  short h;
  while (true) {
    std::cout << "Введите часы (0–23): ";
    if (std::cin >> h and h >= 0 and h < 24) {
      return h;
    }
    std::cout << "Ошибка: должно быть целое число от 0 до 23" << std::endl;
    ClearInput();
  }
}

short InputMinutes() {
  short m;
  while (true) {
    std::cout << "Введите минуты (0–59): ";
    if (std::cin >> m and m >= 0 and m < 60) {
      return m;
    }
    std::cout << "Ошибка: должно быть целое число от 0 до 59." << std::endl;
    ClearInput();
  }
}

int main() {
  setlocale(LC_ALL, "Russian");

  
  // === 1️⃣ ВВОД И ВЫЧИТАНИЕ — СРАЗУ В НАЧАЛЕ ===
  std::cout << "\n  Введите первое время (t1):\n";
  Time t1(InputHours(), InputMinutes());
  std::cout << "   t1 = "; t1.print(); std::cout << "\n";

  std::cout << "\n  Введите второе время (t2):\n";
  Time t2(InputHours(), InputMinutes());
  std::cout << "   t2 = "; t2.print(); std::cout << "\n";

  std::cout << "\n ЗАДАНИЕ 1: Вычитание (t1 - t2) \n";
  Time diff = t1 - t2;
  std::cout << "   ";
  t1.print(); std::cout << " - ";
  t2.print(); std::cout << " = ";
  diff.print(); std::cout << "\n";

  // Унарные операторы 
  std::cout << "\n Задание 2: Унарные операторы\n";
  {
    Time tmp = t1;
    std::cout << "   Было: "; tmp.print(); std::cout << "\n";
    tmp++;
    std::cout << "   После tmp++: "; tmp.print(); std::cout << "\n";

    tmp = t1;
    --tmp;
    std::cout << "   После --tmp: "; tmp.print(); std::cout << "\n";
  }

    // Приведение типов
  std::cout << "\n Приведение типов\n";
  {
    int total = t1;
    std::cout << "   (int)t1 = " << total << " минут\n";
    std::cout << "   (bool)t1 = " << (static_cast<bool>(t1) ? "true" : "false") << "\n";

    Time zero;
    std::cout << "   (bool)00:00 = " << (static_cast<bool>(zero) ? "true" : "false") << "\n";
  }

    // === 4️⃣ Сравнение с int ===
  std::cout << "\n Сравнение с числом минут \n";
  int n;
  std::cout << "   Введите число минут: ";
  while (!(std::cin >> n)) {
    std::cout << "   Введите целое число: ";
    ClearInput();
  }

  std::cout << "   t1 = "; t1.print();
  std::cout << " = " << static_cast<int>(t1) << " мин\n";

  if (t1 < n) {
    std::cout << "   t1 < " << n << " → да\n";
  } else {
    std::cout << "   t1 < " << n << " → нет\n";
    }


  if (t1 > n) {
    std::cout << "   t1 > " << n << " → да\n";
  } else {
    std::cout << "   t1 > " << n << " → нет\n";
    }
  

  return 0;
}