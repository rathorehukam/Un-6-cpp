











#include <iostream>
#include <vector>
#include <stdexcept>

const int MAX_ASSETS = 20;

class InvalidAssetIDException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid asset ID.";
    }
};

class NegativeValueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Asset value cannot be negative.";
    }
};

class Asset {
public:
    std::string id;
    float value;
};

class AssetManagementSystem {
private:
    std::vector<Asset> assets;

public:
    void addAsset(const std::string& id, float value) {
        if (assets.size() >= MAX_ASSETS) {
            std::cout << "Error: Maximum number of assets reached." << std::endl;
            return;
        }

        Asset newAsset;
        newAsset.id = id;
        newAsset.value = value;
        assets.push_back(newAsset);

        std::cout << "Asset with ID " << id << " added with an initial value of " << value << std::endl;
    }

    void updateAssetValue(const std::string& id, float newValue) {
    for (auto& asset : assets) {
        if (asset.id == id) {
            if (newValue < 0) {
                throw NegativeValueException();
            }
            asset.value = newValue;
            std::cout << "Value of asset with ID " << id << " updated to " << newValue << std::endl;
            return;
        }
    }

    throw InvalidAssetIDException();
}

};

int main() {
    AssetManagementSystem assetSystem;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::string id;
        float value;
        std::cin >> id >> value;

        try {
            assetSystem.addAsset(id, value);
        } catch (std::exception& e) {
            std::cout << "Exception caught: Error: " << e.what() << std::endl;
        }
    }

    std::string updateId;
    float updateValue;
    std::cin >> updateId >> updateValue;

    try {
        assetSystem.updateAssetValue(updateId, updateValue);
    } catch (std::exception& e) {
        std::cout << "Exception caught: Error: " << e.what() << std::endl;
    }

    return 0;
}
