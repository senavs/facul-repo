import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class SingletonPoolDB {

    // singleton config
    private static int maxInstances = 6;
    private static int currentInstance = -1;
    private static SingletonPoolDB[] instances;

    // database config
    public static String databaseURL = "jdbc:mysql://root:root@localhost/my_schema";
    private Connection connection;

    private SingletonPoolDB() {}

    private static void createPool() {
        //signing SingletonPoolDB
        instances = new SingletonPoolDB[maxInstances];

        // instantiating
        for (int i = 0; i < maxInstances; i++) {
            instances[i] = new SingletonPoolDB();
        }
    }

    public static SingletonPoolDB getInstance() throws SQLException {
        // if singleton was initialized
        if (instances == null) {
            createPool();
        }

        // getting next instance
        currentInstance = (currentInstance + 1) % maxInstances;
        SingletonPoolDB instance = instances[currentInstance];

        // connecting to database
        instance.connect();

        return instance;
    }

    public void connect() throws SQLException {
        // connecting if connection doesn't exists or is closed
        if (this.connection == null || this.connection.isClosed()) {
            this.connection = DriverManager.getConnection(databaseURL);
        }
    }

    public void close() throws SQLException {
        // closing if connection exists and is opened.
        if (this.connection == null || this.connection.isClosed()) {
            throw new SQLException("Database not connected yet");
        }
        this.connection.close();
    }

    public void doSomethingInDataBase() {
        System.out.println("Something has been done in database by " + this + ". eg. CRUD");
    }
}
