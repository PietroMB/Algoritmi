def merge(l, r):
    i = 0
    j = 0
    b = []
    while i < len(l) and j < len(r):
        if l[i] < r[j]:
            b.append(l[i])
            i += 1
        else:
            b.append(r[j])
            j += 1

    if j < len(r):
        return b + r[j:]
    else:
        return b + l[i:]


def mergesort(a):
    if len(a) <= 1:
        return a

    l = mergesort(a[:int(len(a) / 2)])
    r = mergesort(a[int(len(a) / 2):])

    return merge(l, r)


a = [3, 1, 2, 4, 8, 22, 88, 5, 7]
print(a)
print(mergesort(a))
