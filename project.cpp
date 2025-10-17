#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <set>
#include <cstring> // for strlen

using namespace std;

struct Song {
    string name;
    string artist;
    string category;
    string language;
    
    Song(const string& n, const string& a, const string& c, const string& l) 
        : name(n), artist(a), category(c), language(l) {}
};

class EmotionAnalyzer {
private:
    map<string, string> emotionWords;
    
public:
    EmotionAnalyzer() {
        initializeEmotionDictionary();
    }
    
    void initializeEmotionDictionary() {
        vector<string> happyWords = {"happy", "joy", "excited", "cheerful", "great", 
                                   "amazing", "wonderful", "fantastic", "awesome", 
                                   "good", "excellent", "energetic", "pumped", "upbeat"};
        
        vector<string> sadWords = {"sad", "depressed", "down", "low", "unhappy", 
                                 "miserable", "awful", "terrible", "bad", "upset", 
                                 "disappointed", "heartbroken", "gloomy", "blue"};
        
        vector<string> calmWords = {"calm", "peaceful", "relaxed", "tired", "sleepy", 
                                  "mellow", "quiet", "serene", "tranquil", "gentle", 
                                  "soft", "soothing", "restful"};
        
        for (const string& word : happyWords) emotionWords[word] = "happy";
        for (const string& word : sadWords) emotionWords[word] = "sad";
        for (const string& word : calmWords) emotionWords[word] = "calm";
    }
    
    string cleanWord(const string& word) {
        string cleaned;
        for (char c : word) {
            if (isalpha(c)) cleaned += tolower(c);
        }
        return cleaned;
    }
    
    map<string, int> analyzeEmotion(const string& text) {
        map<string, int> emotionScores;
        emotionScores["happy"] = 0;
        emotionScores["sad"] = 0;
        emotionScores["calm"] = 0;
        emotionScores["energetic"] = 0;
        
        stringstream ss(text);
        string word;
        
        while (ss >> word) {
            string cleanedWord = cleanWord(word);
            if (emotionWords.find(cleanedWord) != emotionWords.end()) {
                string emotion = emotionWords[cleanedWord];
                emotionScores[emotion]++;
                if (emotion == "happy") emotionScores["energetic"]++;
            }
        }
        
        return emotionScores;
    }
    
    string getDominantEmotion(const map<string, int>& scores) {
        string dominant = "calm"; 
        int maxScore = 0;
        for (const auto& pair : scores) {
            if (pair.second > maxScore) {
                maxScore = pair.second;
                dominant = pair.first;
            }
        }
        return maxScore > 0 ? dominant : "calm";
    }
};

class MusicLibrary {
private:
    vector<Song> songs;
    string libraryFile = "music_library.csv";
    string logFile = "mood_history.txt";
    
public:
    MusicLibrary() {
        loadLibrary();
        initializeDefaultSongs();
    }
    
