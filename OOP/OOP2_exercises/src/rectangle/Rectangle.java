package rectangle;

import org.w3c.dom.css.Rect;

public class Rectangle {
    private int iX1;
    private int iY1;
    private int iX2;
    private int iY2;

    public Rectangle() {

    }

    public Rectangle (int x1, int y1, int x2, int y2) {
        this.setIX1(x1);
        this.setIY1(y1);
        this.setIX2(x2);
        this.setIY2(y2);
    }

    private int getIX1() {
        return this.iX1;
    }

    private int getIY1() {
        return this.iY1;
    }

    private int getIX2() {
        return this.iX2;
    }

    private int getIY2() {
        return this.iY2;
    }

    private void setIX1(int x1) {
        this.iX1 = x1;
    }

    private void setIY1(int y1) {
        this.iY1 = y1;
    }

    private void setIX2(int x2) {
        this.iX2 = x2;
    }

    private void setIY2(int y2) {
        this.iY2 = y2;
    }

    public int area() {
        return Math.abs((this.iX2 - this.iX1) * (this.iY2 - this.iY1));
    }

    public int compareTo(Rectangle rectangle) {
        return Integer.compare(this.area(), rectangle.area());
    }

    public boolean equals(Rectangle rectangle) {
        return this.compareTo(rectangle) == 0;
    }

    public void translateX(int iPoints) {
        this.iX1 += iPoints;
        this.iX2 += iPoints;
    }

    public void translateY(int iPoints) {
        this.iY1 += iPoints;
        this.iY2 += iPoints;
    }

    public void translateXY(int iPoints) {
        this.translateX(iPoints);
        this.translateY(iPoints);
    }

    public boolean isInside(int ptX, int ptY) {
        return this.iX1 <= ptX && this.iX2 >= ptX &&
                this.iY1 <= ptY && this.iY2 >= ptY;
    }

    public Rectangle unionRect(Rectangle r) {
        return new Rectangle(Math.min(this.iX1, r.iX1), Math.min(this.iY1, r.iY1), Math.max(this.iX2, r.iX2), Math.max(this.iY2, r.iY2));
    }

    public static void main(String[] args) {
        System.out.println("Hello world");
    }
}