









#include <iostream>
#include <map>
#include <string>

template <size_t N>
void processComplaint(std::map<std::string, int>& complaints, const std::string(&types)[N], const std::string& type) {
    
    complaints[type]++;
}

int main() {
    int numComplaints;
    std::cin >> numComplaints;
    std::cin.ignore(); 

    const std::string complaintTypes[] = {
        "Internet Issue", "Network Problem", "Billing Query", "Other"
    };

    std::map<std::string, int> complaintCounts;

    for (const auto& type : complaintTypes) {
        complaintCounts[type] = 0;
    }

    for (int i = 0; i < numComplaints; ++i) {
        std::string customerName, complaintType;
        std::getline(std::cin, customerName); 
        std::getline(std::cin, complaintType); 
        processComplaint(complaintCounts, complaintTypes, complaintType);
    }

    std::cout << "Complaint Count:" << std::endl;
    for (const auto& type : complaintTypes) {
        std::cout << type << ": " << complaintCounts[type] << std::endl;
    }

    return 0;
}
