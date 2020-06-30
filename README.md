# Class_Assignments
While working and learning about classes, here are the assignments that we had to complete in the Lab.

# Lab 11A (social.cpp):
In this task, write a program social.cpp, in which you have to implement the class Profile that can store the info about a user of the network.

It has two private properties of type string: displayname and username.

The public interface consists of two constructors initializing the private variables and three functions:
getUsername returns the username.
getFullName returns the string in the format “displayname (@username)”.
setDisplayname allows to change the displayname property. (Username is a unique user identifier and cannot change, while displayname can be any string and can be modified, so the class provides a mechanism for updating it.)

# Lab 11B (social2.cpp):
The three main functionalities of the class Network are: 1) adding new users to the network, 2) following, and 3) posting messages. We are going to develop them in these three tasks.

Write a program social2.cpp, implementing the first version of the class Network (feel free to copy your class Profile and anything else from the previous program).

This first version of the class should be able to add new users and store their profiles, for that, the class has the following private variables:

an array of registered user profiles,
an integer numUsers, which stores the number of registered users.
the size of the profiles array is defined as MAX_USERS=20, we cannot sign up more than this number of users.
The index in the array profile is the profile ID. As you keep adding new users, they are receiving ID = 0, 1, 2, and so on. To look up the ID of a specific profile by its username, we have a private function findID(usrn), it should return the ID of the user with that username, or -1 if the user is not found in the profiles array.

The public interface:

a default constructor that creates an empty network. For now, setting numUsers = 0 is enough.
addUser(usrn, dspn) is the central function for the class. It allows adding new users. This function receives the username and display name of a new user, the new user can be signed up only if the following conditions are met:
the new username usrn must be a non-empty alphanumeric string,
there is no other users in the network with the same username,
the array profiles is not full.
If the above conditions are met, the new user should be added to the array profiles and the function should return true, otherwise don’t add the user and return false, thus indicating that the operation failed.

# Lab 12C (social3.cpp):
Write a new program social3.cpp, which is an improved version of the previous program.

The class Network should be changed to keep the friendship (following) relation between the users.
