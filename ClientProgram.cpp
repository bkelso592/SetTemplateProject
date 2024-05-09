#include <iostream>
#include "unorderedSet.h"

int main() {
    // Integer set
    unorderedSetType<int> intSet;
    int intArray[] = { 1, 2, 3, 4, 5, 5 }; // Intentionally duplicating '5' to test duplicate handling
    for (int i = 0; i < 6; ++i) {
        intSet.insertEnd(intArray[i]);
    }

    // String set
    unorderedSetType<std::string> strSet;
    std::string strArray[] = { "apple", "banana", "orange", "banana" }; // Intentionally duplicating 'banana' to test duplicate handling
    for (int i = 0; i < 4; ++i) {
        strSet.insertEnd(strArray[i]);
    }

    // Displaying sets
    std::cout << "Integer Set: ";
    intSet.print();
    std::cout << std::endl;

    std::cout << "String Set: ";
    strSet.print();
    std::cout << std::endl;

    // Testing union and intersection
    unorderedSetType<int> intSet1, intSet2, intUnion, intIntersection;
    intSet1.insertEnd(1);
    intSet1.insertEnd(2);
    intSet2.insertEnd(2);
    intSet2.insertEnd(3);

    intUnion = intSet1 + intSet2;
    intIntersection = intSet1 - intSet2;

    std::cout << "Union of integer sets: ";
    intUnion.print();
    std::cout << std::endl;

    std::cout << "Intersection of integer sets: ";
    intIntersection.print();
    std::cout << std::endl;

    return 0;
}