#include <stdio.h>

void incrementAndPrint() {
    // Static variable retains its value between function calls
    // *** Static variables are only accessible within the scope they are declared in ***
    static int count = 0;
    
    // Increment the static variable
    count++;
    
    // Print the current value of the static variable
    printf("Count is now: %d\n", count);
}

int main() {
    // Call the function multiple times
    incrementAndPrint(); // Output: Count is now: 1
    incrementAndPrint(); // Output: Count is now: 2
    incrementAndPrint(); // Output: Count is now: 3
    
    return 0;
}

//////

#include <stdio.h>

void function() {
    // Static const variable
    static const int num = 10; // scope of num: the function block itself
    
    // Attempting to modify the value of a const variable will result in a compilation error
    // num = 20; // Error: assignment of read-only variable 'num'
    // num is only accessible within this scope, however, it is also const, so num can not be assigned new value
    printf("The value of num: %d\n", num);

    /*
     * Both const and static modify the behavior of variables as follows:
     *     const: Indicates that the variable's value cannot be modified after initialization. It creates a read-only variable.
     *     static: Indicates that the variable retains its value between function calls. It has file or function scope, depending on where it's declared.
     * So, whether you declare a variable as const static or static const, the resulting variable will be both constant and static. The order of the qualifiers doesn't change their meaning. It's more a matter of personal preference or coding convention.
     * */
}

int main() {
    // Call the function multiple times
    function(); // Output: The value of num: 10
    function(); // Output: The value of num: 10
    
    return 0;
}


//////
void otherFunction(int count) {
    // Access and use the value of count
    count = count + 100;
    printf("Count received in otherFunction: %d\n", count); // it prints 101, but once returned it is still 1 in the original scope.
}

void otherFunction(int &count) {
    // Access and use the value of count
    count = count + 100;
    printf("Count received in otherFunction: %d\n", count); // it prints 101 because it is passed by reference, otherwise once returned, count is still 1.
}

int main() {
    static int count = 0; // Static variable declared in main()

    count++; // Increment the static variable, now, count: 1

    printf("Count is now: %d\n", count);

    // Pass count to otherFunction
    otherFunction(count);

    printf("Count is now: %d\n", count); // now, count: 101
    return 0;
}

//////
#include <stdio.h>

// Static function declaration
static void staticFunction() {
    // Static functions are commonly used in C to encapsulate functionality within a single file and prevent their usage from other files, making them useful for implementing file-local functions or helper functions that are not intended to be used outside of their own file.
    printf("This is a static function.\n");
}

// Non-static function declaration
void normalFunction() {
    printf("This is a normal function.\n");
}

int main() {
    // Call both static and non-static functions
    staticFunction(); // Output: This is a static function, which can't be called from outside this .cpp file
    normalFunction(); // Output: This is a normal function.
    
    return 0;
}

