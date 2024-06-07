#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class tweet{

    private:

    string fileName;
    string filteredFileName;
    vector<string> words;
    vector<string> lines;
    vector<string> linesBackUp;
    vector<vector<int>> badIndexes;
    ifstream tweetFile;
    ofstream filteredTweetFile;


    public:

    tweet(string tweetName) : fileName(tweetName){}

    void setTweetName(string tweetName);
    string getTweetName();


};

class words{

    private:

    vector<string> words;
    int findWord(string wrd);
    vector<int> freq;

    public:

    void addWord(string wrd);
    void removeWord(string wrd);
    

};

int main(){




    return 0;

}

void words::addWord(string wrd){
    words.push_back(wrd);
}

void words::removeWord(string wrd){
    int index = findWord(wrd);
    if(index == -1){
        cerr << "error/no word(" << wrd << ")  found" << endl;
        return;
    }
    words.erase(words.begin() + index);
}

int words::findWord(string wrd){
    for(int i = 0; i < words.size(); i++){
        if(wrd == words[i]){
            return i;
        }
    }
    return -1;
}