#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "main.h"

Model::Model() : modelListener(0), motionActive(false), lastMotionState(false)
{
}

void Model::tick()
{
    motionActive = (HAL_GPIO_ReadPin(PIR_SENSOR_GPIO_Port, PIR_SENSOR_Pin) == GPIO_PIN_SET);

    if (motionActive != lastMotionState)
    {
        lastMotionState = motionActive;

        if (modelListener != 0)
        {
            // inform modelListener
            modelListener->updatePinState(motionActive);
        }
    }
}
