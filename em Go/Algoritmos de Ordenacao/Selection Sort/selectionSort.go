package main

import "fmt"

var arr = []int{ 220, 89, -102, 53, 1102, -34, 32, 76 } // Array desordenado

func main() {
	fmt.Println("Antes de Ordenar:", arr)
	selectionSort(arr)
	fmt.Println("Depois de Ordenar: ", arr)
}

func selectionSort(vetor []int) {

	ultimo := len(vetor) - 1 // Variavel que guarda o ultimo elemento do array

	// Loop que percorrerá o array/vetor
	for i := 0; i < ultimo; i++ {

		aMin := vetor[i] // Armazena o valor atual para verificar se os próximos são menores que ele
		iMin := i // Armazena arr2 posicao do elemento atual

		// Loop que percorrerá da proxima posicao à partir da atual até arr2 última posição do array
		for j := i + 1; j < len(vetor); j++ {
			if vetor[j] < aMin { // Se este elemento for menor que o que está sendo verificado
				aMin = vetor[j] // Atualiza arr2 variável min para substituir o valor verificado por ele
				iMin = j // Captura arr2 posição deste elemento para substituí-lo
			}
		}

		vetor[i], vetor[iMin] = aMin, vetor[i] // Troca os valores de posição
	}
}