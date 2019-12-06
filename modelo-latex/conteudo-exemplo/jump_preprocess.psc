rotina preprocessa(árvore)
    M := $\left\lceil \log_2 d \right\rceil$ // d é a profundidade da árvore
    ponteiros := matriz N x (M+1)
    para i de 0 ate N-1 faca
        ponteiros[i][0] := pai(i)
    fim
    para j de 1 ate M faca
        para i de 0 ate N-1 faca
            x := ponteiros[i][j-1]
            ponteiros[i][j] := ponteiros[x][j-1]
        fim
    fim
fim