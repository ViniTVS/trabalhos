import java.util.*;
import java.io.*;


// extends:
class Pessoa{
    private String nome;

    // set:
    public void setNome(String nome) {
        this.nome = nome;
    }

    // get
    public String getNome(){
        return this.nome;
    }
}

class Aluno extends Pessoa{
    private String GRR;

    // set:
    public void setGRR(String GRR){
        this.GRR = GRR;
    }

    // get:
    public String getGRR(){
        return this.GRR;
    } 

    public Aluno(){};
    public Aluno(String nome, String GRR){
        this.GRR = GRR;
        this.setNome(nome);
    }
}

class X{
    public void imprimePessoa(Pessoa p){
        System.out.println(p.getNome());
    }
}



// abstracts:
abstract class Number{

}


abstract class Graphic{
    int x, y;
    abstract void moveTo(int x, int y);
}

class Circle extends Graphic{

    public void moveTo(int x, int y){
        // método a ser feito
    }
}



//  interfaces:





class Teste{
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);

        Aluno al = new Aluno("João", "GRR123456789");
        al.setNome("João Pedro");
  
        System.out.println(al.getNome());
        System.out.println(al.getGRR());
        
        X x1 = new X();
        x1.imprimePessoa(al);

        
        // Number n = new Number();
        // n não pode ser inicializado por ser um abstract
    }
}
