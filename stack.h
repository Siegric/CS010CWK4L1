#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class stack {
    private:
        const int MAX_SIZE = 20;
        T* data;    // Pointer to an array of T
        int size;   // Current size of the stack

    public:
        // Constructor
        stack() {
            size = 0;
            data = new T[size];
        }

        // Destructor
        ~stack() {
            while (!empty()) {
                pop();
            }
        }

        // Pushes a value onto the top of the stack
        void push(T val) {
            // Check if the stack is already full
            if (size == MAX_SIZE) {
                throw overflow_error("Called push on full stack.");
            } else {
                // Allocate a new array with size+1 and copy elements from old array to new array
                T* new_data = new T[size+1];
                if (size != 0) {
                    for (int i = 0; i < size; ++i) {
                        new_data[i] = data[i];
                    }
                }
                // Add the new value to the end of the new array and update size and data pointers
                new_data[size] = val;
                size += 1;
                delete[] data;
                data = new_data;
            }
        }

        // Removes and returns the value at the top of the stack
        void pop() {
            // Check if the stack is already empty
            if (empty()) {
                throw out_of_range("Called pop on empty stack.");
            } else {
                // Allocate a new array with size-1 and copy elements from old array to new array except the last one
                T* new_data = new T[size-1];
                for (int i = 0; i < size-1; ++i) {
                    new_data[i] = data[i];
                }
                // Update size and data pointers and delete old array
                size -= 1;
                delete[] data;
                data = new_data;
            }
        }

        // Removes the top two elements of the stack
        void pop_two() {
            // Check if the stack has less than 2 elements
            if (empty()) {
                throw out_of_range("Called pop_two on empty stack.");
            } else if (size == 1) {
                throw out_of_range("Called pop_two on a stack of size 1.");
            } else {
                // Allocate a new array with size-2 and copy elements from old array to new array except the last two
                T* new_data = new T[size-2];
                for (int i = 0; i < size-2; ++i) {
                    new_data[i] = data[i];
                }
                // Update size and data pointers and delete old array
                size -= 2;
                delete[] data;
                data = new_data;
            }
        }

        // Returns the value at the top of the stack without removing it
        T top() {
            // Check if the stack is already empty
            if (empty()) {
                throw underflow_error("Called top on empty stack.");
            }
            // Return the last element of the stack
            return data[size-1];
        }

        // Returns true if the stack is empty, false otherwise
        bool empty() {
            return (size == 0);
        }
};

#endif //STACH_H
