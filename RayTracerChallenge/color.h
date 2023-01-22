#pragma once

class Color {
public:
    double red;
    double green;
    double blue;

    Color() {
        red = 0;
        green = 0;
        blue = 0;
    }

    Color(double r, double g, double b) {
        red = r;
        green = g;
        blue = b;
    }

    bool equal(Color c2) {
        return Operations::equal(red, c2.red) && Operations::equal(green, c2.green)
            && Operations::equal(blue, c2.blue);
    }

    Color add(Color c2) {
        return Color(red + c2.red, green + c2.green, blue + c2.blue);
    }

    Color subtract(Color c2) {
        return Color(red - c2.red, green - c2.green, blue - c2.blue);
    }

    Color multiply(double scalar) {
        return Color(red * scalar, green * scalar, blue * scalar);
    }

    Color multiply(Color c2) {
        // Hadamard product -> blending two colors
        return Color(red * c2.red, green * c2.green, blue * c2.blue);
    }
};

std::ostream& operator<<(std::ostream& s, const Color& c) {
    return s << typeid(c).name() << "(red: " << c.red << ", " << " green: " << c.green << ", " << " blue: " << c.blue << ")";
}

TestResults colorTestResults;

void testAddColors() {
    Color c1(0.9, 0.6, 0.75); 
    Color c2(0.7, 0.1, 0.25); 
    Color expectedColor(1.6, 0.7, 1.0);
    bool testPassed = false;

    Color resultColor = c1.add(c2); 

    if(resultColor.equal(expectedColor)) {
        testPassed = true;
    }

    if (testPassed) {
        colorTestResults.passed += 1;
        std::cout << "Test Passed: testAddColors\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
    else {
        colorTestResults.failed += 1;
        std::cout << "Test Failed: testAddColors\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
}

void testSubtractColors() {
    Color c1(0.9, 0.6, 0.75); 
    Color c2(0.7, 0.1, 0.25); 
    Color expectedColor(0.2, 0.5, 0.5);
    bool testPassed = false;

    Color resultColor = c1.subtract(c2); 

    if(resultColor.equal(expectedColor)) {
        testPassed = true;
    }

    if (testPassed) {
        colorTestResults.passed += 1;
        std::cout << "Test Passed: testSubtractColors\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
    else {
        colorTestResults.failed += 1;
        std::cout << "Test Failed: testSubtractColors\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
}

void testMultiplyColorByScalar() {
    Color c1(0.2, 0.3, 0.4); 
    double scalar = 2;
    Color expectedColor(0.4, 0.6, 0.8);
    bool testPassed = false;

    Color resultColor = c1.multiply(scalar);

    if(resultColor.equal(expectedColor)) {
        testPassed = true;
    }

    if (testPassed) {
        colorTestResults.passed += 1;
        std::cout << "Test Passed: testMultiplyColorByScalar\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
    else {
        colorTestResults.failed += 1;
        std::cout << "Test Failed: testMultiplyColorByScalar\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
}

void testMultiplyColorByColor() {
    Color c1(1, 0.2, 0.4); 
    Color c2(0.9, 1, 0.1);
    Color expectedColor(0.9, 0.2, 0.04);
    bool testPassed = false;

    Color resultColor = c1.multiply(c2);

    if(resultColor.equal(expectedColor)) {
        testPassed = true;
    }

    if (testPassed) {
        colorTestResults.passed += 1;
        std::cout << "Test Passed: testMultiplyColorByColor\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
    else {
        colorTestResults.failed += 1;
        std::cout << "Test Failed: testMultiplyColorByColor\n";
        std::cout << "\tResult: " << resultColor << "\n";
        std::cout << "\tExpected: " << expectedColor << "\n";
    }
}

void run_color_tests() {
    testAddColors();
    testSubtractColors();
    testMultiplyColorByScalar();
    testMultiplyColorByColor();

    // print out the percentage that have passed 
    unsigned int totalTests = colorTestResults.passed + colorTestResults.failed;
    std::cout << "\n\n run_color_tests " << colorTestResults.passed << "/" << totalTests << " Passed\n\n";
}