#include "BinaryHeap.hpp"
#include "DynamicArray.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    BinaryHeap<int> bheap1;

    bheap1.insert(0);
    bheap1.insert(1);
    bheap1.insert(2);
    bheap1.insert(3);
    bheap1.insert(4);
    bheap1.insert(5);
    bheap1.insert(6);

    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << std::string(30,'*') << std::endl;

    bheap1.insert(6);
    bheap1.insert(5);
    bheap1.insert(4);
    bheap1.insert(3);
    bheap1.insert(2);
    bheap1.insert(1);
    bheap1.insert(0);

    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << std::string(30,'*') << std::endl;

    bheap1.insert(2);
    bheap1.insert(5);
    bheap1.insert(0);
    bheap1.insert(6);
    bheap1.insert(3);
    bheap1.insert(1);
    bheap1.insert(4);

    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << "bheap1.delMin(): " << bheap1.delMin() << std::endl;
    std::cout << std::string(30,'*') << std::endl;

    DynamicArray<int> array1;
    array1.append(2);
    array1.append(5);
    array1.append(0);
    array1.append(6);
    array1.append(3);
    array1.append(1);
    array1.append(4);

    BinaryHeap<int> bheap2(array1);
    std::cout << "bheap2.delMin(): " << bheap2.delMin() << std::endl;
    std::cout << "bheap2.delMin(): " << bheap2.delMin() << std::endl;
    std::cout << "bheap2.delMin(): " << bheap2.delMin() << std::endl;
    std::cout << "bheap2.delMin(): " << bheap2.delMin() << std::endl;
    std::cout << "bheap2.delMin(): " << bheap2.delMin() << std::endl;
    std::cout << "bheap2.delMin(): " << bheap2.delMin() << std::endl;
    std::cout << "bheap2.delMin(): " << bheap2.delMin() << std::endl;
    std::cout << std::string(30,'*') << std::endl;


    return 0;
}


