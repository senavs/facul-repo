package buffer;

public class Consumidor extends Entidade {
	
	public Consumidor(String nome, InterfaceBuffer bufferCompartilhado) {
		super(nome, bufferCompartilhado);
	}

	public void run() {
		for (int i = 1; i <= 10; i++) {
			try {
				this.bufferCompartilhado.ler(this);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}	
}
