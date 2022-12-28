#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <iostream>

const int DEFAULT_STARTING_HP = 100;

class HealthPoints
{
public:


/*
     * C'tor of HealthPoints class
     *@param maxHP- The maximum Healthpoints of the object
     * @return 
     *      a new instance of HealthPoints with maxHealthpoins of 100(default) or maxHP which was entered as argument and currentHP with the same value as MaxHealthpoints
     * 
*/
explicit HealthPoints(int maxHP = DEFAULT_STARTING_HP);

/*
     * operator+= of HealthPoints class with an int
     *if currenHP + add > maxHP the function will return the instance with currentHp=maxHP
     * @return 
     *      the same instance of HealthPoints with another value of currentHP
     * 
     * 
*/
~HealthPoints()=default;
HealthPoints(const HealthPoints& hp) = default;
HealthPoints& operator=(const HealthPoints& hp) = default;
HealthPoints& operator+=(const int add);

/*
     * operator-= of HealthPoints class with an int
     *if currenHP - add > maxHP the function will return the instance with currentHp=maxHP
     *if currentHP - add < 0 the function will return the instance with currentHP=0
     * @return 
     *      the same instance of HealthPoints with an other value of currentHP
     * 
     * 
*/
HealthPoints& operator-=(const int sub);

/*
     * operator+ of HealthPoints class with an int
     *if currenHP + add > maxHP the function will return the instance with currentHp=maxHP
     *if currentHP + add < 0 the function will return the instance with currentHP=0
     * @return 
     *      the same instance of HealthPoints with another value of currentHP
     * 
     * 
*/
HealthPoints operator+(const int add);

HealthPoints& operator=(const int val);

/*
     * operator- of HealthPoints class with an int
     *if currenHP - sub > maxHP the function will return the instance with currentHp=maxHP
     *if currentHP - sub < 0 the function will return the instance with currentHP=0
     * @return 
     *      the same instance of HealthPoints with an other value of currentHP
     * 
     * 
*/
HealthPoints operator-(const int sub);

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);
class InvalidArgument{};



private:
int m_maxHP;
int m_currentHP;
friend bool operator==(const HealthPoints&, const HealthPoints&);
friend bool operator>=(const HealthPoints&, const HealthPoints&);
};

HealthPoints operator+(const int add, const HealthPoints& hp);

HealthPoints operator-(const int sub, const HealthPoints& hp);

bool operator==(const HealthPoints&, const HealthPoints&);
bool operator!=(const HealthPoints&, const HealthPoints&);
bool operator>=(const HealthPoints&, const HealthPoints&);
bool operator>(const HealthPoints&, const HealthPoints&);
bool operator<=(const HealthPoints&, const HealthPoints&);
bool operator<(const HealthPoints&, const HealthPoints&);
#endif
