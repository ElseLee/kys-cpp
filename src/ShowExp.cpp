#include "ShowExp.h"
#include "TextureManager.h"
#include "Font.h"
#include "others/libconvert.h"

ShowExp::ShowExp()
{
    x_ = 100;
    y_ = 100;
}

ShowExp::~ShowExp()
{
}

void ShowExp::draw()
{
    Engine::getInstance()->fillColor({ 0, 0, 0, 192 }, 0, 0, -1, -1);
    for (int i = 0; i < roles_.size(); i++)
    {
        auto r = roles_[i];
        int x = x_ + i % 3 * 300, y = y_ + i / 3 * 200;
        TextureManager::getInstance()->renderTexture("head", r->HeadID, x, y);
        auto str = convert::formatString("%s�@�ý��%d", r->Name, r->ExpGot);
        Font::getInstance()->draw(str, 20, x, y+170, { 255, 255, 255, 255 });
    }
}
