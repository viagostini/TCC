funcao cria_arvore(N, nó)
    raíz := nó
    tamanho := N
    pai := vetor de tamanho N
    profundidade := vetor de tamanho N
    travessia(raíz, 0)
fim

rotina travessia(nó, prof)
    profundidade[nó] = prof
    para filho em nó.filhos() faca
        pai[filho] = nó
        travessia(filho, prof+1)
    fim
fim