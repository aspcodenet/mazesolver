#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <map>


class PathFinder {
     std::stack<std::string> resultingPath; // "0,0", "0,1"
     std::vector<std::vector<int>> maze;
     std::map<std::string,bool> visited;
  public:
    PathFinder(std::vector<std::vector<int>> maze)
      :maze(maze)
    {
      
    }

    std::vector<std::string> getPath(){
         std::vector<std::string> path;
        while(!resultingPath.empty()){
            path.insert(path.begin(),resultingPath.top());
            resultingPath.pop();
        }
        return  path;

    }
    

    bool DFS(int y, int x, int destRow,int destCol) {
        
        std::string thisitem = std::to_string(x) +"," + std::to_string(y);
        std::cout << "TRYING: " << thisitem << std::endl;
        resultingPath.push(thisitem);

        //Är vi framme? return true
        if(x == destCol && y == destRow){
          return true;
        }
        //Har vi redan varit här?  pop och return false
        if(visited[thisitem] == true){
          resultingPath.pop();
          return false;
        }

      visited[thisitem] = true;
      if(isValid(y,x-1)){ //LEFT
        if(DFS(y,x-1,destRow,destCol)) {
          return true;
        }
      }
      if(isValid(y+1,x)){ // DOWN
        if(DFS(y+1,x,destRow,destCol)){
          return true;
        }
      }
      if(isValid(y,x+1)){ //RIGHT
        if(DFS(y,x+1,destRow,destCol) == true){
          return true;
        }
      }
      if(isValid(y-1,x)){// UP
        if(DFS(y-1,x,destRow,destCol) == true){
          return true;
        }
      }
      resultingPath.pop();
      return false;
    }


    bool isValid(int y, int x){
      if(x < 0) return false;
      if(x >= maze[0].size() ) return false;
      if(y >= maze.size() ) return false;
      if(y < 0 ) return false;
      if(maze[y][x] == 1) return false;
      return true;
    }
};



int main(){
    std::vector<std::vector<int>> maze = {
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0},
    };
    PathFinder pathFinder(maze);
    bool found = pathFinder.DFS(0,0,0,2);
    if(found){
      //Print på resultingPath
      std::cout << "RESULT: " << std::endl;
      for(auto s: pathFinder.getPath()){
        std::cout << s << std::endl;
      }
    }


  return 0;
}


// void adminmenu(int r){
//   for(int i = 0; i < 100; i++){
//     adminmenu(r);
//   }
//   std::cout << "1. Play again" << std::endl;
//   std::cout << "3. Back" << std::endl;
//   int action;
//   std::cin >> action;
//   if(action == 1){
//     //
//   }
//   if(action == 3){
//     //
//     headmenu(r);
//   }
// }



// void headmenu(int r){
//   std::cout << "1. Admin" << std::endl;
//   std::cout << "2. Bla bla" << std::endl;
//   std::cout << "3. Back" << std::endl;
//   int action;
//   std::cin >> action;
//   if(action == 1){
//     //
//     adminmenu( r);
//   }
//   if(action == 2){
//     //
//   }
//   if(action == 3){
//     //
//   }
// }

// int summeraAllaTal(int start){
//   // return 5 + 4 + 3 + 2 + 1
//   int sum = 0;
//   for(int i = start ; i > 0; i--){
//     sum += i;
//   }
//   return sum;
// }

// int summeraAllaTalRec(int start){
//   if(start == 0){
//     return 0;
//   }
//   return start + summeraAllaTalRec(start-1);
// }





