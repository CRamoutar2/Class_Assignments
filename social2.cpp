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
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
};

Network::Network()
{
	numUsers = 0;
}

int Network::findID(string usrn)
{
    for(int i = 0; i < 20; i++)
    {
        if(profiles[i].getUsername() == usrn)
        {
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
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}