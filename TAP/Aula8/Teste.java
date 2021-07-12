import java.io.*;
import java.util.*;

public class Teste{
    public static void main(String[] args) {
        Lista lista = new Lista();
        Scanner teclado = new Scanner(System.in);

        // lista.insereInicio();

        String sair = "q";
        String temp = " ";
        while(temp.charAt(0) != sair.charAt(0)){

            System.out.println("Qual operação deseja fazer?");
            System.out.println("[i]nserir, \t[r]emover, \tremover [u]ltimo, \t[q]uit, \t[t]amanho da lista, \t[p]rint");
            temp = teclado.nextLine();
            System.out.println();

            switch (temp.charAt(0)) {
                case ('i'):
                    // System.out.println("Insere aluno");
                    System.out.println("Digite o elem a ser inserido: ");
                    lista.insereInicio(teclado.nextLine());
                    break;

                case ('u'):
                    lista.removeFim();
                    break;

                case ('r'):
                    // lista.removeElem();
                    break;

                case ('p'):
                    lista.imprimeLista();
                    break;
                          
                case ('t'):
                    System.out.println("Tamanho da lista: " + lista.getTam());
                    break;
                    
                default:
                    break;
            }
        }
    }
}