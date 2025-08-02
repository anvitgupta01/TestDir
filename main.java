// Class 1: Greeting.java
public class Greeting {
    public void sayHello() {
        System.out.println("Hello from the Greeting class!");
    }
}

// Class 2: MainClass.java
public class MainClass {
    public static void main(String[] args) {
        // Creating an object of Greeting class
        Greeting greet = new Greeting();

        // Calling the sayHello() method from Greeting class
        greet.sayHello();
    }
}

public class Main {
  public static void main(String[] args) {
    System.out.println("Hello World");
  }
}