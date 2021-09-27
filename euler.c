#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a < b) ? a : b)

long multiples_of_3_or_5(long n) {
    long sum = 0, i;
    for (i = 3; i < n; i += 3) {
        sum += i;
    }
    for (i = 5; i < n; i += 5) {
        if (i % 3 != 0) sum += i;
    }
    return sum;
}

long even_fibonacci_numbers(long prev, long curr, long sum, long max) {
    if (curr > max) return sum;
    return even_fibonacci_numbers(curr, prev+curr, sum+(curr % 2 ? 0 : curr), max);
}

long largest_prime_factor(long n) {
    long mx = 0, x;
    while (n % 2 == 0) {
        (mx, (long)2);
        n /= 2;
    }
    for (x = 3; x*x <= n; x += 2) {
        while (n % x == 0) {
            mx = max(mx, x);
            n /= x;
        }
    }
    if (n > 1) mx = n;
    return mx;
}

long check_palindrome(long prod) {
    char str[21]; sprintf(str, "%ld", prod);
    long end = strlen(str), br = 1, r;
    for (r = 0; r < end/2; r++) {
        br = br && (str[r] == str[end-r-1]);
    }
    return br;
}

long largest_palindrome_product(long n) {
    long mx = 0, i, q;
    for (i = 0; i < n; i++) {
        for (q = i; q < n; q++) {
            long prod = i*q;
            if (check_palindrome(prod)) mx = max(mx, prod);
        }
    }
    return mx;
}

long gcd(long a, long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

long smallest_multiple(long n) {
    long ans = 1, i;
    for (i = 1; i <= n; i++) {
        ans = (ans * i) / gcd(ans, i);
    }
    return ans;
}

long sum_square_difference(long n) {
    long sm1 = n*(n+1)*(2*n+1)/6;
    long sm2 = (n*(n+1)/2) * (n*(n+1)/2);
    return abs(sm1-sm2);
}

long sieve[10000000];
long _10001st_prime(long n) {
    long i, q;
    for (i = 0; i < 1e7; i++) {
        sieve[i] = 1;
    }
    sieve[0] = sieve[1] = 0;
    for (i = 2; i < 1e7; i++) {
        if (sieve[i]) {
            for (q = i+i; q < 1e7; q += i) {
                sieve[q] = 0;
            }
        }
    }
    long c = 0;
    for (i = 0; i < 1e7; i++) {
        if (sieve[i]) c++;
        if (c == n) return i;
    }
    return 0;
}
