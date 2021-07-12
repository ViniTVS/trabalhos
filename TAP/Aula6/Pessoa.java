public class Pessoa implements Gente{
    private int anoNasc;

    // others:
    public int calculaIdade(int ano){
        return (ano - anoNasc);
    }
}