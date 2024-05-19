#include <iostream>
#include <vector>
using namespace std;


class openAddHash
{
        private:
        //Size of Hash Table
        int N;
        ///Capacity of Hash Table
        int cap;
        //hash table
        vector<vector<int>>table;
        
        public:
        openAddHash(int v);
        //insert value into hash table
        void insertVal(int value);
        //delete val from hash table
        void deleteVal(int target);
        // Search if present
        bool ifPresent(int target);
        //hash function to get value into keys
        int hashFunc(int x);
        //displays the hash table
        void printHash();

};