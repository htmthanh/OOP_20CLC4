// StrategyGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

// Forward declaration
class Character;
class Swordman;
class Knight;
class Pikeman;

class IVisitable;

class State;
class NormalState;
class SuperSwordmanState;
class SuperKnightState;
class SuperPikeState;

class Player;
class Game;
class Rule;
class SuperSwordmanRule;
class SuperKnightRule;
class SuperPikeRule;

class RandomInteger;
// Class declaration
class RandomInteger {
public:
    int next();
    int next(int);
    int next(int, int);
};
class Character {
protected:
    int _hp;
    int _atk;
    State* _state;
public:
    Character(int hp, int atk);
    int hp();
    int atk();
    
    void setState(State*);
    void setHp(int);
    void setAtk(int);
    bool isAlive();
    virtual void attack(Character* opponent) = 0;
    virtual string toString() = 0;
};

class IVisitable {
public:
    virtual void attack(Swordman&) = 0;
    virtual void attack(Knight&) = 0;
    virtual void attack(Pikeman&) = 0;

    virtual void hitBy(Swordman&) = 0;
    virtual void hitBy(Knight&) = 0;
    virtual void hitBy(Pikeman&) = 0;

    void select(Character*);
};

class Swordman : public Character, public IVisitable {
public:
    Swordman(int, int);
    string toString();
    void attack(Swordman&);
    void attack(Knight&);
    void attack(Pikeman&);
    void attack(Character*);

    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Pikeman&);
};

class Knight : public Character, public IVisitable {
public:
    Knight(int, int);
    string toString();
    void attack(Swordman&);
    void attack(Knight&);
    void attack(Pikeman&);
    void attack(Character*);

    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Pikeman&);
};

class Pikeman : public Character,public IVisitable {
public:
    Pikeman(int, int);
    string toString();
    void attack(Swordman&);
    void attack(Knight&);
    void attack(Pikeman&);
    void attack(Character*);

    void hitBy(Swordman&);
    void hitBy(Knight&);
    void hitBy(Pikeman&);
};

class State {
public:
    virtual int transformHp(int old) = 0;
    virtual int transformAtk(int old) = 0;
    
};

class NormalState : public State {
public:
    int transformHp(int old);
    int transformAtk(int old);
   
};

class SuperSwordmanState : public State {
public:
    int transformHp(int old);
    int transformAtk(int old);
   
};

class SuperKnightState : public State {
public:
    int transformHp(int old);
    int transformAtk(int old);
   
};
class SuperPikeState : public State {
public:
    int transformHp(int old);
    int transformAtk(int old);
};

class Player {
public:
    vector<Character*> pieces;

    typedef void (Game::* CheckCallBack) (Player*);
    CheckCallBack checker = NULL;

public:
    void add(Character*);
    string toString();
};

class Game {
private:
    Player _player1;
    Player _player2;
    vector<Rule*> _rules;
public:
    Game();
    void start();
    void play(); // hai nguoi choi danh nhau
    void checkRule(Player*);
    void apply(Player*);
    string toString();
};

class Rule {
public:
    virtual bool satisfyWith(Player*) = 0;
    virtual void apply(Player*) = 0;
};

class SuperSwordmanRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};

