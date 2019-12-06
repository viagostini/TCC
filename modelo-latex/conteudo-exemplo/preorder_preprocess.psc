global id = 0

rotina preprocessa(árvore)
    dfs(árvore.raiz, prof = 0)
fim

rotina dfs(nó, prof)
    preordem[nó] = id
    nome[id] = nó
    travessia[prof].insere(id)
    id := id + 1
    para u em nó.filhos() faca
        dfs(u, prof + 1)
    fim
fim
