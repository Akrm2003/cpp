#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;

        
        for (unsigned int i = 0; i < intArray.size(); i++)
        {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        
        try
        {
            std::cout << intArray[10] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << " : " << e.what() << std::endl;
        }

        
        Array<int> copyArray(intArray);
        std::cout << "Copy array size: " << copyArray.size() << std::endl;

        
        intArray[0] = 42;
        std::cout << "intArray[0]: " << intArray[0] << ", copyArray[0]: " << copyArray[0] << std::endl;

        
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        std::cout << "intArray[0]: " << intArray[0] << ", assignedArray[0]: " << assignedArray[0] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}