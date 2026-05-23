package lab10;

import java.awt.*;

import java.awt.event.*;
import javax.swing.*;

public class sh extends JFrame implements ActionListener {
    private JTextField tfDisplay;
    private JPanel panelButtons;
    private JButton btn0, btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9,btnAdd, btnSub, btnMul, btnDiv, btnMod, btnEqual, btnClear;
    private String prevOperator;
    private double result;

    public sh() {
        setTitle("Swing Calculator");
        setSize(300, 200);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        tfDisplay = new JTextField();
        panelButtons = new JPanel();
        btn0 = new JButton("0");
        btn1 = new JButton("1");
        btn2 = new JButton("2");
        btn3 = new JButton("3");
        btn4 = new JButton("4");
        btn5 = new JButton("5");
        btn6 = new JButton("6");
        btn7 = new JButton("7");
        btn8 = new JButton("8");
        btn9 = new JButton("9");
        btnAdd = new JButton("+");
        btnSub = new JButton("-");
        btnMul = new JButton("*");
        btnDiv = new JButton("/");
        btnMod = new JButton("%");
        btnEqual = new JButton("=");
        btnClear = new JButton("C");

        panelButtons.setLayout(new GridLayout(4, 4,3,3));

        panelButtons.add(btn7);
        panelButtons.add(btn8);
        panelButtons.add(btn9);
        panelButtons.add(btnAdd);
        panelButtons.add(btn4);
        panelButtons.add(btn5);
        panelButtons.add(btn6);
        panelButtons.add(btnSub);
        panelButtons.add(btn1);
        panelButtons.add(btn2);
        panelButtons.add(btn3);
        panelButtons.add(btnMul);
        panelButtons.add(btnClear);
        panelButtons.add(btn0);
        panelButtons.add(btnEqual);
        panelButtons.add(btnDiv);

        btn0.addActionListener(this);
        btn1.addActionListener(this);
        btn2.addActionListener(this);
        btn3.addActionListener(this);
        btn4.addActionListener(this);
        btn5.addActionListener(this);
        btn6.addActionListener(this);
        btn7.addActionListener(this);
        btn8.addActionListener(this);
        btn9.addActionListener(this);
        btnAdd.addActionListener(this);
        btnSub.addActionListener(this);
        btnMul.addActionListener(this);
        btnDiv.addActionListener(this);
        btnMod.addActionListener(this);
        btnEqual.addActionListener(this);

        btnClear.addActionListener(new ActionListener() {
            //@Override
            public void actionPerformed(ActionEvent e) {
                tfDisplay.setText("");
                prevOperator = "";
                result = 0;
            }
        });

        add(tfDisplay, BorderLayout.NORTH);
        add(panelButtons, BorderLayout.CENTER);

        setLocationRelativeTo(null);
        setVisible(true);
    }

    //@Override
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();

        if (command.equals("0") || command.equals("1") || command.equals("2") || command.equals("3")
                || command.equals("4") || command.equals("5") || command.equals("6") || command.equals("7")
                || command.equals("8") || command.equals("9")) {
            tfDisplay.setText(tfDisplay.getText() + command);
        } 
        else if (command.equals("+") || command.equals("-") || command.equals("*") || command.equals("/")
                || command.equals("=")) {
            double num = Double.parseDouble(tfDisplay.getText());
            if (prevOperator.equals("")) {
                result = num;
            } else if (prevOperator.equals("+")) {
                result += num;
            } else if (prevOperator.equals("-")) {
                result -= num;
            } else if (prevOperator.equals("*")) {
                result *= num;
            } else if (prevOperator.equals("/")) {
                result /= num;
            }

            tfDisplay.setText(String.format("%.2f", result));

            if (!command.equals("=")) {
                prevOperator = command;
            } else {
                prevOperator = "";
            }
        }
    }

    public static void main(String[] args) {
        new sh();
    }
}