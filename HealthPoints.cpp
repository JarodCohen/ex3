#include "Healthpoints.h"


HealthPoints::HealthPoints(int maxHP):m_maxHP(maxHP),
                                        m_currentHP(maxHP)
{
    if(maxHP<=0)
    {
        throw HealthPoints::InvalidArgument();
    }
}

HealthPoints& HealthPoints:: operator+=(const int add){
    m_currentHP+= add;
    if(m_currentHP < 0){
        m_currentHP = 0;
    }
    if(m_currentHP > m_maxHP){
        m_currentHP = m_maxHP;
    }
    return *this;
}

HealthPoints& HealthPoints:: operator-=(const int sub){
    *this+= -sub;
    return *this;
}

HealthPoints HealthPoints:: operator+(const int add){
    return *this+=add;
}

HealthPoints HealthPoints:: operator-(const int sub){
    return *this-=sub;
}

HealthPoints operator+(const int add, const HealthPoints& hp){
    HealthPoints result = hp;
    return result+=add;
};
HealthPoints operator-(const int sub, const HealthPoints& hp){
    HealthPoints result = hp;
    return result-=sub;
};

HealthPoints& HealthPoints::operator=(const int val){
    *this = HealthPoints(val);
    return *this;
}

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2){
    if(hp1.m_currentHP == hp2.m_currentHP) return true;
    else return false;
}

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2){
    return !(hp1==hp2);
}

bool operator>=(const HealthPoints&hp1, const HealthPoints&hp2){
    if(hp1.m_currentHP >= hp2.m_currentHP) return true;
    else return false;
}
bool operator>(const HealthPoints& hp1, const HealthPoints& hp2){
    if((hp1 >= hp2) &&(hp1 != hp2)) return true;
    else return false;
}
bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2){
    return !(hp1 > hp2);
}
bool operator<(const HealthPoints& hp1, const HealthPoints& hp2){
    return!(hp1 >= hp2);
}