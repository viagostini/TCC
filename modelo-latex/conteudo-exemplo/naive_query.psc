funcao consulta(nó, prof)
    x := nó
    enquanto profundidade(x) != prof
        x := pai(x)
    fim
    devolva x
fim