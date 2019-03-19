# -*- coding: utf-8 -*-

N = int(input())
num = [int(x) for x in input().split()]

maior_cont = 0
cont = 0
numero_anterior = 0
for i, v in enumerate(num):

    if v == numero_anterior or i == 0:
        numero_anterior = v
        cont += 1

        if cont >= maior_cont:
            maior_cont = cont

    else:
        numero_anterior = v
        cont = 1

print(maior_cont)
