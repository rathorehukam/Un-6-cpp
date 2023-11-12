








// You are using GCC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Song {
    std::string title;
    std::string artist;
    int duration; 
};

class Playlist {
private:
    std::vector<Song> songs;
public:
    void addSong(const std::string& title, const std::string& artist, int duration) {
        songs.push_back({title, artist, duration});
    }
    void removeSong(const std::string& title) {
        auto it = std::remove_if(songs.begin(), songs.end(), [title](const Song& song) {
            return song.title == title;
        });
        songs.erase(it, songs.end());
    }

    void displayPlaylist() {
        std::cout << "Playlist:" << std::endl;
        for (const Song& song : songs) {
            std::cout << " " << song.title << " " << song.artist << " " << song.duration << " " << std::endl;
        }
    }
};

int main() {
    Playlist playlist;
    std::string title, artist;
    int duration;
    char choice;
    do {
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cin.ignore();
                std::getline(std::cin, title);
                std::getline(std::cin, artist);
                std::cin >> duration;
                playlist.addSong(title, artist, duration);
                break;

            case '2':
                std::cin.ignore();
                std::getline(std::cin, title);
                playlist.removeSong(title);
                break;

            case '3':
                playlist.displayPlaylist();
                break;

            case '4':
                std::cout << "Exiting the program.";
                break;

            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    } while (choice != '4');
    return 0;
}
