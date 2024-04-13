#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    int capacity;
    int size;

public:
    // Constructor with initial capacity
    Vector(int capacity = 10) {
        this->data = new T[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    // Destructor to free memory
    ~Vector() {
        delete[] data;
    }

    // Add an element to the end
    void push_back(T element) {
        if (size == capacity) {
            // Resize if capacity is reached
            T* newData = new T[capacity * 2];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity *= 2;
        }
        data[size++] = element;
    }

    // Access an element by index
    T& at(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Get the size of the vector
    int getSize() const {
        return size;
    }

    // Check if the vector is empty
    bool isEmpty() const {
        return size == 0;
    }
    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {  // Avoid self-assignment
            // Release existing memory
            delete[] data;

            // Allocate new memory
            capacity = other.capacity;
            size = other.size;
            data = new T[capacity];

            // Copy elements
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};
#endif