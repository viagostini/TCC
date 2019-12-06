funcao consulta(nó, prof)
    x := nó
    enquanto profundidade(x) != prof faca
        d = profundidade(x) - prof
        pulo := $\left\lfloor \log_2 d \right\rfloor$ // seleciona o bit mais significante 
        x := ponteiros[x][pulo]
    fim
    devolva x
fim