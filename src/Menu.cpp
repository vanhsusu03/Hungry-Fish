#include "Menu.h"

Menu::Menu()
{
    loadSource();
}

Menu::~Menu()
{

}

void Menu::loadSource()
{
   gLogo.loadImage(logo);
   gPlayGame[0].loadImage(playgame);
   gInstruction[0].loadImage(instruc);
   gOptions[0].loadImage(option);
   gQuit[0].loadImage(quit);
   gHighScores[0].loadImage(highsc);
   gCredits[0].loadImage(cred);
   gPlayGame[1].loadImage(playgame_button);
   gInstruction[1].loadImage(instruc_button);
   gOptions[1].loadImage(option_button);
   gQuit[1].loadImage(quit_button);
   gHighScores[1].loadImage(highsc_button);
   gCredits[1].loadImage(cred_button);
   gBackground.loadImage(menu);
}

void Menu::renderLogo()
{
    gLogo.render(400,mPosYMenu,nullptr,0,nullptr,flip);

    mPosYMenu+=velLogo;

    if(mPosYMenu >= 19) velLogo=-velLogo;
    if(mPosYMenu <= 11) velLogo = -velLogo;
}

void Menu::renderButtons()
{
    gBackground.render(0,0,nullptr,0,nullptr,flip);
    renderLogo();
    gPlayGame[0].render(325,280, nullptr,-8,nullptr,flip);
    gInstruction[0].render(615,337,nullptr,8,nullptr,flip);
    gHighScores[0].render(345,425,nullptr,-8,nullptr,flip);
    gOptions[0].render(635,505,nullptr,8,nullptr,flip);
    gQuit[0].render(500,580,nullptr,0,nullptr,flip);
    gCredits[0].render(60,580,nullptr,0,nullptr,flip);

    //ON BUTTON
    if(mousex >= gPlayGame[0].getPosX() && mousex <= gPlayGame[0].getPosX() + gPlayGame[0].getWidth()
        && mousey >= gPlayGame[0].getPosY() && mousey <= gPlayGame[0].getPosY() + gPlayGame[0].getHeight())
        {
            gPlayGame[1].render(325,280,nullptr,-8,nullptr,flip);

        }
    if(mousex >= gInstruction[0].getPosX() && mousex <= gInstruction[0].getPosX() + gInstruction[0].getWidth()
        && mousey >= gInstruction[0].getPosY() && mousey <= gInstruction[0].getPosY() + gInstruction[0].getHeight())
        {
            gInstruction[1].render(615,337,nullptr,8,nullptr,flip);

        }
    if(mousex >= gHighScores[0].getPosX() && mousex <= gHighScores[0].getPosX() + gHighScores[0].getWidth()
        && mousey >= gHighScores[0].getPosY() && mousey <= gHighScores[0].getPosY() + gHighScores[0].getHeight())
        {
            gHighScores[1].render(345,425,nullptr,-8,nullptr,flip);

        }
    if(mousex >= gOptions[0].getPosX() && mousex <= gOptions[0].getPosX() + gOptions[0].getWidth()
        && mousey >= gOptions[0].getPosY() && mousey <= gOptions[0].getPosY() + gOptions[0].getHeight())
        {
            gOptions[1].render(635,505,nullptr,8,nullptr,flip);

        }
    if(mousex >= gQuit[0].getPosX() && mousex <= gQuit[0].getPosX() + gQuit[0].getWidth()
        && mousey >= gQuit[0].getPosY() && mousey <= gQuit[0].getPosY() + gQuit[0].getHeight())
        {
            gQuit[1].render(500,580,nullptr,0,nullptr,flip);

        }
    if(mousex >= gCredits[0].getPosX() && mousex <= gCredits[0].getPosX() + gCredits[0].getWidth()
        && mousey >= gCredits[0].getPosY() && mousey <= gCredits[0].getPosY() + gCredits[0].getHeight())
        {
            gCredits[1].render(60,580,nullptr,0,nullptr,flip);

        }
}

