public class TestaArvore {
	public static void main(String[] args) {
	// TODO Auto-generated method stub
		Arvore a = new Arvore();
		a.insere(10);
		a.insere(5);
		a.insere(15);
		a.insere(3);
		a.insere(8);
		a.insere(12);
		a.insere(17);
		a.imprimeR(a.getRaiz());
		System.out.println();
	}
}