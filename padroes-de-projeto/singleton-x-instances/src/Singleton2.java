import java.util.Random;

public class Singleton2 {

    private static Singleton2[] instances = {new Singleton2(), new Singleton2()};
    private static Random rand = new Random();

    private Singleton2() {
    }

    public static Singleton2 getInstance() {
        int n = rand.nextInt(instances.length);
        return instances[n];
    }
}
