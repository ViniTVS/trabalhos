import java.io.*;
public class Principal {

    public static void main(String[] args){
        try{
            FileOutputStream arq = new FileOutputStream("arq.dat");
            ObjectOutputStream out = new ObjectOutputStream(arq);
            for(int i=0;i<5;i++){
                Pessoa p = new Pessoa("pessoa"+i, "pessoa"+i+"@spet");
                out.writeObject(p);
                out.flush();
            }
            out.close();
        }
        catch(java.io.IOException exc){
            System.out.println("Erro ao Gravar o arquivo");
        }

        try{
            FileInputStream arq = new FileInputStream("arq.dat");
            ObjectInputStream in = new ObjectInputStream(arq);
            for(int i=0;i<5;i++){
                Pessoa p = (Pessoa) in.readObject();
                System.out.println(p.getNome());
                System.out.println(p.getEmail());
            }
            in.close();
        }

        catch(java.io.IOException exc2){
            System.out.println("Erro ao Ler o arquivo");
        }
        catch(ClassNotFoundException cnfex){
        }
    }
}