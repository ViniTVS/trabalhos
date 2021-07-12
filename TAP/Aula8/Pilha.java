public class Pilha < E >{
    private int tam;
    private int top;
    private E[] elem;
    
    public Pilha(){
        this( 10 );
    }

    public Pilha( int s ){
        tam = s > 0 ? s : 10;
        top = -1;
        elem = ( E[] ) new Object[ tam ];
    }

    public void push( E v ){
        if ( top == size - 1 ) return;
        elem[ ++top ] = v;
    }

    public E pop(){
        if ( top == -1 ) return null;
        return elem[ top-- ];
    }
}