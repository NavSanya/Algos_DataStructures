import random
 
"""
 creating an array of size n
 initializing the arry with random values
"""
def initializeArrayWithRandomNumbers(n):
    myList = []
    for i in range(n):
        myList.append(random.randint(0,n))
    return myList
	
def partitionMiddle(myList, left, right):
	x = myList[left]
	y = myList[(left + right)//2]
	z = myList[right]
	
	#select pivot point
	if x < y:
		if y < z:
			pivot = y
		elif x < z:
			pivot = z
		else:
			pivot = x
	else:
		if y > z:
			pivot = y
		elif x > z:
			pivot = z
		else:
			pivot = x
	i = left - 1
	j = right + 1
	while i < j:
		j -= 1
		i += 1
		while myList[i] < pivot: #inner while i
			if i == right:
				break
			i += 1

		while myList[j] > pivot: #inner while j
			if j == left:
				break
			j -= 1
		if i >= j:
			break
		myList[i], myList[j] = myList[j], myList[i]
	return j	
 
def quickSort(myList, left, right):
	if left < right:
		mid = partitionMiddle(myList, left, right)
		myList = quickSort(myList, left, mid)
		myList = quickSort(myList, (mid+1), right)
	return myList

size = 10
print("Unsorted Array")
myList = initializeArrayWithRandomNumbers(size)
print(myList)

print("**********Quick Sort**********")
myList = quickSort(myList, 0, (size-1))
print(myList)