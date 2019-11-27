funcao consulta(nó, prof)
    idx := travessia[prof].upper_bound(preordem[nó])
    devolva nome[idx]
fim