import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class HorarioSerialize {
	
	public static void toFile(String path, Horario horario) {
		try {
			ObjectOutputStream fileStream = new ObjectOutputStream(new FileOutputStream(path));
			
			fileStream.writeObject(horario);
			fileStream.close();
		} catch (IOException  e) {
			e.printStackTrace();
		}
	}
	
	public static Horario fromFile(String path) {
		Horario horario = null;
		
		try {
			ObjectInputStream fileStream = new ObjectInputStream(new FileInputStream(path));
			
			horario = (Horario) fileStream.readObject();
			fileStream.close();
		} catch (IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}
		
		return horario;
	}
}
