package final_exercise;

import exercise_four.RectangleCollection;
import rectangle.ColorRectangle;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        RectangleCollection rectangleCollection = new RectangleCollection("rects.txt", "rectsOut.txt");
        ColorRectangle newRectangle = new ColorRectangle(2, 2, 400, 400, 255);
        rectangleCollection.save();
        rectangleCollection.removeFile();

        /*rectangleCollection.add(newRectangle);
        rectangleCollection.save();
        System.out.println("3. Max Rectangle: " + rectangleCollection.getMinArea().toString());
        System.out.println("4. Min Rectangle: " + rectangleCollection.getMax().toString());
        System.out.println("5. Overlapping Rectangles Count: " + rectangleCollection.getOverlappingCount());

        List<ColorRectangle> reverseList = rectangleCollection.getReversedList();
        System.out.println("6 .Reversed List: " + reverseList);

        System.out.println("7. Area Sum: " + rectangleCollection.calcAreaSum());
        System.out.println("8. Params Sum: " + rectangleCollection.calcParamSum());
        System.out.println("9. Collection Size: " + rectangleCollection.getSize());
        System.out.println("11. Contains: " + rectangleCollection.contains(newRectangle));
        System.out.println("12. Union Rectangle: " + rectangleCollection.union().toString());
        rectangleCollection.remove();
        rectangleCollection.load();
        System.out.println("15. " + rectangleCollection.toString());*/
    }
}
