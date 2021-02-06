#include "../../../Headers/Class/Game/Game.hpp"

#include <SDL.h>

#include "../../../Headers/Class/Game/Ball.hpp"
#include "../../../Headers/Class/Game/Player.hpp"

#include "../../../Headers/Class/Menu/Text.hpp"
#include "../../../Headers/Class/Menu/Button.hpp"
#include "../../../Headers/Class/Menu/Slider.hpp"
#include "../../../Headers/Class/Menu/Image.hpp"
#include "../../../Headers/Class/Menu/Menu.hpp"

#include "../../../Headers/Functions/Events.hpp"
#include "../../../Headers/Functions/TextsManagement.hpp"
#include "../../../Headers/Functions/TexturesManagement.hpp"
#include "../../../Headers/Functions/SoundsManagement.hpp"

bool Game::keys[0x4000011A];
bool Game::mouses[7];
int Game::mousePos[3];
int Game::wheel;

Menu TitleScreen;
    Text* Title = nullptr;
    Text* remastered = nullptr;
    Button* Play = nullptr;
    Button* OptionsButton = nullptr;
    Button* QuitTitle = nullptr;

Menu Pause;
    Text* TitlePause = nullptr;
    Button* Resume = nullptr;
    Button* QuitPause = nullptr;

Menu Options;
    Text* QuitOptions = nullptr;
    Text* SoundTest = nullptr;
    Text* TouchP1 = nullptr;
    Text* TouchP2 = nullptr;
    Text* Serv = nullptr;
    Slider* volume = nullptr;
    Image* volumeIcon = nullptr;

Menu Modes;
    Text* Choose = nullptr;
    Button* vsP = nullptr;
    Button* vsIA = nullptr;
    Button* secret = nullptr;


SDL_Renderer* Game::renderer;
std::vector<Element*> Game::ElementsInGame;

//In Game
Player P1(true,false),P2(false,false);
SDL_Rect table = {245,0,10,500};
SDL_Rect tiret = {225,20,50,10};
Text* Score1;
Text* Score2;

Game::Game() { Init("Pong",SDL_WINDOW_SHOWN,500,500,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED); }

Game::~Game() {

    Clean();

}

