#pragma once

class GameObject;

class Component
{
public:
    virtual ~Component() = default;
    virtual void act(GameObject& gameObject, float dt) = 0;

    virtual void onCollision(GameObject& gameObject, GameObject& other);
};
