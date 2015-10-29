#include <string>
#include <cstdlib>
#include <iostream>
#include "myvector.h"
#include "linkedlist.h"
#include "hashmap.h"

using namespace std;

class MultiSetArray{
    private:
        struct AKey{
            string key;
            unsigned long long numOccurrences; // allows mult vals under same key in array
            AKey(string inKey): numOccurrences(0){
                setAndIncrement(inKey);
            };
            
            // default constructor
            AKey(){}; 
            
            void setAndIncrement(string inKey){
                key = inKey;
                numOccurrences += 1;
            };
            void decrement(){
                numOccurrences -= 1;
            }
        };//end of struct
        MyDynamicArray<AKey> theKeys;
    
    public:
        MultiSetArray(){};//constructor
        ~MultiSetArray(){ //destructor
              theKeys.clear();
              cout << "deleting MultiSet..." << endl;
          };
        void insert(string key);
        bool is_in(string key);
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_empty();  
};




class MultiSetList{
    private:
     struct AKey{
            string key;
            unsigned long long numOccurrences; // allows mult vals under same key in array
            AKey(string inKey): numOccurrences(0){
                setAndIncrement(inKey);
            };
            
            // default constructor
            AKey(){}; 
            
            void setAndIncrement(string inKey){
                key = inKey;
                numOccurrences += 1;
            };
            void decrement(){
                numOccurrences -= 1;
            }
        };//end of struct
        LinkedListClass<AKey> theKeys;
    
    public:
        MultiSetList(){};//constructor
        ~MultiSetList(){ //destructor
              cout << "deleting MultiSet..." << endl;
          };
        void insert(string key);
        bool is_in(string key);
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_empty();
};




class MultiSetHash{
    private:
      struct AKey{
            string key;
            unsigned long long numOccurrences; // allows mult vals under same key in array
            AKey(string inKey): numOccurrences(0){
                setAndIncrement(inKey);
            };
            
            // default constructor
            AKey(){}; 
            
            void setAndIncrement(string inKey){
                key = inKey;
                numOccurrences += 1;
            };
            void decrement(){
                numOccurrences -= 1;
            }
        };//end of struct
        
    
    public:
    HashMap<AKey> map;
        MultiSetHash(){};//constructor
        ~MultiSetHash(){ //destructor
              cout << "deleting MultiSet..." << endl;
          };
        void insert(string key);
        bool is_in(string key);
        unsigned long count(string key);
        void removeOne(string key);
        void removeAll(string key);
        bool is_empty();
};