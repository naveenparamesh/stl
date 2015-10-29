#include <string>
#include <cstdlib>
#include <iostream>
#include "myvector.h"
#include "linkedlist.h"
#include "hashmap.h"

using namespace std;

class SetArray{
    private:
        MyDynamicArray<string> theKeys;

    public:
        SetArray(){ //constructor
        };
        ~SetArray(){ //destructor
              theKeys.clear();
              cout << "deleting Set..." << endl;
          };
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();
        // i had to capitalize U because union is a reserved word :/
        // so i thought it owuld look more uniform if they both were uppercase
        SetArray Union(SetArray* set2); 
        SetArray Intersection(SetArray* set2);
        


};

class SetList{
    private:
        LinkedListClass<string> theKeys;
        
    public:
        SetList(){};//constructor
        ~SetList(){ //destructor
            cout << "deleting set..." << endl;
        };
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();
        // LinkedListClass<string> union(HashMap<string>* list);
        // LinkedListClass<string> intersection(HashMap<string>* list);


};

class SetHash{
    private:
        HashMap<string> map;
    public:
        SetHash(){};//constructor
        ~SetHash(){ //destructor
              cout << "deleting set..." << endl;
          };
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();
        // HashMap<string> union(HashMap<string>* map);
        // HashMap<string> intersection(HashMap<string>* map);


};