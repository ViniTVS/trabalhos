import java.io.*;
import java.util.*;

public class Menu{
    
    public void interage(){
        Vector <Aluno> todos = new Vector <Aluno> ();
        Scanner teclado = new Scanner(System.in);
        Arquivo arq = new Arquivo();
        Aluno al;
        ManterAluno man = new ManterAluno();
        String sair = "q";
        String temp = " ";
        while(temp.charAt(0) != sair.charAt(0)){

            System.out.println("Qual operação deseja fazer?");
            System.out.println("[i]nserir, \t[r]emover, \t[s]alvar, \tr[e]cuperar, \t[q]uit, \t[p]rint");
            temp = teclado.nextLine();
            System.out.println();

            switch (temp.charAt(0)) {
                case ('i'):
                    // System.out.println("Insere aluno");
                    man.inserirAluno(todos);
                    break;

                case ('r'):
                    man.removerAluno(todos);
                    break;

                case ('s'):
                    man.salvarAlunos(todos);
                    break;

                case ('e'):
                    al = man.recuperarAlunos(todos);
                    System.out.println("Nome: " + al.getNome() + "\tE-mail: " + al.getEmail() + "\tGRR: " + al.getGRR());
                    break;

                case ('p'):
                    for (int i = 0; i < todos.size(); i++){
                        System.out.println( (i + 1) + "º aluno: " + todos.elementAt(i).getNome());
                    }
                    break;
                                
                default:
                    break;
            }
        }

    }    
}