public class Main {
    public static void main(String[] args) {
        Date date = new Date(29, 2, 2000);
        Time time = new Time(18, 8, 35);
        DateTime datetime = new DateTime();
        DateTime clock;

        System.out.println(date);
        System.out.println(time);
        System.out.println(datetime.getDate());
        System.out.println(datetime.getTime());
        System.out.println(datetime);

        for (int i = 0; i < 10000; i++) {
            clock = ClockSingleton.getInstance();
            System.out.println(clock);
        }
    }
}
