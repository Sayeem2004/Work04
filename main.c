#include <stdio.h>
#include "euler.h"

int main() {
    printf("Problem 1: %ld\n", multiples_of_3_or_5(1000));
    printf("Problem 2: %ld\n", even_fibonacci_numbers(0, 1, 0, 4e6));
    printf("Problem 3: %ld\n", largest_prime_factor(600851475143));
    printf("Problem 4: %ld\n", largest_palindrome_product(1000));
    printf("Problem 5: %ld\n", smallest_multiple(20));
    printf("Problem 6: %ld\n", sum_square_difference(100));
    printf("Problem 7: %ld\n", _10001st_prime(10001));
}
