import java.io.*;
import java.util.*;

public class Interface{
    public static void main(String[] args) {
        Pessoa p = new Pessoa();
        int teste;
        p.setAnoNasc(2000);
        // p.calculaIdade(2003);
        teste = Velho.diferenca(p);

        System.out.println("Teste: " + teste);
    }
}