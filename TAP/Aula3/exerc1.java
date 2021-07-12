import java.io.*; 
import java.util.*;

class sorteio_nomes{
    public static void main(String args[]) {
        Scanner teclado = new Scanner(System.in);
        System.out.println("Insira os 5 nomes para serem sorteados:");
        String nomes[] = new String[5];

        // guarda em emória os nomes inseridos
        for (int i = 0; i < 5; i++){
            System.out.println((i + 1) + "° nome:");
            nomes[i] = teclado.nextLine();
        }
        // sorteio e sua impressão
        int sorteio = (int)(Math.random()*5);
        System.out.println("Nome sorteado: " + nomes[sorteio]);
    }
}
