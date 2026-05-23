/*import java.util.*;

public class hello {
    static int add(int []x)
    {
        for(int i=0;i<(x.length)/2;i++)
        {
            System.out.print(x[i]+x[x.length-i-1]+" ");
        }
        if(x.length%2==1)
        {
            System.out.println(x[(x.length)/2]+" ");
        }
        return 0;
    }
    public static void main(String[] args)
    {
        Scanner Sc = new Scanner(System.in);
        int a=Sc.nextInt();
        int b;
        int [] x=new int[a];
        for(int i=0;i<a;i++)
        {
           x[i]=Sc.nextInt();
        }
        add(x);
    }
}*/


/*import java.util.Scanner;

public class hello {
    static int sum(int []x){
        int s=0;
        for(int i=0;i<x.length;i++){
            s=s+x[i];
        }
        System.out.println(s);
        return 0;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int [] x=new int[a];
        for(int i=0;i<a;i++)
        {
            x[i]=sc.nextInt();
        }
        sum(x);
    }
}
*/

import javax.swing.*;  
import java.awt.event.*;  
public class hello extends JFrame implements ActionListener{  
    JLabel l;  
    JCheckBox cb1,cb2,cb3;  
    JButton b;  
    hello(){  
        l=new JLabel("Food Ordering System");  
        l.setBounds(50,50,300,20);  
        cb1=new JCheckBox("Pizza @ 100");  
        cb1.setBounds(100,100,150,20);  
        cb2=new JCheckBox("Burger @ 30");  
        cb2.setBounds(100,150,150,20);  
        cb3=new JCheckBox("Tea @ 10");  
        cb3.setBounds(100,200,150,20);  
        b=new JButton("Order");  
        b.setBounds(100,250,80,30);  
        b.addActionListener(this);  
        add(l);add(cb1);add(cb2);add(cb3);add(b);  
        setSize(400,400);  
        setLayout(null);  
        setVisible(true);  
        setDefaultCloseOperation(EXIT_ON_CLOSE);  
    }  
    public void actionPerformed(ActionEvent e){  
        float amount=0;  
        String msg="";  
        if(cb1.isSelected()){  
            amount+=100;  
            msg="Pizza: 100\n";  
        }  
        if(cb2.isSelected()){  
            amount+=30;  
            msg+="Burger: 30\n";  
        }  
        if(cb3.isSelected()){  
            amount+=10;  
            msg+="Tea: 10\n";  
        }  
        msg+="-----------------\n";  
        JOptionPane.showMessageDialog(this,msg+"Total: "+amount);  
    }  
    public static void main(String[] args) {  
        new hello();  
    }  
}  