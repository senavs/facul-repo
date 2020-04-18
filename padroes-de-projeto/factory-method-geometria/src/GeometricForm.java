// Product
public abstract class GeometricForm {

    private float[] sides;

    public GeometricForm(float... sides) {
        for (float side: sides) {
            if (side <= 0) {
                throw new RuntimeException("Cannot create a GeometricForm with zero or negative sides");
            }
        }
        this.sides = sides;
    }

    abstract public String getType();

    public String toString() {
        StringBuilder sidesString = new StringBuilder();
        for (float side: this.sides) {
            sidesString.append(" ").append(side);
        }
        return this.getClass().getName() + " :" + sidesString;
    }

}
