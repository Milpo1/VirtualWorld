#pragma once
#include "OrganismType.h"
#include "Point.h"
class World;
class Fight;

class Organism {
protected:
	Organism* next, *prev;
	World* worldPtr;
	Organisms type;
	int strength, initiative;
	Point coords;
	Flag flag;
public:
	friend class World;
	friend class Fight;
	friend class OrganismList;

	virtual void action() = 0;
	virtual void collision(Fight* fight) = 0;
	virtual void draw() = 0;
	Organisms getType() const;
	Point& getCoords();
	int getStrength() const;
	int getInitiative() const;
	void setStrength(int strength);
};
class OrganismList {
	Organism* head;
public:
	Organism* ptr;
	OrganismList();
	Organism* getHead() const;
	void add(Organism* organism);
	void deleteNode(Organism* organism);
	void insertAtPrev(Organism* at, Organism* toBeInserted);
	void insertAtNext(Organism* at, Organism* toBeInserted);
	~OrganismList();
};	

class Fight {
public:
	enum Side {
		ATTACKER,
		VICTIM,
		TIE,
		NEITHER
	};
private:
	Side winner;
	Organism* participant[TIE];
	int netStrength;
public:
	friend class Organism;
	Fight(Organism* attacker, Organism* victim);
	Side getSide(Organism* participant) const;
	Organism* getEnemy(Organism* participant) const;
	Side getWinnerSide() const;
	Organism* getWinner() const;
	Organism* getLoser() const;
	void setWinner(Side side);
	void addStrenght(Side side, int strength);
	bool isComplete() const;
	bool isReady() const;
};