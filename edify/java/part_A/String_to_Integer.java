public class String_to_Integer {
    public static void main(String[] args) {
        String str = "123a45";
        try{
            int num = Integer.parseInt(str);
            System.out.println("The integer value is: " + num);
        } catch (NumberFormatException e) {
            System.out.println("Invalid input: " + str);    
        }
    }
}