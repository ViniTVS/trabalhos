main :: IO ()
main = return ()

lista :: [Int]
lista = [5, 23, 4 ,66]

type Nome = String
type Endereco = String
type Email = String
type Pessoa = (Nome, Endereco, Email)
type ListaPessoas = [Pessoa]

data Cor = Verde | Azul | Amarelo
    deriving (Eq, Show)
    
-- data ListaEnc = NodoNull | Nodo Int ListaEnc
--     deriving (Show)

-- Árvore Binária:
data ArvBin = NodoNull | Nodo String ArvBin ArvBin
    deriving Show
arvoreBin = Nodo "Joao"
    (Nodo "Paulo" NodoNull NodoNull)
    (Nodo "Ana" 
        (Nodo "Maria" NodoNull NodoNull)
        (Nodo "Juan"  NodoNull NodoNull))


            -- Joao
    -- Paulo          Ana
    --            Maria Juan
passeio :: ArvBin -> [String]
passeio (NodoNull) = []
passeio (Nodo a NodoNull NodoNull) = [a]
passeio (Nodo a f1 f2)= [a] ++ passeio f1 ++ passeio f2

cria_no :: String -> ArvBin
cria_no a = (Nodo a NodoNull NodoNull)

insercao :: String -> arvoreBin -> arvoreBin
insercao a (NodoNull) = cria_no a
insercao a (Nodo n NodoNull dir) = (Nodo n (cria_no a) dir)
insercao a (Nodo n esq NodoNull) = (Nodo n esq (cria_no a))
insercao a (Nodo n esq dir) 
    | (a<n) = (Nodo n (insercao a esq) dir)
    | otherwise = (Nodo n esq (insercao a dir))

