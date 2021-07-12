import java.util.*;
import java.io.*;

class exerc5{
    // 5) Construa um método que receba uma String e imprima esta string invertida.
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        String line;
        System.out.println("Digite a String:");
        line = teclado.nextLine();
        System.out.println("String:          " + line);
        System.out.println("String invertida:" + inverteString(line));

    }
    public static String inverteString(String entrada){
        String saida = "";
        for(int i = entrada.length() - 1; i >= 0; i--){
            // System.out.print(entrada.charAt(i));
            saida = saida + entrada.charAt(i);
        }
        // System.out.print("\n");
        // System.out.println(saida);
        return saida;
    }
}