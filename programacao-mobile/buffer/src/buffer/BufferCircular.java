package buffer;

import java.util.LinkedList;

public class BufferCircular implements InterfaceBuffer {
	
	private LinkedList<Integer> buffer = new LinkedList<>();
	private static int MAX_SIZE = 3;
	
	public static void setBufferSize(int tamanho) {
		MAX_SIZE = tamanho;
	}

	@Override
	public synchronized void escrever(Produtor quemEscreve, int valor) throws InterruptedException {
		while (this.buffer.size() == MAX_SIZE) {
			System.out.println("  Buffer cheio");
			wait();
		}
		
		buffer.add(valor);
		System.out.println(String.format("\t\"%s\" escreveu o valor %s", quemEscreve.getNome(), valor));
		
		notifyAll();		
	}

	@Override
	public synchronized int ler(Consumidor quemLe) throws InterruptedException {
		while(this.buffer.size() == 0) {
			System.out.println("  Buffer vazio");
			wait();
		}
		
		int valor = this.buffer.removeFirst();
		System.out.println(String.format("\t\t\"%s\" leu o valor %s", quemLe.getNome(), valor));
		
		notifyAll();
		
		return valor;
		
	}

}
