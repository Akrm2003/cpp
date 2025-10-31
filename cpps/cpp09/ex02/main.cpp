#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> inputVector;
    std::deque<int> inputDeque;

    try
    {
        for (int i = 1; i < argc; ++i)
        {
            int num = std::stoi(argv[i]);
            if (num <= 0)
                throw std::invalid_argument("Non-positive integer");
            inputVector.push_back(num);
            inputDeque.push_back(num);
        }
    }
    catch (const std::exception &)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < inputVector.size(); ++i)
    {
        std::cout << inputVector[i] << (i < inputVector.size() - 1 ? " " : "\n");
    }

    std::chrono::high_resolution_clock::time_point startVector = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVector = mergeInsertSort(inputVector);
    std::chrono::high_resolution_clock::time_point endVector = std::chrono::high_resolution_clock::now();

    std::chrono::high_resolution_clock::time_point startDeque = std::chrono::high_resolution_clock::now();
    std::deque<int> sortedDeque = mergeInsertSort(inputDeque);
    std::chrono::high_resolution_clock::time_point endDeque = std::chrono::high_resolution_clock::now();

    std::cout << "After: ";
    for (size_t i = 0; i < sortedVector.size(); ++i)
    {
        std::cout << sortedVector[i] << (i < sortedVector.size() - 1 ? " " : "\n");
    }

    std::chrono::duration<double, std::micro> vectorTime = endVector - startVector;
    std::chrono::duration<double, std::micro> dequeTime = endDeque - startDeque;

    std::cout << "Time to process a range of " << inputVector.size()
              << " elements with std::vector: " << vectorTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << inputDeque.size()
              << " elements with std::deque: " << dequeTime.count() << " us" << std::endl;

    return 0;
}
