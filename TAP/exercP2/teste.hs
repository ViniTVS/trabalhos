main :: IO ()
main = return ()

s_teste0 :: String
s_teste0 = "ana"
s_teste1 :: String
s_teste1 = "nada"
s_teste2 :: String
s_teste2 = "me mate"

-- Questao 1: (20 pontos)
-- Crie uma fun¸c˜ao em Haskell, com a respectiva defini¸c˜ao de tipo, que receba uma String e verifique se ´e
-- Pal´ındromo ou n˜ao. Podem ser criadas outras fun¸c˜oes, com as respectivas defini¸c˜oes de tipo, para realizar a
-- tarefa.

teste_l :: [Int]
teste_l = [42, 24, 69, 420]


teste :: String -> Bool
teste []  = True
teste [a] = True


-- Quest˜ao 2: (20 pontos)
-- Crie uma fun¸c˜ao recursiva em Haskell, com a respectiva defini¸c˜ao de tipo, que receba uma lista e a posi¸c˜ao
-- do elemento a ser retirado e retorne a lista sem o elemento.

remove_ele :: [Int] -> Int -> [Int]
remove_ele [] a = []
remove_ele l n = let (l1, l2) = splitAt (n-1) l in l1 ++ (tail l2)

-- Quest˜ao 3: (20 pontos)
-- Construa uma fun¸c˜ao recursiva em Haskell, com a respectiva defini¸c˜ao de tipo, que receba um n´umero inteiro
-- em base decimal e retorne a sua representa¸c˜ao em base bin´aria, como no exemplo:
-- *Main> binario 23
-- 10111


-- Quest˜ao 4: (10 pontos)
-- Crie em Haskell as seguintes defini¸c˜oes de tipo, usando como base os tipos primitivos adequados: Nome;
-- Rua; Numero; Bairro; Cep; Email; Telefone; Endereco composto de Rua, Numero, Bairro e Cep; Clente
-- composto de Nome, Endereco, Telefone e Email.

type Nome   = String
type Rua    = String
type Bairro = String
type Email  = String
type CEP    = Int
type Numero = Int
type Telefone = Int

type Endereco = (Rua, Numero, Bairro, CEP)

type Cliente = (Nome, Endereco, Telefone, Email)

-- Quest˜ao 5: (10 pontos)
-- Crie em Haskell a defini¸c˜ao de tipo para uma fun¸c˜ao que recebe um n´umero inteiro, duas listas de inteiros e
-- retorna uma tupla com uma lista de inteiros e um n´umero inteiro.




-- Quest˜ao 6: (20 pontos)
-- Construa fun¸c˜oes em Haskell que, dada a fun¸c˜ao base abaixo, retorne a) a idade m´edia dos doutores; b) o
-- n´umero de mulheres doutoras.
-- base x
--      |x == 1 = ("joao", "mestre", ’m’, 35)
--      |x == 2 = ("jonas", "doutor", ’m’, 37)
--      |x == 3 = ("joice", "mestre", ’f’, 30)
--      |x == 4 = ("janete", "doutor", ’f’, 38)
--      |x == 5 = ("jocileide", "doutor", ’f’, 50)
--      |otherwise = ("ninguem", "", ’x’)