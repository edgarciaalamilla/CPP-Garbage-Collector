#ifndef GCPOINTER_HPP
#define GCPOINTER_HPP 

#include "reference_counting.h"

template <class T> 
class GCPointer{

private:
    T* ptr;

    inline void increment_references() const {
        if(ptr == nullptr) return;

        if(gcp_reference.find(ptr) == gcp_reference.end()) gcp_reference[ptr] = 0;
        gcp_reference[ptr]++;
    }

    inline void decrement_references(){
        if(ptr == nullptr) return;

        if(--gcp[reference] == 0){
            gcp_reference.erase(ptr);
            delete ptr;
        }
    }

public:
    GCPointer(T* pointer = nullptr) : ptr{pointer} { increment_references(); }

    //copy constructor
    GCPointer(const GCPointer<T>& other) : ptr{other.ptr} { }

    //move constructor
    GCPointer(GCPointer<T>&& other) noexcept{
        decrement_references();
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    //destructor
    ~GCPointer(){ decrement_references(); }

    GCPointer<T>& operator=(T* newPtr){
        ptr = newPtr;
        return *this;
    }

    //copy operator
    GCPointer<T>& operator=(const GCPointer<T> other){
        if(this == &other) return *this;
        decrement_references();
        ptr = other.ptr;
        increment_references();
    }

    //move operator
    GCPointer<T>& operator=(GCPointer<T>&& other) noexcept{
        if(this == other) return *this;
        decrement_references();
        ptr = other.ptr;
        other.ptr = nullptr;
    }                                 

    T* pointer(){ 
        return ptr; 
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator->() const{
        return ptr; 
    }

    GCPointer<T> operator+(int n) const{
        return new GCPointer<T>{ptr + n};
    }

    GCPointer<T> operator-(int n) const{
        return new GCPointer<T>{ptr - n};
    }           

    GCPointer<T>& operator++(){
        ptr++;
        return *this;
    } 

    GCPointer<T> operator++(int){
        GCPointer<T> temp{*this};
        operator++();
        return temp;
    }

    GCPointer<T>& operator--(){
        ptr--;
        return *this;
    } 

    GCPointer<T> operator--(int){
        GCPointer<T> temp{*this};
        operator--();
        return temp;
    }

    GCPointer<T>& operator+=(int n){
        ptr += n;
        return *this;
    }

    GCPointer<T>& operator-=(int n){
        ptr -= n;
        return *this;
    }
};

#endif  //conditional compilation