import javax.swing.*;

// import javax.swing.*;
// import java.awt.*;

// public class hs{
// JFrame f;
//     hs(){
//         // JButton b=new JButton("click");
//         // b.setBounds(130,100 , 100, 40);
//         // add(b);
//         // setSize(400,500);
//         // setLayout(null);
//         // setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//         // setVisible(true);
//         f=new JFrame();
//         JButton b1=new JButton("North");
//         JButton b2=new JButton("S");
//         JButton b3=new JButton("Eorth");
//         JButton b4=new JButton("Worth");
//         JButton b5=new JButton("Corth");

//         f.add(b1,BorderLayout.NORTH);
//         f.add(b2,BorderLayout.SOUTH);
//         f.add(b3,BorderLayout.EAST);
//         f.add(b4,BorderLayout.WEST);
//         f.add(b5,BorderLayout.CENTER);

//         f.setSize(300, 300);
//         f.setVisible(true);
//         f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//     }
//     public static void main(String[] args) {
//         new hs();
//     }
// }


import java.awt.*;       
public class hs{    
JFrame f;    
hs(){    
    f=new JFrame();    
    JButton b1=new JButton("1");    
    JButton b2=new JButton("2");    
    JButton b3=new JButton("3");    
    JButton b4=new JButton("4");    
    JButton b5=new JButton("5");    
    JButton b6=new JButton("6");    
    JButton b7=new JButton("7");    
    JButton b8=new JButton("8");    
    JButton b9=new JButton("9");
    //JButton b0=new JButton("0");
     // adding buttons to the frame       
    f.add(b1); f.add(b2); f.add(b3);  
    f.add(b4); f.add(b5); f.add(b6);  
    f.add(b7); f.add(b8); f.add(b9);    
  
    // setting grid layout of 3 rows and 3 columns    
    f.setLayout(new GridLayout(3,3));    
    f.setSize(300,300);    
    f.setVisible(true);    
}    
public static void main(String[] args) {    
    new hs();    
}    
}    