#ifndef SOCIALMEDIAACCOUNT_H
#define SOCIALMEDIAACCOUNT_H
#include <iostream>
using namespace std;

template <typename T>
class SocialMediaAccount {
private:
    T handler;
    T followers[maxFollowers];
    T followed[maxFollowed];
    int followerCount;
    int followedCount;
    bool isPrivate;
public:
    SocialMediaAccount():handler(),followerCount(0), followedCount(0), isPrivate(true){}

};
#endif //SOCIALMEDIAACCOUNT_H
