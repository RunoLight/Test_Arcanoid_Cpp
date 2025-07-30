#include <vector>
#include "Utils.h"

#include "ArcanoidGame/ArkanoidGame.h"
#include "Engine/BaseSolution/Engine.h"
#include "Engine/GameObject.h"

//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()
ArkanoidGame game;

std::vector<std::unique_ptr<GameObject>> myGameObjects;

void addGameObject(std::unique_ptr<GameObject> go)
{
    for (auto& myGameObject : myGameObjects)
    {
        if (!myGameObject->isEnabled())
        {
            myGameObject = std::move(go);
            return;
        }
    }

    myGameObjects.push_back(std::move(go));
}

void initialize()
{
    game.initialize(myGameObjects);
}

void physicsAct()
{
    for (const auto& go1 : myGameObjects)
    {
        if (!go1->isEnabled())
            continue;

        for (const auto& go2 : myGameObjects)
        {
            if (!go2->isEnabled() || go1 == go2)
                continue;

            if (isIntersect(go1->getPosition(), go1->getSize(), go2->getPosition(), go2->getSize()) ||
                isIntersect(go2->getPosition(), go2->getSize(), go1->getPosition(), go1->getSize()))
            {
                go1->onCollision(*go2);
            }
        }
    }
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
    if (is_key_pressed(VK_ESCAPE))
        schedule_quit_game();

game.act(dt);
    
    for (const auto& go : myGameObjects)
    {
        if (go->isEnabled())
            go->act(dt);
    }

    physicsAct();
}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
    // Clear backbuffer
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));

    for (const auto& go : myGameObjects)
    {
        if (go->isEnabled())
            go->render();
    }
}

// free game data in this function
void finalize()
{
    myGameObjects.clear();
}
