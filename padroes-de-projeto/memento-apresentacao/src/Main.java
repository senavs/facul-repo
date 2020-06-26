public class Main {

    public static void main(String[] args) {
        Caretaker backup = new Caretaker();
        Originator keyboard = new Originator();

        // typing and saving 1
        keyboard.setState("state 1");
        backup.addMemento(keyboard.save());
        System.out.println(keyboard.getState());  // current state

        // typing and saving 2
        keyboard.setState("state 2");
        backup.addMemento(keyboard.save());
        System.out.println(keyboard.getState());  // current state

        // typing and saving 3
        keyboard.setState("state 3");
        backup.addMemento(keyboard.save());
        System.out.println(keyboard.getState());  // current state

        // restoring
        keyboard.restore(backup.getMemento());
        System.out.println(keyboard.getState());  // current state 2
        keyboard.restore(backup.getMemento());
        System.out.println(keyboard.getState());  // current state 1
    }
}
