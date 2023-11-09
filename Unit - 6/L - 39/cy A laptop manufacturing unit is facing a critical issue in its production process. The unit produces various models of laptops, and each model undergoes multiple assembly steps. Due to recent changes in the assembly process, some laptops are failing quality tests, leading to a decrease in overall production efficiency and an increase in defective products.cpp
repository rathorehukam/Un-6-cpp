









#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct LaptopModel {
    string name;
    int assemblySteps;
};

template <typename T>
void addLaptopModel(vector<T>& laptopModels, const string& name, int assemblySteps) {
    if (laptopModels.size() < 15) {
        T model;
        model.name = name;
        model.assemblySteps = assemblySteps;
        laptopModels.push_back(model);
        cout << name << " - Added to the production line" << endl;
    } else {
        cout << "Production line is full. Cannot add more laptop models!" << endl;
    }
}
template <typename T>
void updateAssemblySteps(vector<T>& laptopModels, const string& name, int newAssemblySteps) {
    for (T& model : laptopModels) {
        if (model.name == name) {
            model.assemblySteps = newAssemblySteps;
            cout << name << " - Updated" << endl;
            return;
        }
    }
    cout << name << " - Not found" << endl;
}

template <typename T>
void displayLaptopModels(const vector<T>& laptopModels) {
    for (const T& model : laptopModels) {
        cout << "Model Name: " << model.name << ", Assembly Steps: " << model.assemblySteps << endl;
    }
}

int main() {
    vector<LaptopModel> laptopModels;

    int choice;
    while (true) {
        cin >> choice;

        if (choice == 1) {
            string name;
            int assemblySteps;
            cin.ignore();
            getline(cin, name);
            cin >> assemblySteps;
            addLaptopModel(laptopModels, name, assemblySteps);
        } else if (choice == 2) {
            string name;
            int newAssemblySteps;
            cin.ignore();
            getline(cin, name);
            cin >> newAssemblySteps;
            updateAssemblySteps(laptopModels, name, newAssemblySteps);
        } else if (choice == 3) {
            displayLaptopModels(laptopModels);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
