package exercise_four;

import final_exercise.IFile;
import rectangle.ColorRectangle;

import java.io.*;
import java.util.*;

public class RectangleCollection implements IFile {
    private Set<ColorRectangle> rectangles = new TreeSet<>();
    private String inputFileName = "default_input.txt";
    private String outputFileName = "default_output.txt";

    public RectangleCollection(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName;
        this.outputFileName = outputFileName;
        this.load();
    }

    public void add(ColorRectangle rectangle) {
        this.rectangles.add(rectangle);
    }

    public int calcAreaSum() {
        int sum = 0;

        for (ColorRectangle rectangle : this.rectangles) {
            sum += rectangle.calcArea();
        }

        return sum;
    }

    public int calcParamSum() {
        int sum = 0;

        for (ColorRectangle rectangle : this.rectangles) {
            sum += rectangle.calcParamSum();
        }

        return sum;
    }

    public boolean contains(ColorRectangle rectangle) {
        return this.rectangles.contains(rectangle);
    }

    public ColorRectangle getMax() {
        ColorRectangle currentRectangle;
        var iterator = this.rectangles.iterator();
        ColorRectangle maxRectangle = iterator.next();

        while (iterator.hasNext()) {
            currentRectangle = iterator.next();

            if (currentRectangle.calcArea() > maxRectangle.calcArea()) {
                maxRectangle = currentRectangle;
            }
        }

        return maxRectangle;
    }

    public ColorRectangle getMinArea() {
        ColorRectangle currentRectangle;
        var iterator = this.rectangles.iterator();
        ColorRectangle minRectangle = iterator.next();

        while (iterator.hasNext()) {
            currentRectangle = iterator.next();

            if (currentRectangle.calcArea() < minRectangle.calcArea()) {
                minRectangle = currentRectangle;
            }
        }

        return minRectangle;
    }

    public int getSize() {
        return this.rectangles.size();
    }

    // Returns true if one of the rectangles is overlaped by atleast one of the other rectangles, but one is the minimum.
    // A rectangle being overlaped by two or more rectangles as minimum, returns false.
    public int getOverlappingCount() {
        int overlappingCount = 0;

        for (ColorRectangle currentRectangle : this.rectangles) {
            for (ColorRectangle secondRectangle : this.rectangles) {
                if (currentRectangle == secondRectangle) {
                    continue;
                }

                if (currentRectangle.isInside(secondRectangle)) {
                    overlappingCount++;
                    break;
                }
            }
        }

        return overlappingCount;
    }

    public List<ColorRectangle> getReversedList() {
        List<ColorRectangle> list = new ArrayList<>(this.rectangles);
        Collections.reverse(list);

        return list;
    }

    public ColorRectangle intersect() {
        ColorRectangle base = this.rectangles.iterator().next();

        for (int i = 1; i < this.rectangles.size(); i++) {
            base = base.intersectionRect(this.rectangles.iterator().next());
        }

        return base;
    }

    public ColorRectangle union() {
        ColorRectangle base = new ColorRectangle();

        for (ColorRectangle rec : this.rectangles) {
            base = base.unionRect(rec);
        }

        return base;
    }

    /*public void changeRectangleByIndex(int index, ColorRectangle rectangle) {
        this.rectangles.set(index, rectangle);
    }*/

    public String toString() {
        StringBuilder sb = new StringBuilder();

        for (ColorRectangle rec : this.rectangles) {
            sb.append(rec.toString()).append(System.lineSeparator());
        }

        return sb.toString();
    }

    @Override
    public void load() {
        try {
            Scanner scanner = new Scanner(new File(this.inputFileName));

            while (scanner.hasNext()) {
                this.rectangles.add(new ColorRectangle(
                        scanner.nextInt(),
                        scanner.nextInt(),
                        scanner.nextInt(),
                        scanner.nextInt(),
                        scanner.nextLong()));
            }

            scanner.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    @Override
    public boolean remove() {
        if (this.rectangles.isEmpty()) {
            return false;
        }

        this.rectangles.clear();
        return true;
    }

    @Override
    public boolean removeFile() {

        try {
            RandomAccessFile file = new RandomAccessFile(this.outputFileName, "rw");
            file.setLength(0);
            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return false;
    }

    @Override
    public void save() {
        try {
            FileWriter writer = new FileWriter(this.outputFileName);
            writer.write(this.toString());
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
