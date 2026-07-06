#include <gui/screen1_screen/Screen1View.hpp>
#include <touchgfx/Color.hpp>

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    // start screen is white
    currentR = 250.0f;
    currentG = 250.0f;
    currentB = 250.0f;

    isMotionPresent = false;

    blueColor   = touchgfx::Color::getColorFromRGB(250, 250, 250);
    purpleColor = touchgfx::Color::getColorFromRGB(125, 0, 125);

    box1.setColor(blueColor);
    box1.invalidate();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::testButtonDown()
{
	 isMotionPresent = !isMotionPresent;
	 box1.invalidate();
}

// main loop, 60 fps
void Screen1View::handleTickEvent()
{
    bool colorChanged = false;

    if (isMotionPresent)
    {
        // color gradually changing
        if (currentR > 125.0f) { currentR -= 1.0f; colorChanged = true; }
        if (currentG > 0.0f)   { currentG -= 2.0f; colorChanged = true; }
        if (currentB > 125.0f) { currentB -= 1.0f; colorChanged = true; }

        if (currentR < 125.0f) currentR = 125.0f;
        if (currentG < 0.0f)   currentG = 0.0f;
        if (currentB < 125.0f) currentB = 125.0f;
    }

    if (colorChanged)
    {
        box1.setColor(touchgfx::Color::getColorFromRGB((uint8_t)currentR, (uint8_t)currentG, (uint8_t)currentB));
        box1.invalidate();
    }
}

void Screen1View::resetColorClicked()
{
    currentR = 250.0f;
    currentG = 250.0f;
    currentB = 250.0f;
    box1.setColor(touchgfx::Color::getColorFromRGB(250, 250, 250));
    isMotionPresent = false;
    box1.invalidate();
}

void Screen1View::updateMotionState(bool motion)
{
    isMotionPresent = motion;
}
