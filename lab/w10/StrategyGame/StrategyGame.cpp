// StrategyGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>

#include <string.h>
using namespace std;

// Forward declaration
class Random;

class Character;
class Swordman;
class Knight;
class Pikeman;

class IVisitable;

class State;
class NormalState;
class SuperSwordmanState;
class SuperKnightState;
class SuperSpikemanState;

class Player;
class Game;
class Rule;
class SuperSwordmanRule;
class SuperKnightRule;
class SuperSpikemanRule;
//===============RANDOM INTERGER======================
class Random {
public:
	int next() {
		int result = rand();
		return result;
	}

	int next(int ceiling) {
		int result = rand() % ceiling;
		return result;
	}
	int next(int min, int max) {
		int result = min + rand() % (max + 1 - min);
		return result;
	}

};
// Class declaration
class Character {
protected:
	int _hp;
	int _atk;
	//int _def;
	State* _state;
public:
	Character(int hp, int atk);
	int hp();
	int atk();
	//int def();
	void setState(State*);
	void setHp(int);
	void setAtk(int);
	//void setDef(int);
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
	//virtual int transformDef(int old) = 0;
};

class NormalState : public State {
public:
	int transformHp(int old);
	int transformAtk(int old);
	//int transformDef(int old);
};

class SuperSwordmanState : public State {
public:
	int transformHp(int old);
	int transformAtk(int old);
	//int transformDef(int old);
};

