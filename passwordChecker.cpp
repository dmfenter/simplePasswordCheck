#include <iostream>
#include <string>
#include <cctype>
#include <vector>

class PasswordChecker
{
public:
PasswordChecker() {} //default constructor

/// @brief this function takes in a string inputted by the user, which is a potential password. 
/// The password is checked for several factors of password strength. The score is then calculated up to a max of 6, 
/// and a helper function is used to assign ranges of strength to either weak, moderate, or strong.
static int evaluatePasswordStrength(const std::string &password)
    {
        int score = 0;
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        std::string specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";

        if (password.length() >= 8) 
            score++;
        if (password.length() >= 12) //Since password length is the best quality, two points can be earned
            score++;

        for (char i : password)
        {
            if (std::islower(i))
                hasLower = true;
            else if (std::isupper(i))
                hasUpper = true;
            else if (std::isdigit(i))
                hasDigit = true;
            else if (specialChars.find(i) != std::string::npos)
                hasSpecial = true;
        }

        if (hasLower)
        {score++;};
        if (hasUpper)
        {score++;}
        if (hasDigit)
        {score++;}
        if (hasSpecial)
        {score++;}

        return score; 
    }
    /// @brief This function converts the score calculated into one of three verbal scores.
    /// @param score the integer representing their password strength.
    /// @return the phrase representing their password strength. 
    static std::string getStrengthPhrase(int score)
    {
        if (score <= 2)
            return "Weak: Please improve your password.";
        if (score >2 && score <=4)
            return "Moderate: Your password is okay, but could use improving.";
        if(score <=5)
        return "Strong: Your password is very good!";
    }
};

int main()
{
    std::string password;
    std::cout << "Enter a password to check its strength: ";
    std::cin >> password;

    int strengthScore = PasswordChecker::evaluatePasswordStrength(password);
    std::cout << "Password Strength: " << PasswordChecker::getStrengthPhrase(strengthScore) << "\n";

    return 0;
}