#include <iostream>

using namespace std;

class youTubeChannel{

    private:

    string name;
    int subsCount;

    protected:

    string ownersName;
    int quality;

    public:

    void printInfo();
    void subscribe();
    void unsubscribe();
    void analysis();

    youTubeChannel(string Name, string Owner) : name(Name), ownersName(Owner), subsCount(0), quality(0){}

};

class cookingYouTubeChannel : public youTubeChannel {

    public:

    void practice();

	cookingYouTubeChannel(string name, string ownerName):youTubeChannel(name, ownerName) {}
	
};

class singersYouTubeChannel : public youTubeChannel {

    public:

    void practice();

	singersYouTubeChannel(string name, string ownerName):youTubeChannel(name, ownerName) {}
	
};

int main(){

    cookingYouTubeChannel* cookingYtChannel = new cookingYouTubeChannel("Amy's Kitchen", "Amy");
    singersYouTubeChannel* singersYtChannel = new singersYouTubeChannel("John Sings", "John");

    cookingYtChannel->practice();

    for(int i = 0; i < 5; i++){
        singersYtChannel->practice();
    }

    youTubeChannel* yt1p = cookingYtChannel;

    yt1p->analysis();
    singersYtChannel->analysis();

    return 0;

}

void youTubeChannel::printInfo(){
    cout << "Name: " << name << endl;
    cout << "Owner Name: " << ownersName << endl;
    cout << "Subs: " << subsCount << endl;
}

void youTubeChannel::subscribe(){
    subsCount++;
}

void youTubeChannel::unsubscribe(){
    if (subsCount > 0){
        subsCount--;
    }
}

void youTubeChannel::analysis(){
    if(quality < 5){
        cout << name + " has bad quality content." << endl; 
    }
    else{
        cout << name + " has good content." << endl; 
    }
}

void cookingYouTubeChannel::practice() {
		cout << ownersName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        quality++;
}

void singersYouTubeChannel::practice() {
		cout << ownersName << " is taking singing classes, learning new songs, learning how to dance..." << endl;
        quality++;
}
