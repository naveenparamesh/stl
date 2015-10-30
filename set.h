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
        SetList Union(SetList* set2);
        SetList Intersection(SetList* set2);


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
        SetHash Union(SetHash* set2);
        SetHash Intersection(SetHash* set2);
    

};