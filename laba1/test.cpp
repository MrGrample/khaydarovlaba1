#include <cassert>
#include "acid.h"
#include "protein.h"
#include "test.h"

void testDefaultAcidConstructor() {
    // Тестирование конструктора по умолчанию
    Acid glycine("Glycine", "G");
    Acid default_;
    assert(glycine.getFullName() == "Glycine");
    assert(glycine.getShortName() == "G");
    assert(default_.getFullName() == "Default");
    assert(default_.getShortName() == "0");
}

void testCopyAcidConstructor() {
    //Тестирование копирующего конструктора
    Acid glycine("Glycine", "G");
    Acid glycineCopy(glycine);
    assert(glycine.getFullName() == glycineCopy.getFullName());
    assert(glycine.getShortName() == glycineCopy.getShortName());
}

void testSetFullName() {
    //Тестирование установки значения полного названия
    Acid glycine("Glyc", "G");
    assert(glycine.getFullName() == "Glyc");
    glycine.setFullName("Glycine");
    assert(glycine.getFullName() == "Glycine");
}

void testSetShortName() {
    // Тестирование установки однобуквенного обозначения
    Acid glycine("Glycine", "0");
    assert(glycine.getShortName() == "0");
    glycine.setShortName("G");
    assert(glycine.getShortName() == "G");
}

void testDefaultProteinConstructor() {
    // Тестирование конструктора по умолчанию
    Protein test;
    assert(test.GetCount() == 0);
}

void testAdd() {
    // Тестирование методов добавления в конец и начала списка
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Protein test;
    test.AddHead(glycine);
    assert(test.GetElem(1)->data.getFullName() == "Glycine");
    assert(test.GetElem(1)->data.getShortName() == "G");
    test.AddTail(alanine);
    assert(test.GetElem(2)->data.getFullName() == "Alanine");
    assert(test.GetElem(2)->data.getShortName() == "A");
}

void testCopyProteinConstructor() {
    // Тестирование конструктора копирования
    Protein first;
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    first.AddTail(glycine);
    first.AddTail(alanine);
    Protein second = first;
    assert(first.GetElem(1)->data.getFullName() == second.GetElem(1)->data.getFullName());
    assert(first.GetElem(2)->data.getFullName() == second.GetElem(2)->data.getFullName());
}

void testInsert() {
    // Тестирование метода добавления insert
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Protein test;
    test.Insert(1, glycine);
    assert(test.GetElem(1)->data.getFullName() == "Glycine");
    assert(test.GetElem(1)->data.getShortName() == "G");
    test.Insert(1, alanine);
    assert(test.GetElem(1)->data.getFullName() == "Alanine");
    assert(test.GetElem(1)->data.getShortName() == "A");
    Acid serine("Serine", "S");
    test.Insert(2, serine);
    assert(test.GetElem(2)->data.getFullName() == "Serine");
    assert(test.GetElem(2)->data.getShortName() == "S");
}

void testDelElem(){
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Acid serine("Serine", "S");
    Protein test;
    test.Insert(1, glycine);
    test.Insert(2, alanine);
    test.Insert(3, serine);
    assert(test.GetCount() == 3);
    test.Del(2);
    assert(test.GetCount() == 2);
    assert(test.GetElem(1)->data.getFullName() == "Glycine");
    assert(test.GetElem(1)->data.getShortName() == "G");
    assert(test.GetElem(2)->data.getFullName() == "Serine");
    assert(test.GetElem(2)->data.getShortName() == "S");
}

void testDelAll(){
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Acid serine("Serine", "S");
    Protein test;
    test.Insert(1, glycine);
    test.Insert(2, alanine);
    test.Insert(3, serine);
    assert(test.GetCount() == 3);
    test.DelAll();
    assert(test.GetCount() == 0);
}

void testOperatorSimilarity(){
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Acid serine("Serine", "S");
    Protein first;
    first.Insert(1, glycine);
    first.Insert(2, alanine);
    Protein second;
    second = first;
    assert(first == second);
}

void testOperatorComparison(){
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Acid serine("Serine", "S");
    Protein first;
    first.Insert(1, glycine);
    first.Insert(2, alanine);
    Protein second = first;
    second.Insert(3,serine);
    assert(!(first > second));
    assert(first < second);
}

void testOperatorSum(){
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Acid serine("Serine", "S");
    Protein first;
    first.Insert(1, glycine);
    first.Insert(2, alanine);
    Protein second;
    second.Insert(1,serine);
    assert(first.GetCount() == 2);
    assert(second.GetCount() == 1);
    Protein sum = first + second;
    assert(sum.GetCount() == 3);
}

void testOperatorTurning(){
    Acid glycine("Glycine", "G");
    Acid alanine("Alanine", "A");
    Acid serine("Serine", "S");
    Protein test;
    test.Insert(1, glycine);
    test.Insert(2, alanine);
    test.Insert(3, serine);
    assert(test.GetElem(1)->data.getFullName() == "Glycine");
    assert(test.GetElem(1)->data.getShortName() == "G");
    assert(test.GetElem(2)->data.getFullName() == "Alanine");
    assert(test.GetElem(2)->data.getShortName() == "A");
    assert(test.GetElem(3)->data.getFullName() == "Serine");
    assert(test.GetElem(3)->data.getShortName() == "S");
    test = -test;
    assert(test.GetElem(3)->data.getFullName() == "Glycine");
    assert(test.GetElem(3)->data.getShortName() == "G");
    assert(test.GetElem(2)->data.getFullName() == "Alanine");
    assert(test.GetElem(2)->data.getShortName() == "A");
    assert(test.GetElem(1)->data.getFullName() == "Serine");
    assert(test.GetElem(1)->data.getShortName() == "S");
}

void testReadingFile(){
    Protein test;
    test.fromFile("C:/Users/maks/Projects_C++/laba_oop_z2/file_source.txt");
    test.Print();
    test.toFile("C:/Users/maks/Projects_C++/laba_oop_z2/file_out.txt");

}
void testClassAcid() {
    testDefaultAcidConstructor();
    testCopyAcidConstructor();
    testSetFullName();
    testSetShortName();
}

void testClassProtein() {
    testDefaultProteinConstructor();
    testAdd();
    testCopyProteinConstructor();
    testInsert();
    testDelElem();
    testDelAll();
    testOperatorSimilarity();
    testOperatorComparison();
    testOperatorSum();
    testOperatorTurning();
    testReadingFile();
}