    void initializeDefaultSongs() {
        if (songs.empty()) {
            // English Songs
            songs.push_back(Song("Happy", "Pharrell Williams", "happy", "english"));
            songs.push_back(Song("Can't Stop the Feeling", "Justin Timberlake", "happy", "english"));
            songs.push_back(Song("Good as Hell", "Lizzo", "energetic", "english"));
            songs.push_back(Song("Uptown Funk", "Bruno Mars", "energetic", "english"));
            songs.push_back(Song("Walking on Sunshine", "Katrina and the Waves", "happy", "english"));
            
            songs.push_back(Song("Someone Like You", "Adele", "sad", "english"));
            songs.push_back(Song("Hello", "Adele", "sad", "english"));
            songs.push_back(Song("The Night We Met", "Lord Huron", "sad", "english"));
            songs.push_back(Song("Mad World", "Gary Jules", "sad", "english"));
            songs.push_back(Song("Hurt", "Johnny Cash", "sad", "english"));
            
            songs.push_back(Song("Weightless", "Marconi Union", "calm", "english"));
            songs.push_back(Song("Clair de Lune", "Claude Debussy", "calm", "english"));
            songs.push_back(Song("River", "Joni Mitchell", "calm", "english"));
            songs.push_back(Song("Mad About You", "Sting", "calm", "english"));
            songs.push_back(Song("The Night We Met", "Lord Huron", "calm", "english"));
            
            // Hindi Songs
            songs.push_back(Song("Jai Ho", "A.R. Rahman", "happy", "hindi"));
            songs.push_back(Song("Nagada Sang Dhol", "Shreya Ghoshal", "energetic", "hindi"));
            songs.push_back(Song("Malhari", "Vishal Dadlani", "energetic", "hindi"));
            songs.push_back(Song("Senorita", "Zindagi Na Milegi Dobara", "happy", "hindi"));
            songs.push_back(Song("Gallan Goodiyaan", "Dil Dhadakne Do", "happy", "hindi"));
            
            songs.push_back(Song("Tum Hi Ho", "Arijit Singh", "sad", "hindi"));
            songs.push_back(Song("Khairiyat", "Arijit Singh", "sad", "hindi"));
            songs.push_back(Song("Ae Dil Hai Mushkil", "Arijit Singh", "sad", "hindi"));
            songs.push_back(Song("Raabta", "Arijit Singh", "sad", "hindi"));
            songs.push_back(Song("Channa Mereya", "Arijit Singh", "sad", "hindi"));
            
            songs.push_back(Song("Tum Se Hi", "Jab We Met", "calm", "hindi"));
            songs.push_back(Song("Kun Faya Kun", "A.R. Rahman", "calm", "hindi"));
            songs.push_back(Song("Allah Ke Bande", "Kailash Kher", "calm", "hindi"));
            songs.push_back(Song("Moh Moh Ke Dhaage", "Papon", "calm", "hindi"));
            songs.push_back(Song("Raag Desh", "A.R. Rahman", "calm", "hindi"));
            
            // Assamese Songs 
            songs.push_back(Song("Sila", "Zubeen Garg" , "energetic" , "assamese"));
            songs.push_back(Song("Pakhi Pakhi Mon", "Zubeen Garg" , "energetic" , "assamese"));
            songs.push_back(Song("Jaanmoni", "Zubeen Garg" , "energetic" , "assamese"));
            songs.push_back(Song("Bihuwan", "Neel Akash" , "energetic" , "assamese"));
            songs.push_back(Song("Sokute Sokute", "Zubeen Garg" , "energetic" , "assamese")); 
            
            songs.push_back(Song("Maya", "Zubeen Garg" , "sad" , "assamese")); 
            songs.push_back(Song("Mayabini", "Zubeen Garg" , "sad" , "assamese"));
            songs.push_back(Song("Anamika", "Zubeen Garg" , "sad" , "assamese"));
            songs.push_back(Song("Ei Prithbi Ekhon Nopuroni Golpo", "Bhupen Hazarika" , "sad" , "assamese"));
            songs.push_back(Song("Ebar jodi Jao", "Neel Akash" , "sad" , "assamese"));
            
            songs.push_back(Song("Ei Pritihbi Ekhan Niyoror Sobi", "Zubeen Garg" , "calm" , "assamese"));
            songs.push_back(Song("Tumak Rakhisu Hridayot", "Zubeen Garg" , "calm" , "assamese"));
            songs.push_back(Song("Kinu senehor babe", "Zubeen Garg" , "calm" , "assamese"));
            songs.push_back(Song("Kuhipaat ", "Anju Panchi" , "calm" , "assamese"));
            songs.push_back(Song("Akashor Boroxa", "Tarali Sharma" , "calm" , "assamese"));

            saveLibrary();
        }
    }
    
    void loadLibrary() {
        ifstream file(libraryFile);
        if (!file.is_open()) return;
        
        string line;
        getline(file, line); // Skip header
        while (getline(file, line)) {
            stringstream ss(line);
            string name, artist, category, language;
            getline(ss, name, ',');
            getline(ss, artist, ',');
            getline(ss, category, ',');
            getline(ss, language, ',');
            songs.push_back(Song(name, artist, category, language));
        }
        file.close();
    }
    
    void saveLibrary() {
        ofstream file(libraryFile);
        if (!file.is_open()) {
            cout << "Error: Could not save library to file!" << endl;
            return;
        }
        file << "Song Name,Artist,Category,Language" << endl;
        for (const Song& song : songs) {
            file << song.name << "," << song.artist << "," 
                 << song.category << "," << song.language << endl;
        }
        file.close();
    }
    
