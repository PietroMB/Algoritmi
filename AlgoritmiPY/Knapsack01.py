#v = lista valori
#w = lista pesi
#W carico massimo
def zeroOneKnapsack(v,w,W):
    n=len(v)
    c = [[0 for x in range(W+1)] for y in range(n)]
    for i in range(n):
        for j in range(W+1):

            if(w[i] > j):
                c[i][j] = c[i-1][j]

            else:
                c[i][j]=max(c[i-1][j],v[i]+c[i-1][j-w[i]])#meglio riga-1 stessa colonna  o il valore attuale + riga-1 colonna - peso attuale ?
                #ha senso che sia la riga sopra perchè l'attuale lo posso prendere una sola volta
                #print("meglio c["+str(i-1)+"]["+str(j)+"]="+str(c[i-1][j])+" o c["+str(i-1)+"]["+str(j-w[i])+"] = "+ str(c[i-1][j-w[i]])+"?")
    for i in range(n):
        print(str(c[i][0:]))

#v=[6,8,25,10,16]
#w=[1,2,5,3,4]
#W=10
v=[1,2,3,4,5,6,7,8,10,12,22]
w=[1,1,1,1,1,1,1,1,1,1,1]
W=3
zeroOneKnapsack(v,w,W)
