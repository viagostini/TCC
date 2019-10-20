function query(u, d)
    x := u
    if d > depth(x) or d < 0
        return -1 // Não há resposta.
    end
    while depth(x) != d
        x := parent(x)
    end
    return x
end