data ArvoreBin = NodoNull | NodoInt Int ArvoreBin ArvoreBin
    deriving Show

arvoreBin = NodoInt 4   (NodoInt 2 NodoNull NodoNull)
                        (NodoInt 10 (NodoInt 5  NodoNull NodoNull)
                                    (NodoInt 15 NodoNull NodoNull))


cria_no :: Int -> ArvoreBin
cria_no n = (NodoInt n NodoNull NodoNull)

passeio :: ArvoreBin -> [Int]
passeio NodoNull = []
passeio (NodoInt a NodoNull NodoNull) = [a]
passeio (NodoInt a esq dir) = [a] ++ passeio esq ++ passeio dir

insere :: Int -> ArvoreBin -> ArvoreBin
insere x NodoNull = (cria_no x)
insere x (NodoInt a esq dir)
    |x < a = (NodoInt a (insere x esq) dir)
    |x > a = (NodoInt a esq (insere x dir))


---------------------------- Atividades ------------------------------------

-- 1: Construa uma função realize uma rotação a direita em um nó da árvore.
rot_dir :: ArvoreBin -> ArvoreBin
rot_dir NodoNull = NodoNull
rot_dir (NodoInt a (NodoInt b esq dir) c) = (NodoInt b (NodoInt a esq dir) c)