#include "boid.h"
#include "flock.h"

int Flock::getSize() const { return flock.size(); }

Boid Flock::getBoid(int i) { return flock[i]; }


void Flock::addBoid(Boid b) { flock.push_back(b); }

void Flock::flocking()
{
	for (int i = 0; i < flock.size(); i++)
	{
		for (int j = 0; j < flock.size(); j++) 
		{
			if (flock[i].location.distance(flock[j].location) <= abs(20))
			{
				flock[i].run(flock);
			}
		}
	}
}

int Flock::preyCount()
{
	int count = 0;
	for (int i = 0; i < flock.size(); i++)
	{
		if (!flock[i].isPredator)
			count++;
	}
	return count;
}

int Flock::predCount()
{
	return flock.size() - preyCount();
}

void Flock::addDesSep()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setDesSep(1);
	}
}

void Flock::subDesSep()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setDesSep(-1);
	}
}

void Flock::addDesAli()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setDesAli(1);
	}
}

void Flock::subDesAli()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setDesAli(-1);
	}
}

void Flock::addDesCoh()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setDesCoh(1);
	}
}

void Flock::subDesCoh()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setDesCoh(-1);
	}
}

void Flock::addSepW()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setSepW(.1);
	}
}

void Flock::subSepW()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setSepW(-.1);
	}
}

void Flock::addAliW()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setAliW(.1);
	}
}

void Flock::subAliW()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setAliW(-.1);
	}
}

void Flock::addCohW()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setCohW(.1);
	}
}

void Flock::subCohW()
{
	for (int i = 0; i < flock.size(); i++)
	{
		flock[i].setCohW(-.1);
	}
}