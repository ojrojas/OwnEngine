#include "includes/gamebase.hpp"
#include "includes/texturemanager.hpp"
#include "includes/soundmanager.hpp"

class Game : public GameBase
{

public:
    Game() : GameBase()
    {
        _textureManager = TextureManager::Instance();
        _soundManager = SoundManager::Instance();
    };
    void LoadContent()
    {
        _textureManager->Load("assets/view.png", "level1", _renderer, IMG_INIT_PNG);
        _textureManager->Load("assets/smb_mario_sheet.png", "mario", _renderer, IMG_INIT_PNG);
        _soundManager->Load("assets/MarioPrincipalTheme.mp3", "marioTheme", SOUND_MUSIC, MIX_INIT_MP3);
        _soundManager->Load("assets/smb_1-up.wav", "mario1up", SOUND_SFX, MIX_INIT_OGG);

        _soundManager->PlayMusic("marioTheme", 0);
    }
    void Update(GameTime *gameTime)
    {
        counter--;
    }

    void InputHandle()
    {
        SDL_Event event;

        // (1) Handle Input
        // Start our event loop
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            switch (event.type)
            {
            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_B)
                {
                    _soundManager->PlaySound("mario1up", 0);
                }
                break;
            case SDL_QUIT:
                _isRunning = false;
                break;
            default:
                break;
            }
            if (event.type == SDL_QUIT)
            {
                _isRunning = false;
            }
        }
    }

    void Draw(GameTime *gameTime)
    {
        _textureManager->BeginRender(_renderer); // most be only one
        _textureManager->Draw("level1", counter, 0, 3584, 240, _renderer);
        _textureManager->DrawFrame("mario", _renderer, {300, 0, 30, 16}, {x : 80, y : 192, w : 32, h : 16});
        _textureManager->FinishRender(_renderer); // most be only one
    }

private:
    int counter = 0;
    TextureManager *_textureManager;
    SoundManager *_soundManager;
};