#pragma once
#include <memory>
#include "./image.h"

class ImageBrightener {
 private:
    std::unique_ptr<Image> m_inputImage;
 public:
    explicit ImageBrightener(std::unique_ptr<Image> inputImage);
    bool ValidateImage();
    int BrightenWholeImage();
};
