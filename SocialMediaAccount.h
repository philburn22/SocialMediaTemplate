#ifndef SOCIALMEDIAACCOUNT_H
#define SOCIALMEDIAACCOUNT_H
#include <iostream>
using namespace std;

const int maxFollowed=10;               //global variables
const int maxFollowers=10;

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
    SocialMediaAccount():handler(),followerCount(0), followedCount(0), isPrivate(true){}            //constructors
    SocialMediaAccount(T handle, bool privacy=true):handler(handle), followerCount(0), followedCount(0), isPrivate(privacy){}

    void setHandler(T handle){handler=handle;}          //setters and getters
    T getHandler() const{return handler;}
    void setPrivacy(bool privacy){isPrivate=privacy;}
    bool getPrivacy() const {return isPrivate;}
    int getFollowerCount() const {return followerCount;}
    int getFollowedCount() const{return followedCount;}

    void addFollowed(T user) {             //function that adds a followed acct if possible
        if (followedCount<maxFollowed) {
            followed[followedCount++]=user;
        }else {
            cout<<"Max limit of followed accounts reached."<<endl;
        }
    }
    void addFollower(T user) {          //function that adds a follower
        if (followerCount<maxFollowers) {
            followers[followerCount++]=user;
        }else {
            cout<<"Max limit of followers reached."<<endl;
        }
    }
    void displayFollowed()const {       //function that displays followed accounts
        if (!isPrivate) {
            cout<<"Following: ";
            for (int i=0;i<followedCount;i++) {
                cout<<followed[i];
                if (i<followedCount-1) {
                    cout<<", ";
                }
            }
            cout<<endl;
        }else {
            cout<<"Account info cannot be accessed."<<endl;
        }
    }
    void displayFollowers() const {             //function that displays followers
        if (!isPrivate) {
            cout<<"Followers: ";
            for (int i=0;i<followerCount;i++) {
                cout<<followers[i];
                if (i<followerCount-1) {
                    cout<<", ";
                }
            }
            cout<<endl;
        }else {
            cout<<"Account access cannot be displayed."<<endl;
        }
    }
};
template <typename T>
class Twitter:public SocialMediaAccount<T> {
private:
    int retweetCount;
public:
    Twitter():SocialMediaAccount<T>(), retweetCount(0){}
    Twitter(T handle, bool privacy=true):SocialMediaAccount<T>(handle, privacy), retweetCount(0){}
    void setRetweetCount(int count) {           //set and get retweet count
        retweetCount=count;
    }
    int getRetweetCount() const {
        return retweetCount;
    }
    void RT() {
        retweetCount++;             //increments retweet count by 1
    }
};
template <typename T>
class Instagram:public SocialMediaAccount<T> {
private:
    int likeCount;
public:
    Instagram():SocialMediaAccount<T>(), likeCount(0){}         //constructors
    Instagram(T handle, bool privacy=true):SocialMediaAccount<T>(handle, privacy), likeCount(0){}

    void setLikeCount(int count) {              //getters and setters for the count of "likes"
        likeCount=count;
    }
    int getLikeCount() const {
        return likeCount;
    }
    void Like() {
        likeCount++;            //increments like count by 1
    }
    };
#endif //SOCIALMEDIAACCOUNT_H
