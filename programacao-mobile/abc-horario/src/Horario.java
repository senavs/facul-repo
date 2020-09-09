import java.io.Serializable;

public class Horario implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private int totalSegundos = 0;
	private int diasCarregados = 0;

	public Horario() {
		this.setTotalSegundos(0);
	}

	public Horario(int segundos) {
		this.setTotalSegundos(segundos);
	}

	public int getTotalSegundos() {
		return this.totalSegundos;
	}

	private void setTotalSegundos(int segundos) {
		this.totalSegundos = segundos % 86400;
		this.diasCarregados = Math.floorDiv(segundos, 86400);
	}

	public int getDiasCarregados() {
		return this.diasCarregados;
	}

	public int getSegundos() {
		return this.getTotalSegundos() % 60;
	}

	public int getMinutos() {
		return Math.floorDiv(this.getTotalSegundos(), 60) % 60;
	}

	public int getHoras() {
		return Math.floorDiv(this.getTotalSegundos(), 3600);
	}

	public void increamentaSegundos(int segundos) {
		this.setTotalSegundos(segundos);
	}

	public void increamentaMinutos(int minutos) {
		this.setTotalSegundos(minutos * 60);
	}
	
	public void increamentaHoras(int horas) {
		this.setTotalSegundos(horas * 3600);
	}
	
	public boolean isUltimoSegundo() {
		return this.getTotalSegundos() == 86399;
	}
	
	public String format(String spec) {
		spec = spec.replace("%H", Integer.toString(this.getHoras()));
		spec = spec.replace("%M", Integer.toString(this.getMinutos()));
		spec = spec.replace("%S", Integer.toString(this.getSegundos()));
		spec = spec.replace("%s", Integer.toString(this.getTotalSegundos()));
		spec = spec.replace("%c", Integer.toString(this.getDiasCarregados()));
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
		return this.format("Horario(hora=%H, minuto=%M, segundo=%S, totalSegundos=%s, diasCarregados=%c)");
	}
	
	public String toString(String spec) {
		return this.format(spec);
	}
}