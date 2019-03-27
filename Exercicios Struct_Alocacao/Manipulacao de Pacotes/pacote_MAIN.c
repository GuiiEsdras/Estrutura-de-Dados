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

int main() {
    printf("\n----------PACOTES----------\n\n");

    // Data Packet //
    int id_Data = 5, origem_Data = 50, destino_Data = 80, tam_Data = 10;
    int carga[10] = {33, 11, 12, 41, 43, 55, 67, 34, 4, 1};

    TPack* pacote_Data = createDataPacket(id_Data, origem_Data, destino_Data, tam_Data);
    writeData(pacote_Data, carga, tam_Data);
    printPacketInformation(pacote_Data);


    /* ------ */ printf("\n---\n\n"); /* ------ */


    // ACK Packet //
    int id_ACK = 1, origem_ACK = 10, destino_ACK = 20;

    TPack* pacote_ACK = createACKPacket(id_ACK, origem_ACK, destino_ACK);
    printPacketInformation(pacote_ACK);

    // -------------------------------------------------------------------------- //

    printf("\n\n----------CLONES----------\n");
    
    printf("\n| Clone do Pacote Data |\n");
    TPack* clone_DATA = clonePacket(pacote_Data);
    printPacketInformation(clone_DATA);

    /* ------ */ printf("\n---\n\n"); /* ------ */

    printf("\n| Clone do Pacote ACK |\n");
    TPack* clone_ACK = clonePacket(pacote_ACK);
    printPacketInformation(clone_ACK);

    // Liberando Memória Alocada //
    deletePacket(pacote_Data);
    deletePacket(pacote_ACK);
    deletePacket(clone_DATA);
    deletePacket(clone_ACK);

    return 0;
}