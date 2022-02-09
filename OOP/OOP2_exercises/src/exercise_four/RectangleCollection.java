package exercise_four;

import rectangle.Color;
import rectangle.ColorRectangle;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class RectangleCollection {
    private List<ColorRectangle> rectangles = new ArrayList<>();

    RectangleCollection(String fileName) {
        try {
            RandomAccessFile random = new RandomAccessFile(fileName, "r");
            String strLine;

            while((strLine = random.readLine()) != null && (strLine.length() > 0)) {

                String[] strArr = strLine.split(" ");
                ColorRectangle rectangle = new ColorRectangle(
                        Integer.parseInt(strArr[0]),
                        Integer.parseInt(strArr[1]),
                        Integer.parseInt(strArr[2]),
                        Integer.parseInt(strArr[3]),
                        Long.parseLong(strArr[4]));

                this.rectangles.add(rectangle);
            }
        } catch (FileNotFoundException e){
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public void add(ColorRectangle rectangle) {
        this.rectangles.add(rectangle);
    }

    public void sort() {
        Collections.sort(this.rectangles);
    }

    public int getAreaSum() {
        int sum = 0;

        for (ColorRectangle rectangle : this.rectangles) {
            sum += rectangle.calcArea();
        }

        return sum;
    }

    public ColorRectangle unioun() {
        ColorRectangle base = new ColorRectangle();

        for (ColorRectangle rec : this.rectangles) {
            base = base.unionRect(rec);
        }

        return base;
    }

    public ColorRectangle intersect() {
        ColorRectangle base = this.rectangles.get(0);

        for (int i = 1; i < this.rectangles.size(); i++) {
            base = base.intersectionRect(this.rectangles.get(i));
        }

        return base;
    }

    public int getParamSum() {
        int sum = 0;

        for (ColorRectangle rectangle : this.rectangles) {
            sum += rectangle.calcParamSum();
        }

        return sum;
    }

    public void changeRectangleByIndex(int index, ColorRectangle rectangle) {
        this.rectangles.set(index, rectangle);
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();

        for (ColorRectangle rec : this.rectangles) {
            sb.append(rec.toString());
        }

        return sb.toString();
    }
}
