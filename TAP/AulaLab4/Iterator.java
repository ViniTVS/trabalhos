interface Iterator {
	boolean hasNext();
	Object next();

	ListaDeAlunos lista = ListaDeAlunos.getInstance();

	public class MenuIterator implements Iterator {
		MenuItem[] itens;
		int posicao = 0;

		public MenuIterator(MenuItem[] itens) {
		this.itens = itens;
	}

	public Object next() {
		MenuItem menuItem = itens[posicao];
		posicao++;
		return menuItem;
	}

	public boolean hasNext() {
		if (posicao >= itens.length || itens[posicao] == null) {
			return false;
		} else {
			return true;
		}
	} 
}