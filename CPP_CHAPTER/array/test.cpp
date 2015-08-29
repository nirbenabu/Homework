#include <iostream>
#include "array.hpp"

int main()
{
    Array<int,5> arr;
    arr.set(0, 1);  // One way to set values
    arr[1] = 5; // Second way to set values
    std::cout<<arr[0]<<std::endl; // On way to get values

    try {
        std::cout<<*(arr.get(0)++)<<std::endl; // Another way to get values (pointers)
        arr+7; // ERROR! OUT OF BOUNDS!
    } catch (ArrayOutOfBoundsException e)
    {
        e.printInfo(); // Exceptions system.
    }

    std::cout << *(arr.get(2)-1) << std::endl; // Pointer arithmetic
    std::cout << *(arr+1) << std::endl;        // Pointer arithmetic, anyway you want =]


    return 0;
}
