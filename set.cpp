#include "set.h"

using namespace std;

// --------------------------------SetArray-------------------------------------

// pushes given key into array
void SetArray::insert(string key){
    unsigned long long index_of_key = theKeys.searchKey(key);
    if(index_of_key == -1){
        theKeys.push_back(key);
    }
}

// searches the array for given key:
// returns true if found, else false
bool SetArray::is_in(string key){
    unsigned long long index_of_key = theKeys.searchKey(key);
    if(index_of_key == -1){//meaning the key is not in the set
        return false;
        }
    else{
        return true;
    }
}

// removes the given key from the set
void SetArray::remove(string key){
    unsigned long long index_of_key = theKeys.searchKey(key);
    if(index_of_key == -1){// nothing in set to remove
        return;
    }
    else {
       theKeys.removeAt(index_of_key); // this removes the element at that index
    }
    
}

// checks if the set is empty:
// returns true if no elements found, else false
bool SetArray::is_empty(){
    if(theKeys.size() == 0){
        return true;
    }
    else{
        return false;
    }
}

// complexity is O(n^2)
SetArray SetArray::Union(SetArray* set2){
    SetArray* setUnion = new SetArray();
    // adds all of the elements from one set into the union
    for(int i = 0; i < theKeys.size(); i++) {
        setUnion->theKeys.push_back(theKeys.at(i));
    }
    // checks to see if the elements in set2 are in setUnion. If an element
    // of set2 is not in setUnion, then add that element to setUnion
    for(int i = 0; i < set2->theKeys.size(); i++) {
        if (!(setUnion->is_in(set2->theKeys.at(i)))) {
             setUnion->theKeys.push_back(set2->theKeys.at(i));
        }
    }
    return *setUnion;
}
// complexity is O(n^2)
SetArray SetArray::Intersection(SetArray* set2){
    SetArray* setIntersect = new SetArray();
    
    // for(int i = 0; i < theKeys.size(); i++) {
    //         setIntersect->theKeys.push_back(theKeys.at(i));
    //     }
        
    // for(int i = 0; i < set2->theKeys.size(); i++) {
    //         setIntersect->theKeys.push_back(set2->theKeys.at(i));
    // }
    
    // checks which set is greater, so you the for loop runs as long
    // as the longer set
     if(theKeys.size() > set2->theKeys.size()) {
        for(int i = 0; i < set2->theKeys.size(); i++) {
            for(int j = 0; j < theKeys.size(); j++){
                if (theKeys.at(j) == set2->theKeys.at(i)) { //if both sets have same element
                        setIntersect->theKeys.push_back(theKeys.at(j));
                    }
            }
            
        }
    } else { // if set2 is larger
        for(int i = 0; i < theKeys.size(); i++) {
            for(int j = 0; j < set2->theKeys.size(); j++){
                if (set2->theKeys.at(j) == theKeys.at(i)) { //if both sets have same element
                        setIntersect->theKeys.push_back(theKeys.at(i));
                    }
            }
        }
    }
   
    // if(theKeys.size() > set2->theKeys.size()) {
    //     for(int i = 0; i < theKeys.size(); i++) {
    //         if (set2->is_in(theKeys.at(i))) { //if both sets have same element
    //             setIntersect->theKeys.push_back(theKeys.at(i));
    //         }
    //     }
    // } else { // if set2 is larger
    //     for(int i = 0; i < set2->theKeys.size(); i++) {
    //         if (is_in(set2->theKeys.at(i))) {
    //             setIntersect->theKeys.push_back(set2->theKeys.at(i));
    //         }
    //     }
    // }
    return *setIntersect;
    
}


// --------------------------------SetList---------------------------------------


void SetList::insert(string key){
     Node<string>* searchNode = theKeys.searchInts(key);
    if(searchNode == 0){//meaning key is not in the linked list
        theKeys.Append(&key);
    }
}
bool SetList::is_in(string key){
    Node<string>* searchNode = theKeys.searchInts(key);
    if(searchNode == 0){//meaning key is not in the linked list
        return false;
    }
    else{
        return true;
    }
}
void SetList::remove(string key){
    // we dont need to search for the key beforehand because DeleteNode
    // already does that
    theKeys.DeleteNode(key); 
}

// search through List:
// return true if head == 0, else return false
bool SetList::is_empty(){
    int size = theKeys.countNodes();
    if(size > 0){
        return false;
    }
    else{
        return true;
    }
}

