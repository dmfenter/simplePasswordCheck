# simplePasswordCheck
This is a very simple password strength checker written in c++. 
it can be compiled using the following two commands in the terminal:
1. g++ -o check passwordChecker.cpp
2. ./check
You will then be prompted to enter a potential password. The function will then tell you how strong of a password you have entered.
Please be aware of the limitations of this program. No password data is ever stored, so this code is not a security threat, however it is a very simple implementation.
While it can give you a rough idea of how complex, and therefore secure, your password is, it is also easy to game. You can create passwords that barely meet all of the qualifications,
and gets a high score, but is still a weak password. This program was created for a school project, and in no way should be used as definitive peace of mind as to the strength of your password.

