public class Pessoa {

    private String nome;
    private String email;


    public Pessoa() {}   
    public Pessoa(String nome, String email){
        this.nome = nome;
        this.email = email;
    }

    // sets:
    public void setNome(String nome){
        this.nome = nome;
    }
   
    public void setEmail(String email){
        this.email = email;
    }

    // gets:
    public String getNome(){
        return this.nome;
    }
   
    public String getEmail(){
        return this.email;
    }


}