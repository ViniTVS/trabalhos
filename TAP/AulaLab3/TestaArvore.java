public class TestaArvore {
	public static void main(String[] args) {
    // TODO Auto-generated method stub
    
        Arvore a = new Arvore();
        Aluno al = new Aluno("Vinicius", "vtvs18", 2018);
        Aluno ab = new Aluno("Angrey", "vtvs18", 2018);
        Aluno an = new Aluno("Vinicius", "vtvs18", 2018);
    /*    
        a.insere(al);
        a.insere(ab);
        a.insere(an);
		a.imprimeR(a.getRaiz());
    */
    Comparing c = new Comparing();
    int n;
    n = c.compare(ab, an);
    
    System.out.println("Valor de n: " + n);  

	}
}