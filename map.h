#include <string>
#include <cstdlib>
#include <iostream>
#include "myvector.h"
#include "linkedlist.h"
#include "hashmap.h"

using namespace std;

class MapArray{
    private:
        struct KeyAndValue{
            string key;
            int data; // allows mult vals under same key in array
            KeyAndValue(string inKey, int inValue){
                set(inKey, inValue);
            };
            
            // default constructor
            KeyAndValue(){}; 
            
            void set(string inKey, int inValue){
                key = inKey;
                setData(inValue);
            };
            
            void setData(int value){
                data = value;
            };
        
        }; // end of struct
        
        MyDynamicArray<KeyAndValue> thePairs;
    
    
    public:
         MapArray(){};//constructor
        ~MapArray(){ //destructor
              thePairs.clear();
              cout << "deleting Map..." << endl;
          };
        void set(string key, int value);
        void remove(string key);
        int get(string key);
        int& operator[](string key);
        bool searchPairs(string key, int value);
};

class MapList{
    private:
        struct KeyAndValue{
            string key;
            int data; // allows mult vals under same key in array
            KeyAndValue(string inKey, int inValue){
                set(inKey, inValue);
            };
            
            // default constructor
            KeyAndValue(){}; 
            
            void set(string inKey, int inValue){
                key = inKey;
                setData(inValue);
            };
            
            void setData(int value){
                data = value;
            };
        
        }; // end of struct
        LinkedListClass<KeyAndValue> thePairs;
    
    public:
        MapList(){};//constructor
        ~MapList(){ //destructor
            
            cout << "deleting Map..." << endl;
        };
        void set(string key, int value);
        void remove(string key);
        int get(string key);
        int& operator[](string key);
        bool searchPairs(string key, int value);
    
};

class MapHash{
    private:
        struct KeyAndValue{
            string key;
            int data; // allows mult vals under same key in array
            KeyAndValue(string inKey, int inValue){
                set(inKey, inValue);
            };
            
            // default constructor
            KeyAndValue(){}; 
            
            void set(string inKey, int inValue){
                key = inKey;
                setData(inValue);
            };
            
            void setData(int value){
                data = value;
            };
        
        }; // end of struct
        
        HashMap<KeyAndValue> map;
    
    
    public:
        MapHash(){};//constructor
        ~MapHash(){ //destructor
            
            cout << "deleting Map..." << endl;
        };
        void set(string key, int value);
        void remove(string key);
        int get(string key);
        int& operator[](string key);
        bool searchPairs(string key, int value);
};