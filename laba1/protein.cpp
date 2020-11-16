#include "protein.h"
#include <iostream>
#include <fstream>

Protein::Protein() {
    // Изначально список пуст
    Head = Tail = nullptr;
    Count = 0;
}

Protein::Protein(const Protein &L) {
    Head = Tail = nullptr;
    Count = 0;

    // Голова списка, из которого копируем
    Elem *temp = L.Head;
    // Пока не конец списка
    while (temp != nullptr) {
        // Передираем данные
        AddTail(temp->data);
        temp = temp->next;
    }
}

Protein::~Protein() {
    // Удаляем все элементы
    DelAll();
}

void Protein::AddHead(const Acid &acid) {
    // новый элемент
    Elem *temp = new Elem;

    // Предыдущего нет
    temp->prev = nullptr;
    // Заполняем данные
    temp->data = acid;
    // Следующий - бывшая голова
    temp->next = Head;

    // Если элементы есть?
    if (Head != nullptr)
        Head->prev = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - головной
        Head = temp;

    Count++;
}

void Protein::AddTail(const Acid &acid) {
    // Создаем новый элемент
    Elem *temp = new Elem;
    // Следующего нет
    temp->next = nullptr;
    // Заполняем данные
    temp->data = acid;
    // Предыдущий - бывший хвост
    temp->prev = Tail;

    // Если элементы есть?
    if (Tail != nullptr)
        Tail->next = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - хвостовой
        Tail = temp;

    Count++;
}

void Protein::Insert(const int pos, const Acid &data) {
    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count + 1) {
        // Неверная позиция
        std::cout << "Incorrect position !!!\n";
        return;
    }
    // Если вставка в конец списка
    if (pos == Count + 1) {
        // Вставляемые данные. Добавление в конец списка
        AddTail(data);
        return;
    } else if (pos == 1) {
        // Вставляемые данные. Добавление в начало списка
        AddHead(data);
        return;
    }
    // Счетчик
    int i = 1;
    // Отсчитываем от головы n - 1 элементов
    Elem *Ins = Head;

    while (i < pos) {
        // Доходим до элемента, перед которым вставляемся
        Ins = Ins->next;
        i++;
    }

    // Доходим до элемента, который предшествует
    Elem *PrevIns = Ins->prev;

    // Создаем новый элемент
    Elem *temp = new Elem;

    // Вводим данные
    temp->data = data;

    // настройка связей
    if (PrevIns != nullptr && Count != 1)
        PrevIns->next = temp;

    temp->next = Ins;
    temp->prev = PrevIns;
    Ins->prev = temp;

    Count++;
}

void Protein::Del(int pos) {
    // если параметр отсутствует или равен 0, то запрашиваем его
    if (pos == 0) {
        std::cout << "Input position: ";
        std::cin >> pos;
    }
    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count) {
        // Неверная позиция
        std::cout << "Incorrect position !!!\n";
        return;
    }

    // Счетчик
    int i = 1;

    Elem *Del = Head;

    while (i < pos) {
        // Доходим до элемента,
        // который удаляется
        Del = Del->next;
        i++;
    }

    // Доходим до элемента,
    // который предшествует удаляемому
    Elem *PrevDel = Del->prev;
    // Доходим до элемента, который следует за удаляемым
    Elem *AfterDel = Del->next;

    // Если удаляем не голову
    if (PrevDel != nullptr && Count != 1)
        PrevDel->next = AfterDel;
    // Если удаляем не хвост
    if (AfterDel != nullptr && Count != 1)
        AfterDel->prev = PrevDel;

    // Удаляются крайние?
    if (pos == 1)
        Head = AfterDel;
    if (pos == Count)
        Tail = PrevDel;

    // Удаление элемента
    delete Del;

    Count--;
}

[[maybe_unused]] void Protein::Print(const int pos) const {
    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count) {
        // Неверная позиция
        std::cout << "Incorrect position !!!\n";
        return;
    }

    Elem *temp;

    // Определяем с какой стороны
    // быстрее двигаться
    if (pos <= Count / 2) {
        // Отсчет с головы
        temp = Head;
        int i = 1;

        while (i < pos) {
            // Двигаемся до нужного элемента
            temp = temp->next;
            i++;
        }
    } else {
        // Отсчет с хвоста
        temp = Tail;
        int i = 1;

        while (i <= Count - pos) {
            // Двигаемся до нужного элемента
            temp = temp->prev;
            i++;
        }
    }
    // Вывод элемента
    std::cout << pos << " element:\n";
    temp->data.printAcid();
    std::cout << std::endl;
}

