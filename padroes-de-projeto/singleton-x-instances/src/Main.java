public class Main {

    public static void main(String[] args) {

        System.out.println("\nSingles 1 instance");
        for (int i = 0; i < 10; i++) {

            Singleton1 singleton1instance = Singleton1.getInstance();
            System.out.println(singleton1instance);
        }

        System.out.println("\nSingles 2 instance");
        for (int i = 0; i < 10; i++) {

            Singleton2 singleton2instance = Singleton2.getInstance();
            System.out.println(singleton2instance);
        }

    }
}
