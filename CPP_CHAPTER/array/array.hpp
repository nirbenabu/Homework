#if !defined ARRAY_HPP
#define ARRAY_HPP

#include "array_exception.hpp"
#include "array_oob_exception.hpp"

////////////////////// CUSTOM ITERATOR //////////////////////

template <class T, int _size> class Array_iterator {
    private:
        int _i;         // Current index
        T* _pCurrent;   // Current pointer
    public:
        // c'tor
        Array_iterator(int index=0, T* current=NULL): _i(index), _pCurrent(current) { }
        operator T*() const; // cast operator for the type pointer
        int index() const;   // get index
        Array_iterator<T, _size>& operator ++(int); // ++ pointer operator
        Array_iterator<T, _size>& operator --();    // -- pointer operator
        Array_iterator<T, _size> operator +(int);  // pointer addition
        Array_iterator<T, _size> operator -(int);  // pointer subtraction \w integer
        T* operator-(const Array_iterator& other) const; // pointer subtraction
};

template <class T, int _size>
Array_iterator<T, _size> Array_iterator<T, _size>::operator+(int i) {
    if(_i+i >= _size)
        throw ArrayOutOfBoundsException(_size, _i+i);

    return Array_iterator<T, _size>(_i+i, _pCurrent+i);
}

template <class T, int _size>
Array_iterator<T, _size> Array_iterator<T, _size>::operator-(int i) {
    return (*this)+(-i);
}

// A pointer casting operator
template <class T, int _size>
Array_iterator<T, _size>::operator T*() const {
    return _pCurrent;
}

// Safe pointer operation
template<class T, int _size>
Array_iterator<T, _size>& Array_iterator<T, _size>::operator++(int) {
    if(_i+1 >= _size)
        throw new ArrayOutOfBoundsException(_size, _i+1);

    _i++;
    _pCurrent++;

    return *this;
}

// Safe pointer operation
template<class T, int _size>
Array_iterator<T, _size>& Array_iterator<T, _size>::operator--() {
    if(_i-1 >= _size || _i-1 < 0)
        throw new ArrayOutOfBoundsException(_size, _i-1);

    _i--;
    _pCurrent--;
}

template <class T, int _size>
int Array_iterator<T, _size>::index() const {
    return _i;
}

// Safe pointer operator
template<class T, int _size>
T* Array_iterator<T, _size>::operator-(const Array_iterator& other) const {
    return _pCurrent-other;
}

////////////////////// CUSTOM ARRAY //////////////////////

template <class T, int _size>
class Array {

private:
    T _arr[_size];

public:
    int size() const;                               // Return size
    Array_iterator<T,_size> get(int index);         // Get pointer at index
    Array_iterator<T,_size> set(int index, T value);// Set value at index and get iterator to the pointer
    T& operator[](int index);                       // Get reference
    Array_iterator<T,_size> operator+(int);
    Array_iterator<T,_size> operator-(int i);
    //operator T*(); - works but less safe
    operator Array_iterator<T, _size>();
};

// Gets the array size
template <class T, int _size> int Array<T, _size>::size() const {
    return _size;
}

// Gets the VALUE at index
// Throws ArrayOutOfBoundsException
template <class T, int _size> T& Array<T, _size>::operator[](int index) {
    if(index >= _size)
        throw new ArrayOutOfBoundsException(_size, index);

    return _arr[index];
}

template<class T, int _size> Array_iterator<T, _size> Array<T, _size>::get(int index) {
    if(index >= _size)
        throw new ArrayOutOfBoundsException(_size, index);

    return Array_iterator<T, _size>(index, &_arr[index]);
}

// Sets the value at index
// Throws ArrayOutOfBoundsException
template <class T, int _size>
Array_iterator<T,_size> Array<T, _size>::set(int index, T value) {
    if(index >= _size || index < 0)
        throw new ArrayOutOfBoundsException(_size, index);

    _arr[index] = value;
    return Array_iterator<T,_size>(index, &_arr[index]);
}

/*template <class T, int _size>
Array<T, _size>::operator T*() {
    return _arr;
}*/

template <class T, int _size>
Array_iterator<T,_size> Array<T,_size>::operator+(int i) {
    return ((Array_iterator<T,_size>)*this)+i;
}

template <class T, int _size>
Array_iterator<T,_size> Array<T,_size>::operator-(int i) {
    return (*this)+(-i);
}

template <class T, int _size>
Array<T, _size>::operator Array_iterator<T, _size>() {
    return Array_iterator<T, _size>(0, _arr);
}

#endif // ARRAY_HPP
