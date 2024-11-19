// search_algorithm.cpp
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

struct Document {
    int id;
    std::string text;
    float rank;
};

class SearchEngine {
    std::unordered_map<std::string, std::vector<int>> invertedIndex;
    std::vector<Document> documents;

public:
    void addDocument(int id, const std::string& text) {
        documents.push_back({id, text, 0.0f});
        std::istringstream stream(text);
        std::string word;
        while (stream >> word) {
            invertedIndex[word].push_back(id);
        }
    }

    std::vector<Document> search(const std::string& query) {
        std::istringstream stream(query);
        std::string word;
        std::unordered_map<int, float> scores;

        while (stream >> word) {
            if (invertedIndex.find(word) != invertedIndex.end()) {
                for (int id : invertedIndex[word]) {
                    scores[id] += 1.0f; // Simple term frequency
                }
            }
        }

        std::vector<Document> results;
        for (auto& score : scores) {
            auto& doc = documents[score.first];
            doc.rank = score.second;
            results.push_back(doc);
        }

        std::sort(results.begin(), results.end(), [](const Document& a, const Document& b) {
            return a.rank > b.rank;
        });

        return results;
    }
};

int main() {
    SearchEngine engine;
    engine.addDocument(0, "Python crawler for NLP tasks");
    engine.addDocument(1, "Go backend for search engine indexing");
    engine.addDocument(2, "C++ high-performance algorithms");

    auto results = engine.search("NLP");

    for (const auto& doc : results) {
        std::cout << "Document ID: " << doc.id << ", Rank: " << doc.rank << "\n";
    }

    return 0;
}
