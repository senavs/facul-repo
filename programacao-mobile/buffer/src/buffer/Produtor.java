package buffer;

import java.util.LinkedList; 

public class Produtor extends Entidade {
	
	private static LinkedList<Integer> dados;
	
	public Produtor(String nome, InterfaceBuffer bufferCompartilhado) {
		super(nome, bufferCompartilhado);
	}

	public static void setDados(LinkedList<Integer> dados) {
		Produtor.dados = dados;
	}

	public void run() {
		while (dados.size() > 0) {
			int dado = dados.removeFirst();
			try {
				this.bufferCompartilhado.escrever(this, dado);				
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
