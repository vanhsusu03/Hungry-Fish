#include "HighScores.h"

HighScores::HighScores()
{

}

HighScores::~HighScores()
{

}

void HighScores::loadSourceHighsc()
{
    gHS.loadImage(highsc_load);
    gBack[0].loadImage(cback);
    gBack[1].loadImage(cback_button);
}

void HighScores::renderHighsc()
{
    loadSourceHighsc();
    gHS.render(0,0,nullptr,0,nullptr,flip);
    gBack[0].render(50,50,nullptr,0,nullptr,cbflip);

    if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
        && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
        {
            gBack[1].render(50,50,nullptr,0,nullptr,cbflip);
            Mix_PlayChannel(-1,Audio::gMenuButton,0);
        }
}

void HighScores::mainHS()
{
    runningHS = true;
    while(runningHS)
    {
        int framecount =0;
        int lastframe = SDL_GetTicks();
        int lasttime =0;
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
        renderHighsc();

        SDL_RenderPresent(Engine::gRenderer);
        while (SDL_PollEvent(&e) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                runningHS = false;
                Engine::quitloop = false;
                SDL_Quit();
                return;
            }

            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                if(mousex >= gBack[0].getPosX() && mousex <= gBack[0].getPosX() + gBack[0].getWidth()
                && mousey >= gBack[0].getPosY() && mousey <= gBack[0].getPosY() + gBack[0].getHeight())
                    {
                        Engine::status = 0;
                        runningHS = false;
                        return ;
                    }
            }
        }
    }
}
