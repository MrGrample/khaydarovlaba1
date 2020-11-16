#include "test.h"
#include "protein.h"
//#include "containertest.h"

/*
    Сотрудники института биоинформатики хотят восстановить первичную структуру белка, для чего требуется объединить его
    (частично пересекающиеся) фрагменты. Требуется на писать программу, которая хранит белковые последовательности
    (в виде списков амино кислот) и умеет их объединять, если аминокислоты в конце одной последовательности совпадут
    с аминокислотами в начале другой.
1. Протеиногенная аминокислота: способ показывать (и принимать) своё полное название и однобуквенное обозначение
2. Белок (двусвязный список аминокислот): операция сложения, возвращающая результат сложения (с пересечением) двух белков
3. Нестандартная аминокислота: способ показывать и принимать своё полное название
 */

/*using ContainerType = Protein;
using ElementType = Acid;
template<typename T, typename E> class CurrentTest : public ContainerTest<T, E, CurrentTest<T, E> > {
public:
    static E createElementI(size_t i_) {
        return E(i_, 10, 10, 10);
    }
    static E& getFirst(T& container_) {
        return container_.get_first();
    }
};
using SpecialTest = CurrentTest<ContainerType, ElementType>;*/

int main() {
    testClassAcid();
    testClassProtein();

    return 0;
}
