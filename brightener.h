#pragma once
#include "image.h"

class ImageBrightener {
private:
	std::unique_ptr<Image> m_inputImage;
public:
	ImageBrightener(std::unique_ptr<Image> inputImage);
	bool ValidateImage();
	int BrightenWholeImage();
};
