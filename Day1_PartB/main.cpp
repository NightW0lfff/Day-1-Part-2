#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ifstream input_file("input.txt");
    string line;
    int highest_calories = 0;
    vector<int> elf_calories (3,0);
    int current_calories = 0;
    int num;

    while (getline(input_file, line)) {
        if (line.empty()){
          if(current_calories > elf_calories.back()){
              elf_calories.push_back(current_calories);
              sort(elf_calories.begin(), elf_calories.end(), greater<int>());
              if(elf_calories.size() > 3){
                  elf_calories.pop_back();
              }
          }
            current_calories = 0;
        }else{
            num = stoi(line);
            current_calories += num;
        }
    }
    
    for(int calories: elf_calories){
        highest_calories += calories;
    }
  
    cout << highest_calories << endl;
    return 0;
}
