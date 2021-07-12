import java.io.*; 
import java.util.*;

class media_idades{
    public static void main(String args[]) {
        Scanner teclado = new Scanner(System.in);
        int idades[] = new int[10];
        System.out.println("Digite as 10 idades desejadas");
        int soma_idades = 0;
        
        // guarda em emória as idades inseridos e sua soma
        for (int i = 0; i < 10; i++){
            System.out.print((i + 1) + "° idade:");
            idades[i] = teclado.nextInt();
            soma_idades += idades[i];
        }
        // cálculo da média de idades:
        int media;
        media = soma_idades/10;
        System.out.println("Média: " + media + "\n");

        for (int age:idades){
            System.out.print(age);
            if (age < media)
                System.out.println(" é menor que a média");
            else  if (age > media)
                System.out.println(" é maior que a média");
            else
                System.out.println(" está na média");

        }
    }
}