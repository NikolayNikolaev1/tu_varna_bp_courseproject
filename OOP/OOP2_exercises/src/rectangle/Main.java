package rectangle;


import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import  java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        boolean[] boolArr = new boolean[2];
        byte[] byteArr = new byte[2];
        char[] charArr = new char[2];
        short[] shortArr = new short[2];
        int[] intArr = new int[2];
        long[] longArr = new long[2];
        float[] floatArr = new float[2];
        double[] doubleArr = new double[2];
        String[] strArr = new String[2];


        Arrays.fill(charArr,'a');
        Arrays.fill(shortArr, (short)1);
        Arrays.fill(intArr,1);
        Arrays.fill(longArr, 100L);
        Arrays.fill(doubleArr,0.5);
        Arrays.fill(floatArr,0.1f);
        Arrays.fill(strArr,"a");

        Arrays.fill(boolArr,true);
        Arrays.fill(byteArr, (byte)1);

        byte[] secondArr = {
            10, 12, 33, 4, 5
        };

        //Arrays.sort(secondArr);
        //System.out.println(Arrays.toString(secondArr));

       /* Color[] colors = new Color[2];;
        colors[1] = new Color(500);
        colors[0] = new Color(100);

        ColorRectangle[] rectangles = new ColorRectangle[2];
        rectangles[0] = new ColorRectangle(10, 20, 20, 30, 100);
        rectangles[1] = new ColorRectangle(1, 5, 3, 7, 10);

        Arrays.sort(rectangles);
        System.out.println(Arrays.toString(rectangles));*/

        RectangleArray recArr = new RectangleArray("test");
        System.out.println(recArr.toString());
    }
}

class RectangleArray {
    private ColorRectangle[] rectangles;

    RectangleArray(String fileName) {
        this.rectangles = new ColorRectangle[10];

        try {
            RandomAccessFile random = new RandomAccessFile(fileName, "r");
            String output;
            int counter = 0;

            while((output = random.readLine()) != null) {
                if (counter >= 10 || output.isEmpty()) {
                    break;
                }

                String[] strArr = output.split(" ");
                ColorRectangle rectangle = new ColorRectangle(
                                Integer.parseInt(strArr[0]),
                                Integer.parseInt(strArr[1]),
                                Integer.parseInt(strArr[2]),
                                Integer.parseInt(strArr[3]),
                                Long.parseLong(strArr[4]));

                this.rectangles[counter++] = rectangle;
            }
        } catch (FileNotFoundException e){
            System.out.println(e.getMessage());
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    public String toString() {
        return Arrays.toString(this.rectangles);
    }
}
