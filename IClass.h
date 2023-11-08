#pragma once
#include <string>
#include "IRace.h"
#include <memory>

class IClass{
    public:
        IClass(std::shared_ptr<IRace> race) : 
        m_hitPoint(0),
        m_armorClass(0),
        m_hitBonus(0),
        m_initiative(0),
        m_baseDamage(0),
        m_race(race) {};
        
        int classType;

        virtual int getHitPoints(){
            int retVal = m_hitPoint + m_race->getHitPointMod();
            return retVal;
        }

        virtual int getArmorClass(){
            int retVal = m_armorClass + m_race->getArmorClassMod();
            return retVal;
        }

        virtual int getHitBonus(){
            int retVal = m_hitBonus + m_race->getHitBonusMod();
            return retVal;
        }

        virtual int getInitiative(){
            int retVal = m_initiative + m_race->getInitiativeBonus();
            return retVal;
        }

    protected:
        int m_hitPoint;
        int m_armorClass;
        int m_hitBonus;
        int m_initiative;
        int m_baseDamage;
        std::shared_ptr<IRace> m_race;
        
};