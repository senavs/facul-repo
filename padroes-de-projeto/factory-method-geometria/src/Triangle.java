// Concrete Product
public class Triangle extends GeometricForm {

    private float side1, side2, side3;

    public Triangle(float side1, float side2, float side3) {
        super(side1, side2, side3);

        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;

        // validating triangle
        if (!this.isValid()) {
            throw new RuntimeException("It's not a triangle");
        }
    }

    @Override
    public String getType() {
        if (this.side1 == this.side2 && this.side2 == this.side3) {
            return "equilateral";
        } else if (this.side1 == this.side2 || this.side1 == this.side3) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }

    public boolean isValid() {
        return !(this.side1 >= this.side2 + this.side3 || this.side2 >= this.side1 + this.side3 || this.side3 >= this.side1 + this.side2);
    }

    public static boolean isValid(float side1, float side2, float side3) {
        return !(side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2);
    }
}
