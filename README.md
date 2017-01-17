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
0: 970.898ms for 263 calls 3.69163ms per item
1: 887.943ms for 231 calls 3.84391ms per item
2: 800.963ms for 241 calls 3.3235ms per item
3: 492.842ms for 279 calls 1.76646ms per item
4: 804.387ms for 246 calls 3.26987ms per item
5: 474.916ms for 240 calls 1.97882ms per item
```
