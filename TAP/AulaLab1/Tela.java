import java.util.*;
import java.io.*;

public class Tela{
	public static void main(String[] args) {	
		Scanner teclado = new Scanner(System.in);
		int tam = 0;
		Pessoa grupo[] = new Pessoa[1000];
		CadastrarPessoa cadastro = new CadastrarPessoa();
		Pessoa teste = new Pessoa();
		// teste = teste.criaPessoa();
		// teste.devolvePessoa();
		// cadastro.inserePessoa();
		int i = 1;
		String resposta = "s";
		do{
			grupo = cadastro.inserePessoa(teste, grupo, tam);
			System.out.println("Deseja inserir outra pessoa?  S/N");
			resposta = teclado.nextLine();
			tam++;

		}while(resposta.charAt(0) == 's' || resposta.charAt(0) == 'S');

		System.out.println("\nPessoas cadastradas: ");
		for (int j = 0; j < tam; j++){
			grupo[j].devolvePessoa();
		}
	}
}