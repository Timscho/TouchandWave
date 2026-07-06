#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/Color.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    virtual void resetColorClicked();
    void updateMotionState(bool motion);
    virtual void testButtonDown(); // Novo testno dugme

protected:
    bool isMotionPresent;
    float transitionProgress;
    touchgfx::colortype blueColor;
    touchgfx::colortype purpleColor;

    float currentR;
    float currentG;
    float currentB;
};

#endif // SCREEN1VIEW_HPP
