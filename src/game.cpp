#include "includes/gamebase.hpp"
#include "includes/texturemanager.hpp"

class Game : public GameBase
{

public:
    Game():GameBase()
    {
        _textureManager = TextureManager::Instance();
    };
    void LoadContent()
    {
        _textureManager->Load("assets/view.png", "level1", _renderer, IMG_INIT_PNG);
        _textureManager->Load("assets/smb_mario_sheet.png", "mario", _renderer, IMG_INIT_PNG);
    }
    void Update(GameTime *gameTime)
    {
        counter--;
        std::cout << "rate fps: " << gameTime->GetTotalGameTime().GetValue() << std::endl;
    }
    void Draw(GameTime *gameTime)
    {
        _textureManager->BeginRender(_renderer); // most be only one
        _textureManager->Draw("level1", counter, 0, 3584, 240, _renderer);
        _textureManager->DrawFrame("mario", _renderer, {300, 0, 30, 16}, {x : 80, y : 192, w : 32, h : 16});
        _textureManager->FinishRender(_renderer); // most be only one
    }
    private :
    int counter = 0;
    TextureManager *_textureManager;
};