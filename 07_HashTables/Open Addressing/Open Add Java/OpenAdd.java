import java.io.IOException;
import java.util.*;

class OpenAdd
{
        int N;
        int cap;
        ArrayList<Integer>[] table;

        public OpenAdd()
        {
                cap = 20;
                N= 0;
        }

        public OpenAdd(int x)
        {
                N= x;
                cap = 20;
                table = new ArrayList[cap];
                for(int i = 0; i<cap; ++i)
                {
                        table[i] = new ArrayList<>();
                }
        }

        public int hashFunc(int x)
        {
                return x % cap;
        }

        public void insertVal(int val)
        {
                int idx = hashFunc(val);
                if(table[idx].isEmpty())
                {
                        table[idx].add(val);
                        return;
                }

                int newIdx = (idx + 1) % cap;
                while(newIdx != idx && !table[newIdx].isEmpty())
                {
                        newIdx = (newIdx + 1) % cap;
                }

                while(newIdx == idx)
                {
                        System.out.println("Hash Full");
                        return;
                }

                table[newIdx].add(val);
                
        }

        public void deleteVal(int target)
        {
                int idx = hashFunc(target);
                for(int i = 0; i < table[idx].size(); ++i)
                {
                        if(table[idx].get(i) == target)
                        {
                                table[idx].remove(i);
                                System.out.println("Deleted" + target);
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
                System.out.println("Hash Table");
                for(int i = 0; i != cap; ++i)
                {
                        for(int j = 0; j < table[i].size(); ++j)
                        {
                                System.out.print(i + "---->");

                                System.out.print(table[i].get(j));
                        }
                        System.out.println();
                }
        }

        public static void main(String[] args) throws IOException 
        {
            int[] nums = {12,33,45,67,77,57,34,32,63,91,40};

            OpenAdd obj = new OpenAdd(10);

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