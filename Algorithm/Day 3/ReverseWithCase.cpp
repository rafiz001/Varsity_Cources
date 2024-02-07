//Input a string then reverse the string but make sure the character case are correct. Ex: "BanglaDesh" => "HsedalGnab"
#include <iostream>
#include <string>
using namespace std;
int main()
{

    string given;

    cin >> given;
    int n = given.length();
    char output[n];
    bool Case[n];
    for (int i = 0, j = n - 1; i < n; i++)
    {

        output[j] = given[i];

        if ((output[j] >= 'a' && output[j] <= 'z'))
        {
            Case[i] = false;
        }
        else
        {

            output[j] = output[j] + 32;
            Case[i] = true;
        }

        j--;
    }

    for (int i = 0; i < n; i++)
    {
        if (Case[i] == true)
            output[i] = output[i] - 32;

        cout << output[i];
    }

    cout << "\n";

    return 0;
}
