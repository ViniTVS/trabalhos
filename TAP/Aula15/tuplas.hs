main :: IO ()
main = return ()

lista :: [Int]
lista = [5, 23, 4 ,66]
-- (a:c)
-- a: elemento (cabeça)     c: lista (cauda)


-- n primeiros termos
primeiros :: Int -> [Int] -> [Int]
primeiros 0 _  = []
primeiros _ [] = []
primeiros n (a:x) = a : (primeiros (n-1) x)


-- algoritmos de ordenação

menor :: [Int] -> Int
menor [a] = a
menor (a:c)
    | a < (menor c) = a
    | otherwise = menor c


remove_menor :: [Int] -> [Int]
remove_menor [a] = []
remove_menor (a:c)
    | menor (a:c) == a = c
    | otherwise = a:remove_menor c

-- selection sort:
selection :: [Int] -> [Int]
selection []  = []
selection [a] = [a]
selection (a:c) = menor (a:c) : selection (remove_menor (a:c))


concatena :: [Int] -> [Int] -> [Int]
concatena [] b = b
concatena (a:c) b = a : concatena c b
-- ou
-- concatena a b = a ++ b


-- construa uma função em Haskel que dada uma lista de tuplas Pessoa, obtenha o email de uma pessoa 'x'
type Nome = String
type Email = String
type Pessoa = (Nome, Email)

-- obt_email :: Int -> [Pessoa] -> Email
-- obt_email _ [] = []
-- obt_email 1 (n, e) = e
-- obt_email n (a:c) = obt_email (n-1) c



busca :: [Pessoa] -> Nome -> Email
busca [] _ = "Não achou"
busca ((n,e):c) nome
  | nome == n = e
  | otherwise = busca c nome
