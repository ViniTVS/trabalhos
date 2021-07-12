import java.util.*;
import java.io.*;

public class Main{

	public static void main(String[] args) {
		ListaDeAlunos lista = ListaDeAlunos.getInstance();
		Aluno al = new Aluno("Vini","vtvs18@inf.ufpr.br", 6716);

		lista.insere(al);

		lista.imprime();
	}
}