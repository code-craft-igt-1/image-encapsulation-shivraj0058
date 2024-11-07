#include "./brightener.h"

ImageBrightener::ImageBrightener(std::unique_ptr<Image> inputImage)
    : m_inputImage(std::move(inputImage)) {
}

bool ImageBrightener::ValidateImage() {
    if (m_inputImage->m_columns <= 1024 && m_inputImage->m_rows <= 1024) {
        return true;
    } else {
        return false;
    }
}

int ImageBrightener::BrightenWholeImage() {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;
    for (int x = 0; x < m_inputImage->m_rows; x++) {
        for (int y = 0; y < m_inputImage->m_columns; y++) {
            if (m_inputImage->GetPixel(x, y) > (255 - 25)) {
                ++attenuatedPixelCount;
                m_inputImage->SetPixel(x, y, 255);
            } else {
                int pixelIndex = x * m_inputImage->m_columns + y;
                m_inputImage->SetPixel(x, y, m_inputImage->GetPixel(x, y) + 25);
            }
        }
    }
    return attenuatedPixelCount;
}
