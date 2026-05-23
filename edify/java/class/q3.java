abstract class Appliance {
    protected boolean isOn = false;
    public abstract void turnOn();
    public abstract void turnOff();
}

class WashingMachine extends Appliance {

    @Override
    public void turnOn() {
        if (!isOn) {
            isOn = true;
            System.out.println("Washing Machine: Starting wash cycle...");
        } else {
            System.out.println("Washing Machine is already running.");
        }
    }

    @Override
    public void turnOff() {
        if (isOn) {
            isOn = false;
            System.out.println("Washing Machine: Powering down after wash.");
        } else {
            System.out.println("Washing Machine is already off.");
        }
    }
}

class Microwave extends Appliance {

    @Override
    public void turnOn() {
        if (!isOn) {
            isOn = true;
            System.out.println("Microwave: Heating started.");
        } else {
            System.out.println("Microwave is already running.");
        }
    }

    @Override
    public void turnOff() {
        if (isOn) {
            isOn = false;
            System.out.println("Microwave: Heating stopped.");
        } else {
            System.out.println("Microwave is already off.");
        }
    }
}

public class q3 {
    public static void main(String[] args) {
        Appliance washing_machine = new WashingMachine();
        Appliance microwave = new Microwave();

        System.out.println("Controlling Washing Machine");
        washing_machine.turnOn();
        washing_machine.turnOn();
        washing_machine.turnOff();
        washing_machine.turnOff();

        System.out.println("\nControlling Microwave");
        microwave.turnOn();
        microwave.turnOn();
        microwave.turnOff();
        microwave.turnOff();
    }
}
