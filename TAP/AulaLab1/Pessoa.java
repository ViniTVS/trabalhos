import java.util.*;
import java.io.*;

class Pessoa{
	String nome;
	String endereco;
	String telefone;
	String email;

	/*
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
	
	public Pessoa criaPessoa(){
		Scanner teclado = new Scanner(System.in);
		Pessoa p = new Pessoa();
		System.out.println("Insira o nome: ");
		p.setNome(teclado.nextLine());
		System.out.println("Insira o Endereço: ");
		p.setEndereco(teclado.nextLine());
		System.out.println("Insira o telefone: ");
		p.setTelefone(teclado.nextLine());
		System.out.println("Insira o e-mail: ");
		p.setEmail(teclado.nextLine());

		return p;
	}

	public void devolvePessoa(){
		System.out.println();
		System.out.println("Nome:   " + this.getNome());
		System.out.println("End:    " + this.getEndereco());
		System.out.println("Tel:    " + this.getTelefone());
		System.out.println("E-mail: " + this.getEmail());
	}
}