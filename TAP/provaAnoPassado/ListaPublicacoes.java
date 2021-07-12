import java.io.*;
import java

class ListaPublicacoes(){
    private static ListaPublicacoes instancia;

	private ArrayList<Publicacao> lista = new ArrayList<Publicacao>();


    private ListaPublicacoes() {    }

    public static synchronized ListaPublicacoes getInstance() {
        if (instancia == null)
        	instancia = new ListaPublicacoes();
        return instancia;
    }


	public insere (Publicacao p){
		this.lista.add (p);
	}
}