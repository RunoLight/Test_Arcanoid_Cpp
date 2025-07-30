#pragma once
#include "../Engine/Component.h"

class PlatformComponent : public Component
{
public:
    PlatformComponent(float paddleSpeed, float myWidth, float myHeight)
    {
        speed = paddleSpeed;
        this->myWidth = myWidth;
        this->myHeight = myHeight;
    }

    virtual void act(GameObject& gameObject, float dt) override;

    float getWidth() const;
    float getHeight() const;

private:
    float myWidth = 200;
    float myHeight = 10;
    float speed;
};
