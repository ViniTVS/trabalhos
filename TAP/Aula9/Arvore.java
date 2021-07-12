public class Arvore{
	private Nodo raiz;

	public Nodo getRaiz() {
		return raiz;
	}

	public void setRaiz(Nodo raiz) {
		this.raiz = raiz;
	}

	public Arvore() {
		this.raiz = null;
	}

	public void insere(int elem){
		if (this.raiz == null){
			this.raiz = new Nodo (null,null,elem);
			System.out.println("inseriu");
		}else{
			raiz = insereR(elem, this.raiz);
		}
	}

	public Nodo insereR(int elem, Nodo p){
		if (p == null){
			p = new Nodo (null,null,elem);
			System.out.println("inseriu "+ elem);
			return p;
		}
		else{
			if (p.getElem()>elem) {
			p.setDir(insereR(elem, p.getDir()));
			System.out.println("direita");
		}
		else 
			if (p.getElem()<elem){
				p.setEsq(insereR(elem, p.getEsq()));
				System.out.println("esquerda");
			}
		}
	return p;
	}

	public void imprimeR(Nodo p){
		if (p == null) {
			System.out.print("()");
			return;
		}
		System.out.print("("+p.getElem()+" ");
		imprimeR(p.getDir());
		imprimeR(p.getEsq());
		System.out.print(")");
	}


}