/**************************************************************************
 * Author              : Nathan Philburn
 * Program             : Homework 4
 * Date Created        : 4/3/2025
 * Date Last Modified  : 4/9/2025
 * Usage               : No command line arguments.
 *
 * Description:
 *   Demonstrates the use of the SocialMediaAccount template class and its
 *   derived classes Twitter and Instagram. The program creates objects with
 *   both string and Profile types, adds followers/followed accounts, and tests
 *   the increment functions for retweets and likes.
 *************************************************************************/
#include "SocialMediaAccount.h"
#include <iostream>
#include <string>
using namespace std;

struct Profile {
    int userId;
    string username;
};

ostream& operator<<(ostream& os, const Profile& profile){os<<"(Profile ID: "<<profile.userId<<", Username: "<<profile.username<<")";
    return os;
}

int main() {
    Twitter<string> TS("DarthVader", false);  // Public account.
    TS.addFollower("ObiWan");
    TS.addFollower("Yoda");
    TS.addFollowed("Emp_Palpatine");
    TS.addFollowed("JarJar");

    cout<<"Twitter account name: "<<TS.getHandler()<<endl;
    cout<<"Who is following DarthVader?"<<endl;
    TS.displayFollowers();
    cout<<"Who does DarthVader follow?"<<endl;
    TS.displayFollowed();
    cout<<"Initial retweet count: "<<TS.getRetweetCount()<<endl;
    TS.RT();TS.RT();TS.RT();TS.RT();TS.RT();TS.RT();TS.RT();         //retweets
    TS.RT();TS.RT();TS.RT();TS.RT();TS.RT();TS.RT();TS.RT();
    cout<<"Retweet count after "<<TS.getHandler()<<" completed retweeting: "<<TS.getRetweetCount()<<endl;
    cout<<"=================================="<<endl;

    Profile profile1={1, "PrincessLeia"};       //test for twitter profile types
    Profile profile2={2, "HanSolo"};
    Profile profile3={3, "Luke_Skywalker"};

    Twitter<Profile> TP(profile1, false);   //public account
    TP.addFollower(profile2);
    TP.addFollower(profile3);
    TP.addFollowed(profile3);

    cout<<"Twitter profile info: "<<TP.getHandler()<<endl;
    cout<<"Who follows "<<TP.getHandler()<<"?"<<endl;
    TP.displayFollowers();
    cout<<"Who does "<<TP.getHandler()<<" follow?"<<endl;
    TP.displayFollowed();
    cout<<"Initial retweet count: "<<TP.getRetweetCount()<<endl;
    TP.RT();                //retweets
    cout<<"Retweet count after "<<TP.getHandler()<<" completed retweeting: "<<TP.getRetweetCount()<<endl;
    cout<<"=================================="<<endl;

    Instagram<string> IS("Rey_Skywalker", false);  //testing instagram with string type
    IS.addFollower("Finn");
    IS.addFollower("DarthMaul");
    IS.addFollowed("R2_D2");

    cout<<"Instagram account name: "<<IS.getHandler()<<endl;
    cout<<"Who follows "<<IS.getHandler()<<"?"<<endl;
    IS.displayFollowers();
    cout<<"Who does "<<IS.getHandler()<<" follow?"<<endl;
    IS.displayFollowed();
    cout<<"Initial like count: "<<IS.getLikeCount()<<endl;
    IS.Like();IS.Like();IS.Like();
    cout<<"Like count after "<<IS.getHandler()<<" liked post(s): "<<IS.getLikeCount()<<endl;
    cout<<"=================================="<<endl;

    Profile profile4={4, "Mandalorian"};        //testing instagram with profile
    Profile profile5={5, "Boba_Fett"};

    Instagram<Profile> IP(profile4, false);
    IP.addFollower(profile5);
    IP.addFollowed(profile5);

    cout<<"Instagram profile info:"<<IP.getHandler()<<endl;
    cout<<"Who follows "<<IP.getHandler()<<"?"<<endl;
    IP.displayFollowers();
    cout<<"Who does "<<IP.getHandler()<<" follow?"<<endl;
    IP.displayFollowed();
    cout<<"Initial like count: "<<IP.getLikeCount()<<endl;
    IP.Like();IP.Like();IP.Like();IP.Like();                //likes
    cout<<"Like count after "<<IP.getHandler()<<"liked post(s): "<<IP.getLikeCount()<<endl;

    return 0;
}