class SuperKnightState : public State {
public:
	int transformHp(int old);
	int transformAtk(int old);
	//int transformDef(int old);
};
class SuperSpikemanState : public State {
public:
	int transformHp(int old);
	int transformAtk(int old);
	//int transformDef(int old);
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

class SuperSpikemanRule : public Rule {
public:
	bool satisfyWith(Player*);
	void apply(Player*);
};
// Class implementation
// ---- Character
Character::Character(int hp, int atk) {
	_hp = hp;
	_atk = atk;
	//_def = def;
	_state = new NormalState();
}
void IVisitable::select(Character* opponent) {
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
int Character::hp() { return _state->transformHp(_hp); }
int Character::atk() { return _state->transformAtk(_atk); }
//int Character::def() { return _state->transformDef(_def); }
void Character::setHp(int  value) { _hp = value > 0 ? value : 0; }
void Character::setAtk(int value) { _atk = value > 0 ? value : 0; }
//void Character::setDef(int value) { _def = value > 0 ? value : 0; }
bool Character::isAlive() { return _hp > 0; }
void Character::setState(State* value) { _state = value; }

// ---- Swordman
Swordman::Swordman(int hp, int atk) : Character(hp, atk) {
}
string Swordman::toString() {
	stringstream builder;
	builder << "Swordman HP: " << hp()
		<< " ATK: " << atk();
		//<< " DEF: " << def();

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
//void Swordman::attack(Character* opponent) {
//	select(opponent);
//}
void Swordman::hitBy(Swordman& opponent) {
	_hp = _hp - opponent.atk() ;
}
void Swordman::hitBy(Knight& opponent) {
	_hp = _hp -(opponent.atk() + 10) ;
}
void Swordman::hitBy(Pikeman& opponent) {
	_hp = _hp - opponent.atk() ;
}

// ---- Knight
Knight::Knight(int hp, int atk) :Character(hp, atk) {
}
string Knight::toString() {
	stringstream builder;
	builder << "Knight HP: " << hp()
		<< " ATK: " << atk();
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
	_hp = _hp - opponent.atk();
}
void Knight::hitBy(Knight& opponent) {
	_hp = _hp - opponent.atk() ;
}
void Knight::hitBy(Pikeman& opponent) {
	_hp = _hp - (opponent.atk() +25);
}

// ----- Pikeman ----
Pikeman::Pikeman(int hp, int atk) : Character(hp, atk) {}
string Pikeman::toString() {
	stringstream builder;
	builder << "Spikeman HP: " << hp()
		<< " ATK: " << atk();
		//<< " DEF: " << def();

	string result = builder.str();
	return result;
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
	_hp = _hp - (opponent.atk() );
}
void Pikeman::hitBy(Pikeman& opponent) {
	_hp = _hp - (opponent.atk() );
}

// ---- States
int NormalState::transformHp(int old) {
	return old;
}
int NormalState::transformAtk(int old) {
	return old;
}
//int NormalState::transformDef(int old) {
//	return old;
//}
int SuperSwordmanState::transformHp(int old) {
	return old;
}
int SuperSwordmanState::transformAtk(int old) {
	return old * 3;
}
//int SuperSwordmanState::transformDef(int old) {
//	return old;
//}
int SuperKnightState::transformHp(int old) {
	return old * 2;
}
int SuperKnightState::transformAtk(int old) {
	return old * 5;
}
int SuperSpikemanState::transformHp(int old) { return old * 2; }
int SuperSpikemanState::transformAtk(int old) { return old * 5; }
//int SuperKnightState::transformDef(int old) {
//	return old;
//}

// -------Player----------------
void Player::add(Character* item) {
	pieces.push_back(item);
}

string Player::toString() {
	stringstream builder;
	for (int i = 0; i < pieces.size(); i++) {
		// delete "," if it is the last one
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
	_rules.push_back(new SuperSpikemanRule());

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
	Random rng;
	
	for (int i = 0; i < 3; i++)
	{
		int bluePieces = rng.next(1, 3);
		int redPieces = rng.next(1, 3);
		if (bluePieces == 1) { _player1.add(new Swordman(1000, 12)); }
		else if (bluePieces == 2) { _player1.add(new Knight(800, 8)); }
		else if (bluePieces == 3) { _player1.add(new Pikeman(1500, 18)); }

		if (redPieces == 1) { _player2.add(new Swordman(100, 12)); }
		else if (redPieces == 2) { _player2.add(new Knight(800, 12)); }
		else if (redPieces == 3) { _player2.add(new Pikeman(1500, 18)); }
	}
	checkRule(&_player1);
	checkRule(&_player2);
}

void Game::play() {
	Random rng;
	int decide = rng.next(1, 2);
	if (decide == 1) {
		cout << endl << "Red team goes first:" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "Turn " << i + 1 << endl;
			_player2.pieces[i]->attack(_player1.pieces[i]);
			_player1.pieces[i]->attack(_player2.pieces[i]);
			cout << _player1.toString() << endl;
			cout << _player2.toString() << endl;
		}
	}
	else {
		cout << endl << "Blue team goes first:" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "Turn " << i + 1 << endl;
			_player1.pieces[i]->attack(_player2.pieces[i]);
			_player2.pieces[i]->attack(_player1.pieces[i]);
			cout << _player2.toString() << endl;
			cout << _player1.toString() << endl;
		}
	}
}

string Game::toString() {
	stringstream builder;
	builder << _player1.toString() << endl;
	builder << _player2.toString() << endl;

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
bool SuperSpikemanRule::satisfyWith(Player* player) {
	int count = 0;
	for (int i = 0; i < player->pieces.size(); i++) {
		if (typeid(*(player->pieces[i])) == typeid(Pikeman)) {
			count++;
		}
	}

	bool result = count == 3;
	return result;
}
void SuperSpikemanRule::apply(Player* player) {
	for (int i = 0; i < player->pieces.size(); i++) {
		player->pieces[i]->setState(new SuperSpikemanState());
	}
}
int main() {
	Game game;
	game.start();
	
	cout << "Begin" << endl;
	cout << game.toString() << endl;
	game.play();
	cout << endl << "After 3 turns," << endl;
	cout << game.toString();

	game.toString();

	
	cout << endl;

	game.play();

	cout << "Result:" << endl;
	game.toString();
	cout << endl;
}
