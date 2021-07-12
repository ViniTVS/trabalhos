main :: IO ()
main = return ()

lista :: [Int]
lista = [5, 23, 4 ,66]

comp :: [Int] -> Int
-- base ->
comp [] = 0
comp (a:x) = 1 + comp x
-- a é a cabeça (elem.) e x a cauda (lista)

soma :: [Int]-> Int
soma[] = 0
soma (a:x) = a + soma x

busca :: Int -> [Int] -> Bool
busca p [] = False
busca p (a:x)
  | p == a = True
  | otherwise = (busca p x)

busca_valor :: Int -> [Int] -> Int
busca_valor p [] = -1
busca_valor p (a:x)
  | p == a = a
  | otherwise = (busca_valor p x)



-- Exercícios de aula:
-- 1) Maior elemento da lista
-- 2) Remove o último elemento da lista
-- 3) Retorna uma lista com os 'n' primeiros elementos de outra lista
-- 4) remove o maior elemento da lista

maior :: [Int] -> Int
maior[] = 0
maior[a] = a
maior (a:x)
  | (maior x) > a = maior x
  | otherwise = a

-- removeItem _ [] = []


remove_fim :: [Int] -> [Int]
remove_fim[] = []
remove_fim[a] = []
remove_fim (a:x) = [a] ++ remove_fim x


diminui_lista :: Int -> [Int] -> [Int]
diminui_lista 0 x = []
diminui_lista t [] = []
diminui_lista t (a:x) = [a] ++ diminui_lista (t-1) x

-- pos_elem :: Int -> [Int] -> Int