import java.util.*;
import java.io.*;

class exerc3{
//Construa um método que receba uma temperatura em graus Celsius e calcule e retorne o valor
//da temperatura equivalente em graus Farenheit. Celsius = 5.0/9.0 (farenheit -32). 
	public static void main(String[] args) {
		Scanner teclado = new Scanner(System.in);
		System.out.println("Digite o valor em C° para ser traduzido:");
		double celsius = teclado.nextDouble();
		double farenheit;
		farenheit = Cel_to_Fh(celsius);
		System.out.println("Valor em Farenheit: " + farenheit);
	}

	public static double Cel_to_Fh (double cel){
		double farenheit;
		farenheit = (cel * 9.0/5.0) + 32.0;
		return farenheit;
	}
}