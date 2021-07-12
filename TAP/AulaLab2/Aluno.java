import java.io.*;

public class Aluno extends Pessoa implements Serializable{
    private String GRR;


    public Aluno() {}   
    public Aluno(String GRR){
        this.GRR = GRR;
    }

    // sets:
    public void setGRR(String GRR){
        this.GRR = GRR;
    }


    // gets:
    public String getGRR(){
        return this.GRR;
    }
   
}