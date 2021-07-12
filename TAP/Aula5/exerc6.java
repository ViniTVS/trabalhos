import java.util.*;
import java.io.*;

class Produto{
	int codigo;
	String nome;
	int quantidade;
	double preco;

	/*
	// construtor
	public Produto(){	}
	public Produto(int codigo, String nome, int quantidade, double preco){
		this.codigo= codigo;
		this.nome = nome;
		this.quantidade = quantidade;
		this.preco = perco;
	}*/


	// sets:
	public void setCodigo(int cod){
		this.codigo = cod;
	}
	public void setNome(String nome){
		this.nome = nome;
	}
	public void setQuantidade(int quant){
		this.quantidade = quant;
	}
	public void setPreco(double price){
		this.preco = price;
	}
	
	// gets:
	public int getCodigo (){
		return codigo;
	}
	public String getNome (){
		return nome;
	}
	public int getQuantidade (){
		return quantidade;
	}
	public double getPreco (){
		return preco;
	}


	// outrem:
	public void atualizaPreco(double perc){
		preco += preco*perc/100;
	}
}



class exerc6{
// Escreva os métodos get e set para os outros atributos da classe Produto, e coloque a
// visibilidade apropriada para os atributos.
    public static void main(String args[]){
        Scanner teclado = new Scanner (System.in);
        int tam = 4;
        Produto product = new Produto();

		le_produto(product);
		imprime_produto(product);
		mudaPreco(product);
    }

    public static void le_produto (Produto product){
        Scanner teclado = new Scanner(System.in);

        System.out.println("Código: ");
        product.setCodigo(teclado.nextInt());
		teclado.nextLine();	// precisa disso para o inteiro não ser capturado no nome
		System.out.println("Nome: ");
        product.setNome(teclado.nextLine());
        System.out.println("Quantidade: ");
        product.setQuantidade(teclado.nextInt());
        System.out.println("Preço: ");
        product.setPreco(teclado.nextDouble());
        System.out.println(" ");
        
    }

    public static void imprime_produto (Produto product){
        System.out.println("\nInformações do produto:");
        System.out.println("Código:     " + product.getCodigo()    );
        System.out.println("Nome:       " + product.getNome()      );
        System.out.println("Quantidade: " + product.getQuantidade());
        System.out.println("Preço:      " + product.getPreco()+"\n");
    
    }

    public static void mudaPreco(Produto product){
		System.out.println("\nDeseja atualizar o preço?  S/N");
		Scanner teclado = new Scanner(System.in);
		String user = teclado.nextLine();
		if (user.charAt(0) == 's' || user.charAt(0) == 'S'){
			System.out.println("Deseja atualizar em quantos %?");
			// double perc = teclado.nextDouble();
			product.atualizaPreco(teclado.nextDouble());
			imprime_produto(product);
		}
		else
			System.out.println("Preço não atualizado");

    }
}