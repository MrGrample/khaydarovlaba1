#include <iostream>
#include "acid.h"

Acid::Acid() {
    this->fullName_ = "Default";
    this->shortName_ = "0";
}

Acid::Acid(const std::string &fullName, const std::string &shortName) {
    setFullName(fullName);
    setShortName(shortName);
}

Acid::Acid(Acid &acid) {
    // Конструктор копирования
    setFullName(acid.getFullName());
    setShortName(acid.getShortName());
}

void Acid::setFullName(const std::string &fullName) {
    //Проверяет корректность названия и устанавливает значение соответствующего атрибута
    if (fullName.length() <= 0) {
        std::cout << "There is an error in the acid name" << std::endl;
        fullName_ = "ERROR";
    } else {
        fullName_ = fullName;
    }
}

void Acid::setShortName(const std::string &shortName) {
    //Проверяет корректность однобуквенного обозначения и устанавливает значение соответствующего атрибута
    if (shortName.length() != 1) {
        std::cout << "There is an error in the acid name" << std::endl;
        shortName_ = "ERROR";
    } else {
        shortName_ = shortName;
    }
}

const std::string &Acid::getFullName() const {
    // Возвращает полное название
    return fullName_;
}

const std::string &Acid::getShortName() const {
    // Возвращает однобуквеннное обозначение
    return shortName_;
}

void Acid::printAcid() {
    // Выводит на экран данные об аминокислоте
    if (&(this->fullName_) != nullptr && &(this->shortName_)) {
        std::cout << "Amino acid:\t" << fullName_ << '\t' << '[' + shortName_ + ']' << std::endl;
    } else {
        std::cout << "Acid does not exist";
        return;
    }
}
