#ifndef HASHMAP_
#define HASHMAP_
#include <iostream>
#include <string>
#include "linkedlist.h"
#define FNV_32_prime 16777619
#define FNV_32_offset 2166136261
using namespace std;


template<typename T>
class HashMap{
    private:
        int size_of_table;
        LinkedListClass<T>* table;
    public:
        bool empty;
        HashMap(){
            size_of_table = 1000;
            table = new LinkedListClass<T>[size_of_table];
            //initializes the table with each bucket having an empty linked list
            for(int i = 0; i < size_of_table; i++){
                table[i] = LinkedListClass<T>();
            }
        };
        ~HashMap(){
            clearHashMap();//goes through each index and deletes it, thus calls the linked list class destructor
        };
        
        unsigned int FNV1a(const void *bytes, int len){
            unsigned int h = FNV_32_offset;
            for(int i = 0; i < len; ++i){
                unsigned char data = * ((unsigned char *) bytes + i);
                h ^= data;
                h *= FNV_32_prime;
            }
            return h;
        }
    
        int myhash(const void* bytes, int len, int array_length){
            unsigned int hash = FNV1a(bytes, len);
            return hash % array_length;
        }
        
        void add(string key, T element){
            unsigned int bucket = 0;
            bucket = myhash(&key.at(0), key.length(), size_of_table);
            table[bucket].Append(element);
        }
        
        void deleteKeyValue(string key, T element){
            unsigned int bucket = 0;
            bucket = myhash(&key.at(0), key.length(), size_of_table);
            table[bucket].DeleteNodeStructs(element);
        }
        
        void deleteString(string key, T element){
            unsigned int bucket = 0;
            bucket = myhash(&key.at(0), key.length(), size_of_table);
            table[bucket].DeleteNode(element);
        }
        
        LinkedListClass<T>* getTable(){
            return table;
        }
        
        void clearHashMap(){
            delete[] table;
        }


};


#endif