    void addSong() {
        string name, artist, category, language;
        cin.ignore();
        cout << "\n=== Add New Song ===" << endl;
        cout << "Enter song name: ";
        getline(cin, name);
        cout << "Enter artist name: ";
        getline(cin, artist);
        cout << "Enter category (happy/sad/calm/energetic): ";
        getline(cin, category);
        cout << "Enter language (H for Hindi, E for English): ";
        getline(cin, language);
        
        if (language == "H" || language == "h") language = "hindi";
        else if (language == "E" || language == "e") language = "english";
        
        if (category != "happy" && category != "sad" && 
            category != "calm" && category != "energetic") {
            cout << "Invalid category! Using 'calm' as default." << endl;
            category = "calm";
        }
        
        songs.push_back(Song(name, artist, category, language));
        saveLibrary();
        cout << "Song added successfully!" << endl;
    }
    
    void viewLibrary() {
        if (songs.empty()) {
            cout << "No songs in library!" << endl;
            return;
        }
        cout << "\n=== Music Library ===" << endl;
        cout << "Total Songs: " << songs.size() << endl;
        cout << string(80, '-') << endl;
        printf("%-25s %-20s %-12s %-10s\n", "Song Name", "Artist", "Category", "Language");
        cout << string(80, '-') << endl;
        for (const Song& song : songs) {
            printf("%-25s %-20s %-12s %-10s\n", 
                   song.name.c_str(), song.artist.c_str(), 
                   song.category.c_str(), song.language.c_str());
        }
        cout << string(80, '-') << endl;
    }
    
    vector<Song> getRecommendations(const string& emotion, const string& preferredLanguage = "") {
        vector<Song> recommendations;
        for (const Song& song : songs) {
            bool emotionMatch = (song.category == emotion);
            bool languageMatch = (preferredLanguage.empty() || song.language == preferredLanguage);
            if (emotionMatch && languageMatch) recommendations.push_back(song);
        }
        if (recommendations.empty() && !preferredLanguage.empty()) {
            for (const Song& song : songs) {
                if (song.category == emotion) recommendations.push_back(song);
            }
        }
        return recommendations;
    }
    
    vector<Song> getMixedPlaylist(const map<string, int>& emotionScores, const string& preferredLanguage = "") {
        vector<Song> playlist;
        set<string> addedSongs;
        vector<pair<string, int>> sortedEmotions(emotionScores.begin(), emotionScores.end());
        sort(sortedEmotions.begin(), sortedEmotions.end(), 
             [](const pair<string, int>& a, const pair<string, int>& b) {
                 return a.second > b.second;
             });
        for (const auto& emotionPair : sortedEmotions) {
            if (emotionPair.second > 0) {
                vector<Song> emotionSongs = getRecommendations(emotionPair.first, preferredLanguage);
                int songsToAdd = min(emotionPair.second + 1, 3);
                int added = 0;
                for (const Song& song : emotionSongs) {
                    string songKey = song.name + "|" + song.artist;
                    if (addedSongs.find(songKey) == addedSongs.end() && added < songsToAdd) {
                        playlist.push_back(song);
                        addedSongs.insert(songKey);
                        added++;
                    }
                }
            }
        }
        return playlist;
    }
    
    void logMoodHistory(const string& text, const string& dominantEmotion) {
        ofstream file(logFile, ios::app);
        if (file.is_open()) {
            time_t now = time(0);
            char* timeStr = ctime(&now);
            timeStr[strlen(timeStr) - 1] = '\0'; 
            file << "[" << timeStr << "] Input: \"" << text 
                 << "\" | Detected Emotion: " << dominantEmotion << endl;
            file.close();
        }
    }
};

class PlaylistGenerator {
private:
    EmotionAnalyzer analyzer;
    MusicLibrary library;
    
    void displayHeader() {
        cout << "\n" << string(60, '=') << endl;
        cout << "    🎵 EMOTION-BASED MUSIC PLAYLIST GENERATOR 🎵" << endl;
        cout << string(60, '=') << endl;
    }
    
    void displayMenu() {
        cout << "\n=== MAIN MENU ===" << endl;
        cout << "1. Get Music Recommendations" << endl;
        cout << "2. Add New Song to Library" << endl;
        cout << "3. View Full Library" << endl;
        cout << "4. View Mood History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
    }
    
