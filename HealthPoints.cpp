#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHP) : m_maxHP(maxHP),
                                        m_currentHP(maxHP)
{
    if (maxHP <= 0)
    {
        throw HealthPoints::InvalidArgument();
    }
}

HealthPoints &HealthPoints::operator+=(const int add)
{
    m_currentHP += add;
    if (m_currentHP < 0)
    {
        m_currentHP = 0;
    }
    if (m_currentHP > m_maxHP)
    {
        m_currentHP = m_maxHP;
    }
    return *this;
}

HealthPoints &HealthPoints::operator-=(const int sub)
{
    *this += -sub;
    return *this;
}

HealthPoints HealthPoints::operator+(const int add)
{
    HealthPoints result =this;
    return result+=add;
}

HealthPoints HealthPoints::operator-(const int sub)
{
    HealthPoints result =this;
    return result-=sub;
}

HealthPoints operator+(const int add, const HealthPoints &hp)
{
    HealthPoints result = hp;
    return result += add;
}
HealthPoints operator-(const int sub, const HealthPoints &hp)
{
    HealthPoints result = hp;
    return result -= sub;
}

std::ostream &operator<<(std::ostream &os, const HealthPoints &hp)
{
    os << hp.m_currentHP << "(" << hp.m_maxHP << ")";
    return os;
}

bool operator==(const HealthPoints &hp1, const HealthPoints &hp2)
{
    if (hp1.m_currentHP == hp2.m_currentHP)
        return true;
    else
        return false;
}

bool operator!=(const HealthPoints &hp1, const HealthPoints &hp2)
{
    return !(hp1 == hp2);
}

bool operator>=(const HealthPoints &hp1, const HealthPoints &hp2)
{
    if (hp1.m_currentHP >= hp2.m_currentHP) return true;
    return false;
}
bool operator>(const HealthPoints &hp1, const HealthPoints &hp2)
{
    if (hp1.m_currentHP > hp2.m_currentHP) return true;
    return false;
}
bool operator<=(const HealthPoints &hp1, const HealthPoints &hp2)
{
    return !(hp1 > hp2);
}
bool operator<(const HealthPoints &hp1, const HealthPoints &hp2)
{
    return !(hp1 >= hp2);
}