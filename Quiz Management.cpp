#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include <string>
#include <chrono>
#include <thread>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;

struct Question
{
  string question;
    vector < string > options;
  int correctOption;
  string explanation;
};

class QuizGame
{
public:
  void run ()
  {
    srand (static_cast < unsigned >(time (nullptr)));
      displayWelcomeMessage ();
    while (true)
      {
	displayMenu ();
	int choice;
	  cin >> choice;
	switch (choice)
	  {
	  case 1:
	    displayRules ();
	    break;
	    case 2:if (loadQuestions ("C++"))
	      {
		playQuiz ("C++");
	      }
	    break;
	  case 3:
	    if (loadQuestions ("Java"))
	      {
		playQuiz ("Java");
	      }
	    break;
	  case 4:
	    cout << "Exiting the program. Goodbye!" << endl;
	    return;
	  default:
	    cout << "Invalid menu choice. Please try again." << endl;
	  }
      }
  }

private:
  struct User
  {
    string name;
    int score;
      User ():name (""), score (0)
    {
    }
    User (const string & n):name (n), score (0)
    {
    }
  };

  vector < Question > allQuestions;
  map < string, User > users;

  void displayWelcomeMessage ()
  {
    system ("clear");
    cout << "" <<
      endl;
    cout << "*            Welcome to the Quiz Game!                      *" <<
      endl;
    cout << "" <<
      endl << endl;
  }

  void displayMenu ()
  {
    cout << "MENU:" << endl;
    cout << "1. RULES" << endl;
    cout << "2. GIVE C++ QUIZ" << endl;
    cout << "3. GIVE JAVA QUIZ" << endl;
    cout << "4. EXIT" << endl;
    cout << "Enter your choice: ";
  }

  void displayRules ()
  {
    system ("clear");
    cout << "=== Quiz Game Rules ===" << endl;
    cout << "1. You will be presented with a series of questions." << endl;
    cout <<
      "2. Choose the correct answer by entering the corresponding number." <<
      endl;
    cout << "3. Your final score will be displayed at the end of the quiz." <<
      endl << endl;
    cout << "Press enter to return to the main menu...";
    cin.ignore (numeric_limits < streamsize >::max (), '\n');
    cin.get ();
  }

