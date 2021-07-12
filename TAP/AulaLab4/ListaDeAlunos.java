import java.util.*;
import java.io.*;

public class ListaDeAlunos{
    private static ListaDeAlunos uniqueInstance;

    private ArrayList<Aluno> lista = new ArrayList<Aluno>();


    private ListaDeAlunos() {    }

    public static synchronized ListaDeAlunos getInstance() {
        if (uniqueInstance == null)
        	uniqueInstance = new ListaDeAlunos();
        return uniqueInstance;
    }

 	public void insere(Aluno al){
 		this.lista.add(al);
    }

    public int tamanho(){
    	return this.lista.size();
    }

    public boolean vazia(){
    	return (this.tamanho() == 0);
    } 

    public void imprime(){
    	Aluno al;
    	for (int i = 0; i < this.tamanho(); i++){
			System.out.println("Nome: " + this.lista.get(i).getNome());    		
    	}
    }






}