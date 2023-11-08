#include "characterFactory.h"


#include "cleric.h"
#include "dwarf.h"
#include "elf.h"
#include "fighter.h"
#include "halfling.h"
#include "human.h"
#include "rogue.h"
#include "wizard.h"

characterFactory & characterFactory::GetCharacterFactory()
{
	static characterFactory c;
	return c;
} // instance


std::shared_ptr<IClass> ShipFactory::CreateCharacter(enumOfTypeClass enumOfTypeClassType, raceOfTypeClass raceType)
{
	std::shared_ptr<IClass> retVal = nullptr;
	if (enumOfTypeClassType == fighter)
	{
		retVal = std::make_shared<fighter>(m_raceMap[raceType]);
	}
    else if (enumOfTypeClassType == cleric)
	{
		retVal = std::make_shared<cleric>(m_raceMap[raceType]);
	}
    else if (enumOfTypeClassType == rogue)
	{
		retVal = std::make_shared<rogue>(m_raceMap[raceType]);
	}
    else if (enumOfTypeClassType == wizard)
	{
		retVal = std::make_shared<wizard>(m_raceMap[raceType]);
	}
    
	return retVal;
}

characterFactory::characterFactory() 
{
		
	std::shared_ptr<IRace> t1 = std::make_shared<fighter>();
	std::shared_ptr<IRace> t2 = std::make_shared<cleric>();
    std::shared_ptr<IRace> t3 = std::make_shared<rogue>();
	std::shared_ptr<IRace> t4 = std::make_shared<wizard>();
	m_raceMap[FighterType] = t1;
	m_raceMap[ClericType] = t2;
    m_raceMap[RogueType] = t3;
    m_raceMap[WizardType] = t4;
}


 characterFactory::~characterFactory() 
{
    m_raceMap.clear();
}
