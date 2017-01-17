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
a-> 'Darrell Wright': 641.163ms for 268500 calls 2.38794μs per item
b-> 'Darrell Wright': 649.209ms for 252000 calls 2.57623μs per item
c-> 'Darrell Wright': 603.261ms for 276000 calls 2.18573μs per item
d-> 'Arnold Kim': 276.678ms for 238500 calls 1.16008μs per item
e-> 'Original': 478.79ms for 222000 calls 2.15671μs per item
f-> 'Shaun Winters - A': 341.268ms for 262500 calls 1.30007μs per item
g-> 'Matt Bryan - A': 429.867ms for 235500 calls 1.82534μs per item
h-> 'Matt Bryan - B': 456.949ms for 247500 calls 1.84626μs per item
i-> 'Shaun Winters - B': 2857.5ms for 247500 calls 11.5455μs per item
```
