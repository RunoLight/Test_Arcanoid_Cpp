#pragma once
#include <functional>
#include <memory>
#include <vector>

#include "Component.h"
#include "Renderer.h"
#include "../Utils.h"

class GameObject
{
public:
    GameObject(float x, float y, float width = 0, float height = 0);

    float getX() const;
    float getY() const;

    POINT getPosition() const;

    float getWidth() const;
    float getHeight() const;

    POINT getSize() const;

    void setPosition(float x, float y);

    void act(float dt);
    void render() const;

    void registerComponent(std::unique_ptr<Component> component);
    void registerRenderer(std::unique_ptr<Renderer> renderer);

    void destroy();
    void setOnDestroyCallback(const std::function<void()>& newOnDestroyCallback);

    bool isEnabled() const;

    void onCollision(GameObject& other);

private:
    float myX = 0;
    float myY = 0;

    float myWidth = 0;
    float myHeight = 0;

    bool myEnabled = true;
    std::function<void()> onDestroyCallback = nullptr;

    std::vector<std::unique_ptr<Component>> myComponents;
    std::vector<std::unique_ptr<Renderer>> myRenderers;
};
