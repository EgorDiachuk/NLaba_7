#include <iostream>
#include <stack>
#include <windows.h> 

using namespace std;

// Рекурсивна функція для обчислення суми елементів, менших за 5
int sumLessThanFive(stack<int>& s) {
    // Базовий випадок: якщо стек порожній, повертаємо 0
    if (s.empty()) {
        return 0;
    }

    // Отримуємо верхній елемент і видаляємо його зі стека
    int top = s.top();
    s.pop();

    // Обчислюємо суму рекурсивно для решти елементів
    int sum = sumLessThanFive(s);

    // Додаємо до суми, якщо елемент менший за 5
    if (top < 5) {
        sum += top;
    }

    // Повертаємо елемент назад у стек, щоб зберегти його стан
    s.push(top);

    return sum;
}

int main() {
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251); 

    // Створюємо стек і додаємо деякі елементи
    stack<int> s;
    s.push(3);
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(9);

    // Викликаємо функцію і виводимо результат
    int result = sumLessThanFive(s);
    cout << "Сума елементів, менших за 5: " << result << endl;

    return 0;
}
