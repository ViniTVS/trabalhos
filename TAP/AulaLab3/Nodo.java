public class Nodo{
    private Nodo esq, dir;
    private Aluno al;


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


    public Aluno getAl() {
        return al;
    }
    public void setAl(Aluno al) {
        this.al = al;
    }


    public Nodo(Nodo esq, Nodo dir, Aluno al) {
        super();
        this.esq = esq;
        this.dir = dir;
        this.al = al;
    }

}