import java.util.*;
import java.io.*;

abstract class Pessoa{
    private String nome;
    private String sobrenome;

    // sets:
    void setNome (String nome){
        this.nome = nome;
    }
    void setSobrenome (String sobrenome){
        this.sobrenome = sobrenome;
    }

    // gets:
    String getNome (){
        return this.nome;
    }
    String getSobrenome (){
        return this.sobrenome;
    }


    abstract void imprimePessoa ();
}

class PessoaABNT extends Pessoa{
    public void imprimePessoa(){
        System.out.println(this.getSobrenome() + ", " + this.getNome());
    }
}


class exerc_aula{
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);    
        PessoaABNT p = new PessoaABNT();

        System.out.println("Informe o nome:");
        String temp = teclado.nextLine();
        p.setNome(temp);
        
        System.out.println("Informe o sobrenome:");
        temp = teclado.nextLine();
        p.setSobrenome(temp);

        
        System.out.println("\nSeu nome, em formato da ABNT é:");
        p.imprimePessoa();
    }
}