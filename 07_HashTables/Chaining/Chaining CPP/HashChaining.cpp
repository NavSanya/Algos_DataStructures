#include "HashChaining.hpp"

chainHash:: chainHash(int v=0)
{
        N = v;
        table = vector<vector<int>>(N);
}

int chainHash::hashFunc(int x)
{
        return x % N;
}

void chainHash::insertVal(int val)
{
        int idx = hashFunc(val);
        table[idx].push_back(val);
}

void chainHash::deleteVal(int target)
{
        int idx = hashFunc(target);
        for(int i = 0; i < table[idx].size(); i++)
        {
                if(table[idx][i] == target)
                {
                        table[idx].erase(table[idx].begin() + i);
                        return;
                }
                
        }
        cout<<"NotFound\n";

}

bool chainHash::ifPresent(int target)
{
        int idx = hashFunc(target);
        for(int i = 0; i < table[idx].size(); i++)
        {
                if(table[idx][i] == target)
                {
                        return true;
                }
                
        }
        cout<<"NotFound\n";
        return false;

}

void chainHash::printHash()
{
        for(int j = 0; j!=N; ++j)
        {
                cout<<j<<"|";
                for(int i = 0; i != table[j].size(); i++)
                {
                      cout<<"--->"<< table[j][i]; 
                }
                cout<<endl;
        }
}


int main()
{
        vector<int>nums = {12,33,45,67,77,57,34,32,63,91,40};

        chainHash obj(10);

        for( int i = 0; i < nums.size(); ++i)
        {
                obj.insertVal(nums.at(i));
        }

        cout<<"Hash Table"<<endl;
        obj.printHash();

        cout<<"Delete 77 from table\n";
        obj.deleteVal(77);
        obj.printHash();

        cout<<"check if 33 is present\n";
        if(obj.ifPresent(33))
        {
                cout<<"Found\n";
        }


        return 0;
}


