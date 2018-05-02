#include "SceneMgr.h"
#include "SceneGame.h"
#include "SceneMenu.h"
#include "SceneMenuPause.h"

SceneMgr::SceneMgr()
{
    add_scene(new SceneMenu()); // �������� ����
    add_scene(new SceneMenuPause(), false); // ���� �����
}

void SceneMgr::add_scene(Scene *scene, bool set_active)
{
    v_scenes.push_back(scene);
    if(set_active)
    {
        active = scene;
        active->setPaused(false);
    }
}

void SceneMgr::render(SDL_Renderer *renderer)
{
    active->render(renderer);
}

gameReaction SceneMgr::process_mouse_motion(Sint32 x, Sint32 y)
{
    return active->process_mouse_motion(x, y);
}

gameReaction SceneMgr::process_mouse_button_event(SDL_MouseButtonEvent m_btn_event)
{
    gameReaction gr = active->process_mouse_button_event(m_btn_event);
    if(gr == gameReaction::gr_start_new_mikri)
    {
        add_scene(new SceneGame(ball_move_logic::mikriVision));
        return gameReaction::gr_ignore;
    }
    else if(gr == gameReaction::gr_start_new_zemekis)
    {
        add_scene(new SceneGame(ball_move_logic::nZemekisVision));
        return gameReaction::gr_ignore;
    }
    else if(gr == gameReaction::gr_continue)
    {
        // ���� �����, ������������ � ����
        active = v_scenes[2];
        active->setPaused(false);
        active->setFirstRenderState(true);
        return gameReaction::gr_ignore;
    }
    else
        return gr;
}

gameReaction SceneMgr::process_keyboard_keydown(SDL_Keycode keycode)
{
    gameReaction gr = gameReaction::gr_ignore;

    if(keycode == SDLK_ESCAPE)
    {
        if(active == v_scenes[2])
        {
            // ���� ���� - ������ �� �� �����
            active->setPaused(true);
            // �������� ���������� � ���� �����
            active = v_scenes[1];
            active->setFirstRenderState(true);
        }
        else if(active == v_scenes[1])
        {
            // ���� �����, ������������ � ����
            active = v_scenes[2];
            active->setPaused(false);
            active->setFirstRenderState(true);
        }
        else // ������� �� ����
            gr = gameReaction::gr_exit;
    }
    else
        gr = active->process_keyboard_keydown(keycode);

    return gr;
}
