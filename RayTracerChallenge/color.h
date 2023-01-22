#pragma once

class Color {
public:
    double red;
    double green;
    double blue;

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

void run_color_tests() {
    testAddColors();

    // print out the percentage that have passed 
    unsigned int totalTests = colorTestResults.passed + colorTestResults.failed;
    std::cout << "\n\n run_color_tests " << colorTestResults.passed << "/" << totalTests << " Passed\n";
}