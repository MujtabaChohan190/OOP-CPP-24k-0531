#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 🎵 Song Class (Basic Entity)
class Song {
private:
    string title;
    string artist;
    float duration; // in minutes

public:
    // Constructor
    Song(string t, string a, float d) : title(t), artist(a), duration(d) {}

    // Getters
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    float getDuration() const { return duration; }

    // Display Song Info
    void displayInfo() const {
        cout << "🎵 " << title << " by " << artist << " (" << duration << " min)" << endl;
    }
};

// 🎶 Playlist Class (Stores Songs Directly)
class Playlist {
private:
    string name;
    vector<Song> songs; // Stores Song objects (not pointers)

public:
    // Constructor
    Playlist(string n) : name(n) {}

    // Add Song to Playlist
    void addSong(const Song& song) {
        songs.push_back(song);
        cout << "Added: " << song.getTitle() << " to playlist " << name << endl;
    }

    // Remove Song from Playlist
    void removeSong(string title) {
        for (int i = 0; i < songs.size(); i++) {
            if (songs[i].getTitle() == title) {
                cout << "Removed: " << songs[i].getTitle() << " from playlist " << name << endl;
                songs.erase(songs.begin() + i);
                return;
            }
        }
        cout << "Song not found in playlist!\n";
    }

    // Display Playlist Info
    void displayPlaylist() const {
        cout << "\n📀 Playlist: " << name << endl;
        if (songs.empty()) {
            cout << "   (No songs added yet)\n";
        } else {
            for (const Song& song : songs) {
                song.displayInfo();
            }
        }
    }

    // Get Playlist Name
    string getName() const { return name; }
};

// 👤 User Class (Owns Playlists)
class User {
private:
    string name;
    string email;
    vector<Playlist> playlists; // Stores Playlist objects (not pointers)

public:
    // Constructor
    User(string n, string e) : name(n), email(e) {}

    // Create a Playlist
    void createPlaylist(string playlistName) {
        playlists.push_back(Playlist(playlistName));
        cout << name << " created playlist: " << playlistName << endl;
    }

    // Add Song to a Playlist
    void addSongToPlaylist(string playlistName, const Song& song) {
        for (int i = 0; i < playlists.size(); i++) {
            if (playlists[i].getName() == playlistName) {
                playlists[i].addSong(song);
                return;
            }
        }
        cout << "Playlist not found!\n";
    }

    // Remove Song from a Playlist
    void removeSongFromPlaylist(string playlistName, string songTitle) {
        for (int i = 0; i < playlists.size(); i++) {
            if (playlists[i].getName() == playlistName) {
                playlists[i].removeSong(songTitle);
                return;
            }
        }
        cout << "Playlist not found!\n";
    }

    // Display User Playlists
    void displayUserPlaylists() const {
        cout << "\n👤 User: " << name << " (" << email << ")" << endl;
        for (const Playlist& playlist : playlists) {
            playlist.displayPlaylist();
        }
    }
};

// 📌 **Main Function to Demonstrate Functionality**
int main() {
    // 🎤 Create User Alice
    User alice("Alice", "alice@example.com");

    // 🎼 Create Playlists
    alice.createPlaylist("Workout Mix");
    alice.createPlaylist("Relaxation Vibes");

    // 🎶 Create Songs (Stored on Stack)
    Song song1("Eye of the Tiger", "Survivor", 4.2);
    Song song2("Stronger", "Kanye West", 3.8);
    Song song3("Chill Out", "Norah Jones", 4.5);
    Song song4("Weightless", "Marconi Union", 6.0);

    // 🎵 Add Songs to Playlists
    alice.addSongToPlaylist("Workout Mix", song1);
    alice.addSongToPlaylist("Workout Mix", song2);
    alice.addSongToPlaylist("Relaxation Vibes", song3);
    alice.addSongToPlaylist("Relaxation Vibes", song4);

    // 📌 Display Initial Playlists
    alice.displayUserPlaylists();

    // ❌ Alice removes "Stronger" from "Workout Mix"
    alice.removeSongFromPlaylist("Workout Mix", "Stronger");

    // 📌 Display Updated Playlists
    alice.displayUserPlaylists();

    return 0; // No manual memory cleanup needed
}
