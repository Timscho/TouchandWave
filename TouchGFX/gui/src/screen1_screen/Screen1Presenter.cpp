#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::userInterfaceTick()
{

}

void Screen1Presenter::updatePinState(bool isHigh)
{
    // sending directly to view (screen)
    view.updateMotionState(isHigh);
}
