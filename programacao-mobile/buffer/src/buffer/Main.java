package buffer;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {

	public static void main(String[] args) {
		
		ExecutorService pool = Executors.newCachedThreadPool();
		InterfaceBuffer bufferCompartilhado = new BufferCircular();
		
		final int N_PRODUTORES = 6;
		final int N_CONSUMIDORES = 2;
		final int BUFFER_SIZE = 3;
		
		
		LinkedList<Integer> dados = new LinkedList<Integer>(Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9));
		Produtor.setDados(dados);
		BufferCircular.setBufferSize(BUFFER_SIZE);
		
		// criação
		Produtor[] produtores = new Produtor[N_PRODUTORES];
		for (int i = 0; i < N_PRODUTORES; i++) {
			Produtor produtor = new Produtor("Produtor " + i, bufferCompartilhado);
			produtores[i] = produtor;
		}
		
		Consumidor[] consumidores =  new Consumidor[N_CONSUMIDORES];
		for (int i = 0; i < N_CONSUMIDORES; i++) {
			Consumidor consumidor = new Consumidor("Consumidor " + i, bufferCompartilhado);
			consumidores[i] = consumidor;
		}
		
		
		System.out.println("Início");
		
		// inicialização
		for (Consumidor consumidor : consumidores) {
			pool.execute(consumidor);
		}
		for (Produtor produtor : produtores) {
			pool.execute(produtor);
		}
		

		
		pool.shutdown();
	}
}
