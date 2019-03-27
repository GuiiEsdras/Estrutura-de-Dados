/************************************************************************************************
 * Instituto Federal de Educação Ciência e Tecnologia da Paraíba
 * Campus Campina Grande
 * Curso Superior de Bacharel em Engenharia de Computação
 * Componente Curricular: Laboratório de Estrutura de Dados e Algoritmos - 2º Período
 * Professor: Ruan Delgado
 * 
 * Copyright - Guilherme Esdras
 ************************************************************************************************/

#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

TPack* createDataPacket( int id, int origem, int destino, int bytes) {
  TPack *newdataPack = (TPack*) malloc( sizeof(TPack) );

  newdataPack->id = id;
  newdataPack->tipo = DATA;
  newdataPack->origem = origem;
  newdataPack->destino = destino;

  int *pack = (int*) malloc(bytes*sizeof(int));
  newdataPack->carga = pack;
  newdataPack->tam = bytes;

  return newdataPack;
}

TPack* createACKPacket( int id, int origem, int destino) {
  TPack* newACKPack = (TPack*) malloc(sizeof(TPack));

  newACKPack->id = id;
  newACKPack->tipo = ACK;
  newACKPack->origem = origem;
  newACKPack->destino = destino;
  newACKPack->carga = NULL;
  newACKPack->tam = 0;

  return newACKPack;
}

void writeData( TPack *pacote, int bytes[], int tam) {
  for( register int i=0; i < tam; i++ ) {
    pacote->carga[i] = bytes[i];
  }
}

TPack* clonePacket( TPack *pacote ) {
	TPack *clone = (TPack*) malloc (sizeof(TPack));

	clone->id = pacote->id;
	clone->tipo = pacote->tipo;
	clone->origem = pacote->origem;
	clone->destino = pacote->destino;
	clone->carga = pacote->carga;
	clone->tam = 0;

	if( pacote->tipo == 0) {
		clone->tam = pacote->tam;

		int *aux = (int*) malloc ( clone->tam * (sizeof(int)) );
    clone->carga = aux;

		for(register int i = 0; i < pacote->tam; i++) {
		  clone->carga[i] = pacote->carga[i];
		}
	}

	return clone;
}

void printPacketInformation( TPack *pacote ) {

  if( pacote->tipo == 0 ){
    printf("Packet type: DATA\n");
    printf("ID: %d\n", pacote->id);
    printf("Source Address: %d\n", pacote->origem);
    printf("Destination Address: %d\n", pacote->destino);
    printf("Payload Size: %d\n", pacote->tam);
    printf("Payload: ");

    register int i = 0;
    int tamanho_real = 0;
    for( i = 0; i < pacote->tam; i++){
      tamanho_real++;
    }

    int diferenca = pacote->tam - tamanho_real;
    for( i = 0; i < pacote->tam; i++){
      printf("%d ", pacote->carga[i]);
    }

    if (diferenca > 0){
      for (i = 0; i < diferenca; i++){
      printf("0 ");
      }
    }
    printf("\n");

  } else{
      printf("Packet type: ACK\n");
      printf("ID: %d\n", pacote->id);
      printf("Source Address: %d\n", pacote->origem);
      printf("Destination Address: %d\n", pacote->destino);
      }
}

void deletePacket (TPack * pacote){
  free(pacote);
}
