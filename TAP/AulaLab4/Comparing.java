import java.io.*; 
import java.util.*;

// comparador p/ ordenação da lista
public class Comparing implements Comparator <Aluno>{
	// @Override
	public int compare(Aluno o1, Aluno o2){
		String s1 = o1.getNome();
		String s2 = o2.getNome();
		return s1.compareTo(s2);
	}
}
