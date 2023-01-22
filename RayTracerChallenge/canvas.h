#pragma once

class Canvas {
public:
    size_t width;
    size_t height;
    Color* pixels;

    Canvas(size_t w, size_t h) {
        width = w;
        height = h;
        pixels = new Color[width * height];

        // traverse array and set every pixel to black
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                *(pixels + i * height + j) = Color(0, 0, 0);
            }
        }
    }

    void writePixel(size_t x, size_t y, Color color) {
        pixels[height*y+x] = color;
    }

    Color pixelAt(size_t x, size_t y) {
        return pixels[height * y + x];
    }

    ~Canvas() {
        // destructor called when object goves out of scope
        // we want to free the pixels dynamic array
        delete[] pixels;
    }
};

std::ostream& operator<<(std::ostream& s, const Canvas& c) {
    return s << typeid(c).name() << "(width: " << c.width << ", " << "height: " << c.height << ")";
}

TestResults canvasTestResults;

void testCanvasCreation() {
    Canvas c(10, 20);
    bool testPassed = false;

    if (c.width == 10 && c.height == 20) {
        // traverse array and check every pixel is black
        bool allBlack = true;
        for (int i = 0; i < c.width; i++) {
            for (int j = 0; j < c.height; j++) {
                if ((*(c.pixels + i * c.height + j)).equal(Color(0, 0, 0))) {
                    allBlack = true;
                }
                else {
                    allBlack = false;
                }
            }
        }
        if (allBlack) {
            testPassed = true;
        }
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

void testWritePixel() {
    Canvas c(10, 20);
    Color red(1, 0, 0);
    bool testPassed = false;

    c.writePixel(2, 3, red);

    if (c.pixelAt(2, 3).equal(red)) {
        testPassed = true;
    }

    if (testPassed) {
        canvasTestResults.passed += 1;
        std::cout << "Test Passed: testWritePixel\n";
    }
    else {
        canvasTestResults.failed += 1;
        std::cout << "Test Failed: testWritePixel\n";
    }
}

void run_canvas_tests() {
    testCanvasCreation();
    testWritePixel();

    // print out the percentage that have passed 
    unsigned int totalTests = canvasTestResults.passed + canvasTestResults.failed;
    std::cout << "\n\n run_canvas_tests " << canvasTestResults.passed << "/" << totalTests << " Passed\n\n";
}