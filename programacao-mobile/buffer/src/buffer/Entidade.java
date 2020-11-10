package buffer;

public abstract class Entidade implements Runnable {
	
	protected String nome;
	protected InterfaceBuffer bufferCompartilhado;
	
	public Entidade(String nome, InterfaceBuffer bufferCompartilhado) {
		this.bufferCompartilhado = bufferCompartilhado;
		this.nome = nome;		
	}
	
	
	public String getNome() {
		return this.nome;
	}

	@Override
	public abstract void run();
	
	@Override
	public String toString() {
		return this.getClass().getName() + " " + this.nome;
	}
}
