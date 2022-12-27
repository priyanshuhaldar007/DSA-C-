# include<bits/stdc++.h>
using namespace std;

bool isSafe(int n,int maze[4][4],vector<vector<int>> visited, int newX, int newY){
    if((newX>=0 && newX<=n-1) && (newY>=0 && newY<=n-1) && (maze[newX][newY] == 1) && (visited[newX][newY] == 0)){
        return true;
    }
    return false;
}

void SolveMaze(int n,int maze[4][4],vector<vector<int>> visited, int srcX, int srcY,vector<string> path){
    if(maze[0][0]==0 || (srcX==n-1 && srcY==n-1)){
        for(int j=0;j<path.size();j++){
            cout<<path[j]<<" ";
        }
        cout<<endl;
        return;
    }

    visited[srcX][srcY] = 1;

    // 4 options:- DLRU

    // down
    int newX = srcX+1;
    int newY = srcY;
    // cout<<"chekD"<<endl;
    if(isSafe(n, maze, visited, newX, newY)){
        // cout<<"D("<<newX<<","<<newY<<")";
        path.push_back("D");
        SolveMaze(n,maze,visited,newX,newY,path);
        path.pop_back();
    }

    // left
    newX = srcX;
    newY = srcY-1;
    // cout<<"chekL"<<endl;
    if(isSafe(n, maze, visited, newX, newY)){
        // cout<<"L("<<newX<<","<<newY<<")";
        path.push_back("L");
        SolveMaze(n,maze,visited,newX,newY,path);
        path.pop_back();
    }

    // Right
    newX = srcX;
    newY = srcY+1;
    // cout<<"chekR"<<endl;
    if(isSafe(n, maze, visited, newX, newY)){
        // cout<<"R("<<newX<<","<<newY<<")";
        path.push_back("R");
        SolveMaze(n,maze,visited,newX,newY,path);
        path.pop_back();
    }

    // up
    newX = srcX-1;
    newY = srcY;
    // cout<<"chekU"<<endl;
    if(isSafe(n, maze, visited, newX, newY)){
        // cout<<"U("<<newX<<","<<newY<<")";
        path.push_back("U");
        SolveMaze(n,maze,visited,newX,newY,path);
        path.pop_back();
    }

    // cout<<"hello"<<endl;

    visited[srcX][srcY] = 0;
}

int main(){
    int maze[4][4]={
        {1,0,0,1},
        {1,1,1,1},
        {0,1,0,0},
        {0,1,1,1}
    };
    vector<vector<int>> visited(4,vector<int> (4,0));
    vector<string> path;

    SolveMaze(4,maze,visited,0,0, path);
    
    return 0;
}