#include <iostream>
#include <vector>
using namespace std;

class chainHash
{
        private:
        //Size of Hash Table
        int N;
        //hash table (vector of pointers)
        vector<vector<int>> table;
        
        public:
        chainHash(int v);
        //insert value into hash table
        void insertVal(int val);
        //delete val from hash table
        void deleteVal(int target);
        // Search if present
        bool ifPresent(int target);
        //hash function to get value into keys
        int hashFunc(int x);
        //displays the hash table
        void printHash();

};