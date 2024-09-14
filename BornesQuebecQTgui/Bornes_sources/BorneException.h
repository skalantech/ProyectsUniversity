/* 
 * File:   BorneException.h
 * Author: etudiant
 *
 * Created on April 15, 2024, 1:04 a.m.
 */

#ifndef BORNEEXCEPTION_H
#define BORNEEXCEPTION_H

#include <stdexcept>

namespace bornesQuebec
{
class BorneException : public std::runtime_error
{
public:
    BorneException(const std::string& p_raison): std::runtime_error(p_raison) {}
};

class BorneDejaPresentException : public BorneException
{
public:
    BorneDejaPresentException(const std::string& p_raison) : BorneException(p_raison) {}
    
};

class BorneAbsenteException : public BorneException
{
public:
    BorneAbsenteException(const std::string& p_raison) : BorneException(p_raison) {}
    
};
}
#endif /* BORNEEXCEPTION_H */

