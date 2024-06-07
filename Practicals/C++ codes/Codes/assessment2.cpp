//G21236321 - Kasun Kanaka Dodanwala

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Class declaration
class words{

    public:

    string word;
    int frequency = 0;
    bool alreadyTaken = false;

};

//Function prototypes
void lowerLine(string &line);
void storeWordsToVector(vector<string> &sentence, string line);
void storeBadIndexes(vector<int> &badIndexes, string line, words &bannedWord);
void checkWord(vector<int> &badIndexes,int startingIndex, string word, words &bannedWord);
void censoring(const vector<int> &badIndexes, string &line);
void filterLine(string &line, vector<words> &bannedWords);
void filterTweetAndWriteToFile( ifstream &tweet, vector<words> &bannedWords, string tweetName,
                                vector<vector<string>> &wordsOfTweets, vector<words> negativeWords, vector<words> positiveWords);
void readBannedWords(vector<words> &bannedWords);
void printBannedWordsFreq(vector<words> &bannedWords, string tweetName);
void readFromFileToVector(vector<words> &word, string fileName);
void printSentiment(vector<words> negativeWords, vector<words> positiveWords, vector<string> tweetWords);
void printTenMostFreqWords(vector<vector<string>> &allWords);
void calculateWords(vector<words> &arrayOfWords, vector<words> &mostFreqWords);
void sortWordsArray(vector<words> &mostFreqWords);

//Main function
int main(){

    vector<words> bannedWords;

    //File names of the text files which will be filtered
    string tweets[] = {"tweets1.txt", "tweets2.txt", "tweets3.txt", "tweets4.txt"};

    const int tweetsArraySize = sizeof(tweets) / sizeof(tweets[0]);

    vector<vector<string>> wordsOfTweets;

    vector<words> negativeWords;
    vector<words> positiveWords;

    //Opening and storing words to vectors
    readFromFileToVector(negativeWords, "negative.txt");
    readFromFileToVector(positiveWords, "positive.txt");


    ifstream file;

    //Reading banned words to a vector
    readBannedWords(bannedWords);

    //Filtering each text file and writing to a new text file
    for(int i = 0; i < tweetsArraySize; i++){

        file.open(tweets[i]);

        if(file.is_open()){

        filterTweetAndWriteToFile(file, bannedWords, tweets[i], wordsOfTweets, negativeWords, positiveWords);

        file.close();

        }
        else {
            cout << tweets[i] << " failed to open" << endl;
        }

    }

    //Printing most frequent words through out the 4 tweets
    printTenMostFreqWords(wordsOfTweets);

    return 0;
}

//Takes a string and turn it to lowercase letters
void lowerLine(string &line){
    for(int i = 0; i < line.length(); i++){
        line[i] = tolower(line[i]);
    }
}

//Takes a string which has a sentence, and store it to a vector word by word
void storeWordsToVector(vector<string> &sentence, string line){

    string word;
    lowerLine(line);

    for(int i = 0; i < line.size(); i++){
        word.push_back(line[i]);
        if(i == line.size() - 1 || line[i] < 97 || line[i] > 122){
            if(line[i] < 97 || line[i] > 122){
                word.pop_back();
            }
            if(!word.empty()){
                sentence.push_back(word);
            }
            word.clear();
        }
    }
}

//Storing indexes that must be censored
void storeBadIndexes(vector<int> &badIndexes, string line, words &bannedWord){

    string word;
    lowerLine(line);
    int startingIndex;

    for(int i = 0; i < line.size(); i++){
        word.push_back(line[i]);
        if(i == line.size() - 1 || line[i] < 97 || line[i] > 122){ 

            startingIndex = i - word.length();

            if(line[i] < 97 || line[i] > 122){
                word.pop_back();
            }
            if(!word.empty() && bannedWord.word.length() <= word.length()){
                checkWord(badIndexes, startingIndex, word, bannedWord);
            }
            word.clear();
        }
    }
}

