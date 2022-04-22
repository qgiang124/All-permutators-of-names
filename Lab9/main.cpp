/* Author: Giang Tran
 * Date: April 21, 2022
 * Instructor: Dr. Rubenia Borge
 * Description:  a program that lists all ways people can line up for a photo (all permutations of a list of strings). The program will read a list of one word names (until -1), and use a recursive method to create and output all possible orderings of those names separated by a comma, one ordering per line.
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PrintAllPermutations( vector<string> &permList, vector<string> &nameList) {
    string tempName;
    if (nameList.size() == 0) {
        for (unsigned int i = 0; i < permList.size(); i++) {
            if (i == permList.size() - 1) {
                cout << permList.at(i) << endl;
            }
            else {
                cout << permList.at(i) << ", ";
            }
        }
    }
    else {
        for (unsigned int i = 0; i < nameList.size(); i++) {
            tempName = nameList.at(i);
            nameList.erase(nameList.begin() + i);
            permList.push_back(tempName);
            
            PrintAllPermutations(permList, nameList);
            
            nameList.insert(nameList.begin() + i, tempName);
            permList.pop_back();
        }
    }
}

int main() {
    vector<string> nameList;
    vector<string> permList;
    string name;

    cout << "Please enter the list of names:" << endl;
    cin >> name;
    while (name != "-1") {
        nameList.push_back(name);
        cin >> name;
    }
    
    PrintAllPermutations(permList, nameList);
    return 0;
}
