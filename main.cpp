#include "map.h"
#include "multimap.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "multiset.h"
#include "set.h"

using namespace std;

//---------------------------------MultiMapAPI----------------------------------

template <typename T>
void testMultiMapAPI(T testMap, bool& testPassedStatus){
    testMap->set("hello", 54);
    testMap->set("world", 3);
    testMap->set("hello", 24);
    testMap->set("hello", 71);
    testMap->set("cat", 71);

    //Test searchPairs:
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
    int num1 = testMap->count("hello");
    int num2 = testMap->count("world");
    int num3 = testMap->count("cat");
    
    if(num1 == 2){
        cout << "count works" << endl;
    }
    else {
        testPassedStatus = false;
        cout << "count doesn't work" << endl;
    }
    if(num2 == 1){
        cout << "count works" << endl;
    }
    else {
        testPassedStatus = false;
        cout << "count doesn't work" << endl;
    }
    if(num3 == 1){
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

//---------------------------------MapAPI---------------------------------------

template <typename T>
void testMapAPI(T& testMap, bool& testPassedStatus){
    testMap.set("hello", 54);
    testMap.set("world", 3);
    testMap.set("hello", 24);
    testMap.set("hello", 71);
    testMap.set("cat", 71);
    
    
    // Test searchPairs:
    if (testMap.searchPairs("hello", 3)) {
        testPassedStatus = false;
        cout << "3 is in the map under key \"hello\"" << endl;
    } else {
        cout << "3 is not in the map under the key \"hello\", test passes" << endl;
    }
    if (testMap.searchPairs("world", 3)) {
        cout << "3 is in the map under key \"world\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "3 is not in the map under the key \"world\"" << endl;
    }
    if (testMap.searchPairs("hello", 24)) {
        testPassedStatus = false;
        cout << "24 is in the map under key \"hello\", test passes" << endl;
    } else {
        
        cout << "24 is not in the map under the key \"hello\"" << endl;
    }
    if (testMap.searchPairs("hello", 54)) {
        testPassedStatus = false;
        cout << "54 is in the map under key \"hello\", test passes" << endl;
    } else {
        
        cout << "54 is not in the map under the key \"hello\"" << endl;
    }
    if (testMap.searchPairs("hello", 71)) {
        cout << "71 is in the map under key \"hello\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "71 is not in the map under the key \"hello\"" << endl;
    }
    if (testMap.searchPairs("cat", 71)) {
        cout << "71 is in the map under key \"cat\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "71 is not in the map under the key \"cat\"" << endl;
    }
     if (testMap.searchPairs("apples", -5)) {
         testPassedStatus = false;
        cout << "-5 is in the map under key \"apples\", test passes" << endl;
    } else {
        cout << "-5 is not in the map under the key \"apples\"" << endl;
    }
    

    // Test remove:
    testMap.remove("hello");
     if (testMap.searchPairs("hello", 24)) {
         testPassedStatus = false;
        cout << "24 is in the map under key \"hello\", removal failed" << endl;
    } else {
        cout << "pair no longer exists, test passes" << endl;
    }
    if (testMap.searchPairs("hello", 54)) {
        testPassedStatus = false;
        cout << "54 is in the map under key \"hello\", removal failed" << endl;
    } else {
        cout << "pair no longer exists, test passes" << endl;
    }
    if (testMap.searchPairs("world", 3)) {
        cout << "3 is in the map under key \"world\", test passes" << endl;
    } else {
        testPassedStatus = false;
        cout << "pair no longer exists, removal failed" << endl;
    }
    if (testMap.searchPairs("apples", 48)) {
        testPassedStatus = false;
        cout << "3 is in the map under key \"world\", test passes" << endl;
    } else {
        
        cout << "pair not in map" << endl;
    }
    testMap.set("hello", 54);
    testMap.set("hello", 24);
    
    
    
    //Test get: 
    int test1 = 24;
    int test2 = 3;
    int test3 = 71;
    int result1 = testMap.get("hello");
    int result2 = testMap.get("world");
    int result3 = testMap.get("cat");
    
    if(result1 != test1){
      testPassedStatus = false;
      cout << "it doesn't work" << endl;
    }
    if(result2 != test2){
      testPassedStatus = false;
      cout << "it doesn't work" << endl;
    }
    if(result3 != test3){
      testPassedStatus = false;
      cout << "it doesn't work" << endl;
    }
    
    //Test [] operator:
    int test4 = 24;
    int test5 = 3;
    int test6 = 71;
    int result4 = testMap["hello"];
    int result5 = testMap["world"];
    int result6 = testMap["cat"];

    if(result4 != test4){
      testPassedStatus = false;
      cout << "it doesn't work" << endl;
    }
    if(result5 != test5){
      testPassedStatus = false;
      cout << "it doesn't work" << endl;
    }
    if(result6 != test6){
      testPassedStatus = false;
      cout << "it doesn't work" << endl;
    }
    
    testMap["world"] = 22;
    cout<< testMap["world"] << endl;
}

//---------------------------------MultiSetAPI----------------------------------

template <typename T>
void testMultiSetAPI(T testSet, bool& testPassedStatus){
    //testing both insert and count
    testSet->insert("hello");
    testSet->insert("world");
    testSet->insert("hello");
    testSet->insert("hello");
    testSet->insert("cat");
    testSet->insert("world");
    
    
     unsigned long helloNum = testSet->count("hello");
     
     unsigned long worldNum = testSet->count("world");
     unsigned long catNum = testSet->count("cat");

      if(helloNum != 3){
          testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      if(worldNum != 2){
          testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      if(catNum != 1){
          testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      
      //testing removeOne
      testSet->removeOne("hello");
      testSet->removeOne("world");
      testSet->removeOne("cat");
      
    helloNum = testSet->count("hello");
    worldNum = testSet->count("world");
    catNum = testSet->count("cat");
    
    if(helloNum != 2){
        testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      if(worldNum != 1){
          testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      if(catNum != 0){
          testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      
    testSet->insert("hello");
    testSet->insert("world");
    testSet->insert("cat");
      
      //testing removeAll
      testSet->removeAll("hello");
      testSet->removeAll("world");
      testSet->removeAll("cat");
      
    helloNum = testSet->count("hello");
    worldNum = testSet->count("world");
    catNum = testSet->count("cat");
    
    if(helloNum != 0){
        testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      if(worldNum != 0){
          testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      if(catNum != 0){
          testPassedStatus = false;
          cout << "it didn't work" << endl;
      }
      
      
    testSet->insert("hello");
    testSet->insert("world");
    testSet->insert("cat");
 
    //test is_empty()
    bool empty = testSet->is_empty();
    if(empty){
        testPassedStatus = false;
        cout << "it didn't work" << endl;
    }
     testSet->removeAll("hello");
     testSet->removeAll("world");
     testSet->removeAll("cat");
    empty = testSet->is_empty();
    if(!empty){
        testPassedStatus = false;
        cout << "it didn't work" << endl;
    }
}

//---------------------------------SetAPI---------------------------------------

template <typename T>
void testSetAPI(T testSet, bool& testPassedStatus){
    // Test insert and is_in(string key):
    testSet->insert("hello");
    testSet->insert("world");
    testSet->insert("hello");
    testSet->insert("hello");
    testSet->insert("cat");
    testSet->insert("world");
    
    bool helloBool = testSet->is_in("hello");
    bool worldBool = testSet->is_in("world");
    bool catBool = testSet->is_in("cat");
    bool appleBool = testSet->is_in("apple");
    
    if(!helloBool){
        testPassedStatus = false;
        cout << "it didn't work" << endl;
    }
     if(!worldBool){
         testPassedStatus = false;
        cout << "it didn't work" << endl;
    }
     if(!catBool){
         testPassedStatus = false;
        cout << "it didn't work" << endl;
    }
    if(appleBool){
         testPassedStatus = false;
        cout << "it didn't work" << endl;
    }
    
    
    //Tests for remove() and is_empty():
    bool empty = testSet->is_empty();
    if(empty){
        testPassedStatus = false;
        cout << "it didn't work" << endl;
    }
    testSet->remove("hello");
    testSet->remove("world");
    testSet->remove("cat");
    testSet->remove("apple");
    empty = testSet->is_empty();
    if(!empty){
        testPassedStatus = false;
        cout << "it didn't work" << endl;
    }

 //<ADD THE TEST FOR IS_IN>
    
}





int main(){
    

    bool AllTestsPassed = true;
    MultiMapArray* testMap1 = new MultiMapArray();
    MultiMapList* testMap2 = new MultiMapList();
    MultiMapHash* testMap3 = new MultiMapHash();
    MapArray testMap4;
    MapList testMap5;
    MapHash testMap6;
    MultiSetArray*  testSet1 = new MultiSetArray();
    MultiSetList*  testSet2 = new MultiSetList();
    MultiSetHash*  testSet3 = new MultiSetHash();
     SetArray*  testSet4 = new SetArray();
     SetList*  testSet5 = new SetList();
    SetHash*  testSet6 = new SetHash();
    
    testMultiMapAPI<MultiMapArray*>(testMap1, AllTestsPassed);
    delete testMap1;
    
    testMultiMapAPI<MultiMapList*>(testMap2, AllTestsPassed);
    delete testMap2;
    
    
    
    testMultiMapAPI<MultiMapHash*>(testMap3, AllTestsPassed);
    delete testMap3;
    
    testMapAPI<MapArray>(testMap4, AllTestsPassed);
    
    testMapAPI<MapList>(testMap5, AllTestsPassed);
    
    testMapAPI<MapHash>(testMap6, AllTestsPassed);
    
    testMultiSetAPI<MultiSetArray*>(testSet1, AllTestsPassed);
    delete testSet1;
    
    testMultiSetAPI<MultiSetList*>(testSet2, AllTestsPassed);
    delete testSet2;
    
    testMultiSetAPI<MultiSetHash*>(testSet3, AllTestsPassed);
    delete testSet3;
    
    testSetAPI<SetArray*>(testSet4, AllTestsPassed);
    delete testSet4;
    
    testSetAPI<SetList*>(testSet5, AllTestsPassed);
    delete testSet5;
    
    testSetAPI<SetHash*>(testSet6, AllTestsPassed);
    delete testSet6;
    
    
    if(AllTestsPassed){
      cout << "ALL TESTS PASSED!" << endl; 
    }
    else {
        cout << "NOT ALL TESTS PASSED!" << endl; 
    }
    return 0;
}