public class Duck {

    private Behavior quackBehavior;
    private Behavior flyBehavior;

    public Duck(Behavior quackBehavior, Behavior flyBehavior) {
        this.quackBehavior = quackBehavior;
        this.flyBehavior = flyBehavior;
    }

    public void quack() {
        this.quackBehavior.execute();
    }

    public void fly() {
        this.flyBehavior.execute();
    }
}
