package lab10;

import java.awt.event.*;

import javax.swing.*;

public class q5 extends JFrame implements ActionListener {
    private JLabel label,label1;
    private final JTextField CelsiusField,FahrenheitField;

    public q5(){
        label= new JLabel("Celsius:");
        CelsiusField = new JTextField(10);
        label1=new JLabel("Fahrenheit:");
        FahrenheitField = new JTextField(10);

        label.setBounds(60,40,80,20);
        label1.setBounds(60,70,80,20);
        CelsiusField.setBounds(140, 40, 80, 20);
        FahrenheitField.setBounds(140, 70, 80, 20);

        CelsiusField.addActionListener(this);
        FahrenheitField.addActionListener(this);

        add(label);
        add(CelsiusField);
        add(label1);
        add(FahrenheitField);

        // JPanel panel = new JPanel();
        // panel.add(label);
        // panel.add(CelsiusField);
        // panel.add(label1);
        // panel.add(FahrenheitField);

        //this.add(panel, BorderLayout.CENTER);

        setSize(325,175);
        setTitle("Temperature Converter");
        setLayout(null);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == CelsiusField) {
            double celsius = Double.parseDouble(CelsiusField.getText());
            double fahrenheit = celsius * 1.8 + 32;
            FahrenheitField.setText(String.format("%.1f", fahrenheit));
        }
        else if (e.getSource() == FahrenheitField) {
            double fahrenheit = Double.parseDouble(FahrenheitField.getText());
            double celsius = (fahrenheit - 32) / 1.8;
            CelsiusField.setText(String.format("%.1f", celsius));
        }
    } 

    public static void main(String[] args) {
        new q5();
    }
}