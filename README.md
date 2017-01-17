# nerd_snipe_001
Remove the conditionals from

```
if( n % 2 == 0 ) {
    result = 8 + n/2;
} else {
    result = 7 - n/2;
}


Compiled with g++ -O3 -march=native benchmark.cpp and the results are consitantly around
0: 929.987ms
1: 895.725ms
2: 851.275ms
3: 435.446ms
4: 825.341ms
5: 505.456ms
```