  bool loadQuestions (const string & quizType)
  {
    if (allQuestions.empty ())
      {
	// Load questions only if they haven't been loaded yet
	if (quizType == "C++")
	  {
	    allQuestions =
	    {
	      {
		"What is the primary function of main() in a C++ program?",
		{
		"To define the main class", "To execute the main class",
		    "To display text on the console", "To declare variables"}
	      , 2,
		  "The main() function in C++ is the entry point of a program. It is where program execution begins."}
	      ,
	      {
		"Which data type is used to store whole numbers in C++?",
		{
		"float", "char", "int", "double"}
	      , 3,
		  "The 'int' data type is used to store whole numbers in C++."}
	      ,
	      {
		"What is the result of 7 + 3 * 2?",
		{
		"20", "13", "17", "26"}
	      , 4,
		  "In C++, the multiplication (*) operator has higher precedence than the addition (+) operator."}
	      ,
	      {
		"What do you use to define a constant in C++?",
		{
		"const", "var", "let", "define"}
	      , 1, "The 'const' keyword is used to define constants in C++."}
	      ,
	      {
		"Which of the following is not a C++ keyword?",
		{
		"for", "if", "then", "else"}
	      , 3, "In C++, 'then' is not a keyword."}
	      ,
	      {
		"In C++, how can you create a single-line comment?",
		{
		"//", "/*", "#", "--"}
	      , 1,
		  "A double forward slash (//) is used for single-line comments in C++."}
	      ,
	      {
		"What is the C++ operator for 'not equal to'?",
		{
		"==", "!=", "<>", "><"}
	      , 2,
		  "The '!=' operator is used in C++ to represent 'not equal to'."}
	      ,
	      {
		"Which of the following is not a fundamental data type in C++?",
		{
		"bool", "string", "char", "int"}
	      , 2, "In C++, 'string' is not a fundamental data type."}
	      ,
	      {
		"What does the 'cin' object in C++ do?",
		{
		"It performs console input",
		    "It prints text to the console", "It defines classes",
		    "It handles exceptions"}
	      , 1,
		  "'cin' is used for console input in C++ to read values entered by the user."}
	      ,
	      {
		"Which C++ header file is needed to work with files?",
		{
		"<iostream>", "<fstream>", "<stdio.h>", "<stdlib.h>"}
	      , 2,
		  "The '<fstream>' header file is used for working with files in C++."}
	      ,
	      {
		"What is the size of 'int' data type in C++ on a 32-bit system?",
		{
		"2 bytes", "4 bytes", "8 bytes", "Depends on the compiler"}
	      , 2,
		  "On a 32-bit system, the 'int' data type typically occupies 4 bytes of memory."}
	      ,
	      {
		"What is the scope resolution operator in C++?",
		{
		"->", ".", ":", "::"}
	      , 4,
		  "The scope resolution operator '::' is used to access members of a class or namespace in C++."}
	      ,
	      {
		"Which C++ data structure is a collection of elements with no duplicates?",
		{
		"Vector", "Array", "Set", "List"}
	      , 3,
		  "A 'Set' is a data structure in C++ that stores unique elements, meaning it doesn't allow duplicates."}
	      ,
	      {
		"In C++, what is a 'pointer'?",
		{
		"A data type", "A function",
		    "A variable that stores a memory address",
		    "A loop control statement"}
	      , 3,
		  "A 'pointer' is a variable that stores the memory address of another variable."}
	      ,
	      {
		"What is 'polymorphism' in C++?",
		{
		"A type of loop", "A function that calls itself",
		    "The ability of different objects to respond to the same function call",
		    "A keyword to define classes"}
	      , 3,
		  "Polymorphism in C++ allows different objects to respond to the same function call in a way that is appropriate for each object."}
	      ,
	      {
		"What is the output of the following code?\nint x = 5;\nint y = x++ + ++x;\nstd::cout << y;",
		{
		"10", "11", "12", "13"}
	      , 4,
		  "The code uses post-increment and pre-increment operators to modify 'x' and calculate 'y'. The output is 13."}
	      ,
	      {
		"Which C++ operator is used to access the members of a class?",
		{
		".", "->", ":", "::"}
	      , 2,
		  "The '->' operator is used to access members of a class through a pointer to an object."}
	      ,
	      {
		"What is the purpose of 'break' statement in C++?",
		{
		"To define a new loop", "To exit a loop prematurely",
		    "To skip the next iteration of a loop",
		    "To pause program execution"}
	      , 2,
		  "The 'break' statement is used to exit a loop prematurely in C++."}
	      ,
	      {
		"What does 'std::endl' do in C++?",
		{
		"It ends the program", "It declares a variable",
		    "It inserts a new line and flushes the output stream",
		    "It generates a random number"}
	      , 3,
		  "'std::endl' in C++ inserts a new line and flushes the output stream."}
	      ,
	      {
		"Which C++ operator is used for logical 'AND'?",
		{
		"&&", "||", "!", "&"}
	      , 1, "The '&&' operator is used for logical 'AND' in C++."}
	      ,
	      {
		"What is the C++ 'switch' statement used for?",
		{
		"Defining classes", "Logical 'AND' operation",
		    "Selecting one of many code blocks to be executed",
		    "String manipulation"}
	      , 3,
		  "The 'switch' statement in C++ is used to select one of many code blocks to be executed based on a given value."}
	      ,
	      {
		"What is a 'constructor' in C++?",
		{
		"A type of loop", "A function that calls itself",
		    "A special member function to initialize objects",
		    "A data type"}
	      , 3,
		  "A 'constructor' in C++ is a special member function used to initialize objects of a class."}
	      ,
	      {
		"What is 'inheritance' in C++?",
		{
		"A keyword to define classes", "A special operator",
		    "The ability to create a new class from an existing class",
		    "A type of comment"}
	      , 3,
		  "Inheritance in C++ allows you to create a new class that inherits properties and behaviors from an existing class."}
	      ,
	      {
		"What is 'encapsulation' in C++?",
		{
		"A logical operator", "A file format",
		    "The bundling of data and functions that operate on that data into a single unit",
		    "A loop control statement"}
	      , 3,
		  "Encapsulation in C++ involves bundling data and functions that operate on that data into a single unit, known as a class."}
	      ,
	      {
		"What is the C++ 'new' operator used for?",
		{
		"Creating a new object", "Defining a new function",
		    "Reserving memory on the heap", "Ending the program"}
	      , 3,
		  "The 'new' operator in C++ is used to allocate memory on the heap and returns a pointer to the allocated memory."}
	      ,
	      {
		"What is 'cout' in C++?",
		{
		"A reserved word", "A data type", "An input stream",
		    "An output stream"}
	      , 4,
		  "'cout' in C++ is an output stream used for displaying data on the console."}
	      ,
	      {
		"What is the result of 5 / 2 in C++?",
		{
		"2.5", "2", "2.0", "2.25"}
	      , 2,
		  "In C++, the division of two integers results in an integer quotient. The result of 5 / 2 is 2."}
	    };
	  }
	else if (quizType == "Java")
	  {
	    allQuestions =
	    {
	      // Java questions here...
	      {
		"What is the primary purpose of a constructor in Java?",
		{
		"To create an object", "To return a value",
		    "To initialize class variables", "To define a method"}
	      , 1,
		  "A constructor in Java is used to create an object and initialize its state."}
	      ,
	      {
		"Which keyword is used to define a constant in Java?",
		{
		"const", "final", "static", "constant"}
	      , 2, "'final' is used to define a constant in Java."}
	      ,
	      {
		"What data type is used to store text in Java?",
		{
		"int", "float", "char", "String"}
	      , 4, "'String' is used to store text (strings) in Java."}
	      ,
	      {
		"Which access modifier makes a variable or method accessible only within the same package?",
		{
		"public", "private", "protected",
		    "default (package-private)"}
	      , 4,
		  "The default access modifier (package-private) restricts access to the same package."}
	      ,
	      {
		"In Java, which keyword is used to create a new instance of a class?",
		{
		"new", "create", "instantiate", "alloc"}
	      , 1,
		  "The 'new' keyword is used to create a new instance of a class."}
	      ,
	      {
		"What is the default value of a boolean variable in Java?",
		{
		"0", "true", "false", "null"}
	      , 3,
		  "The default value of a boolean variable in Java is 'false'."}
	      ,
	      {
		"Which operator is used for logical 'OR' in Java?",
		{
		"&&", "||", "!", "|"}
	      , 2, "The '||' operator is used for logical 'OR' in Java."}
	      ,
	      {
		"What is the purpose of the 'break' statement in Java?",
		{
		"To define a new loop", "To exit a loop prematurely",
		    "To skip the next iteration of a loop",
		    "To pause program execution"}
	      , 2,
		  "The 'break' statement is used to exit a loop prematurely in Java."}
	      ,
	      {
		"What is the output of the following code?\nint x = 5;\nint y = x++ + ++x;\nSystem.out.println(y);",
		{
		"10", "11", "12", "13"}
	      , 4,
		  "The code uses post-increment and pre-increment operators to modify 'x' and calculate 'y'. The output is 13."}
	      ,
	      {
		"Which Java operator is used to access the members of a class?",
		{
		".", "->", ":", "::"}
	      , 1,
		  "The '.' operator is used to access members of a class in Java."}
	      ,
	      {
		"What does 'System.out.println()' do in Java?",
		{
		"It ends the program", "It declares a variable",
		    "It inserts a new line and flushes the output stream",
		    "It generates a random number"}
	      , 3,
		  "'System.out.println()' in Java inserts a new line and flushes the output stream."}
	      ,
	      {
		"Which Java operator is used to perform bitwise 'AND'?",
		{
		"&&", "||", "&", "!"}
	      , 3, "The '&' operator is used for bitwise 'AND' in Java."}
	      ,
	      {
		"What is a 'method' in Java?",
		{
		"A class", "A variable", "A function that calls itself",
		    "A block of code that can be called"}
	      , 4,
		  "A 'method' in Java is a block of code that can be called to perform a specific task."}
	      ,
	      {
		"What is 'inheritance' in Java?",
		{
		"A keyword to define classes", "A special operator",
		    "The ability to create a new class from an existing class",
		    "A type of comment"}
	      , 3,
		  "Inheritance in Java allows you to create a new class that inherits properties and behaviors from an existing class."}
	      ,
	      {
		"What is 'encapsulation' in Java?",
		{
		"A logical operator", "A file format",
		    "The bundling of data and methods that operate on that data into a single unit",
		    "A loop control statement"}
	      , 3,
		  "Encapsulation in Java involves bundling data and methods that operate on that data into a single unit, known as a class."}
	      ,
	      {
		"What is the Java 'new' operator used for?",
		{
		"Creating a new object", "Defining a new function",
		    "Reserving memory on the heap", "Ending the program"}
	      , 1,
		  "The 'new' operator in Java is used to create a new object."}
	      ,
	      {
		"What is 'System.out' in Java?",
		{
		"A reserved word", "A data type", "An input stream",
		    "An output stream"}
	      , 4,
		  "'System.out' in Java is an output stream used for displaying data on the console."}
	      ,
	      {
		"What is the result of 5 / 2 in Java?",
		{
		"2.5", "2", "2.0", "2.25"}
	      , 2,
		  "In Java, the division of two integers results in an integer quotient. The result of 5 / 2 is 2."}
	      ,
	      {
		"What is a 'variable' in Java?",
		{
		"A keyword", "A function", "A data type",
		    "A container for storing data"}
	      , 4, "A 'variable' in Java is a container for storing data."}
	      ,
	      {
		"What is 'polymorphism' in Java?",
		{
		"A type of loop", "A function that calls itself",
		    "The ability of different objects to respond to the same method call",
		    "A keyword to define classes"}
	      , 3,
		  "Polymorphism in Java allows different objects to respond to the same method call in a way that is appropriate for each object."}
	      ,
	      {
		"What is a 'class' in Java?",
		{
		"A type of loop", "A function that calls itself",
		    "A special member function to initialize objects",
		    "A blueprint for creating objects"}
	      , 4,
		  "A 'class' in Java serves as a blueprint for creating objects with shared characteristics and behaviors."}
	      ,
	      {
		"Which keyword is used to declare a method that does not return a value in Java?",
		{
		"void", "null", "empty", "none"}
	      , 1,
		  "The 'void' keyword is used to declare a method that does not return a value in Java."}
	      ,
	      {
		"What is the Java 'for' loop used for?",
		{
		"Defining classes", "Logical 'AND' operation",
		    "Executing a block of code multiple times",
		    "String manipulation"}
	      , 3,
		  "The 'for' loop in Java is used for executing a block of code multiple times."}
	      ,
	      {
		"What is a 'comment' in Java?",
		{
		"A type of loop", "A function that calls itself",
		    "Text used for documentation or explanation",
		    "A reserved word"}
	      , 3,
		  "A 'comment' in Java is text used for documentation or explanation and is ignored by the compiler."}
	      ,
	      {
		"What is the purpose of the 'return' statement in Java?",
		{
		"To define a new loop", "To exit a loop prematurely",
		    "To skip the next iteration of a loop",
		    "To provide a result from a method"}
	      , 4,
		  "The 'return' statement in Java is used to provide a result (value) from a method."}
	      ,
	      {
		"What is 'try-catch' in Java used for?",
		{
		"Creating objects", "Handling exceptions",
		    "Declaring variables", "Controlling program flow"}
	      , 2,
		  "'try-catch' in Java is used for handling exceptions and gracefully managing errors."}
	      ,
	      {
		"What is a 'package' in Java?",
		{
		"A type of loop", "A container for classes",
		    "A data structure", "A reserved word"}
	      , 2,
		  "A 'package' in Java is a container for organizing and grouping related classes."}
	      ,
	      {
		"What is the Java 'while' loop used for?",
		{
		"Executing a block of code once", "Defining classes",
		    "Logical 'OR' operation",
		    "Executing a block of code repeatedly as long as a condition is true"}
	      , 4,
		  "The 'while' loop in Java is used for executing a block of code repeatedly as long as a condition is true."}
	      ,
	      {
		"What is 'composition' in Java?",
		{
		"A type of loop",
		    "A way to create objects that contain other objects",
		    "A keyword to define classes", "A type of comment"}
	      , 2,
		  "Composition in Java is a way to create objects that contain other objects, promoting code reuse and flexibility."}
	      ,
	      {
		"What is 'method overriding' in Java?",
		{
		"A type of loop", "A way to call methods recursively",
		    "Replacing a superclass method in a subclass with a new implementation",
		    "A keyword to define classes"}
	      , 3,
		  "Method overriding in Java is the process of replacing a superclass method in a subclass with a new implementation."}
	      ,
	      {
		"What is 'toString()' in Java used for?",
		{
		"Defining classes", "Logical 'AND' operation",
		    "Converting an object to a string representation",
		    "String manipulation"}
	      , 3,
		  "'toString()' in Java is used to convert an object to a string representation."}
	      ,
	      {
		"What is 'equals()' in Java used for?",
		{
		"To compare two integers",
		    "To perform mathematical operations",
		    "To compare objects for content equality",
		    "To create a new object"}
	      , 3,
		  "'equals()' in Java is used to compare objects for content equality."}
	      ,
	      {
		"What is 'HashMap' in Java?",
		{
		"A data type", "A way to store data in an ordered sequence",
		    "A collection that stores key-value pairs",
		    "A keyword to define classes"}
	      , 3,
		  "'HashMap' in Java is a collection that stores key-value pairs."}
	      ,
	      {
		"What is 'Exception' in Java?",
		{
		"A type of loop", "A data type",
		    "An error that occurs during program execution",
		    "A type of comment"}
	      , 3,
		  "An 'Exception' in Java is an error that occurs during program execution."}
	      ,
	      {
		"What is 'try-with-resources' in Java used for?",
		{
		"Creating objects", "Handling exceptions",
		    "Managing resources like files or database connections",
		    "Controlling program flow"}
	      , 2,
		  "'try-with-resources' in Java is used for managing resources like files or database connections and ensuring they are properly closed."}
	      ,
	      {
		"What is 'Thread' in Java?",
		{
		"A data type", "A way to store data in an ordered sequence",
		    "A process that executes independently",
		    "A keyword to define classes"}
	      , 3,
		  "A 'Thread' in Java is a process that executes independently, allowing for concurrent execution."}
	      ,
	      {
		"What is 'synchronization' in Java used for?",
		{
		"A type of loop",
		    "Ensuring that only one thread accesses a shared resource at a time",
		    "Managing file input and output", "A type of comment"}
	      , 2,
		  "Synchronization in Java is used to ensure that only one thread accesses a shared resource at a time, preventing data corruption."}
	      ,
	      {
		"What is 'ArrayList' in Java?",
		{
		"A type of loop",
		    "A data structure that stores elements in a dynamic array",
		    "A way to define classes", "A keyword to define classes"}
	      , 2,
		  "'ArrayList' in Java is a data structure that stores elements in a dynamic array, providing flexibility in size."}
	      ,
	      {
		"What is 'static block' in Java?",
		{
		"A type of loop", "A way to create static variables",
		    "A block of code that runs when a class is loaded",
		    "A type of comment"}
	      , 3,
		  "A 'static block' in Java is a block of code that runs when a class is loaded, often used for static initialization."}
	      ,
	      {
		"What is 'lambda expression' in Java used for?",
		{
		"Creating objects", "Defining classes",
		    "A way to define and implement functional interfaces concisely",
		    "String manipulation"}
	      , 3,
		  "A 'lambda expression' in Java is used to define and implement functional interfaces concisely, often used in functional programming."}
	      ,
	      {
		"What is 'var' in Java?",
		{
		"A reserved word", "A data type",
		    "A way to create constants",
		    "A keyword to define classes"}
	      , 1,
		  "'var' in Java is a reserved word used for type inference when declaring local variables."}
	      ,
	      {
		"What is 'recursion' in Java?",
		{
		"A type of loop", "A way to call methods recursively",
		    "A process that executes independently",
		    "A type of comment"}
	      , 2,
		  "Recursion in Java is a technique where a method calls itself to solve a problem, often used in solving repetitive tasks."}
	      ,
	      {
		"What is 'generics' in Java used for?",
		{
		"A type of loop",
		    "Defining generic data types to create reusable code",
		    "Managing file input and output", "A type of comment"}
	      , 2,
		  "'Generics' in Java are used for defining generic data types to create reusable and type-safe code."}
	      ,
	      {
		"What is 'JVM' in Java?",
		{
		"A type of loop", "A reserved word",
		    "The Java Virtual Machine, responsible for running Java programs",
		    "A type of comment"}
	      , 3,
		  "'JVM' in Java stands for the Java Virtual Machine, which is responsible for running Java programs."}
	      ,
	      {
		"What is 'GUI' in Java?",
		{
		"A type of loop",
		    "A way to create graphical user interfaces",
		    "A data structure", "A type of comment"}
	      , 2,
		  "'GUI' in Java stands for Graphical User Interface, and it's a way to create interactive and user-friendly applications."}
	      ,
	      {
		"What is 'serialization' in Java used for?",
		{
		"A type of loop", "A way to create static variables",
		    "A mechanism to convert objects into a byte stream",
		    "A type of comment"}
	      , 3,
		  "Serialization in Java is a mechanism used to convert objects into a byte stream for storage or transmission."}
	      ,
	      {
		"What is 'Swing' in Java?",
		{
		"A type of loop", "A reserved word",
		    "A graphical user interface toolkit for Java",
		    "A type of comment"}
	      , 3,
		  "'Swing' in Java is a graphical user interface toolkit used for creating desktop applications."}
	      ,
	      {
		"What is 'event handling' in Java used for?",
		{
		"A type of loop", "Handling exceptions",
		    "Managing resources like files",
		    "Responding to user actions in graphical interfaces"}
	      , 4,
		  "Event handling in Java is used to respond to user actions in graphical interfaces, such as button clicks and mouse events."}
	      ,
	      {
		"What is 'substring' in Java?",
		{
		"A type of loop", "A method to extract a part of a string",
		    "A keyword to define classes", "A type of comment"}
	      , 2,
		  "'substring' in Java is a method used to extract a part of a string based on specified indices."}
	      ,
	      {
		"What is 'casting' in Java?",
		{
		"A type of loop",
		    "A way to convert one data type into another",
		    "A mechanism to convert objects into arrays",
		    "A type of comment"}
	      , 2,
		  "'Casting' in Java is a way to convert one data type into another, allowing for data type conversion."}
	      ,
	      {
		"What is 'Thread.sleep()' in Java used for?",
		{
		"A way to create static variables",
		    "A method to pause the execution of a thread for a specified time",
		    "A way to define classes", "A keyword to define classes"}
	      , 2,
		  "'Thread.sleep()' in Java is a method used to pause the execution of a thread for a specified amount of time."}
	      ,
	      {
		"What is 'JAR' in Java?",
		{
		"A type of loop",
		    "A way to create reusable libraries and packages",
		    "A data structure", "A type of comment"}
	      , 2,
		  "'JAR' in Java stands for Java Archive, and it's used to create reusable libraries and packages for Java applications."}
	      ,
	      {
		"What is 'enum' in Java?",
		{
		"A type of loop", "A reserved word",
		    "A data type for defining a fixed set of constants",
		    "A type of comment"}
	      , 3,
		  "'enum' in Java is a data type used for defining a fixed set of constants or enumerated values."}
	      ,
	      {
		"What is 'applet' in Java?",
		{
		"A type of loop", "A way to create mobile applications",
		    "A type of graphical user interface",
		    "A small Java program that runs within a web browser"}
	      , 4,
		  "An 'applet' in Java is a small Java program that runs within a web browser, providing interactive content."}
	      ,
	      {
		"What is 'reflection' in Java used for?",
		{
		"A type of loop",
		    "A way to analyze and manipulate classes and objects at runtime",
		    "A keyword to define classes", "A type of comment"}
	      , 2,
		  "'Reflection' in Java is a way to analyze and manipulate classes and objects at runtime, often used in frameworks and libraries."}
	      ,
	      {
		"What is 'stream' in Java?",
		{
		"A type of loop",
		    "A way to handle input and output operations",
		    "A data structure", "A type of comment"}
	      , 2,
		  "'Stream' in Java is a way to handle input and output operations, providing efficient data processing."}
	      ,
	      {
		"What is 'Garbage Collection' in Java?",
		{
		"A type of loop", "A way to allocate memory dynamically",
		    "The process of automatically reclaiming memory occupied by objects no longer in use",
		    "A type of comment"}
	      , 3,
		  "Garbage Collection in Java is the process of automatically reclaiming memory occupied by objects that are no longer in use."}
	      ,
	      {
		"What is 'inheritance' in Java?",
		{
		"A type of loop", "A reserved word",
		    "The ability to create a new class from an existing class",
		    "A type of comment"}
	      , 3,
		  "Inheritance in Java allows you to create a new class that inherits properties and behaviors from an existing class."}
	      ,
	      {
		"What is 'encapsulation' in Java?",
		{
		"A type of loop",
		    "A way to protect data by hiding the internal implementation",
		    "A keyword to define classes", "A type of comment"}
	      , 2,
		  "Encapsulation in Java is a way to protect data by hiding the internal implementation, providing control and security."}
	      ,
	      {
		"What is 'variable scope' in Java?",
		{
		"A type of loop", "A way to define variables in a method",
		    "The region in the code where a variable can be accessed",
		    "A type of comment"}
	      , 3,
		  "Variable scope in Java defines the region in the code where a variable can be accessed and used."}
	      ,
	      {
		"What is 'polymorphism' in Java?",
		{
		"A type of loop", "A function that calls itself",
		    "The ability of different objects to respond to the same method call in a way that is appropriate for each object",
		    "A keyword to define classes"}
	      , 3,
		  "Polymorphism in Java allows different objects to respond to the same method call in a way that is appropriate for each object."}



	    };
	  }
      }

    if (allQuestions.size () < 15)
      {
	cout << "Error: Insufficient questions available for the quiz." <<
	  endl;
	return false;
      }
    return true;
  }