class SuperKnightRule : public Rule {
public:
    bool satisfyWith(Player*);
    void apply(Player*);
};
class SuperPikeRule :public Rule {
    bool satisfyWith(Player*);
    void apply(Player*);
};
// Class implementation
int RandomInteger::next() {
    return rand() % 100;
}
int RandomInteger::next(int n) {
    return rand() % n;;
}
int RandomInteger::next(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void  IVisitable::select(Character* opponent) {
    if (typeid(*opponent) == typeid(Swordman)) {
        attack(*((Swordman*)opponent));
    }
    else if (typeid(*opponent) == typeid(Knight)) {
        attack(*((Knight*)opponent));
    }
    else if (typeid(*opponent) == typeid(Pikeman)) {
        attack(*((Pikeman*)opponent));
    }
}
// ---- Character
Character::Character(int hp, int atk) {
    _hp = hp;
    _atk = atk;
    _state = new NormalState();
}

int Character::hp() { return _state->transformHp(_hp); }
int Character::atk() { return _state->transformAtk(_atk); }
//int Character::def() { return _state->transformDef(_def); }
void Character::setHp(int  value) { _hp = value > 0 ? value : 0; }
void Character::setAtk(int value) { _atk = value > 0 ? value : 0; }
//void Character::setDef(int value) { _def = value > 0 ? value : 0; }
bool Character::isAlive() { return _hp > 0; }
void Character::setState(State* value) { _state = value; }

// ---- Swordman
Swordman::Swordman(int hp, int atk) : Character(hp, atk) {}
string Swordman::toString() {
    stringstream builder;
    builder << "Swordman (HP " << hp()
        << ", ATK " << atk()<<")";
       // << " DEF: " << def();

    string result = builder.str();
    return result;
}
void Swordman::attack(Swordman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Swordman&)
    }
}
void Swordman::attack(Knight& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Swordman::attack(Pikeman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Swordman::attack(Character* opponent) {
    select(opponent);
}

void Swordman::hitBy(Swordman& opponent) {
    _hp = _hp - (opponent.atk());
}
void Swordman::hitBy(Knight& opponent) {
    _hp = _hp - (opponent.atk() + 10 );
}
void Swordman::hitBy(Pikeman& opponent) {
    _hp = _hp - (opponent.atk());
}

// ---- Knight
Knight::Knight(int hp, int atk) :Character(hp, atk) {
}
string Knight::toString() {
    stringstream builder;
    builder << "Knight (HP " << hp()
        << ", ATK " << atk()<<")";
        //<< " DEF: " << def();

    string result = builder.str();
    return result;
}
void Knight::attack(Swordman& opponent) {
    opponent.hitBy(*this); // this: Knight*,  *this: Knight

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Swordman&)
    }
}
void Knight::attack(Knight& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Knight::attack(Pikeman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Knight::attack(Character* opponent) {
    select(opponent);
}
void Knight::hitBy(Swordman& opponent) {
    _hp = _hp - (opponent.atk());
}
void Knight::hitBy(Knight& opponent) {
    _hp = _hp - (opponent.atk());
}
void Knight::hitBy(Pikeman& opponent) {
    _hp = _hp - (opponent.atk() + 25);
}

// ----- Pikeman ----
Pikeman::Pikeman(int hp, int atk) : Character(hp, atk) {}
string Pikeman::toString() {
    stringstream builder;
    builder << "Pikeman (HP " << hp()
        << ", ATK: " << atk()<<")";
        //<< " DEF: " << def();

    string result = builder.str();
    return result;
}
void Pikeman::attack(Swordman& opponent) {
    opponent.hitBy(*this);
    if (opponent.isAlive()) { hitBy(opponent); }
}
void Pikeman::attack(Knight& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Pikeman::attack(Pikeman& opponent) {
    opponent.hitBy(*this); // this: Swordman*,  *this: Swordman

    if (opponent.isAlive()) {
        hitBy(opponent); //hitBy(Knight&);
    }
}
void Pikeman::attack(Character* opponent) {
    select(opponent);
}
void Pikeman::hitBy(Swordman& opponent) {
    _hp = _hp - (opponent.atk() + 12 );
}
void Pikeman::hitBy(Knight& opponent) {
    _hp = _hp - (opponent.atk());
}
void Pikeman::hitBy(Pikeman& opponent) {
    _hp = _hp - (opponent.atk());
}

// ---- States
int NormalState::transformHp(int old) {
    return old;
}
int NormalState::transformAtk(int old) {
    return old;
}

int SuperSwordmanState::transformHp(int old) {
    return old;
}
int SuperSwordmanState::transformAtk(int old) {
    return old * 3;
}

int SuperKnightState::transformHp(int old) {
    return old;
}
int SuperKnightState::transformAtk(int old) {
    return old * 2;
}

int SuperPikeState::transformHp(int old) {
    return old * 2;
}
int SuperPikeState::transformAtk(int old) {
    return old * 5;
}

// -------Player----------------
void Player::add(Character* item) {
    pieces.push_back(item);
}

string Player::toString() {
    stringstream builder;
    //builder << "Player info:" << endl;
    for (int i = 0; i < pieces.size(); i++) {
        if (i == pieces.size() - 1) {
            builder << pieces[i]->toString();
        }
        else {
            builder << pieces[i]->toString() << ", ";
        }
    }

    string result = builder.str();
    return result;
}

Game::Game() {
    _rules.push_back(new SuperSwordmanRule());
    _rules.push_back(new SuperKnightRule());
    _rules.push_back(new SuperPikeRule());

    _player1.checker = &Game::checkRule;
    _player2.checker = &Game::checkRule;
}

void Game::checkRule(Player* player) {
    for (int i = 0; i < _rules.size(); i++) {
        if (_rules[i]->satisfyWith(player)) {
            _rules[i]->apply(player);
        }
    }
}


void Game::start() {
    RandomInteger rng;
    for (int i = 0; i < 3; i++) {
        int rd1 = rng.next(1, 3);
        int rd2 = rng.next(1, 3);
        if (rd1 == 1) {
            _player1.add(new Swordman(1000, 12));
        }
        else if (rd1 == 2) {
            _player1.add(new Knight(1500, 18));
        }
        else if (rd1 == 3) {
            _player1.add(new Pikeman(800, 8));
        }
        if (rd2 == 1) {
            _player2.add(new Swordman(1000, 12));
        }
        else if (rd2 == 2) {
            _player2.add(new Knight(1500, 18));
        }
        else if (rd2 == 3) {
            _player2.add(new Pikeman(800, 8));
        }
    }

    checkRule(&_player1);
    checkRule(&_player2);
}

void Game::play() {
    RandomInteger rng;
    int first = rng.next(1, 2);
    if (first == 1) {
        cout << "Blue team first ! " << endl;
        for (int i = 0; i < 3; i++) {
            //cout << "Turn " << i + 1 << endl;
            _player1.pieces[i]->attack(_player2.pieces[i]);
            _player2.pieces[i]->attack(_player1.pieces[i]);
           // cout << _player1.toString() << endl;
            //cout << _player2.toString() << endl;
        }
    }
    else {
        cout << "Red team first ! " << endl;
        for (int i = 0; i < 3; i++) {
            //cout << "After turn " << i + 1 << endl;
            _player2.pieces[i]->attack(_player1.pieces[i]);
            _player1.pieces[i]->attack(_player2.pieces[i]);
           // cout << _player1.toString() << endl;
           // cout << _player2.toString() << endl;
        }
    }
}

string Game::toString() {
    stringstream builder;
    builder <<"Blue team: "<< _player1.toString() << endl;
    builder <<"Red team: "<< _player2.toString() << endl;

    string result = builder.str();
    return result;
}

bool SuperSwordmanRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->pieces.size(); i++) {
        if (typeid(*(player->pieces[i])) == typeid(Swordman)) {
            count++;
        }
    }

    bool result = count == 3;
    return result;
}

void SuperSwordmanRule::apply(Player* player) {
    for (int i = 0; i < player->pieces.size(); i++) {
        player->pieces[i]->setState(new SuperSwordmanState());
    }
}

bool SuperKnightRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->pieces.size(); i++) {
        if (typeid(*(player->pieces[i])) == typeid(Knight)) {
            count++;
        }
    }

    bool result = count == 3;
    return result;
}

void SuperKnightRule::apply(Player* player) {
    for (int i = 0; i < player->pieces.size(); i++) {
        player->pieces[i]->setState(new SuperKnightState());
    }
}

void SuperPikeRule::apply(Player* player) {
    for (int i = 0; i < player->pieces.size(); i++) {
        player->pieces[i]->setState(new SuperPikeState());
    }
}
bool SuperPikeRule::satisfyWith(Player* player) {
    int count = 0;
    for (int i = 0; i < player->pieces.size(); i++) {
        if (typeid(*(player->pieces[i])) == typeid(Pikeman)) {
            count++;
        }
    }

    bool result = count == 3;
    return result;
}
int main()
{
    srand(time(NULL));
    Game game;
    game.start();

    cout << "Begin" << endl;
    cout << game.toString() << endl;
    cout << endl;

    game.play();

    cout << "After 3 turns:" << endl;
    cout << game.toString() << endl;
    return 0;
}
#endif
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
