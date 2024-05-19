class OpenAdd:
        def __init__(self, x)->None:
                self.N = x
                self.cap = 20
                self.table = [[] for _ in range(self.cap)]
        
        def hashFunc(self, x):
                return x % self.cap

        def insertVal(self, val):
                idx = self.hashFunc(val)
                
                if not self.table[idx]:
                        self.table[idx].append(val)
                        return

                newIdx = (idx + 1) % self.cap
                while newIdx != idx and self.table[newIdx]:
                        newIdx = (newIdx + 1) % self.cap
                
                if newIdx == idx:
                        print("Hash Full")
                        return

                self.table[newIdx].append(val)
                
        
        def deleteVal(self, target):
                idx = self.hashFunc(target)

                for i in range(len(self.table[idx])):
                        if self.table[idx][i] == target:
                                del self.table[idx][i]
                                print(f"Deleted {target}")
                                return
                print("Not Found")
        
        def ifPresent(self,target):
                idx = self.hashFunc(target)
                for val in self.table[idx]:
                        if val == target:
                                return True
                        return False

        def printHash(self):
                print("Hash Table")
                for j in range(self.cap):
                        if self.table[j]:
                                print(f"{j} ----> {'---->'.join(map(str, self.table[j]))}")
                        else:
                                print()
                        # print()
                        
if __name__ == '__main__':
        nums = [12,33,45,67,77,57,34,32,63,91,40]
        
        obj = OpenAdd(10)
        
        for n in nums:
                obj.insertVal(n)
        
        print("Hash Table")
        obj.printHash()
        
        print("\nDelete 77 from table")
        obj.deleteVal(77)
        obj.printHash()
        
        print("\nCheck if 33 is present")
        if(obj.ifPresent):
                print("\nFound")
        