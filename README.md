# Amazon-Dynamo Clone
This is a garbage collector for C++ that makes use of reference counting.

# Main Components
+ GCPointer.hpp
  - A class template.
+ reference_counting.cpp
  - Contains the definition for the unordered map<void*, int> that will be utilized by GCPointer objects.
+ reference_counting.h
  - Contains the declaration of an extern unordered map<void*, int>.
  
# Techniques/Ideas Used
+ Smart Pointer
  - A pointer that does the freeing for you.
+ Class Template
  - A recipe for creating classes.
+ Operator Overloading
  - In this instance, allows for operators such as + and -- to be used on objects of a custom class.
+ Reference Counting
  - Keeps track of the number of references to a pointer.
  - Frees a pointer when its reference count reaches 0.

# How To Use
1. #include GCPointer.hpp in your project!
