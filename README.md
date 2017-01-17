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
a-> 'Darrell Wright': 1199.53ms for 244500 calls 4.90606μs per item
b-> 'Darrell Wright': 1332.5ms for 264000 calls 5.04736μs per item
c-> 'Darrell Wright': 1051.46ms for 243000 calls 4.327μs per item
d-> 'Arnold Kim': 663.334ms for 276000 calls 2.40338μs per item
e-> 'Original': 959.478ms for 222000 calls 4.32197μs per item
f-> 'Shaun Winters - A': 678.823ms for 255000 calls 2.66205μs per item
g-> 'Matt Bryan - A': 884.76ms for 244500 calls 3.61865μs per item
h-> 'Matt Bryan - B': 864.59ms for 238500 calls 3.62512μs per item
i-> 'Shaun Winters - B': 6325.32ms for 262500 calls 24.0964μs per item
```
See [Arnold's Explanation](./arnolds_explanation.jpeg) for a description of his approach

Matt Bryan's approach was:
```
EVEN
8 + n / 2; 
= (16 + n) / 2
= (16 + Zn) / 2
= (15 + Z + Zn) / 2

ODD
7 - n / 2;
=(14 - n) / 2
=(14+Zn) / 2 
=(15 + Z + Zn) / 2
```
Since we now have an equation that works for both odd and even numbers, all we need is a solution for Z
```
Z = ((n%2)* -2) + 1 should work

So

int Z = ((n%2)*(-2)) + 1 
return (15 + Z + Z * n) / 2
```
I added a + (n%2) to Matt's to fix up odd arguments 
