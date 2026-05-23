package lab10;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class q6 extends JFrame implements ActionListener {
    private JTextField text;
    private JButton b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15,b16;

    public q6(){
        text=new JTextField("0",30);
        b1=new JButton("7");    
        b2=new JButton("8");    
        b3=new JButton("9");    
        b4=new JButton("+");    
        b5=new JButton("4");    
        b6=new JButton("5");    
        b7=new JButton("6");    
        b8=new JButton("-");    
        b9=new JButton("1");
        b10=new JButton("2");
        b11=new JButton("3");
        b12=new JButton("*");
        b13=new JButton("c");
        b14=new JButton("0");
        b15=new JButton("=");
        b16=new JButton("/");

        JPanel panel =new JPanel();
        panel.add(text);
        panel.add(b1);panel.add(b2);panel.add(b3);panel.add(b4);
        panel.add(b5);panel.add(b6);panel.add(b7);panel.add(b8);
        panel.add(b9);panel.add(b10);panel.add(b11);panel.add(b12);
        panel.add(b13);panel.add(b14);panel.add(b15);panel.add(b16);
        
        panel.setLayout(new GridLayout(5,4));
        

        setLayout(new BorderLayout());
        add(panel, BorderLayout.CENTER);
        setSize(300,300);
        setTitle("Swing simple calculator");
        //setLayout(null);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
    
    }
    public static void main(String[] args) {
        new q6();
    }

}
