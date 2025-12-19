package main

import (
	"fmt"
	"math"
)

func print_float(msg string, x float64) {
	fmt.Printf("%s%v [%x]\n", msg, x, x)
}

func main() {
	print_float("sin(4)=", math.Sin(4))
	print_float("exp(-5.01)=", math.Exp(-5.01))
	print_float("pow(4.7, -2.7)=", math.Pow(4.7, -2.7))
	print_float("pow(0.6, -0.1)=", math.Pow(0.6, -0.1))
	print_float("pow(17.21, 2.0)=", math.Pow(17.21, 2.0))
	print_float("pow(95.97, 2.0)=", math.Pow(95.97, 2.0))
	print_float("pow(75.7, 0.5)=", math.Pow(75.7, 0.5))
}
