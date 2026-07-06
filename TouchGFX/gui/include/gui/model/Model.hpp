#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();
    void bind(ModelListener* listener) { modelListener = listener; }
    void tick();

    bool isMotionDetected() { return motionActive; }

protected:
    ModelListener* modelListener;
    bool motionActive;
    bool lastMotionState;
};

#endif // MODEL_HPP
