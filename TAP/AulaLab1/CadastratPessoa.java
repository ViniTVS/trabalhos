public class CadastrarPessoa{
	public Pessoa[] inserePessoa(Pessoa p, Pessoa array[], int tam){
		p = new Pessoa();
		p = p.criaPessoa();
		array[tam] = p;

		
		return array; 
	}
}