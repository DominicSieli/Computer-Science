#pragma once
#include <iostream>

template<typename T>
class Container
{
public:
    virtual ~Container(){}
    virtual unsigned int Size() const = 0;
    virtual T& operator[](unsigned int) = 0;
};

template<typename T>
class Vector : public Container<T>
{
private:
    T* vector = nullptr;
    unsigned int size = 0;
public:
    Vector(unsigned int size) : vector(new T[size]), size(size){}
    ~Vector(){delete[] vector;}

    unsigned int Size() const {return this->size;}
    T& operator[](unsigned int index) {return vector[index];}
};

Vector<int> vector(10);

int main()
{
    for(unsigned int i = 0; i < vector.Size(); i++)
    {
        vector[i] = i;
        std::cout << vector[i] << '\n';
    }

    std::cin.get();
}