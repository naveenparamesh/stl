#include "map.h"

using namespace std;


void MapArray::set(string key, int value){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    if(index_of_key == -1){// meaning the key is not in the map, just add it normally
        thePairs.push_back(KeyAndValue(key, value));
    }
    else {
        thePairs.at(index_of_key).data = value;
    }
}

// removes KeyandValue pair at given index
void MapArray::remove(string key){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    if(index_of_key == -1){
        return; // nothing to remove
    }
    else{
        thePairs.removeAt(index_of_key);
    }
    
}

// returns the value paired with the given key
int MapArray::get(string key){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    if(index_of_key == -1){
        return -1;
    }
    else {
        return thePairs.at(index_of_key).data;
    }
    
    
}

int& MapArray::operator[](string key){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    //MAKE SURE YOU FIGURE THIS OUT LATER
    
    
    
     //if(index_of_key == -1){
         //return -1;
     //}
    //else {
        return thePairs.at(index_of_key).data;
    //}
}



bool MapArray::searchPairs(string key, int value){
    unsigned long long index_of_key = thePairs.searchKeys(key);
    if(index_of_key == -1){
        return false;
    }
    else{
        if(thePairs.at(index_of_key).data == value){
            return true;
        }
        else{
            return false;
        }
    }
}


// return data from keyandvalue struct
void MapList::set(string key, int value){
    KeyAndValue* keyValue = new KeyAndValue(key, value);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyValue);
    if(keyNode == 0){// key is not in map
        thePairs.Append(keyValue);
    }
    else{
        keyNode->data.data = value;
    }
}

void MapList::remove(string key){
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyValue);
    // if key is not in array add value and key
    if(keyNode == 0){
        return;
    }
    else {
        thePairs.DeleteNodeStructs(keyValue);
    }
}

// return data from keyandvalue struct
int MapList::get(string key){
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyValue);
    if(keyNode == 0){// key is not in map
        return -1;
    }
    else{
        return keyNode->data.data;
    }
}


int& MapList::operator[](string key){
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyValue);
    // if(keyNode == 0){// key is not in map
    //     int num = -1;
    //     return num;
    // }
    //else {
        return keyNode->data.data;
    //}
}


// searches for the given key value pair, returns true if found, false otherwise
bool MapList::searchPairs(string key, int value){
    KeyAndValue* keyValue = new KeyAndValue(key, value);
    Node<KeyAndValue>* keyNode = thePairs.searchStructs(keyValue);
    if(keyNode == 0){// meaning the if that key wasn't in the list
        return false;
    }
    else {
        if(keyNode->data.data == value){//meaning that data isn't there under that key
            return true;
        }
        else {
            return false;
        }
        
    }
    
    return false;
    
}





void MapHash::set(string key, int value){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    KeyAndValue* keyValue = new KeyAndValue(key, value);
    Node<KeyAndValue>* keyNode = map.getTable()[bucket].searchStructs(keyValue);
    
    // if key is not in array add value and key
    if(keyNode == 0){
        map.getTable()[bucket].Append(keyValue);
    }
    //add an extra data value onto that key
    else{
        keyNode->data.data = value;
    }
        
    
}

void MapHash::remove(string key){
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    map.getTable()[bucket].DeleteNodeStructs(keyValue);
    
}

int MapHash::get(string key){
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    Node<KeyAndValue>* keyNode = map.getTable()[bucket].searchStructs(keyValue);
    if(keyNode == 0){// key is not in map
        return -1;
    }
    else {
        return keyNode->data.data;    
    }
    
    
}

int& MapHash::operator[](string key){
    KeyAndValue* keyValue = new KeyAndValue(key, 0);
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    Node<KeyAndValue>* keyNode = map.getTable()[bucket].searchStructs(keyValue);
    // if(keyNode == -1){// key is not in map
    //     return -1;
    // }
    //else {
        return keyNode->data.data;
    //}
    
    
}

// searches for the given key value pair, returns true if found, false otherwise
bool MapHash::searchPairs(string key, int value){
    KeyAndValue* keyValue = new KeyAndValue(key,value);
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    Node<KeyAndValue>* keyNode =  map.getTable()[bucket].searchStructs(keyValue);
    if(keyNode == 0){// meaning the if that key wasn't in the list
        return false;
    }
    else {
        
        if(keyNode->data.data == value){//meaning that data isn't there under that key
            return true;
        }
        else {
            return false;
        }
        
    }
}