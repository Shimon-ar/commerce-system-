//
// Created by Shimon Arshavsky on 13/12/2019.
//

#ifndef COMMERS_PROJECT_DYNAMICARRAY_H
#define COMMERS_PROJECT_DYNAMICARRAY_H

#include <iostream>

using namespace std;//template class of array of addresses

template<class T>
class DynamicArray {
private:
    T *array;
    int allocatedSize;
    int arraySize;

    T privateGetElement(int i) const {//check if the index is valid
        if (i >= 0 && i < arraySize) return array[i];
        return nullptr;
    }

public:
    DynamicArray(int allocatedSize = 1) : allocatedSize(allocatedSize),arraySize(0), array(new T[allocatedSize]) {}//initial the class

    ~DynamicArray() { delete[]array; }

    DynamicArray(DynamicArray &other) : array(nullptr) {//copy all the attributes and the adresses
        *this = other;
    }

    const T getElement(int index) const { return privateGetElement(index); }//getting address by index in the array
    T getElement(int index) { return privateGetElement(index); }

    int getSize() const { return arraySize; }//getting actual size

    const DynamicArray &operator+=(T element) {//add element
        if (arraySize == allocatedSize) {//check if need to allocate space
            allocatedSize *= 2;
            T *newArray = new T[allocatedSize];//allocate
            for (int i = 0; i < arraySize; i++)//copy the addresses
                newArray[i] = array[i];
            delete[]array;
            array = newArray;
        }
        array[arraySize++] = element;//add the address
        return *this;
    }

    const DynamicArray &operator=(const DynamicArray &other) {
        if (this != &other) {//copy the array
            delete[]array;
            arraySize = other.arraySize;
            allocatedSize = other.allocatedSize;
            array = new T[allocatedSize];
            for (int i = 0; i < arraySize; i++)
                array[i] = other.array[i];
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const DynamicArray &dynamicArray) {
		if (dynamicArray.arraySize == 0)
		{
			
			os << "you dont have any\n";
		}
        for (int i = 0; i < dynamicArray.arraySize; i++)//print the array
            os << *(dynamicArray.array[i]) << "\n\n";
		
        return os;
    }

    const DynamicArray &operator-(const T element) {//remove element from array by shift left all the next ones
        bool stop = false;
        for (int i = 0; i < arraySize && !stop; i++)
            if(array[i] == element){
                stop = true;
                for(int j = i+1 ; j<arraySize;j++)
                    array[j-1] = array[j];
            }
        arraySize--;//update size
        return *this;
    }

    void MakeEmpty(){//make the array empty
        arraySize=0;
        allocatedSize = 1;
        delete []array;
        array = new T[allocatedSize];
    }

};


#endif //COMMERS_PROJECT_DYNAMICARRAY_H
