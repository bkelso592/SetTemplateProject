#ifndef UNORDEREDSET_H
#define UNORDEREDSET_H

#include "unorderedArrayList.h"

template <class ItemType>
class unorderedSetType : public unorderedArrayListType<ItemType>
{
public:
    // Override insertAt, insertEnd, and replaceAt

    // Overload + operator for union
    unorderedSetType<ItemType> operator+(const unorderedSetType<ItemType>& otherSet);

    // Overload - operator for intersection
    unorderedSetType<ItemType> operator-(const unorderedSetType<ItemType>& otherSet);

private:
    using unorderedArrayListType<ItemType>::list; // Access to base class's list array
};

// Implementation of overloaded operators
template <class ItemType>
unorderedSetType<ItemType> unorderedSetType<ItemType>::operator+(const unorderedSetType<ItemType>& otherSet)
{
    unorderedSetType<ItemType> resultSet = *this; // Create a copy of current set

    for (int i = 0; i < otherSet.listSize; ++i) {
        if (this->seqSearch(otherSet.list[i]) == -1) {
            resultSet.insertEnd(otherSet.list[i]); // Add items from other set not in current set
        }
    }

    return resultSet;
}

template <class ItemType>
unorderedSetType<ItemType> unorderedSetType<ItemType>::operator-(const unorderedSetType<ItemType>& otherSet)
{
    unorderedSetType<ItemType> resultSet;

    for (int i = 0; i < this->listSize; ++i) {
        if (otherSet.seqSearch(this->list[i]) != -1) {
            resultSet.insertEnd(this->list[i]); // Add items in both sets to the result set
        }
    }

    return resultSet;
}

#endif // UNORDEREDSET_H