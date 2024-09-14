#include "File.h"

#include "gtest/gtest.h"

#include <iostream>

using namespace tp1;
using namespace std;

TEST(File, constructor)
{
    File<int> f;
    EXPECT_EQ(0, (int)f.taille());
}

TEST(File, enfiler)
{
    File<int> f;
    f.enfiler(1);
    f.enfiler(2);
    EXPECT_EQ(2, (int)f.taille());
}

TEST(File, defiler)
{
    File<int> f;
    EXPECT_EQ(0, (int)f.taille());
    f.enfiler(1);
    EXPECT_EQ(1, (int)f.taille());
    f.enfiler(2);
    EXPECT_EQ(2, (int)f.taille());
    f.defiler();
    EXPECT_EQ(1, (int)f.taille());
}

TEST(File, impression)
{
    File<int> f;
    // cout << "liste: " << f << "; taille: " << f.taille() << endl;
    EXPECT_EQ(0, (int)f.taille());
    f.enfiler(1);
    // cout << "liste: " << f << "; taille: " << f.taille() << endl;
    EXPECT_EQ(1, (int)f.taille());
    f.enfiler(2);
    // cout << "liste: " << f << "; taille: " << f.taille() << endl;
    EXPECT_EQ(2, (int)f.taille());
    f.defiler();
    // cout << "liste: " << f << "; taille: " << f.taille() << endl;
    EXPECT_EQ(1, (int)f.taille());
    f.defiler();
    // cout << "liste: " << f << "; taille: " << f.taille() << endl;
    EXPECT_EQ(0, (int)f.taille());
}