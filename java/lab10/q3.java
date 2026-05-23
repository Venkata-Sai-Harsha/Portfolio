package lab10;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class q3 extends JFrame implements ActionListener {
    private JLabel label,label1;
    private JTextField text,text1;
    private JButton button;
    private int n;

    public q3(){
        n=1;
        label= new JLabel("Counter");
        text=new JTextField("1",5);
        label1=new JLabel("factorial(n)");
        text1=new JTextField("1",6);
        button= new JButton("Next");
        button.addActionListener(this);

        JPanel panel = new JPanel();
        panel.add(label);
        panel.add(text);
        panel.add(label1);
        panel.add(text1);
        panel.add(button);

        this.add(panel, BorderLayout.CENTER);

        setSize(375,250);
        setTitle("Swing Factorial");
        setLayout(new FlowLayout());
        //setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        n++;
        int factorial = 1;
        for (int i = 2; i <= n; i++) {
            factorial *= i;
        }
        text.setText(String.valueOf(n));
        text1.setText(String.valueOf(factorial));
    } 

    public static void main(String[] args) {
        new q3();
    }
}