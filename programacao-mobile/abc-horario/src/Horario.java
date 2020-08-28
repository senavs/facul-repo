public class Horario {
	private static final int TOTAL_SEGUNDOS_EM_UM_DIA = 86400;
	private static final int TOTAL_SEGUNDOS_EM_UMA_HORA = 3600;

	private int totalSegundos = 0;
	private int carry = 0;
	
	public Horario() {
		this.totalSegundos = 0 % TOTAL_SEGUNDOS_EM_UM_DIA;
		this.carry = Math.floorDiv(0, TOTAL_SEGUNDOS_EM_UM_DIA);
	}

	public Horario(int sec) {
		this.totalSegundos = sec % TOTAL_SEGUNDOS_EM_UM_DIA;
		this.carry = Math.floorDiv(sec, TOTAL_SEGUNDOS_EM_UM_DIA);
	}

	public int getTotalSegundos() {
		return this.totalSegundos;
	}

	public int getCary() {
		return this.carry;
	}
	
	public int segundo() {
		return this.getTotalSegundos() % 60;
	}
	
	public int minuto() {
		return Math.floorDiv(this.getTotalSegundos(), 60) % 60;
	}
	
	public int hora() {
		return Math.floorDiv(this.getTotalSegundos(), TOTAL_SEGUNDOS_EM_UMA_HORA);
	}
	
	public String format(String spec) {
		spec = spec.replace("%H", Integer.toString(this.hora()));
		spec = spec.replace("%M", Integer.toString(this.minuto()));
		spec = spec.replace("%S", Integer.toString(this.segundo()));
		spec = spec.replace("%s", Integer.toString(this.getTotalSegundos()));
		spec = spec.replace("%c", Integer.toString(this.getCary()));
		spec = spec.replace("%%", "%%");
		return spec;
	}
	
	public Horario adiciona(Horario outro) {
		return new Horario(this.getTotalSegundos() + outro.getTotalSegundos());
	}
	
	public Horario subtrai(Horario outro) {
		return new Horario(this.getTotalSegundos() - outro.getTotalSegundos());
	}
	
	public String toString() {
		return this.format("Horario(hora=%H, minuto=%M, segundo=%S, totalSegundos=%s, cary=%c)");
	}
	
	public String toString(String spec) {
		return this.format(spec);
	}

}
