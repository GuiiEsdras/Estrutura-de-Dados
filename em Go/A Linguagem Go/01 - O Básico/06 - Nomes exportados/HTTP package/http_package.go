package main

import (
	"fmt"
	"net/http"
)

func main() {
	fmt.Printf("HTTP status OK uses code: %d", http.StatusOK)
}