// SetList -> SetList
// Walk thru List, append data to setUnion, 
// second walk thru given set, append only if data isnt already in setUnion
SetList SetList::Union(SetList* set2){
    SetList* setUnion = new SetList();
    Node<string>* nodeSet2 = set2->theKeys.getHeadNode();
    //Node<string>* nodeKey = theKeys.searchInts(key);
    Node<string>* nodeKey = theKeys.getHeadNode();

    // adds all of the elements from one set into the union
    for(int i = 0; i < theKeys.countNodes(); i++) {
        setUnion->theKeys.Append(&(nodeKey->data));
        nodeKey = nodeKey->nextNode;
        
    }
    // checks to see if the elements in set2 are in setUnion. If an element
    // of set2 is not in setUnion, then add that element to setUnion
    
    for(int i = 0; i < set2->theKeys.countNodes(); i++) {
        
        if (!(setUnion->is_in(nodeSet2->data))){ //if that string is not in the other list, then add
            setUnion->theKeys.Append(&(nodeSet2->data));
        }
       
        nodeSet2 = nodeSet2->nextNode;
    }
    return *setUnion;
    
}

SetList SetList::Intersection(SetList* set2){
    SetList* setIntersect = new SetList();
    Node<string>* nodeKey = theKeys.getHeadNode();
    Node<string>* nodeSet2 = set2->theKeys.getHeadNode();
    
    if(theKeys.countNodes() < set2->theKeys.countNodes()){
        for(int i = 0; i < theKeys.countNodes(); i++){
            for(int j = 0; j < set2->theKeys.countNodes(); j++){
                if(nodeSet2->data == nodeKey->data){
                    setIntersect->theKeys.Append(&(nodeKey->data));
                }   
                nodeSet2 = nodeSet2->nextNode;
            }
            nodeKey = nodeKey->nextNode;
        }
    }
    else {
         for(int i = 0; i < set2->theKeys.countNodes(); i++){
            for(int j = 0; j < theKeys.countNodes(); j++){
                 if(nodeKey->data == nodeSet2->data){
                    setIntersect->theKeys.Append(&(nodeKey->data));
                }   
                nodeKey = nodeKey->nextNode;
            }
            nodeSet2 = nodeSet2->nextNode;
        }
    }
    
    return *setIntersect;
}

// --------------------------------SetHash--------------------------------------

// add given key to the set, no repeating keys allowed
void SetHash::insert(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    Node<string>* keyNode = map.getTable()[bucket].searchInts(key);
    // if key is not in array add value and key to set
    if(keyNode == 0){
        map.getTable()[bucket].Append(&key);
    }
}

bool SetHash::is_in(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    Node<string>* keyNode = map.getTable()[bucket].searchInts(key);
    
    // if key is not in array add value and key
    if(keyNode == 0){
        return false;
    }
    //add an extra data value onto that key
    else{
        return true;
    }
    
}

void SetHash::remove(string key){
    unsigned int bucket = map.myhash(&key.at(0), key.length(), 1000);
    map.getTable()[bucket].DeleteNode(key);
}


bool SetHash::is_empty(){
    int size = 0;
    int i = 0;
    while(true){
        if(i < 1000){
            size = map.getTable()[i].countNodes();
            if(size > 0){
                return false;
            }
        }
        else{
            break;
        }
        
        i += 1;
    }
    return true;
    
}

SetHash SetHash::Union(SetHash* set2){
    SetHash* setUnion = new SetHash();
    
    // for(int i = 0; i < 1000; i++){
    //     Node<string>* nodeKey = map.getTable()[i].getHeadNode();
    //     if(nodeKey != 0){//meaning there is something at that bucket to add
    //         for(int j = 0; j < map.getTable()[i].countNodes(); j++) {
    //             setUnion->map.getTable()[i].Append(&(nodeKey->data));
    //             nodeKey = nodeKey->nextNode;
    //         }
    //     }
    // }
    
    
    // for(int i = 0; i < 1000; i++){
    //     Node<string>* nodeSet2 = set2->map.getTable()[i].getHeadNode();
    //     if(nodeSet2 != 0){//meaning there is something at that bucket to add
    //         for(int j = 0; j < map.getTable()[i].countNodes(); j++) {
    //             if(nodeSet2->data == setUnion->map.getTable()[]){
                    
    //             }
    //             setUnion->map.getTable()[i].Append(&(nodeKey->data));
    //             nodeKey = nodeKey->nextNode;
    //         }
    //     }
    // }
    
    
    
    return *setUnion;
}

SetHash SetHash::Intersection(SetHash* map){
    SetHash* setIntersect = new SetHash();

    
    return *setIntersect;
}
