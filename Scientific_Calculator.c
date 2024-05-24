#include <stdio.h>
#include <math.h>

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return NAN; // Not-A-Number
    }
}

// Function to calculate sine of an angle
double sine(double angle) {
    return sin(angle);
}

// Function to calculate cosine of an angle
double cosine(double angle) {
    return cos(angle);
}

// Function to solve a quadratic equation
void quadraticSolver(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Root 1: %lf\n", root1);
        printf("Root 2: %lf\n", root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        printf("Root: %lf\n", root);
    } else {
        printf("Complex roots\n");
    }
}

int main() {
    double num1, num2, angle, a, b, c;
    char op;
    
    printf("Welcome to the Scientific Calculator!\n");
    
    while (1) {
        printf("Enter operation (+, -, *, /, s for sine, c for cosine, q to solve quadratic, x to exit): ");
        scanf(" %c", &op);
        
        if (op == 'x') {
            printf("Exiting...\n");
            break;
        }
        
        switch(op) {
            case '+':
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", add(num1, num2));
                break;
            case '-':
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", subtract(num1, num2));
                break;
            case '*':
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", multiply(num1, num2));
                break;
            case '/':
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                printf("Result: %lf\n", divide(num1, num2));
                break;
            case 's':
                printf("Enter angle in radians: ");
                scanf("%lf", &angle);
                printf("Sine: %lf\n", sine(angle));
                break;
            case 'c':
                printf("Enter angle in radians: ");
                scanf("%lf", &angle);
                printf("Cosine: %lf\n", cosine(angle));
                break;
            case 'q':
                printf("Enter coefficients a, b, c for quadratic equation (ax^2 + bx + c = 0): ");
                scanf("%lf %lf %lf", &a, &b, &c);
                quadraticSolver(a, b, c);
                break;
            default:
                printf("Invalid operation\n");
        }
    }
    
    return 0;
}
