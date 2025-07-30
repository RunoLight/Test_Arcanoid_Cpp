#include "GameObject.h"

#include "BaseSolution/Engine.h"

GameObject::GameObject(float x, float y, float width, float height) : myX(x), myY(y), myWidth(width), myHeight(height) {}

float GameObject::getX() const
{
    return myX;
}

float GameObject::getY() const
{
    return myY;
}

POINT GameObject::getPosition() const
{
    return POINT(myX, myY); 
}

float GameObject::getWidth() const
{
    return myWidth;
}

float GameObject::getHeight() const
{
    return myHeight;
}

std::pair<float, float> GameObject::getSize() const
{
    return POINT(myWidth, myHeight);
}

void GameObject::setPosition(float x, float y)
{
    const float maxX = SCREEN_WIDTH - myWidth / 2;
    const float minX = 0 + myWidth / 2;
    const float maxY = SCREEN_HEIGHT - myHeight / 2;
    const float minY = 0 + myHeight / 2;
    myX = std::max(std::min(x, maxX), minX);
    myY = std::max(std::min(y, maxY), minY);
}

void GameObject::act(float dt)
{
    for (const std::unique_ptr<Component>& component : myComponents)
    {
        component->act(*this, dt);
    }
}

void GameObject::render() const
{
    for (const std::unique_ptr<Renderer>& renderer : myRenderers)
    {
        renderer->render(*this);
    }
}

// todo: double ref for ptrs?
void GameObject::registerComponent(std::unique_ptr<Component> component)
{
    myComponents.push_back(std::move(component));
}

void GameObject::registerRenderer(std::unique_ptr<Renderer> renderer)
{
    myRenderers.push_back(std::move(renderer));
}

void GameObject::destroy()
{
    myEnabled = false;
    if (onDestroyCallback != nullptr)
        onDestroyCallback();
}

void GameObject::setOnDestroyCallback(const std::function<void()>& newOnDestroyCallback)
{
    this->onDestroyCallback = newOnDestroyCallback;
}

bool GameObject::isEnabled() const
{
    return myEnabled;
}

void GameObject::onCollision(GameObject& other)
{
    for (const auto& component : myComponents)
    {
        component->onCollision(*this, other);
    }
}





