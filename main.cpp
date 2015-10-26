#include "multimap.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
    
//---------------------------------MutliMapArray---------------------------------
    
    MultiMapArray* testMap = new MultiMapArray();
    testMap->set("hello", 54);
    testMap->set("world", 3);
    testMap->set("hello", 24);
    testMap->set("hello", 71);
    bool AllTestsPassed = true;
    
    // Test searchPairs:
    if (testMap->searchPairs("hello", 3)) {
         AllTestsPassed = false;
        cout << "3 is in the multimap under key \"hello\"" << endl;
    } else {
        cout << "3 is not in the multimap under the key \"hello\", test passes" << endl;
    }
    if (testMap->searchPairs("world", 3)) {
        cout << "3 is in the multimap under key \"world\", test passes" << endl;
    } else {
        AllTestsPassed = false;
        cout << "3 is not in the multimap under the key \"world\"" << endl;
    }
    if (testMap->searchPairs("hello", 24)) {
        cout << "24 is in the multimap under key \"hello\", test passes" << endl;
    } else {
         AllTestsPassed = false;
        cout << "24 is not in the multimap under the key \"hello\"" << endl;
    }
    if (testMap->searchPairs("hello", 54)) {
        cout << "54 is in the multimap under key \"hello\", test passes" << endl;
    } else {
         AllTestsPassed = false;
        cout << "54 is not in the multimap under the key \"hello\"" << endl;
    }
    
    // Test removeAll:
    testMap->removeAll("hello");
     if (testMap->searchPairs("hello", 24)) {
          AllTestsPassed = false;
        cout << "24 is in the multimap under key \"hello\", removal failed" << endl;
    } else {
        cout << "pair no longer exists, test passes" << endl;
    }
    if (testMap->searchPairs("hello", 54)) {
         AllTestsPassed = false;
        cout << "54 is in the multimap under key \"hello\", removal failed" << endl;
    } else {
        cout << "pair no longer exists, test passes" << endl;
    }
    if (testMap->searchPairs("world", 3)) {
        cout << "3 is in the multimap under key \"world\", test passes" << endl;
    } else {
         AllTestsPassed = false;
         
    }
    
    
    delete testMap;// deletes this object and frees the memory
    
    
//---------------------------------MutliMapList---------------------------------
//     MultiMapList* testMap2 = new MultiMapList();
//     testMap2->set("hello", 54);
//     testMap2->set("world", 3);
//     testMap2->set("hello", 24);
    
//     // Test searchPairs:
//     if (testMap2->searchPairs("hello", 3)) {
//         AllTestsPassed = false;
//         cout << "3 is in the multimap under key \"hello\"" << endl;
//     } else {
//         cout << "3 is not in the multimap under the key \"hello\", test passes" << endl;
//     }
//     if (testMap2->searchPairs("world", 3)) {
//         cout << "3 is in the multimap under key \"world\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "3 is not in the multimap under the key \"world\"" << endl;
//     }
//     if (testMap2->searchPairs("hello", 24)) {
//         cout << "24 is in the multimap under key \"hello\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "24 is not in the multimap under the key \"hello\"" << endl;
//     }
//     if (testMap2->searchPairs("hello", 54)) {
//         cout << "54 is in the multimap under key \"hello\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "54 is not in the multimap under the key \"hello\"" << endl;
//     }
    
//     // Test removeAll:
//     testMap2->removeAll("hello");
//      if (testMap2->searchPairs("hello", 24)) {
//         AllTestsPassed = false;
//         cout << "24 is in the multimap under key \"hello\", removal failed" << endl;
//     } else {
//         cout << "pair no longer exists, test passes" << endl;
//     }
//     if (testMap2->searchPairs("hello", 54)) {
//         AllTestsPassed = false;
//         cout << "54 is in the multimap under key \"hello\", removal failed" << endl;
//     } else {
//         cout << "pair no longer exists, test passes" << endl;
//     }
//     if (testMap2->searchPairs("world", 3)) {
//         cout << "3 is in the multimap under key \"world\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "pair no longer exists, removal failed" << endl;
//     }
//     testMap2->set("hello", 54);
//     testMap2->set("hello", 24);
    
//     // // Test count:
//     int num4 = testMap2->count("hello");
//     int num5 = testMap2->count("world");
//     int num6 = testMap2->count("cat");
    
//     if(num4 == 2){
//         cout << "count works" << endl;
//     }
//     else {
//         AllTestsPassed = false;
//         cout << "count doesn't work" << endl;
//     }
//     if(num5 == 1){
//         cout << "count works" << endl;
//     }
//     else {
//         AllTestsPassed = false;
//         cout << "count doesn't work" << endl;
//     }
//     if(num6 == 0){
//         cout << "count works" << endl;
//     }
//     else {
//         AllTestsPassed = false;
//         cout << "count doesn't work" << endl;
//     }
    