    string getLanguagePreference() {
        string choice;
        cout << "\nLanguage Preference:" << endl;
        cout << "As - Assamese Songs" <<endl;
        cout << "H - Hindi Songs" << endl;
        cout << "E - English Songs" << endl;
         
        cout << "A - All Languages" << endl;
        cout << "Enter your preference: ";
        cin >> choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        if (choice == "h") return "hindi";
        if (choice == "e") return "english";
        if (choice == "as") return "assamese";
        return ""; // all languages
    }
    
    void displayRecommendations(const vector<Song>& recommendations, const string& emotion) {
        if (recommendations.empty()) {
            cout << "\nSorry, no songs found matching your mood!" << endl;
            return;
        }
        cout << "\n🎵 RECOMMENDED PLAYLIST FOR '" << emotion << "' MOOD 🎵" << endl;
        cout << string(70, '-') << endl;
        for (size_t i = 0; i < recommendations.size(); i++) {
            const Song& song = recommendations[i];
            cout << (i + 1) << ". \"" << song.name << "\" by " << song.artist;
            cout << " [" << song.language << "] (" << song.category << ")" << endl;
        }
        cout << string(70, '-') << endl;
        cout << "Total Recommendations: " << recommendations.size() << endl;
    }
    
    void displayEmotionScores(const map<string, int>& scores) {
        cout << "\n📊 Emotion Analysis Results:" << endl;
        cout << string(30, '-') << endl;
        for (const auto& pair : scores) {
            if (pair.second > 0) {
                cout << "• " << pair.first << ": " << pair.second << " matches" << endl;
            }
        }
    }
    
    void viewMoodHistory() {
        ifstream file("mood_history.txt");
        if (!file.is_open()) {
            cout << "\nNo mood history found!" << endl;
            return;
        }
        cout << "\n=== MOOD HISTORY (Last 10 Entries) ===" << endl;
        cout << string(80, '-') << endl;
        vector<string> lines;
        string line;
        while (getline(file, line)) lines.push_back(line);
        int start = max(0, (int)lines.size() - 10);
        for (int i = start; i < (int)lines.size(); i++) {
            cout << lines[i] << endl;
        }
        if (lines.empty()) cout << "No mood history available." << endl;
        else {
            cout << string(80, '-') << endl;
            cout << "Showing last " << min(10, (int)lines.size()) << " mood entries." << endl;
        }
        file.close();
    }
    
public:
    void run() {
        displayHeader();
        int choice;
        do {
            displayMenu();
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << "\nEnter how you're feeling: ";
                    cin.ignore();
                    string userInput;
                    getline(cin, userInput);
                    if (userInput.empty()) {
                        cout << "Please enter some text!" << endl;
                        break;
                    }
                    map<string, int> emotionScores = analyzer.analyzeEmotion(userInput);
                    string dominantEmotion = analyzer.getDominantEmotion(emotionScores);
                    displayEmotionScores(emotionScores);
                    string languagePreference = getLanguagePreference();
                    int totalEmotions = 0;
                    for (const auto& pair : emotionScores) {
                        if (pair.second > 0) totalEmotions++;
                    }
                    vector<Song> recommendations;
                    if (totalEmotions > 1) {
                        cout << "\nMultiple emotions detected! Creating a mixed playlist..." << endl;
                        recommendations = library.getMixedPlaylist(emotionScores, languagePreference);
                        displayRecommendations(recommendations, "Mixed");
                    } else {
                        recommendations = library.getRecommendations(dominantEmotion, languagePreference);
                        displayRecommendations(recommendations, dominantEmotion);
                    }
                    library.logMoodHistory(userInput, dominantEmotion);
                    break;
                }
                case 2:
                    library.addSong();
                    break;
                case 3:
                    library.viewLibrary();
                    break;
                case 4:
                    viewMoodHistory();
                    break;
                case 5:
                    cout << "\nThank you for using the Emotion-Based Music Playlist Generator!" << endl;
                    break;
                default:
                    cout << "Invalid choice! Please enter 1-5." << endl;
            }
            if (choice != 5) {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }
        } while (choice != 5);
    }
};

int main() {
    PlaylistGenerator generator;
    generator.run();
    return 0;
}   
                
                