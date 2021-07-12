public class Nodo{
    private String elem;
    private Nodo prox = null;

    // sets:
    public void setElem(String elem){
        this.elem = elem;
    }
    public void setProx(Nodo prox){
        this.prox = prox;
    }

    // public void set

    // gets:
    public String getElem(){
        return this.elem;
    }
    public Nodo getProx(){
        return this.prox;
    }
}