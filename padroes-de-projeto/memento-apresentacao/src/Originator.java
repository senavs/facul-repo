class Originator {
    private String state = "";

    public String getState() {
        return this.state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public Memento save() {
        return new Memento(this.state);
    }

    public void restore(Memento memento) {
        this.state = memento.getState();
    }
}