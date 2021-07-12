import java.util.*;

public class Lista{
    private int tam = 0;
    private Nodo inicio = null;
    private Nodo fim;


    public void aumentaTam(){
        this.tam++;
    }
    public void dimTam(){
        this.tam--;
    }

    public int getTam(){
        return this.tam;
    }

    public Nodo getFim(){
        return this.fim;
    }

    public boolean vazio(){
        if (this.inicio == null)
            return true;
        
        return false;
    }

    public void insereInicio(String ent){
        Nodo n = new Nodo();
        Nodo aux;
        Scanner teclado = new Scanner(System.in);

        n.setElem(ent);
        // checagem p/ ver se a lista não está vazia
        if (this.inicio == null){
            this.inicio = n;
        }
        else{
            aux = this.fim;
            aux.setProx(n);
        }

        this.fim = n;
        this.aumentaTam();
    }

    public void removeFim(){
        Nodo aux = this.inicio;
        // Nó aux percorre a lista até o penúltimo elem
        for (int i = 1; i < (this.tam - 1); i++){
            aux = aux.getProx();
        }

        // o fim recebe o penúltimo e aponta seu prox p/ null:
        Nodo aux2 = this.fim;
        aux2 = aux;
        aux.setProx(null);

        // diminui o tam da lista 
        if (this.getTam() > 0){
            this.dimTam();
        }
        
    }

    public void imprimeLista(){
        Nodo aux = this.inicio;
        System.out.println("Lista:");  

        for (int i = 0; i < this.tam; i++){
            System.out.println("\t" + aux.getElem());
            aux = aux.getProx();
        }
        System.out.println();
    }
}