#include "filaenccab.h"
#include <stdio.h>


int main (void) {
	// a "cabeça" da fila...
	TFilaEncCab fila;

    // coloca a fila num estado válido (e consistente)
    criarFila( &fila );

    if( filaVazia( fila ) ) printf( "Esta vazia!" );

    enfileirar( &fila, 10 );
    enfileirar( &fila, 20 );
    enfileirar( &fila, 30 );

    int frente; elementoFrente( fila, &frente );
    printf( "\nElemento frente: %d", frente  );

    imprimir( fila );
    printf( "\nTamanho da fila: %d", tamanhoFila( fila )  );

    desenfileirar( &fila, &frente ); //10
    printf( "\n\nElemento desenfileirado: %d", frente );

    imprimir( fila );
    printf( "\nTamanho da fila: %d", tamanhoFila( fila )  );

   	desenfileirar( &fila, &frente ); //20
    printf( "\n\nElemento desenfileirado: %d", frente );
   	desenfileirar( &fila, &frente ); //30
    printf( "\n\nElemento desenfileirado: %d", frente );

    // e se quem utiliza a biblioteca comete equívocos?
    printf( "\n%s", desenfileirar( &fila, &frente ) ? "Sucesso" : "Erro na retirada!" );

    imprimir( fila );
    printf( "\nTamanho da fila: %d", tamanhoFila( fila )  );

	return 0;
}