void Menu::loadSourceOpts()
{
   gOpts.loadImage(opt_load);
   gBack[0].loadImage(cback);
   gBack[1].loadImage(cback_button);
   gBubbleM[0].loadImage(bub);
   gBubbleS[0].loadImage(bub);
   gBubbleM[1].loadImage(bub_button);
   gBubbleS[1].loadImage(bub_button);
   gTickM.loadImage(tick);
   gTickS.loadImage(tick);
}
void Menu::renderOpts()
{
    gOpts.render(0,0,nullptr,0,nullptr,flip);
    gBack[0].render(560,472,nullptr,0,nullptr,cbflip);
    gBubbleM[0].render (505,325,nullptr,0,nullptr,flip);
    gBubbleS[0].render (505,440,nullptr,0,nullptr,flip);
    if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
        && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
        {
            gBack[1].render(560,472,nullptr,0,nullptr,cbflip);

        }
    if(mousex >= gBubbleM[0].getPosX() && mousex <= gBubbleM[0].getPosX() + gBubbleM[0].getWidth()
        && mousey >= gBubbleM[0].getPosY() && mousey <= gBubbleM[0].getPosY() + gBubbleM[0].getHeight())
        {
            gBubbleM[1].render(505,325,nullptr,0,nullptr,flip);

        }
    if(mousex >= gBubbleS[0].getPosX() && mousex <= gBubbleS[0].getPosX() + gBubbleS[0].getWidth()
        && mousey >= gBubbleS[0].getPosY() && mousey <= gBubbleS[0].getPosY() + gBubbleS[0].getHeight())
        {
            gBubbleS[1].render(505,440,nullptr,0,nullptr,flip);

        }
    if(Engine::tickM == true)
    {
        gTickM.render(512,310,nullptr,0,nullptr,flip);
    }
    if(Engine::tickS == true)
    {
        gTickS.render(512,427,nullptr,0,nullptr,flip);
    }
}

void Menu::mainOpts()
{
    runningOpts = true;
    while(runningOpts)
    {
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime =0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }

        SDL_GetMouseState(&mousex,&mousey);
        renderOpts();

        if(Engine::tickM == false)
        {
            Mix_HaltMusic();
        }
        if(Engine::tickS == false)
        {
            Mix_HaltChannel(-1);
        }

        SDL_RenderPresent(Engine::gRenderer);

        while (SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningOpts = false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
                && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
                    {
                         Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        runningOpts = false;
                        return ;
                    }
                if(mousex >= gBubbleM[0].getPosX() && mousex <= gBubbleM[0].getPosX() + gBubbleM[0].getWidth()
                && mousey >= gBubbleM[0].getPosY() && mousey <= gBubbleM[0].getPosY() + gBubbleM[0].getHeight())
                    {
                         Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        if(Engine::tickM == true) Engine::tickM = false;
                        else Engine::tickM = true;
                    }
                if(mousex >= gBubbleS[0].getPosX() && mousex <= gBubbleS[0].getPosX() + gBubbleS[0].getWidth()
                && mousey >= gBubbleS[0].getPosY() && mousey <= gBubbleS[0].getPosY() + gBubbleS[0].getHeight())
                    {
                         Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        if(Engine::tickS == true) Engine::tickS = false;
                        else Engine::tickS = true;
                    }
            }
        }
    }
}

void Menu::loadSourceInstruc()
{
    gInstruc.loadImage(ins_load);
    gBack[0].loadImage(cback);
    gBack[1].loadImage(cback_button);
    gInstruc.render(0,0,nullptr,0,nullptr,flip);
}

void Menu::renderInstruc()
{
    gBack[0].render(50,50,nullptr,0,nullptr,cbflip);
    if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
        && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
        {
            gBack[1].render(50,50,nullptr,0,nullptr,cbflip);

        }
}

void Menu::mainIns()
{
    runningInstruc = true;
    while(runningInstruc)
    {
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime =0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }

        SDL_GetMouseState(&mousex,&mousey);
        renderInstruc();

        SDL_RenderPresent(Engine::gRenderer);

        while (SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningInstruc = false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
                && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        runningInstruc = false;
                        return ;
                    }
            }
        }
    }
}

void Menu::loadSourceHighSc()
{
   gHighSc.loadImage(highsc_load);
   gBestScore.loadFromRenderedText(to_string(Engine::readBest()), {241,175,0});
   gBack[0].loadImage(cback);
   gBack[1].loadImage(cback_button);
}

void Menu::renderHighSc()
{
    gHighSc.render(250,200,nullptr,0,nullptr,flip);
    gBack[0].render(492,525,nullptr,0,nullptr,cbflip);
    if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
        && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
        {
            gBack[1].render(492,525,nullptr,0,nullptr,cbflip);
        }
    gBestScore.render (400,420,nullptr,0,nullptr,flip);
}

