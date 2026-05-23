package lab10;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class q1 extends JFrame implements ActionListener {
    private JLabel label;
    private JTextField text;
    private JButton button;
    private int count=0;

    public q1(){
        //count=0;
        label= new JLabel("Counter");
        text=new JTextField("0",5);
        button= new JButton("Count");
        button.addActionListener(this);

        JPanel panel = new JPanel();
        panel.add(label);
        panel.add(text);
        panel.add(button);

        this.add(panel, BorderLayout.CENTER);

        setSize(375,250);
        setTitle("Swing Counter");
        setLayout(new FlowLayout());
        //getContentPane().setBackground(Color.BLUE);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        count++;
        text.setText(Integer.toString(count));
    } 

    public static void main(String[] args) {
        new q1();
    }
}