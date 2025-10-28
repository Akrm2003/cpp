#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
    T *_data;
    unsigned int _size;

public:
    // Default constructor
    Array() : _data(NULL), _size(0) {}

    // Constructor with size parameter
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array &other) : _data(NULL), _size(0)
    {
        *this = other;
    }

    // Destructor
    ~Array()
    {
        if (_data)
            delete[] _data;
    }

    // Assignment operator
    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            if (_data)
                delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Subscript operator
    T &operator[](unsigned int index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    // Size function
    unsigned int size() const
    {
        return _size;
    }
};

#endif
