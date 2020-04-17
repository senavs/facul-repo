import java.sql.SQLException;

public class Main {

    public static void main(String[] args) throws SQLException {

        for (int i = 0; i < 5; i++) {
            SingletonPoolDB instance = SingletonPoolDB.getInstance();
            System.out.println(instance);
            instance.doSomethingInDataBase();
        }
        SingletonPoolDB instance = SingletonPoolDB.getInstance();
        instance.connect();
        instance.connect();
        instance.connect();
        instance.close();
        instance.close();
    }
}
