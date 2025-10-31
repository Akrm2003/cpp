#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <algorithm>

// Generate Jacobsthal sequence up to n
std::vector<size_t> generateJacobsthalSequence(size_t n)
{
    std::vector<size_t> seq;
    size_t a = 0;
    size_t b = 1;
    while (b <= n)
    {
        seq.push_back(b);
        size_t next = a + 2 * b;
        a = b;
        b = next;
    }
    return seq;
}

template <typename Container>
void binaryInsert(Container &sorted, typename Container::value_type value)
{
    typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

template <typename Container>
Container mergeInsertSortImpl(const Container &input)
{
    if (input.size() <= 1)
        return input;

    Container larger, smaller;

    // Step 1: Pair up and separate smaller/larger
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 < input.size())
        {
            if (input[i] < input[i + 1])
            {
                smaller.push_back(input[i]);
                larger.push_back(input[i + 1]);
            }
            else
            {
                smaller.push_back(input[i + 1]);
                larger.push_back(input[i]);
            }
        }
        else
            larger.push_back(input[i]); // unpaired goes to larger
    }

    // Step 2: Recursively sort the 'larger' elements
    larger = mergeInsertSortImpl(larger);

    // Step 3: Insert the smaller elements into the sorted list
    // First insert the first smaller element
    Container result = larger;
    if (!smaller.empty())
    {
        binaryInsert(result, smaller[0]);
        if (smaller.size() == 1)
            return result;
    }

    // Use Jacobsthal sequence for remaining smaller elements
    // jacob = [1, 3, 5, 11, 21, ...]
    std::vector<size_t> jacob = generateJacobsthalSequence(smaller.size());
    size_t lastJ = 1;
    for (size_t idx = 0; idx < jacob.size(); ++idx)
    {
        size_t j = jacob[idx];
        for (size_t i = std::min(j, smaller.size()) - 1; i >= lastJ && i < smaller.size(); --i)
            binaryInsert(result, smaller[i]);
        lastJ = j;
        if (lastJ >= smaller.size())
            break;
    }
    return result;
}

std::vector<int> mergeInsertSort(const std::vector<int> &input)
{
    return mergeInsertSortImpl(input);
}

std::deque<int> mergeInsertSort(const std::deque<int> &input)
{
    return mergeInsertSortImpl(input);
}
