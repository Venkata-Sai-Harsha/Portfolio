package lab10;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class q2 extends JFrame implements ActionListener {
    private JLabel label;
    private JTextField text;
    private JButton button;
    private int count;

    public q2(){
        count=88;
        label= new JLabel("Counter");
        text=new JTextField("88",5);
        button= new JButton("Count Down");
        button.addActionListener(this);

        JPanel panel = new JPanel();
        panel.add(label);
        panel.add(text);
        panel.add(button);

        this.add(panel, BorderLayout.CENTER);

        setSize(375,250);
        setTitle("Swing Counter Down");
        setLayout(new FlowLayout());
        //setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        count--;
        text.setText(String.valueOf(count));
    } 

    public static void main(String[] args) {
        new q2();
    }
}