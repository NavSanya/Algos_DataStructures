#include "OpenAdd.hpp"

openAddHash::openAddHash(int v=0)
{
        cap = 20;
        N = v;  
        table.resize(cap);
        arr.resize(cap);      
}

void openAddHash::printHash()
{

        //printing vector of vectors
        cout<<"\nVector of Vectors\n";
        for(int i = 0; i < table.size(); ++i)
        {
                for(int j = 0; j < table.at(i).size(); ++j)
                {
                        if(j == table.at(i).size()-1)
                                cout<<table[i][j];
                        else
                                cout<<table[i][j]<<"---->";
                }
                cout<<endl;
        }

        //printing array of nodes
        cout<<"\nArray of Nodes\n";
        for(int i = 0; i<N; ++i)
        {
                cout<<arr[i].key<<"---->"<<arr[i].val<<endl;
        }

}

int openAddHash::hashFunc(int x)
{
        return x % cap;
}

void openAddHash::insertVal(int value)
{
        int key = hashFunc(value);

        if(table[key].empty())
        {
                table[key].push_back(value);
                return;
        }

        int newIdx = (key + 1) % cap;
        while(newIdx != key && !table[newIdx].empty())
        {
                newIdx = (newIdx + 1) % cap;
        }

        if(newIdx == key)
        {
                cout<<"Hash Full\n";
                return;
        }

        table[newIdx].push_back(value);
}



int main()
{
        vector<int>nums = {12,33,45,67,77,57,34,32,63,91,40};

        openAddHash obj(10);

        for( int i = 0; i < nums.size(); ++i)
        {
                obj.insertVal(nums.at(i));
        }

        cout<<"Hash Table"<<endl;
        obj.printHash();

        // cout<<"Delete 77 from table\n";
        // obj.deleteVal(77);
        // obj.printHash();

        // cout<<"check if 33 is present\n";
        // if(obj.ifPresent(33))
        // {
        //         cout<<"Found\n";
        // }


        return 0;
}