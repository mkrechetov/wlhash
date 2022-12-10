# wlhash
A simple C++ implementation of Weisfeiler-Lehman (WL) graph hash

Compile:
```
g++ wlhash.cpp -lssl -lcrypto -o wlhash
```

Usage:
```
./wlhash 0100110000101000100001010001000010100010100100000110000001100100000011001001000100010110000000101100
```

Where argument is a flattened adjacency matrix of a graph.
