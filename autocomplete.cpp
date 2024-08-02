#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    void insert(TrieNode* node, const std::string& word, int index) {
        if (index == word.size()) {
            node->isEndOfWord = true;
            return;
        }
        char c = std::tolower(word[index]);
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new TrieNode();
        }
        insert(node->children[c], word, index + 1);
    }

    void search(TrieNode* node, std::vector<std::string>& results, std::string current) {
        if (node->isEndOfWord) {
            results.push_back(current);
        }
        for (auto& pair : node->children) {
            search(pair.second, results, current + pair.first);
        }
    }

    TrieNode* searchPrefix(TrieNode* node, const std::string& prefix) {
        for (char c : prefix) {
            c = std::tolower(c);
            if (node->children.find(c) == node->children.end()) {
                return nullptr;
            }
            node = node->children[c];
        }
        return node;
    }

public:
    Trie() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        insert(root, word, 0);
    }

    std::vector<std::string> getSuggestions(const std::string& prefix) {
        std::vector<std::string> results;
        TrieNode* node = searchPrefix(root, prefix);
        if (node != nullptr) {
            search(node, results, prefix);
        }
        return results;
    }
};

int main(int argc, char* argv[]) {
    Trie trie;
    std::vector<std::string> words = {
        "apple", "banana","bandra", "grape","grid","grade", "orange", "oran", "pineapple","pines","straw", "stir","strawberry", "watermelon", "Apple", "Banana", "Cherry","code","coder","coding","index","indexer","indexing","date","data","database","databasing","file","folder","directory","directory","directorying","foldering","file","fileing","gaming","game","gamer","hacker","hack","hacking","hackering","internet","inter","intering","network","net","networking","networker","online","offline","onlineing","offlineing","programming","program","programmer","programminging","software","soft","softwareing","system","sys","systeming","technology","tech","technologying","web","website","webing","webpage","webpager","webpageing","webdesign","webdesigner","webdesigning","webdevelopment","webdeveloper","webdeveloping","webhosting","webhoster","webhostinging","webmaster","webmastering","webmasterer","webmastering","webmasteringing","webmasteringer","test","today","tomorrow","google","play","palystore","sunday","monday","tuesday","wednesday","thursday","friday","saturday","january","february","march","april","may","june","july","august","september","october","november","december","spring","summer","fall","winter","autumn","rain","rainy","rainfall","rainfalling","rainfallinger","rainfallinging","rainfallinger",
        "Date", "Elderberry", "Fig", "Grape", "Honeydew", "Kiwi", "Lemon", "Mango", "Nectarine", "Orange", "Papaya",
        "Quince", "Raspberry", "Strawberry", "Tangerine", "Ugli", "Vanilla", "Watermelon", "Xigua", "Yam", "Zucchini",
        "Animal", "Bird", "Cat", "Dog", "Elephant", "Fish", "Giraffe", "Horse", "Insect", "Jaguar", "Kangaroo", "Lion",
        "Monkey","monday", "Newt", "Owl", "pen","Penguin", "Quail", "rabies","Rabbit","snap", "Snake", "Tiger", "Umbrella", "Vase", "Watch","watching", "Xylophone", "Yak", "Zebra","bookworm","rainbow","grading","educated","education","tap","neck","water","kitten","ball","alpha","found",
        "Xylophone", "Yacht", "Zebra", "Alphabet", "Book", "Computer", "Desk", "Eraser", "Folder", "Glue", "Highlighter",
        "Ink", "Journal", "Keyboard", "Laptop", "Marker", "Notebook", "Organizer", "Paper", "Quiz", "Ruler", "Stapler",
        "Tape", "USB", "Video", "Whiteboard", "Xerox", "Yarn", "Zigzag", "Adjective", "Balloon", "Camera", "Dance",
        "Envelope", "Fountain", "Garden", "Helicopter", "Island", "Jungle", "Kite", "Lighthouse", "Mountain", "Necklace",
        "Ocean", "Palace", "Quilt", "Rainbow", "Sunset","sun", "Treasure", "Universe", "Volcano", "Waterfall", "Xenon"
    };

    for (const auto& word : words) {
        trie.insert(word);
    }

    std::string query = (argc >= 1) ? argv[1] : "default"; 
    auto results = trie.getSuggestions(query);

    if (results.empty()) {
        std::cout << "No suggestions found.\n";
    } else {
        for (const auto& result : results) {
            std::cout << result << "\n";
        }
    }

    return 0;
}
