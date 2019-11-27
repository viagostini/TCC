funcao consulta(nó, prof)
    x := nó
    se prof > profundidade(x) ou prof < 0
        devolva -1 // Não há resposta.
    fim
    enquanto profundidade(x) != prof
        x := pai(x)
    fim
    devolva x
fim