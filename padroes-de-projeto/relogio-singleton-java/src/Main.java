public class Main {
    public static void main(String[] args) {
        Date date = new Date(29, 2, 2000);
        Time time = new Time(18, 8, 35);
        DateTimeSingleton singleton;

        System.out.println(date);
        System.out.println(time);

        for (int i = 0; i < 10; i++) {
            singleton = DateTimeSingleton.getInstance();
            System.out.println(singleton + " " + singleton.hashCode());
        }
    }
}
