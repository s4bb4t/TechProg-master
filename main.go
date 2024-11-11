package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(isHappy(19))
}
func isHappy(n int) bool {
	if n == 1 {
		return true
	}
	i := 0

	for n%10 != 0 && n%10 != 1 && i != 10 {
		i++

		nStr := strconv.Itoa(n)
		n = 0

		for _, r := range nStr {
			digit, _ := strconv.Atoi(string(r))
			n += digit * digit
		}
	}

	if i != 10 {
		return false
	}
	return true
}
