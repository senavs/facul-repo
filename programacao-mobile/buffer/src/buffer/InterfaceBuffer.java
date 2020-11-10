package buffer;

public interface InterfaceBuffer {
	
	public void escrever(Produtor quemEscreve, int valor) throws InterruptedException;
		
	public int ler(Consumidor quemLe) throws InterruptedException;

}