void Game::Init(std::string WindowName,SDL_WindowFlags WindowMode,int resolutionX,int resolutionY,int x,int y) {

    run = true;
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

        windowGame = SDL_CreateWindow(WindowName.c_str(),x,y,resolutionX,resolutionY,WindowMode);
        renderer = SDL_CreateRenderer(windowGame,-1,0);

    }

    ImageInit();
    TextInit();
    SoundInit();

    //Title Screen
        Title = new Text("PONG",50,new Uint8[3]{255,0,0});
        remastered = new Text("remastered",10,new Uint8[3]{255,0,0});
        Play = new Button("PLAY",30,new Uint8[3]{0,255,0});
        OptionsButton = new Button("OPTIONS",30,new Uint8[3]{255,255,0});
        QuitTitle = new Button("QUIT",30,new Uint8[3]{255,0,0});
        Title->SetPos(150,100);
        Title->AddContour(5,new Uint8[3]{0,0,255});
        remastered->SetPos(350,120);
        remastered->AddContour(5,new Uint8[3]{0,0,255});
        Play->SetPos(150,150);
        OptionsButton->SetPos(150,200);
        QuitTitle->SetPos(150,250);
        TitleScreen.AddWidget(Title);
        TitleScreen.AddWidget(remastered);
        TitleScreen.AddWidget(Play);
        TitleScreen.AddWidget(OptionsButton);
        TitleScreen.AddWidget(QuitTitle);

    //Options
        QuitOptions = new Text("press \"escape\" to menu",10,new Uint8[3]{255,255,255});
        SoundTest = new Text("press \"space\" to test sound",10,new Uint8[3]{255,255,255});
        TouchP1 = new Text("P1: use arrow up/down for mouv",10,new Uint8[3]{255,255,255});
        TouchP2 = new Text("P2: use mouse or (z/w)/s for mouv",10,new Uint8[3]{255,255,255});
        Serv = new Text("press \"space\" (in game) to serv",10,new Uint8[3]{255,255,255});
        volume = new Slider();
        volumeIcon = new Image("song.png");
        QuitOptions->SetPos(125,300);
        SoundTest->SetPos(125,320);
        TouchP1->SetPos(125,340);
        TouchP2->SetPos(125,360);
        Serv->SetPos(125,380);
        volume->SetPos(125,200);
        volume->SetValue(120);
        volumeIcon->SetPos(300,183);
        volumeIcon->SetSize(40);
        Options.AddWidget(QuitOptions);
        Options.AddWidget(SoundTest);
        Options.AddWidget(TouchP1);
        Options.AddWidget(TouchP2);
        Options.AddWidget(Serv);
        Options.AddWidget(volume);
        Options.AddWidget(volumeIcon);

    //Pause
        TitlePause = new Text("PAUSE",50,new Uint8[3]{255,255,255});
        Resume = new Button("RESUME",30,new Uint8[3]{0,255,0});
        QuitPause = new Button("QUIT",30,new Uint8[3]{255,0,0});
        TitlePause->SetPos(150,200);
        Resume->SetPos(150,250);
        QuitPause->SetPos(150,300);
        Pause.AddWidget(TitlePause);
        Pause.AddWidget(Resume);
        Pause.AddWidget(QuitPause);

    //Modes
        Choose = new Text("Choose Play Mode",20,new Uint8[3]{255,255,255});
        vsP = new Button("PLAYER VS PLAYER",20,new Uint8[3]{0,255,0});
        vsIA = new Button("PLAYER VS CPU",20,new Uint8[3]{0,255,0});
        secret = new Button("CPU VS CPU",20,new Uint8[3]{0,255,0});
        Choose->SetPos(110,200);
        vsP->SetPos(20,250);
        vsIA->SetPos(20,280);
        secret->SetPos(20,310);
        Modes.AddWidget(Choose);
        Modes.AddWidget(vsP);
        Modes.AddWidget(vsIA);

    ElementsInGame.push_back(new Ball);
    ElementsInGame.push_back(&P1);
    ElementsInGame.push_back(&P2);

    score1 = score2 = 0;
    Score1 = new Text(std::to_string(score1),25,new Uint8[3]{255,255,255});
    Score2 = new Text(std::to_string(score2),25,new Uint8[3]{255,255,255});
    Score1->SetPos(190,15);
    Score2->SetPos(280,15);

    menu = &TitleScreen;
    pause = false;

}

void Game::Event() {

    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT) { run = false; }

    UpdateKeys(event);
    UpdateMouse(event);

}

