//1
/*import java.util.Scanner; 
class Person
{ 
    private String Employee_name; 
    private int Employee_age; 
    Person(String name,int age) 
    { 
        this.Employee_name=name; 
        this.Employee_age=age; 
    } 
    String tostring() 
    { 
        return "Employee_Name: " + Employee_name + "\n" + "Employee_Age: "+ Employee_age + "\n"; 
    } 
} 
class Employee extends Person
{ 
    private int empid; 
    private double hourlypay; 
    public Employee(String Employee_name,int Employee_age,int eid,double hpay) 
    { 
        super(Employee_name,Employee_age); 
        empid=eid; 
        hourlypay=hpay; 
    } 
    int getId() 
    { 
        return empid; 
    } 
    double getHourlyPay() 
    { 
        return hourlypay; 
    } 
    void setId(int id) 
    { 
        empid=id; 
    } 
    void sethourpay(int hp) 
    { 
        hourlypay=hp; 
    } 
    double getRaise() 
    { 
        hourlypay=hourlypay+((hourlypay*15)/100); 
        return hourlypay; 
    } 
    double payday(int h) 
    { 
        int x; 
        double total_pay; 
        if(h>40) 
        { 
            x = h-40; 
            total_pay = (40*hourlypay)+((1.5)*(x)*hourlypay); 
        } 
        else
        { 
            total_pay = 40*hourlypay; 
        } 
        return total_pay; 
    } 
    String tostring() 
    { 
        return super.tostring() + "They make: " + hourlypay + "\n" + "They have the employee ID: "+empid; 
    } 
} 
public class lab4 
{ 
    public static void main(String[] args) 
    { 
        Scanner scan = new Scanner(System.in); 
        String n; 
        int a; 
        int e; 
        double hpay; 
        System.out.print("Enter Employee_Name: "); 
        n=scan.next(); 
        System.out.print("Enter Employee_Age: "); 
        a=scan.nextInt(); 
        System.out.print("Enter Empid: "); 
        e=scan.nextInt(); 
        System.out.print("Enter Hpay: "); 
        hpay=scan.nextDouble(); 
        Employee emp = new Employee(n,a,e,hpay); 
 
        System.out.print("Getraise :" + emp.getRaise()); 
        System.out.println(); 
        int h; 
        System.out.print("Enter no hrs: "); 
        h=scan.nextInt(); 
        System.out.println("Payday :" + emp.payday(h) + "\n"); 
        System.out.println(emp.tostring()); 
        scan.close(); 
    } 
}*/

//2
/*import java.util.Scanner; 
class Rectangle
{ 
    float length,breadth; 
    Rectangle(float l, float b) 
    { 
        length=l; 
        breadth=b; 
    } 
    void R_area() 
    { 
        float a = length*breadth; 
        System.out.println("Rectangle area : "+ a); 
    } 
    void R_perimeter() 
    { 
        float p = 2*(length+breadth); 
        System.out.println("Rectangle perimeter : "+ p); 
    } 
} 
class Square extends Rectangle
{ 
    int side; 
    Square(float length,float breadth, int s) 
    { 
        super(length,breadth); 
        side=s; 
    } 
    void S_area() 
    { 
        float a = side*side; 
        System.out.println("Square area : "+ a); 
    } 
    void S_perimeter() 
    { 
        float p = 4*side; 
        System.out.println("Square perimeter : "+ p); 
    } 
} 
public class lab4 
{ 
    public static void main(String[] args) 
    { 
        float l,b; 
        int s; 
        Scanner scan = new Scanner(System.in); 
        System.out.print("Enter length: "); 
        l=scan.nextFloat(); 
        System.out.print("Enter breadth: "); 
        b=scan.nextFloat(); 
        System.out.print("Enter side: "); 
        s=scan.nextInt(); 
        System.out.println(); 
        Square x = new Square(l,b,s); 
        x.R_area(); 
        x.R_perimeter(); 
        System.out.println(); 
        x.S_area(); 
        x.S_perimeter(); 
        scan.close(); 
    } 
}*/

//3
/*class complex
{ 
    private float real; 
    private float img; 
    complex(float r, float i) 
    { 
        real=r; 
        img=i; 
    } 
    complex() 
    { 
        real=1; 
        img=1; 
    } 
    public void add(complex c1, complex c2) 
    { 
        float x,y; 
        x=c1.real+c2.real; 
        y=c1.img+c2.img; 
        System.out.println("complex num: " + x + " + " + y +"i"); 
    } 
    public void sub(complex c1, complex c2) 
    { 
        float x,y; 
        x=c1.real-c2.real; 
        y=c1.img-c2.img; 
        System.out.println("complex num: " + x + " + " + y +"i"); 
    } 
} 

public class lab4
{ 
    public static void main(String[] args) 
    { 
        complex c1 = new complex(1,2); 
        complex c2 = new complex(3,4); 
 
        complex c3 = new complex(); 
        complex c4 = new complex(); 
        complex c = new complex(); 
        System.out.println("Values passed thourgh constructor: "); 
        c.add(c1,c2); 
        c.sub(c1,c2); 
        System.out.println("Values not passed thourgh constructor: "); 
        c.add(c3,c4); 
        c.sub(c3,c4); 
    } 
}*/

//4
import java.util.Scanner; 
class PurchaseProduct
{ 
    private String name; 
    private double unitprice; 
    PurchaseProduct() 
    { 
        this.name="no product"; 
        this.unitprice=0.0; 
    } 
    PurchaseProduct(String name,double unitprice) 
    { 
        this.name=name; 
       this.unitprice=unitprice; 
    } 
    public void setname(String name) 
    { 
        this.name=name; 
    } 
    public String getname() 
    { 
        return name; 
    } 
    public void setunitprice(double unitp) 
    { 
        unitprice=unitp; 
    } 
    public double getPrice() 
    { 
        return unitprice; 
    } 
    String tostring() 
    { 
        return name + " @ " + unitprice; 
    } 
} 
class Weighedproduct extends PurchaseProduct
{ 
    double weight; 
    Weighedproduct(String name, double unitprice, double w) 
    { 
        super(name,unitprice); 
        weight=w; 
    } 
    String tostring() 
    { 
        return super.tostring() + ", weight: " + weight +" kg, " ; 
    } 
} 
class Counterproduct extends PurchaseProduct
{ 
    private int quantity; 
    Counterproduct(String name, double unitprice, double weight, int q) 
    { 
        super(name,unitprice); 
        quantity = q; 
    } 
    public double getPrice() 
    { 
        double x; 
        x=super.getPrice()*quantity; 
        return x; 
    } 
    String tostring() 
    { 
        return "Quntity: "+ quantity + ", TotalPrice: " + getPrice()+ " Rs"; 
    } 
} 
public class lab4 
{ 
    public static void main(String[] args) 
    { 
        Scanner scan = new Scanner(System.in); 
        String name; 
        int q; 
        double up,w; 
        System.out.print("Enter Item Name: "); 
        name=scan.next(); 
        System.out.print("Enter UnitPrice: "); 
        up=scan.nextDouble(); 
        System.out.print("Enter Weight: "); 
        w=scan.nextDouble(); 
        System.out.print("Enter Quantity: "); 
        q=scan.nextInt(); 
        Weighedproduct a = new Weighedproduct(name,up,w); 
        Counterproduct b = new Counterproduct(name,up,w,q); 
        System.out.println("\nTotalPrice: "+ b.getPrice()); 
        System.out.print("Bill Recipt: "+ a.tostring()); 
        System.out.print(" "+b.tostring() + "\n\n"); 
 
        scan.close(); 
    } 
}