//Comparing two words
void checkWord(vector<int> &badIndexes,int startingIndex, string word, words &bannedWord){

    int counter;

    for(int i = 0; i < word.length(); i++){

        counter = 0;

        for(int j = 0; j < bannedWord.word.length(); j++){

            if(bannedWord.word[j] == word[i + j]){
                counter++;
                if(counter == bannedWord.word.length()){
                    bannedWord.frequency++;
                    badIndexes.push_back(startingIndex + i + bannedWord.word.length() / 2 + 1);
                    break;
                }
            }
            else{
                break;
            }
        }

        if(i == word.length() - bannedWord.word.length()){
            break;
        }

    }

}

//Censors string with given indexes
void censoring(const vector<int> &badIndexes, string &line){
    for(int i = 0; i < badIndexes.size(); i++){
        line[badIndexes[i]] = '*';
    }
}

//Filters a given line(string) by censoring given banned words
void filterLine(string &line, vector<words> &bannedWords){

    vector<int> badIndexes;

    for(int i = 0; i < bannedWords.size(); i++){
        storeBadIndexes(badIndexes, line, bannedWords[i]);
    }

    censoring(badIndexes, line);

}

//Filters a given text file by censoring given banned words and writes to a new text file
void filterTweetAndWriteToFile( ifstream &tweet, vector<words> &bannedWords, string tweetName,
                                vector<vector<string>> &wordsOfTweets, vector<words> negativeWords, vector<words> positiveWords){

    string line;
    string filteredTweetName = tweetName;
    ofstream file;
    vector<string> wordsOfTheTweet;

    for(int i = 0; i < filteredTweetName.length(); i++){

        if(filteredTweetName[i] == '.'){

            filteredTweetName = filteredTweetName.substr(0, i);
            filteredTweetName.append("Filtered.txt");

            break;
        }
    }

    file.open(filteredTweetName);

    if(file.is_open()){

        while(getline(tweet, line)){
            storeWordsToVector(wordsOfTheTweet, line);
            filterLine(line, bannedWords);
            file << line << endl;
        }

        wordsOfTweets.push_back(wordsOfTheTweet);

        printBannedWordsFreq(bannedWords, tweetName);

            printSentiment(negativeWords, positiveWords, wordsOfTheTweet);

        cout << "\n\n-----------------------------------------------\n\n";

        for(int i = 0; i <  bannedWords.size(); i++){
            bannedWords[i].frequency = 0;
        }

    }
    else{
        cout << "File writing failed!" << endl;
    }

    file.close();

}

//Reads banned words to a vector
void readBannedWords(vector<words> &bannedWords){

    words bannedWord;
    ifstream file;
    file.open("banned.txt");

    while(getline(file, bannedWord.word)){
        bannedWords.push_back(bannedWord);
    }
    file.close();

}

//Prints number of times each banned word has appeared in a text file
void printBannedWordsFreq(vector<words> &bannedWords, string tweetName){

    cout << "In file, '" + tweetName + "',\n\n";
    for(int i = 0; i < bannedWords.size(); i++){
        cout << "'" + bannedWords[i].word + "' found " << bannedWords[i].frequency << " times" << endl;
    }
}

//Reads words from file to vector
void readFromFileToVector(vector<words> &word, string fileName){
    words wordClz;
    ifstream file;
    file.open(fileName);

    if(file.is_open()){
        while(getline(file, wordClz.word)){
            lowerLine(wordClz.word);
            for(int i = 0; i < wordClz.word.length(); i++){
                if(wordClz.word[i] > 122 || wordClz.word[i] < 97){
                    wordClz.word = wordClz.word.substr(0, i);
                    break;
                }
            }
            word.push_back(wordClz);
        }
        file.close();
    }
    else {
        cout << fileName + " opening failed!" << endl;
    }
}

