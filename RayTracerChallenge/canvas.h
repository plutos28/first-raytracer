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
        // To write to a pixel, we have to get the right address in the memory block pixels which is a long line sized
        // width * height and contains Color objects at each address pixels points to Color* so we have to deference to change value
        // to get to the right address, we first add x to pixels to get the right x location then we have to multiply height*y to get the
        // right row which then we add to pixels+x to get the correct address
        *(pixels + x + (height*y)) = color;
    }

    Color readPixel(size_t x, size_t y) {
        return *(pixels + x + (height*y));
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

class PPM {
public:
    std::string content;
    PPM(size_t w, size_t h) {
        // Add PPM Header
        std::string line1 = "P3\n";
        std::string line2 = std::to_string(w) + " " + std::to_string(h) + "\n";
        std::string line3 = "255\n";

        content = line1 + line2 + line3;
    }
};

TestResults canvasTestResults;

PPM CanvasToPPM(Canvas& c) {
    PPM p(c.width, c.height);
    int max_colors = 256;

    // traverse array and convert each line of canvas onto ppm
    // for (int i = 0; i < c.height; i++) {
    //     std::string current_line = "";
    //     for (int j = 0; j < c.width; j++) {
    //         Color* current_color = (c.pixels + i * c.height + j);
    //         std::string current_color_ppm = std::to_string(current_color->red*max_colors) + " " 
    //             + std::to_string(current_color->green*max_colors) + " " + std::to_string(current_color->blue*max_colors);
    //         current_line += current_color_ppm;
    //     }
    //     current_line += "\n";
    //     p.content += current_line;
    // }

    return p;
}

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

    if (c.readPixel(2, 3).equal(red)) {
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

void testConstructingPPMHeader() {
    Canvas c(5, 3);
    PPM p = CanvasToPPM(c);
    std::string expectedContent = 
        "P3\n"
        "5 3\n"
        "255\n";

    bool testPassed = false;

    if (p.content == expectedContent) {
        testPassed = true;
    }

    if (testPassed) {
        canvasTestResults.passed += 1;
        std::cout << "Test Passed: testConstructingPPMHeader\n";
    }
    else {
        canvasTestResults.failed += 1;
        std::cout << "Test Failed: testConstructingPPMHeader\n";
    }
}

void testConstructingPPMPixelData() {
    Canvas c(5, 3);
    Color c1(1.5, 0, 0);
    Color c2(0, 0.5, 0);
    Color c3(-0.5, 0, 1);

    c.writePixel(0, 0, c1);
    c.writePixel(2, 1, c2);
    c.writePixel(3, 2, c3);
    PPM p = CanvasToPPM(c);

    std::string expectedContent = 
        "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";

    bool testPassed = false;

    if (p.content == expectedContent) {
        testPassed = true;
    }

    if (testPassed) {
        canvasTestResults.passed += 1;
        std::cout << "Test Passed: testConstructingPPMPixelData\n";
    }
    else {
        canvasTestResults.failed += 1;
        std::cout << "Test Failed: testConstructingPPMPixelData\n";
    }
}


void run_canvas_tests() {
    testCanvasCreation();
    testWritePixel();
    testConstructingPPMHeader();
    testConstructingPPMPixelData();

    // print out the percentage that have passed 
    unsigned int totalTests = canvasTestResults.passed + canvasTestResults.failed;
    std::cout << "\n\n run_canvas_tests " << canvasTestResults.passed << "/" << totalTests << " Passed\n\n";
}