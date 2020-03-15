# -*- coding: utf-8 -*-

E1 = input().lower()
E2 = input().lower()
E3 = input().lower()

if E1 == "vertebrado":
    if E2 == "ave":
        if E3 == "carnivoro":
            print("aguia")
        elif E3 == "onivoro":
            print("pomba")
    elif E2 == "mamifero":
        if E3 == "onivoro":
            print("homem")
        elif E3 == "herbivoro":
            print("vaca")
elif E1 == "invertebrado":
    if E2 == "inseto":
        if E3 == "hematofago":
            print("pulga")
        elif E3 == "herbivoro":
            print("lagarta")
    elif E2 == "anelideo":
        if E3 == "hematofago":
            print("sanguessuga")
        elif E3 == "onivoro":
            print("minhoca")
