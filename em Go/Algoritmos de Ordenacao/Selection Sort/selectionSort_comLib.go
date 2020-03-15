package main

import (
	"fmt"
	"sort"
)

var arr2 = []int { 170, 45, 75, -90, -802, 24, 2, 66 }

func main() {
	fmt.Println("Antes de Ordenar:", arr2)
	selectionSort_comLib(sort.IntSlice(arr2))
	fmt.Println("Depois de Ordenar: ", arr2)
}

func selectionSort_comLib(vetor sort.Interface) {

	ultimo := vetor.Len() - 1

	for i := 0; i < ultimo; i++ {

		iMin := i

		for j := i + 1; j < vetor.Len(); j++ {
			if vetor.Less(j, iMin) { // Usa a função Less da biblioteca "sort" para verificar o menor elemento da pos
				iMin = j
			}
		}

		vetor.Swap(i, iMin) // Usa a função Swap da biblioteca "sort" para trocar os valores (swap) de posição
	}
}