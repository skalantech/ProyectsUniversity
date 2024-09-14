#include "Case.h"

#include "gtest/gtest.h"

#include <iostream>
#include <sstream>

using namespace tp1;
using namespace std;

TEST(Case, constructor_default)
{
    Case c;
    // cout << c << endl;
    std::ostringstream os;
    os << c;
    EXPECT_EQ("(2,A)", os.str());
    EXPECT_EQ(2, c.couleur);
    EXPECT_EQ(0, c.decoration);
}

TEST(Case, constructor_parameters)
{
    Case c(Case::Couleur::Rouge, Case::Decoration::Serpent);
    Case c1(Case::Couleur::Vert, Case::Decoration::Echelle);
    // cout << c << endl;
    // cout << c1 << endl;
    std::ostringstream os;
    os << c;
    EXPECT_EQ("(0,S)", os.str());
    EXPECT_EQ(0, c.couleur);
    EXPECT_EQ(1, c.decoration);
    os.str("");
    os.clear();
    os << c1;
    EXPECT_EQ("(1,E)", os.str());
    EXPECT_EQ(1, c1.couleur);
    EXPECT_EQ(2, c1.decoration);
}
