import java.io.*;

public class Aluno extends Pessoa implements Serializable{
    private int GRR;


    public Aluno() {}   
    public Aluno(String nome, String email, int GRR){
        this.GRR = GRR;
        this.setNome(nome);
        this.setEmail(email);
    }

    // sets:
    public void setGRR(int GRR){
        this.GRR = GRR;
    }


    // gets:
    public int getGRR(){
        return this.GRR;
    }
/*
    @Override
    public int compareTo(Aluno p){
        // Aluno p1 = (Aluno)p;
        return this.getNome().compareTo(p.getNome());
    }
  */ 
}