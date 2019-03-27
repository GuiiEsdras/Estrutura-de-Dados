/************************************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba
 * Campus Campina Grande
 * Curso Superior de Bacharel em Engenharia de Computação
 * Componente Curricular: Laboratório de Estrutura de Dados e Algoritmos - 2º Período
 * Professor: Ruan Delgado
 * 
 * Copyright - Guilherme Esdras
 ************************************************************************************************/

#define DATA 0
#define ACK 1

typedef struct package {
    int id;
    int tipo;
    int origem;
    int destino;
    int *carga;
    int tam;
} TPack;

TPack* createDataPacket( int id, int origem, int destino, int bytes);

TPack* createACKPacket( int id, int origem, int destino);

void writeData( TPack *pacote, int bytes[], int tam);

TPack* clonePacket( TPack *pacote );

void printPacketInformation( TPack *pacote );

void deletePacket( TPack *pacote );