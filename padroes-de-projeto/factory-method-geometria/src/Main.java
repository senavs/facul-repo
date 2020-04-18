public class Main {

    public static void main(String[] args) {
        Tangram tangram = new Tangram();

        GeometricForm triangle = tangram.createGeometricForm(3, 4, 5);
        System.out.println(triangle);
        System.out.println(triangle.getType());

        GeometricForm square = tangram.createGeometricForm(4, 4, 4, 4);
        System.out.println(square);
    }
}
