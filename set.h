#include <iostream>
#include <string>

using namespace std;

class SetArray{
    private:
    
    public:
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();

};

class SetList{
    private:
    
    public:
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();

};

class SetHash{
    private:
    
    public:
        void insert(string key);
        bool is_in(string key);
        void remove(string key);
        bool is_empty();

};