  void displayQuestion (const Question & q, int questionNumber)
  {
    system ("clear");
    cout << "Question " << questionNumber << ":" << endl;
    cout << q.question << endl << endl;

    for (size_t i = 0; i < q.options.size (); ++i)
      {
	this_thread::sleep_for (chrono::milliseconds (200));
	cout << setw (2) << i + 1 << ") " << q.options[i] << endl;
      }

    cout << "Enter your answer (1-" << q.options.size () << "): ";
  }

  void playQuiz (const string & quizType)
  {
    set < int >randomIndices;
    while (randomIndices.size () < 15)
      {
	int randomIndex = rand () % allQuestions.size ();
	randomIndices.insert (randomIndex);
      }

    int questionNumber = 1;

    string userName;
    cout << "Enter your name: ";
    cin.ignore ();
    getline (cin, userName);

    if (users.find (userName) == users.end ())
      {
	users[userName] = User (userName);
      }

    User & currentUser = users[userName];
    int correctAnswers = 0;

  for (int index:randomIndices)
      {
	const Question & currentQuestion = allQuestions[index];
	displayQuestion (currentQuestion, questionNumber);
	int userResponse;
	cin >> userResponse;

	while (userResponse < 1
	       || userResponse > currentQuestion.options.size ())
	  {
	    cout << "Invalid option. Please enter a number between 1 and " <<
	      currentQuestion.options.size () << "." << endl;
	    cin.clear ();
	    cin.ignore (numeric_limits < streamsize >::max (), '\n');
	    cout << "Enter your answer (1-" << currentQuestion.options.
	      size () << "): ";
	    cin >> userResponse;
	  }

	if (evaluateResponse (currentQuestion, userResponse))
	  {
	    cout << "Correct!" << endl;
	    correctAnswers++;
	  }
	else
	  {
	    cout << "Incorrect. The correct answer is: " <<
	      currentQuestion.options[currentQuestion.correctOption -
				      1] << endl;
	  }

	cout << "Explanation: " << currentQuestion.explanation << endl;
	pauseForNextQuestion ();
	questionNumber++;
      }

    system ("clear");
    displayQuizResult (userName, quizType, correctAnswers);
  }

  bool evaluateResponse (const Question & q, int response)
  {
    return (response == q.correctOption);
  }

  void pauseForNextQuestion ()
  {
    cout << "Press Enter to continue to the next question...";
    cin.ignore (numeric_limits < streamsize >::max (), '\n');
    cin.get ();
  }

  void displayQuizResult (const string & userName, const string & quizType,
			  int correctAnswers)
  {
    system ("clear");
    cout << "Quiz completed, " << userName << "! Your score in the " <<
      quizType << " quiz: " << correctAnswers << " out of 15" << endl;
    cout << "Press enter to return to the main menu...";
    cin.ignore (numeric_limits < streamsize >::max (), '\n');
    cin.get ();
  }
};

int
main ()
{
  QuizGame quiz;
  quiz.run ();
  return 0;
}
