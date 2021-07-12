main :: IO ()
main = return ()

lista :: [Int]
lista = [5, 23, 4, 99, 66, 42]

-- 1: Construa uma fun¸c˜ao que inverta uma lista.-- 
inverte_lista :: [Int] -> [Int]
inverte_lista [] = []
inverte_lista (a:x) = inverte_lista x ++ [a]

-- 2: Construa uma fun¸c˜ao que remova o primeiro elemento de uma lista.
remove_primeiro :: [Int] -> [Int]
remove_primeiro [] = []
remove_primeiro (a:x) = x 

-- 3: Construa uma fun¸c˜ao que remova o ´ultimo elemento de uma lista.
remove_ultimo :: [Int] -> [Int]
remove_ultimo [a] = []
remove_ultimo [] = []
remove_ultimo (a:x) = [a] ++ remove_ultimo x

-- 4: Construa uma fun¸c˜ao que some os elementos pares de uma lista.
soma_el_pares :: [Int] -> Int
soma_el_pares [] = 0
soma_el_pares (a:x)
    | (rem a 2 == 0) = a + soma_el_pares x
    | otherwise = soma_el_pares x

-- 5: Construa uma fun¸c˜ao que some os elementos em posi¸c˜oes pares de uma lista. (A
-- primeira posi¸c˜ao da lista ´e a posi¸c˜ao 1).
soma_pares :: [Int] -> Int
soma_pares [] = 0
soma_pares [a] = 0
soma_pares (a:b:x) = b + soma_pares x


-- 6: Construa uma fun¸c˜ao que receba uma lista e um n´umero ’n’ e insira um elemento na
-- n-´esima posi¸c˜ao da lista
-- vet -> pos -> val -> lista_saida
insere_pos :: [Int] -> Int -> Int -> [Int]
insere_pos [] pos val = [val]
insere_pos lista pos val = let (l1,l2) = splitAt pos lista in l1 ++ (val:l2)

-- 7: Construa uma fun¸c˜ao que encontre o pen´ultimo elemento de uma lista.
penultimo :: [Int] -> Int
penultimo [] = 0
penultimo [a] = 0
penultimo [a,b] = a
penultimo (a:x) = penultimo x

-- 8: Construa uma fun¸c˜ao que elimine duplicatas consecutivas dos elementos da lista.



-- 9: Construa uma fun¸c˜ao que divida uma lista em duas partes; ´e fornecido o comprimento
-- da primeira parte.
-- divide :: [Int] -> Int -> ([Int], [Int])
