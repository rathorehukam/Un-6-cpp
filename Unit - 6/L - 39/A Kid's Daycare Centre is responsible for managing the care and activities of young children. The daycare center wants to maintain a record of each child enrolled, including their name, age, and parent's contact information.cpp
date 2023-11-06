


#include <iostream>
#include <vector>
#include <string>
template<typename T1, typename T2>
class Child {
public:
    T1 name;
    T2 age;
    T1 parentsContact;

    Child(T1 name, T2 age, T1 parentsContact) : name(name), age(age), parentsContact(parentsContact) {}

    void displayChild() {
        std::cout << "Child Name: " << name << ", Age: " << age << ", Parent's Contact: " << parentsContact << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n; 

    std::vector<Child<std::string, int>> childrenList;

    std::string name, contact;
    int age;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> age >> contact;
        childrenList.emplace_back(name, age, contact);
    }
 
    std::cout << "Enrolled Children:" << std::endl;
    for (auto &child : childrenList) {
        child.displayChild();
    }

    return 0;
}
