#include "multimap.h"
#include "myvector.h"
#include "linkedlist.h"
#include "hashmap.h"
#include <cstdlib>
#include <string>

using namespace std;

// adds given key and given value to Map
void MultiMapArray::set(string key, int value){
        // search if KeyValuePair is already in array
        if(!searchPairs(key, value)){
            unsigned long long index_of_key = thePairs.searchKeys(key);
            // if key is not in array add value and key
            if(index_of_key == -1){
                KeyAndValue keyAndvalue(key, value);
                thePairs.push_back(keyAndvalue);
            }
            //add the data value onto that key
            else{
                thePairs.at(index_of_key).setData(value);
                //thePairs.at(index_of_key).data.push_back(value);
            }
        }
}

// searches for given value in given index of thePairs, returns true if found
// false otherwise (note: data is array, must walk thru entirely to search)
bool MultiMapArray::searchData(unsigned long long index_of_key, int value){
    for(unsigned long long i = 0; i < thePairs.at(index_of_key).data.size(); i++){
        if(thePairs.at(index_of_key).data.at(i) == value){
            return true;
        }
    }
    
    return false;
}

// searches for the given key value pair, returns true if found, false otherwise
bool MultiMapArray::searchPairs(string key, int value){
    // call searchKeys(key) to get index of given key
    unsigned long long index_of_key = thePairs.searchKeys(key);
    if(index_of_key == -1){
        return false;
    }
    // key exists -> call searchData
    else{
       return searchData(index_of_key, value);
    }
}

// removes all values mapped w/ key
void MultiMapArray::removeAll(string key){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    // removes key and all values from array (see removeAt fn)
    thePairs.removeAt(index_of_key);
}

// find number of elements contained under given key
int  MultiMapArray::count(string key){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    // key doesnt exist
    if(index_of_key == -1){
        return 0;
    }
    else {
        return (int)(thePairs.at(index_of_key).data.size());   
    }
    // cast it to int, because numDataElements is an unsigned long and we want an int
}

// returns all data mapped under given key
int* MultiMapArray::getAll(string key){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    if(index_of_key == -1){
        return 0;
    }
    return (int*)(thePairs.at(index_of_key).data.getArray());
    
}

int MultiMapArray::getNumElements(){
    return (int)thePairs.size();
}


//    BEGINING OF LINKEDLIST IMPLEMENTATION




// adds given key and given value to Map
void MultiMapList::set(string key, int value){
    //KeyAndValue keyValue(key, value);
    KeyAndValue* keyAndValue = new KeyAndValue(key, value);
     if(!searchPairs(key, value)){//if that key value pair doesn't already exist
            
            Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyAndValue);
            // if key is not in array add value and key
            if(keyNode == 0){
                // KeyAndValue keyAndvalue(key, value);
                 thePairs.Append(keyAndValue);
            }
            //add an extra data value onto that key
            else{
                //thePairs.at(index_of_key).setData(value);
                keyNode->data.data.Append(&value);
            }
        }
}


// searches for the given key value pair, returns true if found, false otherwise
bool MultiMapList::searchPairs(string key, int value){
    KeyAndValue* keyAndValue = new KeyAndValue(key, value);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyAndValue);
    if(keyNode == 0){// meaning the if that key wasn't in the list
        return false;
    }
    else {
        Node<int>* dataNode = keyNode->data.data.searchInts(value);//search that key's data
        if(dataNode == 0){//meaning that data isn't there under that key
            return false;
        }
        else {
            return true;
        }
        
    }
    
    // return false;
    
}

// removes all values mapped w/ key
void MultiMapList::removeAll(string key){
    KeyAndValue* keyAndValue = new KeyAndValue(key, 0);
    thePairs.DeleteNodeStructs(keyAndValue);
}

// find number of elements contained under given key
int  MultiMapList::count(string key){
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyValue);
    if(keyNode == 0){
        return 0;
    }
    else {
        return keyNode->data.data.countNodes();     
    }
   

}

// returns all data mapped under given key
int* MultiMapList::getAll(string key){
    KeyAndValue* keyAndValue = new KeyAndValue(key, 0);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyAndValue);
    if(keyNode == 0){//if that key isn't even in the map
        return 0;
    }
    int size = keyNode->data.data.countNodes();
    MyDynamicArray<int> temp_array;
    
        // consider base-case -> key not in List
        if(keyNode == 0){
            return temp_array.getArray(); // (int*)(temp_array.getArray());s
        }
        // lets walk thru LL and add data of each node into temp_array each step
        else{
            Node<int>* currentNode = keyNode->data.data.getHeadNode();
            for(int i = 0; i < size; i++){
                temp_array.push_back(currentNode->data);
                currentNode = currentNode->nextNode;
            }
            return temp_array.getArray();
        }
        
}


//    BEGINING OF HASHMAP IMPLEMENTATION



// adds given key and given value to Map
void MultiMapHash::set(string key, int value){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    KeyAndValue* keyValue = new KeyAndValue(key, value);
    
     if(!searchPairs(key, value)){//if that key value pair doesn't already exist
            Node<KeyAndValue>* keyNode = map.getTable()[bucket].searchStructs(keyValue);
            // if key is not in array add value and key
            if(keyNode == 0){
                 map.getTable()[bucket].Append(keyValue);
            }
            //add an extra data value onto that key
            else{
                //thePairs.at(index_of_key).setData(value);
                Node<KeyAndValue>* keyNode =  map.getTable()[bucket].searchStructs(keyValue);
                keyNode->data.data.Append(&value);
            }
        }
}

// searches for the given key value pair, returns true if found, false otherwise
bool MultiMapHash::searchPairs(string key, int value){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    KeyAndValue* keyValue = new KeyAndValue(key, value);
    Node<KeyAndValue>* keyNode =  map.getTable()[bucket].searchStructs(keyValue);
    if(keyNode == 0){// meaning the if that key wasn't in the list
        return false;
    }
    else {
        Node<int>* dataNode = keyNode->data.data.searchInts(value);//search that key's data
        if(dataNode == 0){//meaning that data isn't there under that key
            return false;
        }
        else {
            return true;
        }
        
    }
}

// removes all values mapped w/ key
void MultiMapHash::removeAll(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    map.getTable()[bucket].DeleteNodeStructs(keyValue);
    
}

// find number of elements contained under given key
int  MultiMapHash::count(string key){

    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    Node<KeyAndValue>*  keyNode =  map.getTable()[bucket].searchStructs(keyValue);
    if(keyNode == 0){
        return 0;
    }
    else {
        return keyNode->data.data.countNodes();   
    }

}

// returns all data mapped under given key
int* MultiMapHash::getAll(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    Node<KeyAndValue>* keyNode = map.getTable()[bucket].searchStructs(keyValue);
    int size = keyNode->data.data.countNodes();
    MyDynamicArray<int> temp_array;
    
        // consider base-case -> key not in List
        if(keyNode == 0){
            return temp_array.getArray(); // (int*)(temp_array.getArray());
        }
        // lets walk thru LL and add data of each node into temp_array each step
        else{
            Node<int>* currentNode = keyNode->data.data.getHeadNode();
            for(int i = 0; i < size; i++){
                temp_array.push_back(currentNode->data);
                currentNode = currentNode->nextNode;
            }
            return temp_array.getArray();
        }
        return temp_array.getArray();
    
}



