import java.util.*;
import java.io.*;

class Pessoa{
	String nome;
	String endereco;
	String telefone;
	String email;

	public Pessoa(){}
	public Pessoa(String nome){
		this.nome = nome;
	}
	

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

class Exemplo{
	public static void main(String args[]){
		Pessoa professor = new Pessoa("Andrey");
		// professor.setNome("Andrey");
		professor.setEndereco("rua X, 1234");
		professor.setEmail("andrey@inf.ufpr.br");
		professor.setTelefone("333-4900");
		System.out.println("Nome: " + professor.getNome());
		System.out.println("Endereço: " + professor.getEndereco());
		System.out.println("E-mail: " + professor.getEmail());
		System.out.println ("Telefone: " + professor.getTelefone());
	}
	
}