#include "party.h"


Party::Party(){

}

Party::Party(const std::shared_ptr<IClass> character) : m_flagClass(character){
    
}

void Party::setFlagClass(const std::shared_ptr<IClass> character){
    m_flagClass = character;
}

std::shared_ptr<IClass> Party::getCharacter() const {
    return m_flagClass;
}

void Party::addCharacter(const std::shared_ptr<IClass> character){
    if (m_party.size() != 0){
        for (int i = 0; i<m_party.size(); i++){
            if(*m_party[i].classType > *character.classType){
                m_party.insert(m_party.begin()+i, character);
            }
        }
    
    }
}

std::vector<std::shared_ptr<IClass>> Party::getParty(){
    return m_party;
}
