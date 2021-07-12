public class ImprimeVetor {
    public static void main(String[] args) {
        int vetorInteger [] = {1,2,3,4,5,6};
        double vetorDouble [] = {1.0,2.0,3.0,4.0,5.0};

        imprime(vetorInteger);
        imprime(vetorDouble);
    }
    public static void imprime(int [] v){
        for (int e: v)
            System.out.printf("%d, ",e);
        System.out.printf("\n");
    }
    public static void imprime(double [] v){
        for (double e: v)
            System.out.printf("%2.2f, ",e);
        System.out.printf("\n");
    }
}