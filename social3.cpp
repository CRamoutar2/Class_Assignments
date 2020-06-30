//Name: Chethram Ramoutar
//Email: Chethram.Ramoutar79@myhunter.cuny.edu

#include <iostream>
#include <string>
using namespace std;

class Profile
{
    private:
        string username;
        string displayname;
    public:
        // Profile constructor for a user (initializing
        // private variables username=usrn, displayname = dspn)
        Profile(string usrn, string dspn);

        // Default Profile constructor (username - "", displayname = "")
        Profile();

        // Return username
        string getUsername();

        // Return name in the format: "displayname (@username)"
        string getFullName();

        // Change display name
        void setDisplayName(string dspn);
};

class Network {
    private:
      static const int MAX_USERS = 20; // max number of user profiles
      int numUsers;                    // number of registered users
      Profile profiles[MAX_USERS];     // user profiles array:
                                       // mapping integer ID -> Profile
    
      // Returns user ID (index in the 'profiles' array) by their username
      // (or -1 if username is not found)
      int findID (string usrn);
      bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
        // following[id1][id2] == true when id1 is following id2
    public:
      // Constructor, makes an empty network (numUsers = 0)
      Network();
      // Attempts to sign up a new user with specified username and displayname
      // return true if the operation was successful, otherwise return false
      bool addUser(string usrn, string dspn);
      // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
      // return true if success (if both usernames exist), otherwise return false
      bool follow(string usrn1, string usrn2);
      // Print Dot file (graphical representation of the network)
      void printDot();
};

bool Network::follow(string usrn1, string usrn2){
    if ( (findID(usrn1) == -1) or (findID(usrn2) == -1) ){
        return false;
    }
    else {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    }
}

void Network::printDot(){
    cout << "digraph {" << endl;
    for(int i = 0; i < numUsers; i++){
        cout << "\t\"@" << profiles[i].getUsername() << "\"" << endl;
    }
    cout << endl;
    for(int i = 0; i < numUsers; i++){
        for (int k = 0; k < numUsers; k++){
            if(following[i][k]){
                cout << "\t\"@" << profiles[i].getUsername() << "\"";
                cout << " -> ";
                cout << "\"@" << profiles[k].getUsername() << "\"" << endl;
            }
            
        }
    }
    
    cout << "}";
}


Network::Network(){
    numUsers = 0;
    
    for(int i = 0; i < MAX_USERS; i++){
        for(int k = 0; k < MAX_USERS; k++){
            following[i][k] = false;
        }
    }
    
}

int Network::findID(string usrn){
    for(int i = 0; i < MAX_USERS; i++){
        if(usrn == profiles[i].getUsername()){
            return i;
        }
    }
    return -1;
}

bool Network::addUser(string usrn, string dspn){

    bool filler; // Nonempty and alphanumeric.

    if (usrn.length() >= 1){
        for (int i = 0; i < usrn.length(); i++){
            if(!isalnum(usrn[i])){
                filler = false;
                break;
            }
            else filler = true;
        }
    }
    else{
		filler = false;
	}
    bool filler_2; // Check if name is taken.

    for(int i = 0; i < MAX_USERS; i++){
        if (usrn == profiles[i].getUsername()){
            filler_2 = false;
            break;
        }
        else {
			filler_2 = true;
    }
	}

    bool filler_3; // If there array isn't filled up.
    if(numUsers == 20){
        filler_3 = false;
    }
    else {
		filler_3 = true;
	}

    // If all three conditions are met, add profile to array and return true.

    if (filler and filler_2 and filler_3)
	{
        profiles[numUsers] = Profile(usrn, dspn);
        numUsers++;
        return true;
    }
    else {
		return false;
	}
}

Profile::Profile(string usrn, string dspn)
{
  username = usrn;
  displayname = dspn;
}
Profile::Profile(){}

string Profile::getUsername()
{
    return username;
}
string Profile::getFullName()
{
    string potato_head;
	potato_head = displayname + " (@" + username + ")";
	return potato_head;
}
void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}