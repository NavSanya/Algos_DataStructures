#include <iostream>
#include <vector>
using namespace std;

class HashNode
{
        public:
                int key;
                int val;


                HashNode(int k = -1, int v = -1)
                {
                        key = k;
                        val = v;
                }
};


class openAddHash
{
        private:
        //Size of Hash Table
        int N;
        ///Capacity of Hash Table
        int cap;
        //Hash Key Val Node array
        vector<HashNode> arr;
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