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

	public void insere(Aluno al){
		if (this.raiz == null){
			this.raiz = new Nodo (null,null,al);
			System.out.println("inseriu");
		}else{
			raiz = insereR(al, this.raiz);
		}
	}

	public Nodo insereR(Aluno al, Nodo p){
        Comparing comp = new Comparing();
        Aluno aux = p.getAl();
        System.out.println("x");

		if (p == null){
            System.out.println("xx");
            p = new Nodo (null,null,al);
			System.out.println("inseriu "+ al.getNome());
			return p;
		}
		else{
            System.out.println("xxx");

			if (comp.compare(p.getAl(), al) >= 0) {

        System.out.println("x3");

			p.setDir(insereR(al, p.getDir()));
			System.out.println("direita");
		}
		else 
			if (comp.compare(p.getAl(), al) < 0){

        System.out.println("sx");

				p.setEsq(insereR(al, p.getEsq()));
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
		System.out.print("("+p.getAl().getNome()+" ");
		imprimeR(p.getDir());
		imprimeR(p.getEsq());
		System.out.print(")");
	}


}