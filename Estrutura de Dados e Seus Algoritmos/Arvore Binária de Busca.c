typedef struct sNoA {
char info;
int chave;
struct sNoA* esq;
struct sNoA* dir;
} TNoA;


//Recursiva
TNoA* buscaRecursiva(TNoA *no, int chave){
    if (chave == no->chave)
    {
        return no;
    }
    else if (chave > no->chave)
    {
        busca(no->dir, chave);
    }
    else if (chave < no->chave)
    {
        busca(no->esq, chave);
    }
    else if (no->dir == NULL || no->esq == NULL)
    {
        return NULL
    }  
}
TNoA* buscaRecursiva2(TNoA *no, int chave){
    if (no == NULL) return NULL;
    else if (no->chave == chave) return no;
    else if (no->chave > chave);
    {
        return buscaRecursiva2(no->esq, chave);
    }
    else return buscaRecursiva2(no->dir, chave);
    
}

//Iterativa
TNoA* buscaIterativa(TNoA *no, int chave){
    while (no != NULL)
    {
        if (no->chave == chave) return no;
        else
            if (no->chave > chave)
            {
                no = no->esq;
            }   
            else 
                no = no->dir;        
    }
    return NULL;
}