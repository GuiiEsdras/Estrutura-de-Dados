/************************************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba
 * Campus Campina Grande
 * Curso Superior de Bacharel em Engenharia de Computação
 * Componente Curricular: Laboratório de Estrutura de Dados e Algoritmos - 2º Período
 * Professor: Ruan Delgado
 * 
 * Copyright - Guilherme Esdras
 ************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifyListInt(char s[]) {
    int i, n=0, c=0;

    for( i = 0; i < strlen(s); i++ ) {

        if( (s[i] != ' ') && !(s[i] >= '0' && s[i] <= '9') ) return 0;

        else if( s[i] >= '0' && s[i] <= '9' ) {
            if(!n) {
                n = 1;
            }
        }

        else if( s[i] == ' ' ) {
            if(n) {
                c++;
                n = 0;
            }
        }
    }

    if(n) c++;

    return c;
}

int* splitInt(char s[], int *size) {
    *size = verifyListInt(s);
    if(*size == 0) return NULL;
    int *v = (int*) malloc(*size * sizeof(int));
    char aux[15] = {0};
    int i, j = 0, c = 0;

    for(i = 0; s[i] != '\0'; i++) {

        if( s[i] >= '0' && s[i] <= '9' ) {
            aux[j] = s[i];
            j++;

            if( s[i+1] == '\0' ) {
                aux[j] = '\0';
                v[c] = atoi(aux);
            }
        }

        else if( (s[i] == ' ') && (j > 0) ) {
            aux[j] = '\0';
            j = 0;
            v[c] = atoi(aux);
            c++;
        }
    }

    return v;
}

int main()
{
    char ent[100];
    scanf("%[^\n]s", ent);
    int size;
    int *ent_int = splitInt(ent, &size);
    if( ent_int == NULL ) {
        printf("String inválida");
        return 1;
    }
    printf("Size: %d\n", size);
    int i;
    for( i = 0; i < size; i++ ) {
        printf("%d ", ent_int[i]);
    }
    return 0;
}
