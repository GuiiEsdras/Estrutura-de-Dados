package main

import (
	"fmt"
	"time"
)

const laguraDaPagina = 80

func main() {
	printCal(1997)
}

func printCal(ano int) {

	essaData := time.Date(ano, 1, 1, 1, 1, 1, 1, time.UTC)

	var (
		arrDeDias             [12][7][6]int // mes, dia da semana, semana
		mes, ultimoMes        time.Month
		semanaDoMes, diaDoMes int
	)

	for essaData.Year() == ano {
		if mes = essaData.Month(); mes != ultimoMes {
			semanaDoMes = 0
			diaDoMes = 1
		}
		diaDaSemana := essaData.Weekday()
		if diaDaSemana == 0 && diaDoMes > 1 {
			semanaDoMes++
		}
		arrDeDias[int(mes)-1][diaDaSemana][semanaDoMes] = essaData.Day()
		ultimoMes = mes
		diaDoMes++
		essaData = essaData.Add(time.Hour * 24)
	}

	centro := fmt.Sprintf("%d", laguraDaPagina/2)
	fmt.Printf("%"+centro+"s\n\n", "[GUIESDRAS]")
	centro = fmt.Sprintf("%d", laguraDaPagina/2-2)
	fmt.Printf("%"+centro+"d\n\n", ano)

	meses := [12]string {
		" Janeiro ", "Fevereiro", "  Marco  ", "  Abril  ",
		"  Maio   ", "  Junho  ", "  Julho  ", "  Agosto ",
		" Setembro", " Outubro ", " Novembro", " Dezembro" }
	dias := [7]string {"Do", "Se", "Te", "Qa", "Qt", "Sx", "Sa" }

	for qtr := 0; qtr < 4; qtr++ {

		for mesEmQtr := 0; mesEmQtr < 3; mesEmQtr++ { // Nome dos meses
			fmt.Printf("      %s           ", meses[qtr*3+mesEmQtr])
		}
		fmt.Println()

		for mesEmQtr := 0; mesEmQtr < 3; mesEmQtr++ { // Nome dos dias
			for dia := 0; dia < 7; dia++ {
				fmt.Printf(" %s", dias[dia])
			}
			fmt.Printf("     ")
		}
		fmt.Println()

		for semanaDoMes = 0; semanaDoMes < 6; semanaDoMes++ {
			for mesEmQtr := 0; mesEmQtr < 3; mesEmQtr++ {
				for dia := 0; dia < 7; dia++ {
					if arrDeDias[qtr*3+mesEmQtr][dia][semanaDoMes] == 0 {
						fmt.Printf("   ")
					} else {
						fmt.Printf("%3d", arrDeDias[qtr*3+mesEmQtr][dia][semanaDoMes])
					}
				}
				fmt.Printf("     ")
			}
			fmt.Println()
		}
		fmt.Println()
	}
}