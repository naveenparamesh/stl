#include <string>
#include <cstdlib>
#include <iostream>
#include "myvector.h"
#include "linkedlist.h"
#include "hashmap.h"
using namespace std;

class MultiMapArray{
    private:
        struct KeyAndValue{
            string key;
            MyDynamicArray<int> data; // allows mult vals under same key in array
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
                data.push_back(value);
            };
        }; // end of struct

        
        bool searchData(unsigned long long index_of_key, int value);

    public:
    MyDynamicArray<KeyAndValue> thePairs;
        MultiMapArray(){};//constructor
        ~MultiMapArray(){ //destructor
            thePairs.clear();
            cout << "deleting MultiMap..." << endl;
        };
        bool searchPairs(string key, int value);
        void set(string key, int value);
        void removeAll(string key);
        int  count(string key);
        int* getAll(string key);
        int getNumElements();
};






class MultiMapList{
    private:
        struct KeyAndValue{
            string key;
            LinkedListClass<int> data; // allows mult vals under same key in array
            KeyAndValue(string inKey, int inValue){
                set(inKey, inValue);
            };
            
            // default constructor
            KeyAndValue(){}; 
            ~KeyAndValue(){
                
            }; 
            
            void set(string inKey, int inValue){
                key = inKey;
                setData(inValue);
            };
            
            void setData(int value){
                data.Append(&value);
            };
        
        }; // end of struct
        
        LinkedListClass<KeyAndValue> thePairs;

    public:
        MultiMapList(){};//constructor
        ~MultiMapList(){ //destructor
            //thePairs.clearList();
            cout << "deleting MultiMap..." << endl;
        };
        bool searchPairs(string key, int value);
        void set(string key, int value);
        void removeAll(string key);
        int  count(string key);
        int* getAll(string key);

};

class MultiMapHash{
    
    private:
         struct KeyAndValue{
                string key;
                LinkedListClass<int> data; // allows mult vals under same key in array
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
                    data.Append(&value);
                };
            
            }; // end of struct
        HashMap<KeyAndValue> map;

    public:
        MultiMapHash(){};//constructor
        ~MultiMapHash(){ //destructor
            //map.~HashMap<KeyAndValue>();
            cout << "deleting MultiMap..." << endl;
        };
        bool searchPairs(string key, int value);
        void set(string key, int value);
        void removeAll(string key);
        int  count(string key);
        int* getAll(string key);

};






