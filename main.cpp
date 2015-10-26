#include "multimap.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T>
bool testMultiMapAPI(T testMap, bool& testPassedStatus){
    testMap->set("hello", 54);
    testMap->set("world", 3);
    testMap->set("hello", 24);
    testMap->set("hello", 71);
    testMap->set("cat", 71);

    // Test searchPairs:
    if (testMap->searchPairs("hello", 3)) {
        testPassedStatus = false;
        cout << "3 is in the multimap under key \"hello\"" << endl;
    } else {
        cout << "3 is not in the multimap under the key \"hello\", test passes" << endl;
    }
    if (testMap->searchPairs("world", 3)) {
        cout << "3 is in the multimap under key \"world\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "3 is not in the multimap under the key \"world\"" << endl;
    }
    if (testMap->searchPairs("hello", 24)) {
        cout << "24 is in the multimap under key \"hello\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "24 is not in the multimap under the key \"hello\"" << endl;
    }
    if (testMap->searchPairs("hello", 54)) {
        cout << "54 is in the multimap under key \"hello\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "54 is not in the multimap under the key \"hello\"" << endl;
    }
    if (testMap->searchPairs("hello", 71)) {
        cout << "71 is in the multimap under key \"hello\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "71 is not in the multimap under the key \"hello\"" << endl;
    }
    if (testMap->searchPairs("cat", 71)) {
        cout << "71 is in the multimap under key \"cat\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "71 is not in the multimap under the key \"cat\"" << endl;
    }
     if (testMap->searchPairs("apples", -5)) {
         testPassedStatus = false;
        cout << "-5 is in the multimap under key \"apples\", test passes" << endl;
    } else {
        cout << "-5 is not in the multimap under the key \"apples\"" << endl;
    }
    

    // Test removeAll:
    testMap->removeAll("hello");
     if (testMap->searchPairs("hello", 24)) {
         testPassedStatus = false;
        cout << "24 is in the multimap under key \"hello\", removal failed" << endl;
    } else {
        cout << "pair no longer exists, test passes" << endl;
    }
    if (testMap->searchPairs("hello", 54)) {
        testPassedStatus = false;
        cout << "54 is in the multimap under key \"hello\", removal failed" << endl;
    } else {
        cout << "pair no longer exists, test passes" << endl;
    }
    if (testMap->searchPairs("world", 3)) {
        cout << "3 is in the multimap under key \"world\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "pair no longer exists, removal failed" << endl;
    }
    if (testMap->searchPairs("apples", 48)) {
        testPassedStatus = false;
        cout << "3 is in the multimap under key \"world\", test passes" << endl;
    } else {
        
        cout << "pair not in multimap" << endl;
    }
    testMap->set("hello", 54);
    testMap->set("hello", 24);
    
    
    // Test count:
    int num7 = testMap->count("hello");
    int num8 = testMap->count("world");
    int num9 = testMap->count("cat");
    
    if(num7 == 2){
        cout << "count works" << endl;
    }
    else {
        testPassedStatus = false;
        cout << "count doesn't work" << endl;
    }
    if(num8 == 1){
        cout << "count works" << endl;
    }
    else {
        testPassedStatus = false;
        cout << "count doesn't work" << endl;
    }
    if(num9 == 1){
        cout << "count works" << endl;
    }
    else {
        testPassedStatus = false;
        cout << "count doesn't work" << endl;
    }
    
    // Test getNumElements: 
    int* test1 = new int[2];
    test1[0] = 54;
    test1[1] = 24;
    int* test2 = new int[1];
    test2[0] = 3;
    int* test3 = new int[1];
    test3[0] = 71;
    int* result1 = testMap->getAll("hello");
    int* result2 = testMap->getAll("world");
    int* result3 = testMap->getAll("cat");
    
    for(int i = 0; i < 2; i++){
        if(result1[i] != test1[i]){
            cout << "It didn't work!" << endl;
            testPassedStatus = false;
        }
    }
    
    for(int i = 0; i < 1; i++){
        if(result2[i] != test2[i]){
            cout << "It didn't work!" << endl;
            testPassedStatus = false;
        }
    }
     for(int i = 0; i < 1; i++){
        if(result3[i] != test3[i]){
            testPassedStatus = false;
            cout << "It didn't work!" << endl;
        }
    }
}


int main(){
    
//---------------------------------MutliMapArray---------------------------------
    bool AllTestsPassed = true;
    MultiMapArray* testMap1 = new MultiMapArray();
    MultiMapList* testMap2 = new MultiMapList();
    MultiMapHash* testMap3 = new MultiMapHash();
    
    testMultiMapAPI<MultiMapArray*>(testMap1, AllTestsPassed);
    delete testMap1;
    
    testMultiMapAPI<MultiMapList*>(testMap2, AllTestsPassed);
    delete testMap2;
    
    testMultiMapAPI<MultiMapHash*>(testMap3, AllTestsPassed);
    delete testMap3;
    
    
    if(AllTestsPassed){
      cout << "ALL TESTS PASSED!" << endl; 
    }
    else {
        cout << "NOT ALL TESTS PASSED!" << endl; 
    }
    return 0;
}