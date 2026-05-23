package lab10;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class q4 extends JFrame implements ActionListener {
    private JLabel label;
    private JTextField text;
    private JButton button,button2,button3;
    private int count;

    public q4(){
        count=0;
        label= new JLabel("Counter");
        text=new JTextField("0",5);
        button= new JButton("Count Up");
        button2= new JButton("Count Down");
        button3= new JButton("Reset");

        button.addActionListener(this);
        button2.addActionListener(this);
        button3.addActionListener(this);

        JPanel panel = new JPanel();
        panel.add(label);
        panel.add(text);
        panel.add(button);
        panel.add(button2);
        panel.add(button3);
        
        add(panel, BorderLayout.CENTER);

        setSize(450,250);
        setTitle("Swing Counter Buttons");
        //setLayout(new FlowLayout());
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == button) {
            count++;
            text.setText(Integer.toString(count));
         } 
         else if (e.getSource() == button2) {
            count--;
            text.setText(String.valueOf(count));
         } 
         else if (e.getSource() == button3) {
            count = 0;
            text.setText(String.valueOf(count));
         }
    } 

    public static void main(String[] args) {
        new q4();
    }
}