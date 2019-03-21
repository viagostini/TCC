# MAC0499 - Trabalho de Conclusão de Curso



```c++
// produces size 2*N - 1 array representing Euler Tour of a rooted n-ary tree

void euler_tour (int root) {
    Euler.push_back(root);
    for (child : root.children) {
        euler_tour(child);
        Euler.push_back(child);
    } 	
}
```

