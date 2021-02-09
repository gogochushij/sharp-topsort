# sharp-topsort
Counts the number of topological sorts of a given graph.

# How to use
Create the file `input.txt` and list *all the edges* in the file like this:
```
a b
b c
a d
d c
```
Compile `topsort.cpp` with no specific options and run it. It should produce an output like the following:
```
Vertices: a b c d
Edges:
a < b
b < c
a < d
d < c
|a|b|d|c| |a|d|b|c|
Total permutations: 2 out of 24
1/12
```
