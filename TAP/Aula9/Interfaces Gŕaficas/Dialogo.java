import java.awt.*;
import javax.swing.JOptionPane;

public class Dialogo
{
	public static void main(String[] args)
	{
		String frase = JOptionPane.showInputDialog(null,
		"digite a frase", "janela1",0);
		JOptionPane.showMessageDialog(null, frase);
	}
}