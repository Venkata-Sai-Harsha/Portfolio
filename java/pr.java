import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class pr extends JFrame implements ActionListener{
    public JMenu jm7,jm8,jm9;
    public JMenuItem m11,m12,m13,m14,m15,m16,m17,m21;
    public JMenuBar mb;
    public JLabel bus_id,to,from,email1,name1,age,salary,type,email2,name2,email3,name3,bus_id2;
    public JTextField bus_id1,to1,from1,email11,name11,age1,salary1,email21,name21,email31,name31,bus_id21;
    public JComboBox type1;
    public JFrame f1,f2,f3,f4,f5;
    public pr(){
        jm7 = new JMenu(" ADD/REMOVE ");
        m11 = new JMenuItem("add bus"); 
        m12 = new JMenuItem("add staff"); 
        m13 = new JMenuItem("remove customer"); 
        m14 = new JMenuItem("remove staff"); 
        m15 = new JMenuItem("remove bus"); 
        jm7.add(m11);jm7.add(m12);jm7.add(m13);jm7.add(m14);jm7.add(m15);
        mb.add(jm7);
        jm8 = new JMenu("view");
        m16 = new JMenuItem("view customers"); 
        m17 = new JMenuItem("view staff"); 
        jm8.add(m17);jm8.add(m16);
        mb.add(jm8);
        jm9 = new JMenu("tickets");
        m21 = new JMenuItem("view booking"); 
        m21.addActionListener(this);
        jm9.add(m21);
        mb.add(jm9);
        mb = new JMenuBar();
        setJMenuBar(mb);

        
        bus_id = new JLabel("bus_id");
        to = new JLabel("to");
        from = new JLabel("from");
        email1 = new JLabel("email");
        name1 = new JLabel("name");
        age = new JLabel("age");
        salary = new JLabel("salary");
        type = new JLabel("type");
        email2 = new JLabel("email");
        name2 = new JLabel("name");
        email3 = new JLabel("email");
        name3 = new JLabel("name");
        bus_id2 = new JLabel("bus_id");
        bus_id1 = new JTextField(10);
        to1 = new JTextField(10);
        from1 = new JTextField(10);
        email11 = new JTextField(10);
        name11 = new JTextField(10);
        age1 = new JTextField(10);
        salary1 = new JTextField(10);
        String typee[]={"driver","conductor","cleaner"};
        type1=new JComboBox(typee);
        email21 = new JTextField(10);
        name21 = new JTextField(10);
        email31 = new JTextField(10);
        name31 = new JTextField(10);
        bus_id21 = new JTextField(10);

        bus_id.setBounds(60,40,80,20);
        bus_id1.setBounds(150,40,80,20);
        to.setBounds(60,80,80,20);
        to1.setBounds(150,80,80,20);
        from.setBounds(60,120,80,20);
        from1.setBounds(150,120,80,20);
        email1.setBounds(60,40,80,20);
        email11.setBounds(150,40,80,20);
        name1.setBounds(60,80,80,20);
        name11.setBounds(150,80,80,20);
        age.setBounds(60,120,80,20);
        age1.setBounds(150,120,80,20);
        salary.setBounds(60,160,80,20);
        salary1.setBounds(150,160,80,20);
        type.setBounds(60,200,80,20);
        type1.setBounds(150,200,80,20);
        email2.setBounds(60,40,80,20);
        email21.setBounds(150,40,80,20);
        name2.setBounds(60,80,80,20);
        name21.setBounds(150,80,80,20);
        email3.setBounds(60,40,80,20);
        email31.setBounds(150,40,80,20);
        name3.setBounds(60,80,80,20);
        name31.setBounds(150,80,80,20);
        bus_id2.setBounds(60,120,80,20);
        bus_id21.setBounds(150,120,80,20);
        
        bus_id1.addActionListener(this);
        to1.addActionListener(this);
        from1.addActionListener(this);
        email11.addActionListener(this);
        name11.addActionListener(this);
        age1.addActionListener(this);
        salary1.addActionListener(this);
        type1.addActionListener(this);
        email21.addActionListener(this);
        name21.addActionListener(this);
        email31.addActionListener(this);
        name31.addActionListener(this);
        bus_id21.addActionListener(this);

        f1 = new JFrame("add bus");
        f1.setSize(300,300);
        f1.setLayout(null);
        f1.setVisible(true);
        f1.add(bus_id);
        f1.add(bus_id1);
        f1.add(to);
        f1.add(to1);
        f1.add(from);
        f1.add(from1);

        f2 = new JFrame("add staff");
        f2.setSize(300,300);
        f2.setLayout(null);
        f2.setVisible(true);
        f2.add(email1);
        f2.add(email11);
        f2.add(name1);
        f2.add(name11);
        f2.add(age);
        f2.add(age1);
        f2.add(salary);
        f2.add(salary1);
        f2.add(type);
        f2.add(type1);

        f3 = new JFrame("remove customer");
        f3.setSize(300,300);
        f3.setLayout(null);
        f3.setVisible(true);
        f3.add(email2);
        f3.add(email21);
        f3.add(name2);
        f3.add(name21);

        f4 = new JFrame("remove staff");
        f4.setSize(300,300);
        f4.setLayout(null);
        f4.setVisible(true);
        f4.add(name3);
        f4.add(name31);
        f4.add(email3);
        f4.add(email31);

        f5 = new JFrame("remove bus");
        f5.setSize(300,300);
        f5.setLayout(null);
        f5.setVisible(true);
        f5.add(bus_id2);
        f5.add(bus_id21);


        f1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f3.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f4.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f5.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // f1.addWindowListener(new WindowAdapter() {
        //     public void windowClosing(WindowEvent e) {
        //         f1.dispose();
        //     }
        // });
        // f2.addWindowListener(new WindowAdapter() {
        //     public void windowClosing(WindowEvent e) {
        //         f2.dispose();
        //     }
        // });
        // f3.addWindowListener(new WindowAdapter() {

        //     public void windowClosing(WindowEvent e) {
        //         f3.dispose();
        //     }
        // });
        // f4.addWindowListener(new WindowAdapter() {
            
        //     public void windowClosing(WindowEvent e) {
        //         f4.dispose();
        //     }
        // });
        // f5.addWindowListener(new WindowAdapter() {

        //     public void windowClosing(WindowEvent e) {
        //         f5.dispose();
        //     }
        // });

    
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setVisible(true);
        }
    public static void main(String[] args) {
        new pr();
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        
    }
}