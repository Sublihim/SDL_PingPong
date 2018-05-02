#include "SceneMgr.h"
#include "SceneGame.h"
#include "SceneMenu.h"

SceneMgr::SceneMgr()
{
    //add_scene(new SceneGame(ball_move_logic::mikriVision));
    //add_scene(new SceneGame(ball_move_logic::nZemekisVision));
    add_scene(new SceneMenu());
}

void SceneMgr::add_scene(Scene *scene, bool set_active)
{
    v_scenes.push_back(scene);
    if(set_active)
        active = scene;
}

void SceneMgr::render(SDL_Renderer *renderer)
{
    active->render(renderer);
}

void SceneMgr::process_mouse_motion(Sint32 x, Sint32 y)
{
    active->process_mouse_motion(x, y);
}

void SceneMgr::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    active->process_mouse_button_event(m_btn_event);
}

void SceneMgr::process_keyboard_keydown(SDL_Keycode keycode)
{
    active->process_keyboard_keydown(keycode);
}
