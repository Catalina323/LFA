f = open("gramatica.in", "r")
d = {}
for linie in f:
    l = []
    L = linie.split()
    for i in range(1, len(L)):
        l.append(L[i])
    d[L[0]] = l
c = open("cuvinte.in", "r")
aux = []
aux2 = []
for cuvant in c:
    aux.clear()
    aux2.clear()
    k = False
    for x in d["S"]:
        if (x[0] == cuvant[0]) and (x[1] not in aux):
            k = True
            aux.append(x[1])
    if k != True:
        print("Cuvantul NU E acceptat din prima")
    else:
        # de aici incepe verificarea:
        for i in range(1, len(cuvant)-1):     # notita: cuvant[i] e litera actuala din cuvant
            k = False
            aux2.clear()
            for y in aux:                   # aux e vectorul cu cheile gasite
                for x in d[y]:
                    if cuvant[i] == x[0]:
                        aux2.append(x[1])
                        k = True
            if k == True:
                aux.clear()
                for a in aux2:
                    aux.append(a)
            if k == False:
                print("Cuvantul NU E acceptat dupa cautare")
                break
        if k == True:
            f = []
            for x in aux:
                f.extend(d[x])
            if "lambda" in f:
                print("Cuvantul E acceptat")
            else:
                print("Cuvantul NU E acceptat la sfarsit")
