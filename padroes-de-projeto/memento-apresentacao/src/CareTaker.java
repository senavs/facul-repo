class Caretaker {
    private Memento[] mementos = new Memento[32];
    private int nextMemento = 0;

    public Caretaker() {
    }

    public void addMemento(Memento memento) {
        this.mementos[this.nextMemento] = memento;
        this.nextMemento++;
    }

    public Memento getMemento() {
        if (this.nextMemento > 0) {
            this.nextMemento--;
        }
        return this.mementos[this.nextMemento - 1];
    }
}