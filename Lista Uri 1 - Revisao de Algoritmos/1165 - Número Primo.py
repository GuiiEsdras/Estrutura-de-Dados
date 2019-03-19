# -*- coding: utf-8 -*-

N = int(input())
for x in range(0, N):
    num = int(input())
    acumulador = 0
    for y in range(1, num+1):
        if num % y == 0:
            acumulador += 1
    if acumulador == 2:
        print("{} eh primo".format(num))
    else:
        print("{} nao eh primo".format(num))
