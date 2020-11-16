#ifndef OOP_FIRST_PROTEIN_H
#define OOP_FIRST_PROTEIN_H

#include <iostream>
#include "acid.h"

class Protein {
public:
    struct Elem {
        Acid data; // данные
        Elem *next, *prev;
    };

    // Конструктор
    Protein();

    // Конструктор копирования
    Protein(const Protein &);

    // Деструктор
    ~Protein();

    // Получить количество
    [[maybe_unused]] [[nodiscard]] int GetCount() const;

    // Получить элемент списка
    [[maybe_unused]] [[nodiscard]] Elem *GetElem(int) const;

    // Получить первый элемент списка
    [[maybe_unused]] [[nodiscard]] Elem *GetHead() const;

    // Получить последний элемент списка
    [[maybe_unused]] [[nodiscard]] Elem *GetTail() const;

    // Удалить весь список
    void DelAll();

    // Удаление элемента, если параметр не указывается,
    // то функция его запрашивает
    void Del(int pos = 0);

    // Вставка элемента
    void Insert(int pos, const Acid &data);

    // Добавление в конец списка
    void AddTail(const Acid &acid);

    // Добавление в начало списка
    void AddHead(const Acid &acid);

    // Печать списка
    [[maybe_unused]] void Print() const;

    // Печать определенного элемента
    [[maybe_unused]] void Print(int pos) const;

    Protein &operator=(const Protein &);

    // сложение двух списков
    Protein operator+(const Protein &);

    // сравнение по элементам
    bool operator==(const Protein &) const;

    bool operator!=(const Protein &) const;

    // сравнение по кол-ву элементов
    bool operator<(const Protein &) const;

    bool operator>(const Protein &) const;

    // переворачивание списка
    Protein operator-();

    void fromFile(const std::string &fileName);

    void toFile(const std::string &fileName);

protected:
    // Начало, конец
    Elem *Head, *Tail;
    // Количество элементов
    int Count;

};

#endif //OOP_FIRST_PROTEIN_H
