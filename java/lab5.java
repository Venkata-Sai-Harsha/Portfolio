/*import java.util.Scanner;
class Rectangle{
    int l;
    int b;
    Rectangle(int length,int breadth){
        this.l=length;
        this.b=breadth;
    }
    public int getArea(){
        return l*b;
    }
    public int getPerimeter(){
        return 2*(l+b);
    }
}
class Square extends Rectangle{
    int side;
    Square(int side){
        super(side,side);
        this.side=side;
    }
}
public class lab5{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the length of rectangle : ");
        int length=sc.nextInt();
        System.out.print("Enter the breadth if rectangle : ");
        int breadth=sc.nextInt();
        Rectangle r=new Rectangle(length,breadth);
        System.out.println("Area of Rectangle : "+r.getArea());
        System.out.println("Perimeter of Rectangle : "+r.getPerimeter());
        System.out.print("Enter the side of square : ");
        int side=sc.nextInt();
        Square s=new Square(side);
        System.out.println("Area of Square : "+s.getArea());
        System.out.println("Perimeter of Square : "+s.getPerimeter());
    }
}*/

/*import java.util.*;
abstract class Marks {
    public abstract float getPercentage();
}
class A extends Marks{
    float percentage;
    A(int x,int y,int z){
        percentage=(x+y+z)/3;
    }
    public float getPercentage(){
        return percentage;
    }
}
class B extends Marks{
    float percentage;
    B(int w,int x,int y,int z){
        percentage=(w+x+y+z)/4;
    }
    public float getPercentage(){
        return percentage;
    }
}
public class lab5 {
    public static void main(String args[]){
        int s1m1,s1m2,s1m3,s2m1,s2m2,s2m3,s2m4;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the marks of subject 1 : ");
        s1m1= sc.nextInt();
        System.out.print("Enter the marks of subject 2 : ");
        s1m2= sc.nextInt();
        System.out.print("Enter the marks of subject 3 : ");
        s1m3= sc.nextInt();
        Marks s1 = new A(s1m1,s1m2,s1m3);
        System.out.println("The percentage of Student 1 is : "+s1.getPercentage());
        System.out.print("Enter the marks of subject 1 : ");
        s2m1= sc.nextInt();
        System.out.print("Enter the marks of subject 2 : ");
        s2m2= sc.nextInt();
        System.out.print("Enter the marks of subject 3 : ");
        s2m3= sc.nextInt();
        System.out.print("Enter the marks of subject 3 : ");
        s2m4= sc.nextInt();
        Marks s2=new B(s2m1,s2m2,s2m3,s2m4);
        System.out.println("The percentage of Student 1 is : "+s2.getPercentage());
    }
}*/

/*import java.util.*;
abstract class Shape{
    abstract float RectangleArea(float length,float breadth);
    abstract float SquareArea(float length);
    abstract double CircleArea(float radius);
}
class Area extends Shape{
    float RectangleArea(float length, float breadth) {
        return length*breadth;
    }
    float SquareArea(float side){
        return side*side;
    }
    double CircleArea(float radius){
        double area=3.14*radius*radius;
        return area;
    }
}
public class lab5 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the length of rectangle : ");
        float length=sc.nextFloat();
        System.out.print("Enter the breadth of rectangle : ");
        float breadth=sc.nextFloat();
        Shape a=new Area();
        System.out.println("Area of Rectangle : "+a.RectangleArea(length,breadth));
        System.out.print("Enter the side of square : ");
        float side=sc.nextFloat();
        System.out.println("Area of Square : "+a.SquareArea(side));
        System.out.print("Enter the radius of circle : ");
        float radius=sc.nextFloat();
        System.out.println("Area of Circle : "+a.CircleArea(radius));
    }
}*/

/*interface Polygon {
	void getArea(int a,int b);

}
class Rectangle implements Polygon{
	int l;
	int b;
	public int getLength() {
		return l;
	}
	public void setLength(int length) {
		this.l = length;
	}
	public int getBreadth() {
		return b;
	}
	public void setBreadth(int breadth) {
		this.b = breadth;
	}
	
	public void getArea(int l,int b)
	{
		System.out.println("area : "+(l*b));
	}
}
class lab5 {
	public static void main(String[] args) {
	    Rectangle r1=new Rectangle();
		r1.setBreadth(5);
		r1.setLength(4);
		r1.getArea(r1.getBreadth(), r1.getLength());
	}
}*/

interface Instrument{
	void play();
	String what();
	void adjust();
}
 class Wind implements Instrument{
	public void play() {
		System.out.println("Playing Wind Instruments");
	}
	public String what() {
		return "Wind Instruments";
	}
	public void adjust() {
		System.out.println("Adjusting Wind Instruments");
	}
}
 class Percussion implements Instrument{
	public void play() {
		System.out.println("Playing Percussion Instruments");
	}
	public String what() {
		return "Percussion Instruments";
	}
	public void adjust() {
		System.out.println("Adjusting Percussion Instruments");
	}
}
class Stringed implements Instrument{
	public void play() {
		System.out.println("Playing Stringed Instruments");
	}
	public String what() {
		return "Stringed Instruments";
	}
	public void adjust() {
		System.out.println("Adjusting Stringed Instruments");
	}
}
class WoodWind extends Wind{
	public void play() {
		System.out.println("Paying Woodwind");
	}
	public  String what() {
		return "Woddwind";
	}
}
class Brass extends Wind{
	public void play() {
		System.out.println("Playing Brass");
	}
	public  String what() {
		return "Brass";
	}
}
public class lab5{
	public static void main(String[] args) {

		Wind w1 = new Wind();
		w1.play();
		System.out.print(w1.what() + "\n");
		w1.adjust();

		System.out.println();

		Percussion p1 = new Percussion();
		p1.play();
		System.out.println(p1.what());
		p1.adjust();

		System.out.println();

		Stringed s1 = new Stringed();
		s1.play();
		System.out.println(s1.what());
		s1.adjust();

		System.out.println();

		WoodWind ww1 = new WoodWind();
		ww1.play();
		System.out.println(ww1.what());
		ww1.adjust();

		System.out.println();

		Brass b1 = new Brass();
		b1.play();
		System.out.println(b1.what());
		b1.adjust();

		System.out.println();
	}
}



