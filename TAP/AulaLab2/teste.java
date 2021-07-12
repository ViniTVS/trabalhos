import java.io.*;
import java.util.*;

public class teste{
    public static void main(String[] args) {
/*
        Vector <Aluno> todos = new Vector <Aluno> ();
        Scanner teclado = new Scanner(System.in);
        Arquivo arq = new Arquivo();
        Aluno al;
        ManterAluno man = new ManterAluno();


        for (int i = 0; i < 3; i++){
            man.inserirAluno(todos);
        }
        
        al = man.recuperarAlunos(todos);
        System.out.println("Aluno recuperado: " + al.getNome() + "\tGRR: " + al.getGRR());

        System.out.println("\nImpressão do Vector:");
        for(int i=0; i < todos.size(); i++){
            al = todos.elementAt(i);
            System.out.println(al.getNome() + ";\t" + al.getGRR());
        }

        man.removerAluno(todos);

        System.out.println("\nImpressão do novo Vector:");
        for(int i=0; i < todos.size(); i++){
            al = todos.elementAt(i);
            System.out.println("Nome: " + al.getNome() + ",\tGRR: " + al.getGRR() + ",\t E-mail: " + al.getEmail());
        }

*/
        Menu m = new Menu();
        m.interage();
    }

}