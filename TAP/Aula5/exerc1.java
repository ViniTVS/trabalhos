import java.util.*;
import java.io.*;

class Pessoa{
	String nome;
	String endereco;
	String telefone;
	String email;

    /*
    //construtor:
	public Pessoa(){}
	public Pessoa(String nome){
		this.nome = nome;
    }
    */
	
    // sets:
	public void setNome(String nome){
		this.nome = nome;
	}
	public void setEndereco(String end){
		this.endereco = end;
	}
	public void setTelefone(String tel){
		this.telefone = tel;
	}
	public void setEmail(String email){
		this.email = email;
	}
	
    // gets:
	public String getNome (){
		return nome;
	}
	public String getEndereco (){
		return endereco;
	}
	public String getTelefone (){
		return telefone;
	}
	public String getEmail (){
		return email;
	}
}


class Leitor{
    public float leNumeroFloat(){
        Scanner teclado = new Scanner(System.in);
        float dado;
        dado = teclado.nextFloat();
        return dado;
    }

    public int leNumeroInt(){
        Scanner teclado = new Scanner(System.in);
        int dado;
        dado = teclado.nextInt();
        return dado;
    }

    public double leNumeroDouble(){
        Scanner teclado = new Scanner(System.in);
        double dado;
        dado = teclado.nextDouble();
        return dado;
    }

    public String leString(){
        Scanner teclado = new Scanner(System.in);
        String dado;
        dado = teclado.nextLine();
        return dado;
    }

}


class exerc_1{
// Usando as classes Leitor e Pessoa, apresentadas nesta unidade construa um programa que
// leia os dados de 4 pessoas guarde nos objetos e os imprima. 
    public static void main(String args[]){
        Leitor leitor = new Leitor();
        int tam = 4;
        Pessoa grupo[] = new Pessoa[tam];
        String teste;

        le_pessoas(grupo, tam);
        // leitor.leNumeroFloat();
        imprime_pessoas(grupo, tam);
    }

    public static void le_pessoas (Pessoa pessoas[], int tam){
        Leitor leitor = new Leitor();

        for(int i = 0; i < tam; i++){
            System.out.println((i+1) + "ª̣ pessoa: \n");
            System.out.println("Nome: ");
            // teste = leitor.leString();
            pessoas[i] = new Pessoa();
            pessoas[i].setNome(leitor.leString());
            System.out.println("Endereço: ");
            pessoas[i].setEndereco(leitor.leString());
            System.out.println("Telefone: ");
            pessoas[i].setTelefone(leitor.leString());
            System.out.println("E-mail: ");
            pessoas[i].setEmail(leitor.leString());
            System.out.println(" ");
        }
    }

    public static void imprime_pessoas (Pessoa pessoas[], int tam){
        for (int i = 0; i < tam; i++){
            System.out.println("\n" + (i+1) + "ª̣ pessoa: \n");
            System.out.println("Nome:     " + pessoas[i].getNome()     );
            System.out.println("Endereço: " + pessoas[i].getEndereco() );
            System.out.println("Telefone: " + pessoas[i].getTelefone() );
            System.out.println("E-mail:   " + pessoas[i].getEmail()    );
       }
    }
}