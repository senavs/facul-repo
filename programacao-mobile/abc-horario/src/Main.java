public class Main {

	public static void main(String args[]) {
		Horario h1 = new Horario();
		Horario h2 = new Horario(62345);
		Horario h3 = new Horario(86399);
		Horario h4 = new Horario(86400);
		
		System.out.println(h1);
		System.out.println(h2);
		System.out.println(h3);
		System.out.println(h4);
		
		System.out.println(h2.format("%H:%M:%S"));
		
		HorarioSerialize.toFile("./horario.bin", h2);
		Horario h5 = HorarioSerialize.fromFile("./horario.bin");
		System.out.println(h5.format("%H:%M:%S"));
	}
}