void Menu::mainHighSc()
{
    runningHighsc = true;
    while(runningHighsc)
    {
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime =0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }

        SDL_GetMouseState(&mousex,&mousey);
        renderHighSc();

        SDL_RenderPresent(Engine::gRenderer);

        while (SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningHighsc = false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
                && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        runningHighsc = false;
                        return ;
                    }
            }
        }
    }
}

void Menu::loadSourceCredits()
{
   gCred.loadImage(credits_load);
   gBack[0].loadImage(cback);
   gBack[1].loadImage(cback_button);
}

void Menu::renderCredits()
{
    gCred.render(250,200,nullptr,0,nullptr,flip);
    gBack[0].render(492,525,nullptr,0,nullptr,cbflip);
    if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
        && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
        {
            gBack[1].render(492,525,nullptr,0,nullptr,cbflip);
        }
}

void Menu::mainCredits()
{
    runningCredits = true;
    while(runningCredits)
    {
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime =0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }

        SDL_GetMouseState(&mousex,&mousey);
        renderCredits();

        SDL_RenderPresent(Engine::gRenderer);

        while (SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningCredits = false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
                && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        runningCredits = false;
                        return ;
                    }
            }
        }
    }
}

void Menu::firstmenu()
{
    runningMenu = true;
    if(Engine::tickM) Mix_PlayMusic(Audio::gMenu,-1);
    while (runningMenu)
    {
        if(Engine::tickM == false)
        {
            Mix_HaltMusic();
        }
        if(Engine::tickS == false)
        {
            Mix_HaltChannel(-1);
        }

        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime = 0;
        if (lastframe >= lasttime+1000) {
                lasttime = lastframe;
                framecount = 0;
        }
        SDL_SetRenderDrawColor(Engine::gRenderer,255,255,255,255);
        SDL_RenderClear(Engine::gRenderer);

        framecount++;
        int timerFPS = SDL_GetTicks() - lastframe;
        if (timerFPS < (1000/50)) {
            SDL_Delay((1000/50)-timerFPS);
        }
        SDL_GetMouseState(&mousex,&mousey);

        renderButtons();

        SDL_RenderPresent(Engine::gRenderer);

        while(SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningMenu=false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gPlayGame[0].getPosX() && mousex <= gPlayGame[0].getPosX() + gPlayGame[0].getWidth()
                    && mousey >= gPlayGame[0].getPosY() && mousey <= gPlayGame[0].getPosY() + gPlayGame[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        Engine::status=1;
                        runningMenu = false;
                        return;
                    }
                if(mousex >= gInstruction[0].getPosX() && mousex <= gInstruction[0].getPosX() + gInstruction[0].getWidth()
                    && mousey >= gInstruction[0].getPosY() && mousey <= gInstruction[0].getPosY() + gInstruction[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        loadSourceInstruc();
                        mainIns();
                    }
                if(mousex >= gHighScores[0].getPosX() && mousex <= gHighScores[0].getPosX() + gHighScores[0].getWidth()
                    && mousey >= gHighScores[0].getPosY() && mousey <= gHighScores[0].getPosY() + gHighScores[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        loadSourceHighSc();
                        mainHighSc();
                    }
                if(mousex >= gOptions[0].getPosX() && mousex <= gOptions[0].getPosX() + gOptions[0].getWidth()
                   && mousey >= gOptions[0].getPosY() && mousey <= gOptions[0].getPosY() + gOptions[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        loadSourceOpts();
                        mainOpts();
                    }
                if(mousex >= gCredits[0].getPosX() && mousex <= gCredits[0].getPosX() + gCredits[0].getWidth()
                   && mousey >= gCredits[0].getPosY() && mousey <= gCredits[0].getPosY() + gCredits[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        loadSourceCredits();
                        mainCredits();
                    }
                if(mousex >= gQuit[0].getPosX() && mousex <= gQuit[0].getPosX() + gQuit[0].getWidth()
                    && mousey >= gQuit[0].getPosY() && mousey <= gQuit[0].getPosY() + gQuit[0].getHeight())
                    {
                        Mix_PlayChannel(-1,Audio::gMenuButton,0);
                        runningMenu = false;
                        Engine::quitloop = true;
                        return;
                    }
            }
        }

    }
}



