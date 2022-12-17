#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum State
{
    IDLE,
    WALK,
    RUN,
    ATTACK,
    JUMP,
    DUCK,
    READY,
    ULTIMATE
};

class Image
{
private:
    vector<string> _images;

public:
    Image()
    {
        _images.push_back("idle");
        _images.push_back("walk");
        _images.push_back("run");
        _images.push_back("attack");
        _images.push_back("jump");
        _images.push_back("duck");
        _images.push_back("ready");
        _images.push_back("ultimate");
    }

    void draw(State state)
    {
        cout << _images[state] << endl;
    }
};

// Interface for state of character
class HeroState
{
public:
    virtual HeroState *handleInput(Hero &hero, char input) = 0;
    virtual void update(Hero &hero) = 0;
    virtual void enter(Hero &hero) = 0;
    virtual void exit(Hero &hero) = 0;
};

class Hero
{
public:
    virtual void handleInput(char input)
    {
        HeroState *state = _state->handleInput(*this, input);
        if (_state != nullptr)
        {
            delete _state;
            _state = state;
            _state->enter(*this);
        }
    }

    virtual void update()
    {
        _state->update(*this);
    }

    virtual void ulimateSkill()
    {
        _image.draw(ULTIMATE);
    }

    virtual void setGraphic(State state)
    {
        _image.draw(state);
    }

    void setState(HeroState *state)
    {
        _state = state;
    }

private:
    HeroState *_state = nullptr;
    Image _image;
};

class IdleState : public HeroState
{
public:
    virtual HeroState *handleInput(Hero &hero, char input)
    {
        if (input == 'w')
        {
            return new WalkState();
        }
        else
        {
            return nullptr;
        }
    }

    virtual void update(Hero &hero)
    {
        hero.setState(new IdleState());
    }

    virtual void enter(Hero &hero)
    {
        hero.setGraphic(IDLE);
    }

    virtual void exit(Hero &hero)
    {
        hero.setGraphic(READY);
    }
};

class WalkState : public HeroState
{
public:
    virtual HeroState *handleInput(Hero &hero, char input)
    {
        if (input == 's')
        {
            return new IdleState();
        }
        else
        {
            return nullptr;
        }
    }

    virtual void update(Hero &hero)
    {
        hero.setState(new WalkState());
    }

    virtual void enter(Hero &hero)
    {
        hero.setGraphic(WALK);
    }

    virtual void exit(Hero &hero)
    {
        hero.setGraphic(READY);
    }
};