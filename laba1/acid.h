#include <string>

#ifndef OOP_FIRST_OOP_FIRST_HEADER_H
#define OOP_FIRST_OOP_FIRST_HEADER_H

class Acid {
public:
    Acid();

    Acid(const std::string &fullName, const std::string &shortName);

    Acid(Acid &acid);

    void setFullName(const std::string &fullName);

    void setShortName(const std::string &shortName);

    void printAcid();

    [[nodiscard]] const std::string &getFullName() const;

    [[nodiscard]] const std::string &getShortName() const;

private:
    std::string fullName_, shortName_;
};

#endif //OOP_FIRST_OOP_FIRST_HEADER_H
