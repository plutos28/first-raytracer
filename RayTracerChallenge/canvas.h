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

    void setBackgroundColor(Color c) {
        // traverse array and set every pixel to color c
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                *(pixels + i * height + j) = c;
            }
        }
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
    std::string headerContent;
    std::string pixelContent;
    PPM(size_t w, size_t h) {
        // Add PPM Header
        std::string line1 = "P3\n";
        std::string line2 = std::to_string(w) + " " + std::to_string(h) + "\n";
        std::string line3 = "255\n";

        headerContent = line1 + line2 + line3;

        content += headerContent;
    }
};

TestResults canvasTestResults;

PPM CanvasToPPM(Canvas& c) {
    PPM p(c.width, c.height);
    int max_colors = 256;
    size_t max_line_length = 70;

    for (int i = 0; i < c.height; i++) { // row(i)
        for (int j = 0; j < c.width; j++) { // column(j)
            // we need to make sure that lines are not longer than 70 characters, for now I'll only do the check once
            // and then split the lines into two, but in the future I think it'll be necessary to split it multiple times
            // if the width of the canvas is very large
            // Splitting doesn't happen exactly at 70 characters but should instead happen when 
            // the current line plus the new color values are greater than 70 than we have to split so that 
            // that next color goes over to the next line
            Color* current_color = (c.pixels + j + (c.height * i));

            // we can't just multiply by max_line_length, we also need to move the substring who's size we're considering
            // hack: for now just multiply the max_line_length by the row number(i)
            // potentially better: would be using different substrings as we move along
            if (p.pixelContent.size() + (current_color->toPPM() + " ").size() > max_line_length*(i+1)) {
                p.pixelContent += "\n";
                p.pixelContent += current_color->toPPM() + " ";
            }
            else {
                p.pixelContent += current_color->toPPM() + " ";
            }
            
        }
        p.pixelContent.pop_back(); // remove an extra epace at the end as we add spaces after each color value
        p.pixelContent += "\n";
    }
    p.content += p.pixelContent;

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

    if (p.headerContent == expectedContent) {
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
    c.writePixel(4, 2, c3);
    PPM p = CanvasToPPM(c);

    std::string expectedContent = 
        "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n"
        "0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";

    bool testPassed = false;

    if (p.pixelContent == expectedContent) {
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

void testSplittingLongLinesInPPM() {
    Canvas c(10, 2);
    c.setBackgroundColor(Color(1, 0.8, 0.6));
    PPM p = CanvasToPPM(c);

    std::string expectedContent = 
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
        "153 255 204 153 255 204 153 255 204 153 255 204 153\n"
        "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n"
        "153 255 204 153 255 204 153 255 204 153 255 204 153\n";

    bool testPassed = false;

    if (p.pixelContent == expectedContent) {
        testPassed = true;
    }

    if (testPassed) {
        canvasTestResults.passed += 1;
        std::cout << "Test Passed: testSplittingLongLinesInPPM\n";
    }
    else {
        canvasTestResults.failed += 1;
        std::cout << "Test Failed: testSplittingLongLinesInPPM\n";
    }
}


void run_canvas_tests() {
    testCanvasCreation();
    testWritePixel();
    testConstructingPPMHeader();
    testConstructingPPMPixelData();
    testSplittingLongLinesInPPM();

    // print out the percentage that have passed 
    unsigned int totalTests = canvasTestResults.passed + canvasTestResults.failed;
    std::cout << "\n\n run_canvas_tests " << canvasTestResults.passed << "/" << totalTests << " Passed\n\n";
}