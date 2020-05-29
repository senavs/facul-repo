public class Main {

    public static void main(String[] args) {
        Duck duck01 = new Duck(new SimpleQuackBehavior(), new SimpleFlyBehavior());
        Duck duck02 = new Duck(new NoQuackBehavior(), new NoFlyBehavior());

        duck01.fly();
        duck01.quack();

        duck02.fly();
        duck02.quack();
    }

}