void Game::Update() {

    if (menu != nullptr) menu->Update();
    if (pause) Pause.Update();

    if (menu == &TitleScreen) {

        if (Play->Click()) { menu = &Modes; PlaySound("beep1.wav"); }
        if (OptionsButton->Click()) { menu = &Options; PlaySound("beep1.wav"); Game::mouses[SDL_BUTTON_LEFT] = false; }
        if (QuitTitle->Click()) { run = false; }

    }

    if (menu == &Options) {

        SetVolume(volume->GetValue());
        if (Game::keys[SDLK_SPACE]) { PlaySound("beep.wav"); Game::keys[SDLK_SPACE] = false; }
        if (Game::keys[SDLK_ESCAPE]) menu = &TitleScreen;

    }

    if (menu == &Modes) {

        if (vsP->Click()) { menu = nullptr; P1.SetUser(false); P2.SetUser(false); PlaySound("beep1.wav"); for (int i = 0;i < ElementsInGame.size();i++) if (ElementsInGame[i] != &P1 && ElementsInGame[i] != &P2) { ElementsInGame[i]->SetPos(245,245); ElementsInGame[i]->SetMouv(false); } }
        if (vsIA->Click()) { menu = nullptr; P1.SetUser(false); P2.SetUser(true); PlaySound("beep1.wav"); for (int i = 0;i < ElementsInGame.size();i++) if (ElementsInGame[i] != &P1 && ElementsInGame[i] != &P2) { ElementsInGame[i]->SetPos(245,245); ElementsInGame[i]->SetMouv(false); } }
        if (Game::keys[SDLK_c]) Modes.AddWidget(secret);
        if (secret->Click() && Modes.HasWidget(secret)) { menu = nullptr; P1.SetUser(true); P2.SetUser(true); PlaySound("beep1.wav"); for (int i = 0;i < ElementsInGame.size();i++) if (ElementsInGame[i] != &P1 && ElementsInGame[i] != &P2) { ElementsInGame[i]->SetPos(245,245); ElementsInGame[i]->SetMouv(false); } }

    }

    if (menu == nullptr) {

        if (Game::keys[SDLK_ESCAPE]) { Game::keys[SDLK_ESCAPE] = false; pause = !pause; }

        if (pause) {

            if (Resume->Click()) { pause = false; PlaySound("beep1.wav"); }
            if (QuitPause->Click()) { menu = &TitleScreen; score1 = score2 = 0; P1.SetPos(P1.GetPosX(),1); P2.SetPos(P2.GetPosX(),300); Game::keys[SDL_BUTTON_LEFT] = false; PlaySound("beep1.wav"); pause = false; }

        }
        
        if (!pause) { 
            
            for (int i = 0;i < ElementsInGame.size();i++) ElementsInGame[i]->Update(); 

            Score1->SetText(std::to_string(score1));
            Score2->SetText(std::to_string(score2));
            Score1->Update();
            Score2->Update();
            
            if (Game::keys[SDLK_b]) { ElementsInGame.push_back(new Ball); Game::keys[SDLK_b] = false; }

            if (Game::keys[SDLK_1]) { P1.SetUser(!P1.IsBot()); Game::keys[SDLK_1] = false; }
            if (Game::keys[SDLK_2]) { P2.SetUser(!P2.IsBot()); Game::keys[SDLK_2] = false; }

            for (int i = 0;i < ElementsInGame.size();i++) {
        
                if (ElementsInGame[i] != &P1 && ElementsInGame[i] != &P2) {

                    if (ElementsInGame[i]->GetPosX() < P1.GetPosX()) { score2++; ElementsInGame[i]->SetPos(245,245); ElementsInGame[i]->SetAxeMouvY(0); if (!P1.IsBot() || !P2.IsBot()) ElementsInGame[i]->SetMouv(false); }
                    if (ElementsInGame[i]->GetPosX() > P2.GetPosX()) { score1++; ElementsInGame[i]->SetPos(245,245); ElementsInGame[i]->SetAxeMouvY(0); if (!P1.IsBot() || !P2.IsBot()) ElementsInGame[i]->SetMouv(false); }

                }
        
            }
            
            if (score1 > 9 || score2 > 9) score1 = score2 = 0;
            
        }
        

    }

}

void Game::Render() {

    SDL_RenderClear(renderer);
    if (menu != nullptr) menu->Render(); else if (!pause) {
        
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderFillRect(renderer,&table);
        SDL_RenderFillRect(renderer,&tiret);
        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        Score1->Render();
        Score2->Render();

        for (int i = 0;i < ElementsInGame.size();i++) ElementsInGame[i]->Render();
        
    }

    if (pause) Pause.Render();

    SDL_RenderPresent(renderer);

}

void Game::Clean() {

    delete &Options,&Modes,&Pause,&TitleScreen;
    ElementsInGame.clear();

    ImageDestroy();
    TextDestroy();
    SoundDestroy();

    SDL_DestroyWindow(windowGame);
    SDL_DestroyRenderer(renderer);

}