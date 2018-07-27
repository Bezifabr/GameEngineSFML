#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "GESFML/State.h"

class IntroState : public GESFML::State
{
public:

    virtual void OnEnter();
    virtual void OnLeave();
    virtual void OnHide();
    virtual void OnShow();

    virtual void Update();
};

#endif // INTRO_STATE_H
