rotina preprocessa()
    para u de 0 ate n-1 faca
        v := u
        tabela[u][profundidade(u)] = u
        para w de profundidade(u)-1 ate 0 faca
            tabela[u][w] = pai(v)
            v = pai(v)
        fim
    fim
fim