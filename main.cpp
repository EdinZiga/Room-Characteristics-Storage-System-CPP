#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>

/*
Simple Room data storage system
By Edin Ziga
Final Project for CS305 Programming Languages
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀ ⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀
⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀ ⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/


using namespace std;
class Room{
private:
    //Variables -----------------------------------------------
    string RoomType;
    double m2=0; //Room Size
    int WinOrient[4]={0,0,0,0}; //Vector size is the number of windows, container info is the windows orientation
    vector<string> nFurniture; // -//--//-, container info is type of furniture
    int nWalls=0; //Number of walls
public:
    //No Argument Constructor
    Room(){
    system("CLS");
    string temp;
    int itemp=0;
    double dtemp=0;
    cout <<"Enter your room name"<<endl;
    getline(cin, temp);
    setRoomType(temp);
    system("CLS");
    cout<<"Enter your room size"<<endl;
    cin >>dtemp;
    setRoomSize(dtemp);
    system("CLS");
    while (1){
        cout <<"Enter the number of windows"<<endl;
    cin >>itemp;
    if(itemp<0) cout<<"Bad input"<<endl; else break;
    }
    resetWindows(itemp);
    system("CLS");
    cout <<"Enter the number of furniture in said room"<<endl;
    cin >>itemp;
    resetFurniture(itemp);
    system("CLS");
    cout <<"Enter the number of walls"<<endl;
    cin >>itemp;
    resetWalls(itemp);
    system("CLS");
    }
    //Constructor -----------------------------------------------
    Room(string inpType, double inpM2, int inpNWindow, int inpNFurniture, int inpNWalls){
    setRoomType(inpType);
    setRoomSize(inpM2);
    resetWindows(inpNWindow);
    resetFurniture(inpNFurniture);
    resetWalls(inpNWalls);
    }
    //Copy Constructor -----------------------------------------------
    Room(const Room &obj){
    RoomType=obj.RoomType;
    m2=obj.m2;
    for(int i=0; i<4; i++) WinOrient[i]=obj.WinOrient[i];
    for(int i=0; i<obj.nFurniture.size(); i++) nFurniture.push_back(obj.nFurniture[i]);
    nWalls=obj.nWalls;
    }

    //RoomTypeCommands -----------------------------------------------
    void setRoomType(string input){
    RoomType=input;
    }
    string getRoomType(){
    return RoomType;
    }
    void clearRoomType(){
    cout <<"Now "<<RoomType<<" is just a room"<<endl;
    RoomType="Just a room";
    }

    //Room Size Functions -----------------------------------------------
    void setRoomSize(double input){
    while(input<=0){
        cout <<"Impossible room size, try again - ";
        cin>>input;
    }
    m2=input;
    }
    double getRoomSize(){
    return m2;
    }
    void clearRoomSize(){
    m2=0;
    int temp=0;
    cout <<"Enter a new room size - ";
    cin>>temp;
    setRoomSize(temp);
    }

    //Windows Functions -----------------------------------------------
    void resetWindows(int inpNWindow){
         bool sw=false;
         int itemp;
    while(sw==false && inpNWindow>0) {
        int WinSum=0;
        cout <<"We see that "<<RoomType<<" has "<<inpNWindow<<" windows"<<endl;
        cout <<"How many windows facing North?"<<endl;
        cin>>itemp;
        WinOrient[0]=itemp;
        cout <<"How many windows facing West?"<<endl;
        cin>>itemp;
        WinOrient[1]=itemp;
        cout <<"How many windows facing East?"<<endl;
        cin>>itemp;
        WinOrient[2]=itemp;
        cout <<"How many windows facing South?"<<endl;
        cin>>itemp;
        WinOrient[3]=itemp;
        sw=true;
        for(int i=0; i<=4;i++){
            if(WinOrient[i]<0){
                cout<<"Bad input, restarting windows."<<endl;
                sw=false;
                break;
            }
            WinSum+=WinOrient[i];
        }
         if(WinSum!=inpNWindow && sw==true){
                cout <<"More/Less windows than stated, restarting windows."<<endl;
                sw=false;
            }
    }
    }
    void addWindwos(int a, int n){
    if (a==0)
        if(n<1) cout<<"Input cannot be zero or negative number"<<endl;
            else WinOrient[0]+=n;
    if (a==1)
        if(n<1) cout<<"Input cannot be zero or negative number"<<endl;
            else WinOrient[1]+=n;
    if (a==2)
        if(n<1) cout<<"Input cannot be zero or negative number"<<endl;
            else WinOrient[2]+=n;
    if (a==3)
        if(n<1) cout<<"Input cannot be zero or negative number"<<endl;
            else WinOrient[3]+=n;
    }
    void removeWindows(int a, int n){
        if(a==0)
            if(WinOrient[0]-n<0) cout<<"Too many windows to remove"<<endl;
                else WinOrient[0]-=n;
        if(a==1)
            if(WinOrient[1]-n<1) cout<<"Too many windows to remove"<<endl;
                else WinOrient[1]-=n;
        if(a==2)
            if(WinOrient[2]-n<2) cout<<"Too many windows to remove"<<endl;
                else WinOrient[2]-=n;
        if(a==3)
            if(WinOrient[3]-n<3) cout<<"Too many windows to remove"<<endl;
                else WinOrient[3]-=n;
    }
    int getTotalWindows(){
       int sum=0;
       for (int i=0; i<4; i++) sum+=WinOrient[i];
       return sum;
    }

    //Furniture Functions -----------------------------------------------
    void resetFurniture(int inpNFurniture){
    string temp;
    nFurniture.clear();
     for(int i=1; i<=inpNFurniture; i++){
        if (i==1) cout <<"We see that "<<RoomType<<" has "<<inpNFurniture<<" pieces of furniture"<<endl;
        cout <<"Tell us what furniture no. "<<i<<" is ";
        cin >>temp;
        nFurniture.push_back(temp);
    }
    }
    void addFurniture(string inp){
    nFurniture.push_back(inp);
    }
    void removeFurniture(string inp){
        bool sw=false;
   while(sw==false){
     for(int i=0; i<nFurniture.size(); i++){
        if(inp==nFurniture[i]) {
                nFurniture.erase(nFurniture.begin()+i);
                sw=true;
    }
    }
    if(sw==false) {
        cout<<"Could not find item, try again"<<endl;
        cout<<"Available furniture"<<endl;
        for(int i=0;i<nFurniture.size(); i++)
            cout <<nFurniture[i]<<", ";
        cout<<endl;
        getline(cin,inp);
    }

   }

    }
    int getNFurniture() {
    return nFurniture.size();
    }

    //Wall Functions -----------------------------------------------
    void resetWalls(int inpNWalls){
    while(inpNWalls<3){
        cout <<"Impossible wall number, try again - ";
        cin>>inpNWalls;
    }
    nWalls=inpNWalls;
    }
    void addWalls(int inp){
    if(inp<1) cout <<"Input cannot be zero or less than zero"<<endl;
    else nWalls+=inp;
    }
    void removeWalls(int inp){
    if(nWalls-inp<3) cout<<"You can't have less than three walls"<<endl;
    else nWalls-=inp;
    }
    int getWalls(){
    return nWalls;
    }
    //Printer -----------------------------------------------
    void printRoomStats(){
    cout<<"Room Type - "<<RoomType<<endl;
    cout<<"Room Size - "<<m2<<"m2"<<endl;
    if(getTotalWindows()>0){
    cout<<"Windows:"<<endl;
    cout<<"Facing North - "<< WinOrient[0]<<endl;
    cout<<"Facing West - "<< WinOrient[1]<<endl;
    cout<<"Facing East - "<< WinOrient[2]<<endl;
    cout<<"Facing South - "<< WinOrient[3]<<endl;
    }
    if(getNFurniture()>0){
        cout<<"Furniture:"<<endl;
    for(int i=0; i<nFurniture.size(); i++){
        cout <<nFurniture[i]<<", ";
    }
    cout<<endl;
    }
    cout<<"Number of walls - "<<nWalls<<endl;
    }
};
class AparmentADT{
private:
    vector<Room> RoomList;
public:

    void addRoom(){
        Room obj;
        RoomList.push_back(obj);
    }
    void listRooms(){
        for(int i=0; i<RoomList.size(); i++){
                cout<<"Room number - "<<i<<endl;
                RoomList[i].printRoomStats();
                  cout<<endl;
                }
    }
    void removeRoom(){
        int temp;
        cout<<"Which Room would you like to remove?"<<endl;
        listRooms();
        cin>>temp;
        RoomList.erase(RoomList.begin()+temp);
    }
    void roomEditor(){
    int edit=0;
    string stemp;
    system("CLS");
    listRooms();
        cout<<"Which room would you like to edit?"<<endl;
        while(1){
            cin>>edit;
            if(edit>RoomList.size()-1 || edit < 0)
                cout <<"Bad input"<<endl; else break;
        }

        cin.ignore();
    while(1){
    int temp=0;
    int temp2=0;
    system("CLS");
    listRooms();
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Change the name of the room?"<<endl;
    cout<<"2. Clear the name of the room?"<<endl;
    cout<<"3. Change the size of the room?"<<endl;
    cout<<"4. Add a window?"<<endl;
    cout<<"5. Remove a window?"<<endl;
    cout<<"6. Completely reset the windows?"<<endl;
    cout<<"7. Add some furniture?"<<endl;
    cout<<"8. Remove some furniture?"<<endl;
    cout<<"9. Completely reset the furniture?"<<endl;
    cout<<"10. Add a wall?"<<endl;
    cout<<"11. Remove a wall?"<<endl;
    cout<<"12. Reset the wall count?"<<endl;
    cout<<"13. Exit"<<endl;
    cin>>temp;
    cin.ignore();
    switch (temp){
    case 1:
        system("CLS");
        cout <<"What do you want your new room name to be?"<<endl;
        getline(cin,stemp);
        RoomList[edit].setRoomType(stemp);
        cout <<""<<endl;
        break;
    case 2:
        system("CLS");
        RoomList[edit].clearRoomType();
        break;
    case 3:
        system("CLS");
        cout <<"What do you want your new room size to be?"<<endl;
        cin >>temp;
        cin.ignore();
        RoomList[edit].setRoomSize(temp);
        break;
    case 4:
        system("CLS");
        cout <<"On which side do you want your windows?"<<endl;
        cout <<"(0-North,1-West,2-East,3-South)"<<endl;
        cin>>temp;
        cin.ignore();
        cout <<"How many windows?"<<endl;
        cin>>temp2;
        cin.ignore();
        RoomList[edit].addWindwos(temp,temp2);
        break;
    case 5:
        system("CLS");
        cout <<"On which side do you want to remove windows?"<<endl;
        cout <<"(0-North,1-West,2-East,3-South)"<<endl;
        cin>>temp;
        cin.ignore();
        cout <<"How many windows?"<<endl;
        cin>>temp2;
        cin.ignore();
        RoomList[edit].removeWindows(temp,temp2);
        break;
    case 6:
        system("CLS");
        cout <<"How many total windows do you want?"<<endl;
        cin>>temp;
        cin.ignore();
        RoomList[edit].resetWindows(temp);
        break;
    case 7:
        system("CLS");
        cout <<"What do you want to add?"<<endl;
        getline(cin,stemp);
        RoomList[edit].addFurniture(stemp);
        break;
    case 8:
        system("CLS");
        cout <<"What do you want to remove?"<<endl;
        getline(cin,stemp);
        RoomList[edit].removeFurniture(stemp);
        break;
    case 9:
        system("CLS");
        cout <<"How much total furniture do you want?"<<endl;
        cin>>temp;
        cin.ignore();
        RoomList[edit].resetFurniture(temp);
        break;
    case 10:
        system("CLS");
        cout <<"How many walls do you want to add?"<<endl;
        cin >>temp;
        cin.ignore();
        RoomList[edit].addWalls(temp);
        break;
    case 11:
        system("CLS");
        cout <<"How many walls do you want to remove?"<<endl;
        cin >>temp;
        cin.ignore();
        RoomList[edit].removeWalls(temp);
        break;
    case 12:
        system("CLS");
        cout <<"How many walls do you want in total?"<<endl;
        cin >>temp;
        cin.ignore();
        RoomList[edit].resetWalls(temp);
        break;
    default:
        if (temp!=13)cout<<"Unknown input"<<endl;
    }
    if(temp==13) break;
    }
    }
    void mainScreen(){
        while(1){
            int temp=0;

    listRooms();
    cout<<"What would you like to do?"<<endl;
    cout<<"1. Add a room?"<<endl;
    cout<<"2. Remove a room?"<<endl;
    cout<<"3. Edit a room"<<endl;
    cout<<"4. Exit"<<endl;
    cin>>temp;
    cin.ignore();
    switch (temp){
    case 1:
        addRoom();
        break;
    case 2:
        system("CLS");
        removeRoom();
        break;
    case 3:
        system("CLS");
        if(RoomList.size()>0)
        roomEditor(); else cout <<"No rooms to edit"<<endl;
        break;
    default:
        if(temp!=4)
        cout<<"Unknown input"<<endl;
    }
    if(temp==4) break;
    }
        }



};
int main()
{
    AparmentADT obj1;
    obj1.mainScreen();
    return 0;
}
