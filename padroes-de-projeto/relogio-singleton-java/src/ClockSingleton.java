public class ClockSingleton {
    private static DateTime instance = null;

    private ClockSingleton() {
    }

    public static DateTime getInstance() {
        if (instance == null) {
            instance = new DateTime();
        }
        return instance;
    }
}