[[maybe_unused]] void Protein::Print() const {
    // Если в списке присутствуют элементы, то пробегаем по нему
    // и печатаем элементы, начиная с головного
    if (Count != 0) {
        Elem *temp = Head;
        std::cout << "{\n";
        while (temp->next != nullptr) {
            temp->data.printAcid();
            temp = temp->next;
        }

        temp->data.printAcid();
        std::cout << "}\n";
    }
}

void Protein::DelAll() {
    // Пока остаются элементы, удаляем по одному с головы
    while (Count != 0)
        Del(1);
}

[[maybe_unused]] int Protein::GetCount() const {
    return Count;
}

[[maybe_unused]] Protein::Elem *Protein::GetHead() const {
    if (this->Count == 0) {
        std::cout << "\nThere are 0 acids in protein!!\n";
        return nullptr;
    } else
        return Head;
}

[[maybe_unused]] Protein::Elem *Protein::GetTail() const {
    if (this->Count == 0) {
        std::cout << "\nThere are 0 acids in protein!\n";
        return nullptr;
    } else
        return Tail;
}

[[maybe_unused]] Protein::Elem *Protein::GetElem(int pos) const {
    Elem *temp = Head;

    // Позиция от 1 до Count?
    if (pos < 1 || pos > Count) {
        // Неверная позиция
        std::cout << "Incorrect position !!!\n";
        return nullptr;
    }

    int i = 1;
    // Ищем нужный нам элемент
    while (i < pos && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr)
        return nullptr;
    else
        return temp;
}

Protein &Protein::operator=(const Protein &L) {
    // Проверка присваивания элемента "самому себе"
    if (this == &L)
        return *this;

    // удаление старого списка
    this->~Protein(); // DelAll();

    Elem *temp = L.Head;

    // Копируем элементы
    while (temp != nullptr) {
        AddTail(temp->data);
        temp = temp->next;
    }

    return *this;
}

// сложение двух списков
Protein Protein::operator+(const Protein &L) {
    // Заносим во временный список элементы первого списка
    Protein Result(*this);
    // Protein Result = *this;

    Elem *temp = L.Head;

    // Добавляем во временный список элементы второго списка
    while (temp != nullptr) {
        Result.AddTail(temp->data);
        temp = temp->next;
    }

    return Result;
}

bool Protein::operator==(const Protein &L) const {
    // Сравнение по количеству
    if (Count != L.Count)
        return false;

    Elem *t1, *t2;

    t1 = Head;
    t2 = L.Head;

    // Сравнение по содержанию
    while (t1 != nullptr) {
        // Сверяем данные, которые
        // находятся на одинаковых позициях
        if (t1->data.getFullName() != t2->data.getFullName() || t1->data.getShortName() != t2->data.getShortName())
            return false;

        t1 = t1->next;
        t2 = t2->next;
    }

    return true;
}

bool Protein::operator!=(const Protein &L) const{
    // Используем предыдущую функцию сравнения
    return !(*this == L);
}

bool Protein::operator>(const Protein &L) const {
    if (Count > L.Count)
        return true;

    return false;
}

bool Protein::operator<(const Protein &L) const {
    if (Count < L.Count)
        return true;

    return false;
}

// переворот
Protein Protein::operator-() {
    Protein Result;

    Elem *temp = Head;
    // Копируем элементы списка, начиная с головного,
    // в свой путем добавления элементов в голову,
    // таким образом временный список Result будет содержать
    // элементы в обратном порядке
    while (temp != nullptr) {
        Result.AddHead(temp->data);
        temp = temp->next;
    }

    return Result;
}

void Protein::fromFile(const std::string &fileName) {
    std::string fullName;
    std::string shortName;

    std::ifstream file(fileName);


    if (file.is_open()) {
        while (file >> fullName >> shortName) {
            Acid readingAcid(fullName, shortName);
            this->AddTail(readingAcid);
        }
        file.close();
    }
}

void Protein::toFile(const std::string &fileName) {
    if (Count != 0) {
        std::ofstream fout(fileName);
        Elem *temp = Head;
        while (temp->next != nullptr) {
            fout << temp->data.getFullName() << " " << temp->data.getShortName() << std::endl;
            temp = temp->next;
        }
        fout << temp->data.getFullName() << " " << temp->data.getShortName() << std::endl;

        fout.close();
    } else {
        std::cout << "Protein is empty";
        return;
    }
}
