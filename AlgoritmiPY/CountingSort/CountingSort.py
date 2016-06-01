def CountingSort(list, k):
    CList = [0] * k #create a list for storing cardinality of a number
    SList = [0] * len(list) #Sorted list
    for i in range(0, len(list)):
        CList[list[i]] += 1 #Count cardinality of list
    j = 0
    for i in range(0,k):
        while CList[i] > 0:
            SList[j] = i #create a sorted list
            j += 1
            CList[i] -= 1
    return SList

list = [1, 8, 8, 5, 6, 4, 3, 6, 7, 8, 33, 44, 66, 1]
print(list)
SortedList = CountingSort(list, max(list)+1)
print(SortedList)
