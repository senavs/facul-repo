// Concrete Creator
public class Tangram implements GeometricFormMaker {

    @Override
    public GeometricForm createGeometricForm(float... sides) {
        if (sides.length == 3) {
            return new Triangle(sides[0], sides[1], sides[2]);
        }
        throw new RuntimeException("Cannot create a geometric form with " + sides.length + " sides, yet.");
    }
}
