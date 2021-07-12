public class Nodo{
    private Nodo esq, dir;
    private int elem;


    public Nodo getEsq() {
        return esq;
    }
    public void setEsq(Nodo esq) {
        this.esq = esq;
    }
    public Nodo getDir() {
        return dir;
    }
    public void setDir(Nodo dir) {
        this.dir = dir;
    }
    public int getElem() {
        return elem;
    }
    public void setElem(int elem) {
        this.elem = elem;
    }
    public Nodo(Nodo esq, Nodo dir, int elem) {
        super();
        this.esq = esq;
        this.dir = dir;
        this.elem = elem;
    }
}