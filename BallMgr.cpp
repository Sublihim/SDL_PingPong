#include "BallMgr.h"

BallMgr::BallMgr(SDL_Point p_begin, int radius)
{
    ball = new Ball();
    ball->setCentreXY(p_begin.x, p_begin.y);
    ball->setRadius(radius);
    srand(time(NULL));
    chg_dir_angle();
}

void BallMgr::chg_dir_angle()
{
    // ������������ � ������������
    // 1. ����� ����� ���� ��� �����
    int direction = rand()%50;
    // ��� ������������ ������ - ����� ��� ����
    if(direction%2 == 0) // ����� ����� - �� 30 �� 150 ��������
        dir_angle = rand()%120 + 31;
    else // ����� ���� - �� 210 �� 330
        dir_angle = rand()%120 + 211;
}

void BallMgr::draw(SDL_Renderer *renderer)
{
    ball->draw(renderer);
}
