// import

class MapSimples <T> {
	private String[] chaves = new String[10];

	private T[] tesao = new T[10];

	public T buscaElem(String chave){
		int i = 0;
		while (!chave.equals(this.chaves[i])){
			i++;
		}

		return this.tesao[i];
	}

}