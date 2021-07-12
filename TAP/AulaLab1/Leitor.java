public class Leitor{
	public float leNumeroFloat(){
		Scanner teclado = new Scanner(System.in);
		float dado;
		dado = teclado.nextFloat();
		return dado;
	}

	public int leNumeroInt(){
		Scanner teclado = new Scanner(System.in);
		int dado;
		dado = teclado.nextInt();
		return dado;
	}

	public double leNumeroDouble(){
		Scanner teclado = new Scanner(System.in);
		double dado;
		dado = teclado.nextDouble();
		return dado;
	}

	public String leString(){
		Scanner teclado = new Scanner(System.in);
		String dado;
		dado = teclado.nextLine();
		return dado;
	}

}