//     // Test getNumElements: 
//     int* test3 = new int[2];
//     test3[0] = 54;
//     test3[1] = 24;
//     int* test4 = new int[1];
//     test4[0] = 3;
//     int* result3 = testMap2->getAll("hello");
//     int* result4 = testMap2->getAll("world");
    
//     for(int i = 0; i < 2; i++){
//         if(result3[i] != test3[i]){
//             AllTestsPassed = false;
//             cout << "It didn't work!" << endl;
//         }
//     }
    
//     for(int i = 0; i < 1; i++){
//         if(result4[i] != test4[i]){
//             AllTestsPassed = false;
//             cout << "It didn't work!" << endl;
//         }
//     }

//     delete testMap2;// deletes this object and frees the memory
    
// // //---------------------------------MutliMapHash---------------------------------

//     MultiMapHash* testMap3 = new MultiMapHash();
//     testMap3->set("hello", 54);
//     testMap3->set("world", 3);
//     testMap3->set("hello", 24);
    
//     // Test searchPairs:
//     if (testMap3->searchPairs("hello", 3)) {
//         AllTestsPassed = false;
//         cout << "3 is in the multimap under key \"hello\"" << endl;
//     } else {
//         cout << "3 is not in the multimap under the key \"hello\", test passes" << endl;
//     }
//     if (testMap3->searchPairs("world", 3)) {
//         cout << "3 is in the multimap under key \"world\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "3 is not in the multimap under the key \"world\"" << endl;
//     }
//     if (testMap3->searchPairs("hello", 24)) {
//         cout << "24 is in the multimap under key \"hello\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "24 is not in the multimap under the key \"hello\"" << endl;
//     }
//     if (testMap3->searchPairs("hello", 54)) {
//         cout << "54 is in the multimap under key \"hello\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "54 is not in the multimap under the key \"hello\"" << endl;
//     }
    
//     // Test removeAll:
//     testMap3->removeAll("hello");
//      if (testMap3->searchPairs("hello", 24)) {
//          AllTestsPassed = false;
//         cout << "24 is in the multimap under key \"hello\", removal failed" << endl;
//     } else {
//         cout << "pair no longer exists, test passes" << endl;
//     }
//     if (testMap3->searchPairs("hello", 54)) {
//         AllTestsPassed = false;
//         cout << "54 is in the multimap under key \"hello\", removal failed" << endl;
//     } else {
//         cout << "pair no longer exists, test passes" << endl;
//     }
//     if (testMap3->searchPairs("world", 3)) {
//         cout << "3 is in the multimap under key \"world\", test passes" << endl;
//     } else {
//         AllTestsPassed = false;
//         cout << "pair no longer exists, removal failed" << endl;
//     }
//     testMap3->set("hello", 54);
//     testMap3->set("hello", 24);
    
    
//     // Test count:
//     int num7 = testMap3->count("hello");
//     int num8 = testMap3->count("world");
//     int num9 = testMap3->count("cat");
    
//     if(num7 == 2){
//         cout << "count works" << endl;
//     }
//     else {
//         AllTestsPassed = false;
//         cout << "count doesn't work" << endl;
//     }
//     if(num8 == 1){
//         cout << "count works" << endl;
//     }
//     else {
//         AllTestsPassed = false;
//         cout << "count doesn't work" << endl;
//     }
//     if(num9 == 0){
//         cout << "count works" << endl;
//     }
//     else {
//         AllTestsPassed = false;
//         cout << "count doesn't work" << endl;
//     }
    
//     // Test getNumElements: 
//     int* test5 = new int[2];
//     test5[0] = 54;
//     test5[1] = 24;
//     int* test6 = new int[1];
//     test6[0] = 3;
//     int* result5 = testMap3->getAll("hello");
//     int* result6 = testMap3->getAll("world");
    
//     for(int i = 0; i < 2; i++){
//         if(result5[i] != test5[i]){
//             cout << "It didn't work!" << endl;
//             AllTestsPassed = false;
//         }
//     }
    
//     for(int i = 0; i < 1; i++){
//         if(result6[i] != test6[i]){
//             cout << "It didn't work!" << endl;
//             AllTestsPassed = false;
//         }
//     }
    
//---------------------------------MapArray---------------------------------








    // delete testMap3;// deletes this object and frees the memory
    if(AllTestsPassed){
       cout << "ALL TESTS PASSED!" << endl; 
    }
    else {
        cout << "NOT ALL TESTS PASSED!" << endl; 
    }
    return 0;
}