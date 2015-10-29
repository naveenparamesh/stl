#include "multiset.h"

using namespace std;

// ----------------------------MultiSetArray------------------------------------

void MultiSetArray::insert(string key){
    unsigned long long index_of_key = theKeys.searchKeys(key);
    if(index_of_key == -1){//meaning the key is not in the multiset
        theKeys.push_back(AKey(key));    
    }
    else {
        theKeys.at(index_of_key).setAndIncrement(key);
    }
}

bool MultiSetArray::is_in(string key){
    unsigned long long index_of_key = theKeys.searchKeys(key);
    if(index_of_key == -1){//meaning the key is not in the multiset
        return false;
    }
    else {
        return true;
    }
    
}

unsigned long MultiSetArray::count(string key){
    unsigned long long index_of_key = theKeys.searchKeys(key);
    if(index_of_key == -1){//meaning the key is not in the multiset
        return 0;
    }
    else {
        return (unsigned long)theKeys.at(index_of_key).numOccurrences;
    }
    
}

void MultiSetArray::removeOne(string key){
    unsigned long long index_of_key = theKeys.searchKeys(key);
    if(index_of_key == -1){//meaning the key is not in the multiset so nothing to decrement
        return;
    }
    else {
       theKeys.at(index_of_key).decrement();
    }
    
}

void MultiSetArray::removeAll(string key){
    unsigned long long index_of_key = theKeys.searchKeys(key);
    if(index_of_key == -1){//meaning the key is not in the multiset so no struct to remove
        return;
    }
    else {
       theKeys.removeAt(index_of_key);
    }
    
}

bool MultiSetArray::is_empty(){
    unsigned long long size = theKeys.size();
    if(size == 0){
        return true;
    }
    else {
        return false;
    }
}


// ----------------------------MultiSetList-------------------------------------



void MultiSetList::insert(string key){
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = theKeys.searchStructs(aKey);
    if(keyNode == 0){//meaning the key is not in the multiset
        theKeys.Append(aKey);
    }
    else {
        keyNode->data.setAndIncrement(key);
    }
}

bool MultiSetList::is_in(string key){
    AKey* aKey = new AKey(key);
     Node<AKey>* keyNode = theKeys.searchStructs(aKey);
    if(keyNode == 0){//meaning the key is not in the multiset
        return false;
    }
    else {
        return true;
    }
    
}

unsigned long MultiSetList::count(string key){
    AKey* aKey = new AKey(key);
   Node<AKey>* keyNode = theKeys.searchStructs(aKey);
    if(keyNode == 0){//meaning the key is not in the multiset
        return 0;
    }
    else {
        return (unsigned long)keyNode->data.numOccurrences;
    }
}

void MultiSetList::removeOne(string key){
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = theKeys.searchStructs(aKey);
    if(keyNode == 0){//meaning the key is not in the multiset so nothing to decrement
        return;
    }
    else {
       keyNode->data.decrement();
    }
    
    
}

void MultiSetList::removeAll(string key){
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = theKeys.searchStructs(aKey);
    if(keyNode == 0){//meaning the key is not in the multiset so nothing to decrement
        return;
    }
    else {
       theKeys.DeleteNodeStructs(aKey);
    }
    
}

bool MultiSetList::is_empty(){
    int size = theKeys.countNodes();
    if(size == 0){
        return true;
    }
    else {
        return false;
    }
}


// ----------------------------MultiSetHash-------------------------------------



void MultiSetHash::insert(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = map.getTable()[bucket].searchStructs(aKey);
    
    // if key is not in array add value and key
    if(keyNode == 0){
        map.getTable()[bucket].Append(aKey);
    }
    //add an extra data value onto that key
    else{
        keyNode->data.setAndIncrement(key);
    }
    
}

bool MultiSetHash::is_in(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = map.getTable()[bucket].searchStructs(aKey);
    
    // if key is not in array add value and key
    if(keyNode == 0){
        return false;
    }
    //add an extra data value onto that key
    else{
        return true;
    }
    
}

unsigned long MultiSetHash::count(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = map.getTable()[bucket].searchStructs(aKey);
     // if key is not in array add value and key
    if(keyNode == 0){
        return 0;
    }
    //add an extra data value onto that key
    else{
        //cout << "numOccurrences is: " << keyNode->data.numOccurrences << endl;
        return keyNode->data.numOccurrences;
    }
    
}

void MultiSetHash::removeOne(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = map.getTable()[bucket].searchStructs(aKey);
     // if key is not in array add value and key
    if(keyNode == 0){
        return;
    }
    //add an extra data value onto that key
    else{
        keyNode->data.decrement();
    }
}

void MultiSetHash::removeAll(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    AKey* aKey = new AKey(key);
    Node<AKey>* keyNode = map.getTable()[bucket].searchStructs(aKey);
     // if key is not in array add value and key
    if(keyNode == 0){
        return;
    }
    //add an extra data value onto that key
    else{
        map.getTable()[bucket].DeleteNodeStructs(aKey);
    }
}

bool MultiSetHash::is_empty(){
    int size = 0;
    int i = 0;
    while(true){
        if(i < 1000){
            size = map.getTable()[i].countNodes();
            if(size > 0){
                return false;
            }
        }
        else {
            break;
        }
        
        i += 1;
    }
    return true;
}
