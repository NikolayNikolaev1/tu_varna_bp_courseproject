package rectangle;

public class Color {
    private long red;
    private long green;
    private long blue;
    private long color;

    public Color() {

    }

    public Color(long color) {
        this.color = color;
        this.getRGB();
    }

    private void getRGB() {
        /*this.red = this.color >>> 16;
        this.green = this.color >> 8 & 255;
        this.blue = this.color & 255;*/

        this.blue = this.color % 256;
        this.green = (this.color / 256) % 256;
        this.red = ((this.color / 256) / 256) % 256;
    }

    private long getRed() {
        return this.red;
    }

    private long getGreen() {
        return this.green;
    }

    private long getBlue() {
        return this.blue;
    }

    private void setRed(long red) {
        this.red = red;
    }

    private void setGreen(long green) {
        this.green = green;
    }

    private void setBlue(long blue) {
        this.blue = blue;
    }


    public static void main(String[] args) {
        Color c = new Color(134425);

        System.out.println(c.red + " " + c.green + " " + c.blue);
    }
}
