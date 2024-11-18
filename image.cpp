#include "./image.h"
#include <iostream>
#include <memory>

Image::Image(uint16_t rows, uint16_t columns) : m_rows(rows), m_columns(columns) {
    pixels = std::make_unique<uint8_t[]>(rows * columns);
}

Image::~Image() {
    std::cout << "Image destroyed. Pixel memory automatically freed.\n";
}

uint8_t Image::GetPixel(uint16_t x, uint16_t y) const {
    return pixels[x * m_columns + y];
}

void Image::SetPixel(uint16_t x, uint16_t y, uint8_t value) {
    pixels[x * m_columns + y] = value;
}
bool Image::ValidateImage() const {
    if (m_columns <= 1024 && m_rows <= 1024) {
        return true;
    } else {
        return false;
    }
}
