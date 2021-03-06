#include "SceneMgr.h"
#include "SceneMenu.h"
#include "SceneMenuPause.h"

SceneMgr::SceneMgr()
{
    add_scene(new SceneMenu()); // Основное меню
}

SceneMgr::~SceneMgr()
{
    // Удаляем сцены
    delete_all_scenes();
#ifdef DEBUG_MESSAGES_SHOW
    std::cout << "SceneMgr end\n";
#endif // DEBUG_MESSAGES_SHOW
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

void SceneMgr::delete_all_scenes()
{
    // Удаляем сцены
#ifdef DEBUG_MESSAGES_SHOW
    int i = 0;
#endif // DEBUG_MESSAGES_SHOW
    for(auto it : v_scenes)
    {
#ifdef DEBUG_MESSAGES_SHOW
        std::cout << "i = " << i << " begin\n";
#endif // DEBUG_MESSAGES_SHOW
        delete it;
#ifdef DEBUG_MESSAGES_SHOW
        std::cout << "i = " << i << " end\n";
        i++;
#endif // DEBUG_MESSAGES_SHOW
    }
    v_scenes.clear();
}

void SceneMgr::reinit()
{
    delete_all_scenes();
    add_scene(new SceneMenu()); // Основное меню
}

void SceneMgr::start_new_game(ball_move_logic bmv)
{
    add_scene(new SceneGame(bmv));
    add_scene(new SceneMenuPause(), false); // Меню паузы
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
        start_new_game(ball_move_logic::mikriVision);
        gr = gameReaction::gr_ignore;
    }
    else if(gr == gameReaction::gr_start_new_zemekis)
    {
        start_new_game(ball_move_logic::nZemekisVision);
        gr = gameReaction::gr_ignore;
    }
    else if(gr == gameReaction::gr_continue)
    {
        // Если пауза, возвращаемся в игру
        active = v_scenes[1];
        active->setPaused(false);
        active->setFirstRenderState(true);
        gr = gameReaction::gr_ignore;
    }
    else if(gr == gameReaction::gr_main_menu)
    {
        // Сбрасываем все и запускаем главное меню
        reinit();
        gr = gameReaction::gr_ignore;
    }

    return gr;
}

gameReaction SceneMgr::process_keyboard_keydown(SDL_Keycode keycode)
{
    gameReaction gr = gameReaction::gr_ignore;

    if(keycode == SDLK_ESCAPE)
    {
        if(active == v_scenes[1])
        {
            // Если игра - ставим ее на паузу
            active->setPaused(true);
            // Передаем управление в меню паузы
            active = v_scenes[2];
            active->setFirstRenderState(true);
        }
        else if(active == v_scenes[2])
        {
            // Если пауза, возвращаемся в игру
            active = v_scenes[1];
            active->setPaused(false);
            active->setFirstRenderState(true);
        }
        else // Выходим из игры
            gr = gameReaction::gr_exit;

    }
    else
        gr = active->process_keyboard_keydown(keycode);

    return gr;
}
