#pragma once

class Canvas {
public:
    size_t width;
    size_t height;
    //Color* pixels;

    Canvas(size_t w, size_t h) {
        width = w;
        height = h;
        //pixels = new Color[width * height];
    }

    // ~Canvas() {
    //     // destructor called when object goves out of scope
    //     // we want to free the pixels dynamic array
    //     delete[] pixels;
    // }
};

std::ostream& operator<<(std::ostream& s, const Canvas& c) {
    return s << typeid(c).name() << "(width: " << c.width << ", " << "height: " << c.height << ")";
}

TestResults canvasTestResults;

void testCanvasCreation() {
    Canvas c(10, 20);
    bool testPassed = false;

    if (c.width == 10 && c.height == 20) {
        // also check that every pixel is black(Color(0, 0, 0))
        testPassed = true;
    }

    if (testPassed) {
        canvasTestResults.passed += 1;
        std::cout << "Test Passed: testCanvasCreation\n";
        std::cout << "\tResult: " << c << "\n";
    }
    else {
        canvasTestResults.failed += 1;
        std::cout << "Test Failed: testCanvasCreation\n";
        std::cout << "\tResult: " << c << "\n";
    }
}

void run_canvas_tests() {
    testCanvasCreation();

    // print out the percentage that have passed 
    unsigned int totalTests = canvasTestResults.passed + canvasTestResults.failed;
    std::cout << "\n\n run_canvas_tests " << canvasTestResults.passed << "/" << totalTests << " Passed\n\n";
}