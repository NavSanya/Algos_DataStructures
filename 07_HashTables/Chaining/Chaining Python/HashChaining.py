class HashChaining:
        def __init__(self, x)->None:
                self.N = x
                self.table = [[] for _ in range(self.N)]
        
        def hashFunc(self, x):
                return x % self.N

        def insertVal(self, val):
                idx = self.hashFunc(val)
                self.table[idx].append(val)
        
        def deleteVal(self, target):
                idx = self.hashFunc(target)
                if target not in self.table[idx]:
                        print("Not Found")
                        return
                self.table[idx].remove(target)
        
        def ifPresent(self,target):
                idx = self.hashFunc(target)
                if target not in self.table[idx]:
                        print("Not Found")
                        return False
                return True

        def printHash(self):
                for j in range(self.N):
                        s=(f"{j}\t|")
                        for i in range(len(self.table[j])):
                                s+=(f"---->{self.table[j][i]}")
                        print(s)
                        
if __name__ == '__main__':
        nums = [12,33,45,67,77,57,34,32,63,91,40]
        
        obj = HashChaining(10)
        
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
        