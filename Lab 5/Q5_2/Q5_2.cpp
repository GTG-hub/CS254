//Garima Upadhyay
//220001029
// Given a snake and ladder board, assume, a player has total control over the outcome of the dice
// throw and wants to determine the minimum number of throws required to reach the last cell
// from the first cell. The solution is not necessarily unique.
// [Rule: If the player reaches a cell which is the base of a ladder, the player has to climb up that
// ladder and if reaches a cell is the mouth of the snake, and has to go down to the tail of the snake
// without a dice throw.]
#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(N)  Space Complexity : O(N)
int min_number_of_throws(vector<int> game,int n){
    vector<bool> visited(n,false);
    queue<pair<int,int> > q;
    visited[0] = true;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> p = q.front();
        int vertex = p.first;
        int turn = p.second;
        if(vertex==n-1) break;
        q.pop();
        for(int i=vertex+1;i<=vertex+6;i++){
            if(visited[i]==false){
                visited[i] = true;
                int pos = (game[i]==-1?i:game[i]);
                q.push({pos,turn+1});
            }
        }
    }
    return q.front().second;
}

int main(){
    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<int> game(n,-1);
    int ladders ;
    cin >> ladders ;
    for(int i=0;i<ladders;i++){
        int ladderInitial,ladderFinal;
        cin >> ladderInitial >> ladderFinal;
        game[ladderInitial] = ladderFinal;
    }
    int snakes;
    cin >> snakes;
    for(int i=0;i<snakes;i++){
        int snakeInitial,snakeFinal;
        cin >> snakeInitial >> snakeFinal;
        game[snakeInitial] = snakeFinal;
    }
    cout << min_number_of_throws(game,n) << endl;
}