//Prints if a tweet is negative or positive or netrual by examining them
void printSentiment(vector<words> negativeWords, vector<words> positiveWords, vector<string> tweetWords){

    int numOfPosWords = 0;
    int numOfNegWords = 0;

    for(int i = 0; i < tweetWords.size(); i++){
        lowerLine(tweetWords[i]);
    }

    for(int i = 0; i < tweetWords.size(); i++){

       string word = tweetWords[i];
       
       for(int j = 0; j < negativeWords.size(); j++){
            string negativeWrd = negativeWords[j].word;
            for(int k = 0; k < word.size(); k++){
                int count = 0;
                for(int l = 0; l < negativeWrd.length(); l++){
                    if(word[k + l] == negativeWrd[l]){
                        count++;
                        if(count == negativeWrd.size()){
                            negativeWords[j].frequency++;
                            break;
                        }
                    }
                }
            }
       }

       for(int j = 0; j < positiveWords.size(); j++){
            string positiveWrd = positiveWords[j].word;
            for(int k = 0; k < word.size(); k++){
                int count = 0;
                for(int l = 0; l < positiveWrd.length(); l++){
                    if(word[k + l] == positiveWrd[l]){
                        count++;
                        if(count == positiveWrd.size()){
                            positiveWords[j].frequency++;
                            break;
                        }
                    }
                }
            }
       }

    }

    for(int i = 0; i < positiveWords.size(); i++){
        numOfPosWords += positiveWords[i].frequency;
    }
    for(int i = 0; i < negativeWords.size(); i++){
        numOfNegWords += negativeWords[i].frequency;
    }

    cout << endl;

    if(numOfPosWords > numOfNegWords){
        cout << "Overall the tweet seems to be quite positive" << endl;
    }
    else if (numOfNegWords > numOfPosWords) {
        cout << "Overall the tweet seems to be quite negative" << endl;
    }
    else {
        cout << "Overall the tweet seems to be neutral" << endl;
    }

}

//Prints the 10 most frequent words that have appeared through out all the read text files
void printTenMostFreqWords(vector<vector<string>> &allWords){

    vector<words> arrayOfWords;
    words word;
    vector<words> mostFreqWords;

    for(int i = 0; i < allWords.size(); i++){
        for(int j = 0; j < allWords[i].size(); j++){
            word.word = allWords[i][j];
            arrayOfWords.push_back(word);
        }
    }

    calculateWords(arrayOfWords, mostFreqWords);
    sortWordsArray(mostFreqWords);

    cout << "The 10 most frequent words:" << endl << endl;

    int j = 1;

    for(int i = mostFreqWords.size() - 1; mostFreqWords.size() - 11 < i; i--){
        cout << j << ". " << mostFreqWords[i].word << " - " << mostFreqWords[i].frequency << " times" << endl;
        j++;
    }

}

//Calculate frequencies of each word that have appeared through out all the read text files
//The calculation seems to wrong
void calculateWords(vector<words> &arrayOfWords, vector<words> &mostFreqWords){

    for(int i = 0; i < arrayOfWords.size(); i++){

        if(arrayOfWords[i].alreadyTaken){
            continue;
        }
        else{
            
            words word;
            word.word = arrayOfWords[i].word;

            for(int j = i; j < arrayOfWords.size(); j++){

                if(!arrayOfWords[j].alreadyTaken && arrayOfWords[j].word == word.word){
                    word.frequency++;
                    arrayOfWords[j].alreadyTaken = true;
                }

            }
            
            mostFreqWords.push_back(word);
        }

    }

}

//Bubble sort
//For most frequent words
void sortWordsArray(vector<words> &mostFreqWords){
    
    for(int i = 0; i < mostFreqWords.size() - 1; i++){

        for(int j = 0; j < mostFreqWords.size() - 1; j++){

            if(mostFreqWords[j].frequency > mostFreqWords[j + 1].frequency){
                words temp;
                temp = mostFreqWords[i];
                mostFreqWords[j] = mostFreqWords[j + 1];
                mostFreqWords[j + 1] = temp;
            }
        }
    }
}