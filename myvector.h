#ifndef MYVECTOR_
#define MYVECTOR_
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class MyDynamicArray {

  public:
    MyDynamicArray(unsigned long long initial_size = 0);
    void push_back(T element);
    unsigned long long size();
    T at(unsigned long long index);
    void removeAt(unsigned long long index_of_key);
    void clear();
    T* getArray();
    unsigned long long searchKeys(string key);

  private:
    T* my_vector;
    unsigned long long size_of_array;
};

template<typename T>
MyDynamicArray<T>::MyDynamicArray(unsigned long long initial_size){
  my_vector = new T[initial_size];
  size_of_array = initial_size;
}

template<typename T>
void MyDynamicArray<T>::push_back(T element){
  T* temp = new T[size_of_array + 1];
  for(int i = 0; i < size_of_array; i++){
    temp[i] = my_vector[i];
  }
  size_of_array += 1;
  delete[] my_vector;
  my_vector = temp;
  my_vector[size_of_array - 1] = element;
}

template<typename T>
void MyDynamicArray<T>::removeAt(unsigned long long index_of_key){
        if(size_of_array == 0){
          return;
        }
        T* temp = new T[size_of_array - 1];
        unsigned long long j = 0; //variable running throught temp
        // we want this for loop to iterate throught the entire Pairs array for sure
        // because we want to check every key, but when we get to the key which we don't
        // want to add to the final array, we make sure we don't add it by comparing i
        // to the index of that key and only add it if it isn't that index. But we also
        // need a variable j because we don't want to use i to iterate through temp else we will
        // eventually go out of bounds because temp is one size less that thePairs, resulting in a 
        // seg fault. Thus, we need another counter, j which keeps track of which index temp is at
        // thus adding the correct key and value pairs to the correct index in temp
        for(unsigned long long i = 0; i < size_of_array; i++){
            //meaning don't add that KeyAndValue Struct to the temporary array, so we don't have it
            // in the final array
            if(i != index_of_key){
                temp[j] = my_vector[i];
                j += 1;
            }
        }
        delete[] my_vector;
        my_vector = temp;
        size_of_array -= 1; // resize because now it has one less key and value pair
}

template<typename T>
unsigned long long MyDynamicArray<T>::size(){
  return size_of_array;
}

template<typename T>
T MyDynamicArray<T>::at(unsigned long long index){
  return my_vector[index];
}

template<typename T>
void MyDynamicArray<T>::clear(){
  delete[] my_vector;
  size_of_array = 0;
}

template<typename T>
T* MyDynamicArray<T>::getArray(){
  return my_vector;
}

template<typename T>
unsigned long long MyDynamicArray<T>::searchKeys(string key){
    for(unsigned long long i = 0; i < size_of_array; i++){
        if(my_vector[i].key == key){
            return i;
        }
    }
    return -1;
}

#endif