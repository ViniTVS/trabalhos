import java.io.*;
import java.util.*;

public class ManterAluno extends Aluno{

    public void inserirAluno(Vector <Aluno> pessoas){
        // System.out.println("\n" + (i + 1) + "º: ");
        Scanner teclado = new Scanner(System.in);

        System.out.println("Nome: ");
        String nome  = teclado.nextLine();
        System.out.println("E-mail: ");
        String email = teclado.nextLine();
        System.out.println("GRR: ");
        String GRR = teclado.nextLine();

        Aluno a = new Aluno(GRR);
        a.setEmail(email);
        a.setNome(nome);

        pessoas.add(a);
    }

    public void removerAluno(Vector <Aluno> pessoas){
        Aluno al = new Aluno();
        Scanner teclado = new Scanner(System.in);

        System.out.println("Digite o nome a ser removido: ");
        String nome = teclado.nextLine();

        for (int i = 0; i < pessoas.size(); i++){
            al = pessoas.elementAt(i);

            if (nome.equals(al.getNome())){
                pessoas.removeElementAt(i);
            }
        }

    }

    public void salvarAlunos(Vector <Aluno> pessoas){

    }

    public Aluno recuperarAlunos(Vector <Aluno> pessoas){
        Scanner teclado = new Scanner(System.in);
        Aluno al = new Aluno(); Aluno temp;

        System.out.println("Digite o nome a ser buscado: ");
        String nome = teclado.nextLine();

        for (int i = 0; i < pessoas.size(); i++){
            // System.out.println(pessoas.getClass());
            temp = pessoas.elementAt(i);
            
            if (nome.equals(temp.getNome()) ){
                System.out.println("Aluno encontrado");
                al = temp;
            }

        }
        return al;
    }
}