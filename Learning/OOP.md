Sure, let's dive into the core concepts of Object-Oriented Programming (OOP) in Java. OOP is based on four main principles: Encapsulation, Inheritance, Polymorphism, and Abstraction. We will also cover additional concepts like classes, objects, method overloading, method overriding, and interfaces. 

### 1. Classes and Objects

#### Class:
A class is a blueprint for creating objects. It defines a datatype by bundling data and methods that work on the data into one single unit.

#### Object:
An object is an instance of a class. When a class is defined, no memory is allocated until an object of that class is created.

**Example:**

```java
class Car {
    // Attributes
    String color;
    String model;
    int year;

    // Constructor
    Car(String color, String model, int year) {
        this.color = color;
        this.model = model;
        this.year = year;
    }

    // Method
    void displayDetails() {
        System.out.println("Model: " + model + ", Color: " + color + ", Year: " + year);
    }
}

public class Main {
    public static void main(String[] args) {
        // Creating objects
        Car car1 = new Car("Red", "Toyota", 2020);
        Car car2 = new Car("Blue", "Honda", 2021);

        // Using objects
        car1.displayDetails();
        car2.displayDetails();
    }
}
```

### 2. Encapsulation

Encapsulation is the wrapping up of data and methods into a single unit, and it restricts direct access to some of the object's components. This is usually done through the use of private fields and public methods to access them.

**Example:**

```java
class Person {
    // Private fields
    private String name;
    private int age;

    // Public constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Public getter and setter methods
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age > 0) {
            this.age = age;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Person person = new Person("John", 25);

        // Accessing and modifying private fields using public methods
        System.out.println("Name: " + person.getName());
        person.setAge(30);
        System.out.println("Age: " + person.getAge());
    }
}
```

### 3. Inheritance

Inheritance is a mechanism where one class acquires the properties (fields) and behaviors (methods) of another class. The class that inherits is called the subclass, and the class from which it inherits is called the superclass.

**Example:**

```java
class Animal {
    void eat() {
        System.out.println("This animal eats food.");
    }
}

class Dog extends Animal {
    void bark() {
        System.out.println("The dog barks.");
    }
}

public class Main {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.eat(); // Inherited method
        dog.bark(); // Own method
    }
}
```

### 4. Polymorphism

Polymorphism allows objects of different classes to be treated as objects of a common superclass. It is of two types: compile-time (method overloading) and runtime (method overriding).

#### Method Overloading (Compile-Time Polymorphism):

**Example:**

```java
class MathOperations {
    // Method overloading
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
}

public class Main {
    public static void main(String[] args) {
        MathOperations math = new MathOperations();
        System.out.println(math.add(2, 3)); // Calls int version
        System.out.println(math.add(2.5, 3.5)); // Calls double version
    }
}
```

#### Method Overriding (Runtime Polymorphism):

**Example:**

```java
class Animal {
    void makeSound() {
        System.out.println("Some generic animal sound");
    }
}

class Dog extends Animal {
    @Override
    void makeSound() {
        System.out.println("Dog barks");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal myDog = new Dog();
        myDog.makeSound(); // Calls the Dog's makeSound method
    }
}
```

### 5. Abstraction

Abstraction is the process of hiding the implementation details and showing only the functionality. It can be achieved with abstract classes and interfaces.

#### Abstract Class:

**Example:**

```java
abstract class Shape {
    abstract void draw(); // Abstract method

    void display() {
        System.out.println("This is a shape");
    }
}

class Circle extends Shape {
    @Override
    void draw() {
        System.out.println("Drawing a circle");
    }
}

public class Main {
    public static void main(String[] args) {
        Shape shape = new Circle();
        shape.draw(); // Calls the Circle's draw method
        shape.display(); // Calls the Shape's display method
    }
}
```

#### Interface:

**Example:**

```java
interface Animal {
    void eat(); // Abstract method
    void makeSound(); // Abstract method
}

class Dog implements Animal {
    @Override
    public void eat() {
        System.out.println("Dog eats food");
    }

    @Override
    public void makeSound() {
        System.out.println("Dog barks");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal myDog = new Dog();
        myDog.eat(); // Calls the Dog's eat method
        myDog.makeSound(); // Calls the Dog's makeSound method
    }
}
```

### 6. Use Cases for Different Classes

#### Utility Class:

Utility classes contain static methods and are used to perform common operations.

**Example:**

```java
class MathUtils {
    static int add(int a, int b) {
        return a + b;
    }

    static double sqrt(double a) {
        return Math.sqrt(a);
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println(MathUtils.add(5, 10));
        System.out.println(MathUtils.sqrt(25));
    }
}
```

#### Singleton Class:

A singleton class ensures that only one instance of the class exists.

**Example:**

```java
class Singleton {
    private static Singleton instance;

    private Singleton() {}

    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}

public class Main {
    public static void main(String[] args) {
        Singleton singleton1 = Singleton.getInstance();
        Singleton singleton2 = Singleton.getInstance();
        
        System.out.println(singleton1 == singleton2); // true
    }
}
```

### 7. Interface vs. Abstract Class

**Interface:**
- Can have only abstract methods (until Java 8, where default and static methods were introduced).
- A class can implement multiple interfaces.

**Abstract Class:**
- Can have both abstract and concrete methods.
- A class can inherit from only one abstract class.

**Example Using Interface:**

```java
interface Drawable {
    void draw();
}

class Rectangle implements Drawable {
    @Override
    public void draw() {
        System.out.println("Drawing a rectangle");
    }
}

public class Main {
    public static void main(String[] args) {
        Drawable d = new Rectangle();
        d.draw();
    }
}
```

**Example Using Abstract Class:**

```java
abstract class Shape {
    abstract void draw();

    void display() {
        System.out.println("This is a shape");
    }
}

class Circle extends Shape {
    @Override
    void draw() {
        System.out.println("Drawing a circle");
    }
}

public class Main {
    public static void main(String[] args) {
        Shape shape = new Circle();
        shape.draw();
        shape.display();
    }
}
```

These are the core concepts and detailed examples of OOP in Java. This should give you a solid understanding for your technical interview. Good luck!