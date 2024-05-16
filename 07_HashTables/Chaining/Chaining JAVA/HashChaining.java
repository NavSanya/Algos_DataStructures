import java.io.IOException;
import java.util.*;

class HashChaining
{
        int N;
        ArrayList<Integer>[] table;

        public HashChaining()
        {
                N= 0;
        }

        public HashChaining(int x)
        {
                N= x;
                table = new ArrayList[N];
                for(int i = 0; i<N; ++i)
                {
                        table[i] = new ArrayList<>();
                }
        }

        public int hashFunc(int x)
        {
                return x % N;
        }

        public void insertVal(int val)
        {
                int idx = hashFunc(val);
                table[idx].add(val);
        }

        public void deleteVal(int target)
        {
                int idx = hashFunc(target);
                for(int i = 0; i < table[idx].size(); ++i)
                {
                        if(table[idx].get(i) == target)
                        {
                                table[idx].remove(Integer.valueOf(target));
                                return;
                        }
                }
                System.out.println("Not Found");
        }

        public boolean ifPresent(int target)
        {
                int idx = hashFunc(target);
                for(int i = 0; i < table[idx].size(); ++i)
                {
                        if(table[idx].get(i) == target)
                        {
                                return true;
                        }
                }
                System.out.println("Not Found");
                return false;
        }

        public void printHash()
        {
                for(int j = 0; j!=N; ++j)
                {
                        System.out.print(j + "\t|");
                        for(int i = 0; i != table[j].size(); i++)
                        {
                                System.out.print("---->" + table[j].get(i)); 
                        }
                        System.out.println();
                }
        }

        public static void main(String[] args) throws IOException 
        {
            int[] nums = {12,33,45,67,77,57,34,32,63,91,40};

            HashChaining obj = new HashChaining(10);

            for( int i = 0; i < nums.length; ++i)
            {
                obj.insertVal(nums[i]);
            }

            System.out.println("Hash Table");
            obj.printHash();

            System.out.println("Delete 77 from table");
            obj.deleteVal(77);
            obj.printHash();

            System.out.println("CHeck if 33 is present");
            if(obj.ifPresent(33))
            {
                System.out.println("Found");
            }
        }


}