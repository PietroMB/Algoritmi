def quicksort(list, start, end):
    if start >= end: return
    part = partition(list, start, end)
    quicksort(list, start, part - 1)
    quicksort(list, part + 1, end)


def partition(list, start, end):
    pivot = list[end]
    i = start
    for j in range(start, end):
        if list[j] <= pivot:
            list[j], list[i] = list[i], list[j]
            i += 1
    list[i], list[end] = list[end], list[i]
    return i


list = [7, 2, 1, 6, 8, 44, 22, 5, 3, 33, 86, 4]
print(list)
quicksort(list, 0, len(list) - 1)
print(list)
