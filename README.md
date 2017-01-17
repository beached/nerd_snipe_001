# nerd_snipe_001
Remove the conditionals from

```
if( n % 2 == 0 ) {
    result = 8 + n/2;
} else {
    result = 7 - n/2;
}
```

Compiled with g++ -O3 -march=native benchmark.cpp and the results are consitantly around when run with ./a.out 1500
```
0: 838.988ms for 321000 calls 2.61367μs per item
1: 932.733ms for 370500 calls 2.5175μs per item
2: 853.587ms for 388500 calls 2.19714μs per item
3: 487.332ms for 412500 calls 1.18141μs per item
4: 817.144ms for 378000 calls 2.16176μs per item
5: 509.995ms for 379500 calls 1.34386μs per item
```
