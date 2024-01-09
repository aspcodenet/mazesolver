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





// int main(){
//   int summa  = summeraAllaTal(5);
//   return 1;
// }


// class Solution {
//     std::stack<std::string> result;
//  public:
//     std::vector<std::string> GetResult(){
//          std::vector<std::string> path;
//         while(!result.empty()){
//             path.insert(path.begin(),result.top());
//             result.pop();
//         }
//         return  path;
//     }

//   bool hasPath(std::vector<std::vector<int>>& maze, int startRow, int startCol,
//                int destRow, int destCol) {
//     return dfs(maze,
//                std::vector<std::vector<bool>>(maze.size(), std::vector<bool>(maze[0].size())),
//                startRow, startCol, destRow,destCol);
//   }

//  private:
//   const std::vector<int> dirs{0, 1, 0, -1, 0};

//   bool dfs(std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>&& seen, int i, int j,
//             int destRow,int  destCol) {
//     result.push(std::to_string(i) + "," + std::to_string(j));
//     if (i == destRow && j == destCol){
//       return true;
//     }
//     if (seen[i][j])
//     {
//       result.pop();
//       return false;
//     }

//     seen[i][j] = true;

//     for (int k = 0; k < 4; ++k) {
//       int x = i;
//       int y = j;
//       if (isValid(maze, x -1, y ) && dfs(maze, std::move(seen), x-1, y, destRow,destCol)) {
//         return true;
//       }
//       if (isValid(maze, x +1, y ) && dfs(maze, std::move(seen), x+1, y, destRow,destCol)) {
//         return true;
//       }
//       if (isValid(maze, x, y+1 ) && dfs(maze, std::move(seen), x, y+1, destRow,destCol)) {
//         return true;
//       }
//      if (isValid(maze, x, y-1 ) && dfs(maze, std::move(seen), x, y-1, destRow,destCol)) {
//         return true;
//      }

//     }

//       result.pop();
//      return false;
//   }

//   bool isValid(const std::vector<std::vector<int>>& maze, int x, int y) {
//     return 0 <= x && x < maze.size() && 0 <= y && y < maze[0].size() &&
//            maze[x][y] == 0;
//   }
// };


// int main(){
//     std::vector<std::vector<int>> maze = {
//         {0, 1, 0, 0, 0, 1},
//         {0, 1, 1, 1, 0, 0},
//         {0, 0, 0, 1, 0, 0},
//         {1, 1, 0, 0, 0, 0},
//         {1, 1, 1, 1, 1, 0},
//     };
//     // std::vector<std::vector<char>> maze = {
//     //     {'S', 'E', 'O', 'O', 'O', 'X'},
//     //     {'O', 'X', 'O', 'O', 'O', 'O'},
//     //     {'O', 'X', 'X', 'X', 'O', 'O'},
//     //     {'O', 'X', 'O', 'O', 'O', 'O'},
//     //     {'O', 'O', 'O', 'O', 'O', 'O'},
//     //     {'O', 'X', 'O', 'X', 'O', 'O'},
//     //     {'O', 'O', 'O', 'O', 'X', 'O'},
//     //     {'O', 'O', 'O', 'O', 'O', 'O'}     
//     // };
//     Solution sol;
//     sol.hasPath(maze,0,0,0,2);
//     for(auto s : sol.GetResult()){
//         std::cout <<s << std::endl;
//     }
//     // Graph graph(maze);
//     // graph.DFS(0,0);

//     return 0;
// }

// // using namespace std;

// // // Defining hash Function for pair<T1, T2>
// // struct hash_pair {
// //     template <class T1, class T2>
// //     size_t operator()(const pair<T1, T2>& p) const
// //     {
// //         auto hash1 = hash<T1>{}(p.first);
// //         auto hash2 = hash<T2>{}(p.second);
// //         return hash1 ^ hash2;
// //     }
// // };
// // class MazePathFinding{
// //     public:
// //         vector<vector<char>> maze;
// //         unordered_map<pair<int, int>, bool, hash_pair> visited;

// //         // Defining some constants
// //         const string DOWN = "down";
// //         const string RIGHT = "right";
// //         const string UP = "up";
// //         const string LEFT = "left";
// //         const char START = 'S';
// //         const char END = 'E';
// //         const char BLOCK = 'O';

// //         MazePathFinding(vector<vector<char>> maze){
// //             this->maze = maze;
// //         }

// //         // finding the start index
// //         pair<int, int> find_start_point(vector<vector<char>>& maze) {
// //             pair<int, int> start_index; 
// //             for (int i = 0; i < maze.size(); i++) {
// //                 for (int j = 0; j < maze[i].size(); j++) {
// //                     if (maze[i][j] == START) 
// //                         start_index = {i, j};
// //                 }
// //             }
// //             return start_index;
// //         }

// //         // Utility Function to check of "O" or "E" ('O' means BLOCK and 'E' means END)
// //         bool check_for_O_or_E(vector<vector<char>> &maze, string next_move, pair<int, int> current_index){
// //             bool isPossible = false;
// //             if(next_move == DOWN){
// //                 if(maze[current_index.first + 1][current_index.second] == BLOCK || maze[current_index.first + 1][current_index.second] == END)
// //                     isPossible = true;
// //             }
// //             else if(next_move == RIGHT){
// //                 if(maze[current_index.first][current_index.second + 1] == BLOCK || maze[current_index.first][current_index.second + 1] == END)
// //                     isPossible = true;
// //             }
// //             else if(next_move == UP){
// //                 if(maze[current_index.first - 1][current_index.second] == BLOCK || maze[current_index.first - 1][current_index.second] == END)
// //                     isPossible = true;
// //             }
// //             else if(next_move == LEFT){
// //                 if(maze[current_index.first][current_index.second - 1] == BLOCK || maze[current_index.first][current_index.second - 1] == END)
// //                     isPossible = true;
// //             }
// //             return isPossible;
// //         }
// //         // Utility function to check in the hash table if a particular BLOCK is visited or not
// //         bool isVisited(pair<int, int> current_index, string next_move){
// //             bool isPossible = false;
// //             if(next_move == DOWN){
// //                 if(visited[{current_index.first + 1, current_index.second}])
// //                     isPossible = true;
// //             }
// //             else if(next_move == RIGHT){
// //                 if(visited[{current_index.first, current_index.second + 1}])
// //                     isPossible = true;
// //             }
// //             else if(next_move == UP){
// //                 if(visited[{current_index.first - 1, current_index.second}])
// //                     isPossible = true;
// //             }
// //             else if(next_move == LEFT){
// //                 if(visited[{current_index.first, current_index.second - 1}])
// //                     isPossible = true;
// //             }
// //             return isPossible;
// //         }

// //         // Utility function for above 2 utility functions (combining above two conditions)
// //         bool combined_check(vector<vector<char>> &maze, pair<int, int> current_index, string next_move){
// //             bool isPossible = false;
// //             if(next_move == DOWN){
// //                 if(current_index.first + 1 < maze.size() && check_for_O_or_E(maze, DOWN, current_index) && !isVisited(current_index, DOWN))
// //                     isPossible = true;
// //             }
// //             else if(next_move == RIGHT){
// //                 if(current_index.second + 1 < maze[0].size() && check_for_O_or_E(maze, RIGHT, current_index) && !isVisited(current_index, RIGHT))
// //                     isPossible = true;
// //             }
// //             else if(next_move == UP){
// //                 if(current_index.first - 1 >= 0 && check_for_O_or_E(maze, UP, current_index) && !isVisited(current_index, UP))
// //                     isPossible = true;
// //             }
// //             else if(next_move == LEFT){
// //                 if(current_index.second - 1 >= 0 && check_for_O_or_E(maze, LEFT, current_index) && !isVisited(current_index, LEFT))
// //                     isPossible = true;
// //             }
// //             return isPossible;
// //         }

// //         // Moving the current_index to the next Fesable Block
// //         pair<int, int> next_fesable_move(vector<vector<char>>& maze, pair<int, int> current_index) {
// //             int rows = maze.size();
// //             int columns = maze[0].size();
// //             if (combined_check(maze,current_index,  DOWN)) {
                
// //                     current_index.first += 1;
// //             }
// //             else if (combined_check(maze,current_index,  RIGHT)) {
                
// //                     current_index.second += 1;
// //             }
// //             else if (combined_check(maze,current_index,  UP)) {
                
// //                     current_index.first -= 1;
// //             }
// //             else if (combined_check(maze,current_index,  LEFT)) {
                
// //                     current_index.second -= 1;
// //             }
// //             return current_index;
// //         }

// //         // Utility Fuction to check if the next move is Fesable or not
// //         bool ifNextMovePossible(vector<vector<char>>& maze, pair<int, int> current_index) {
// //             bool is_fesable = false;
            
// //             if (combined_check(maze,current_index,  DOWN)) {
// //                     is_fesable = true;
// //             }
// //             else if (combined_check(maze,current_index,  RIGHT)) {
                
// //                     is_fesable = true;
// //             }
// //             else if (combined_check(maze,current_index,  UP)) {
                
// //                     is_fesable = true;
// //             }
// //             else if (combined_check(maze,current_index,  LEFT)) {
            
// //                     is_fesable = true;
// //             }
// //             else
// //                 is_fesable = false;
// //             return is_fesable;
// //         }

// //         // Depth First Search Function combining all the above utility function 
// //         // to return a stack of possible moves
// //         stack<pair<int, int>> depth_first_search() {
// //             pair<int, int> start_index = find_start_point(maze);
// //             pair<int, int> current_index = start_index;
// //             stack<pair<int, int>> st;
// //             // pushing the start_index
// //             st.push(start_index);
// //             // setting the start_index as visited
// //             visited[start_index] = true;
// //             while (maze[current_index.first][current_index.second] != 'E') {

// //                 // if Next move is possible then move the current_index to next fesable block
// //                 // and update the stack and hashtable accordingly
// //                 if (ifNextMovePossible(maze, current_index)) {
// //                     current_index = next_fesable_move(maze, current_index);
// //                     visited[current_index] = true;
// //                     st.push(current_index);
// //                 }
// //                 // If there is on fesable move, then backtrack to the last last index
// //                 // and set it to the current_index
// //                 else if (!ifNextMovePossible(maze, current_index)) {
// //                     //pair<int, int> temp = st.top();
// //                     st.pop();
// //                     current_index = st.top();
// //                 }
// //             }
// //             // finally after doing the DFS the final stack will contain all the possible moves to reach the END point
// //             return st;
// //         }
// //         void printPath(){
// //             stack<pair<int, int>> path = depth_first_search();
// //             vector<pair<int, int>> vt;
// //             while(!path.empty()){
// //                 vt.push_back(path.top());
// //                 path.pop();
// //             }
// //             for(int i = vt.size() - 1; i >= 0; i--){
// //                 cout << '(' << vt[i].first << ", " << vt[i].second << ')' << " -> " ;
// //             }
// //             cout << endl;
// //         }
// // };

// // int main() {
    
// //     // 'O' means empty space (BLOCK)
// //     // 'X' means barrier
// //     // 'S' means start point
// //     // 'E' means end point


// //     // vector<vector<char>> maze = {
// //     //     {'S', 'E', 'O', 'O', 'O', 'X'},
// //     //     {'O', 'X', 'O', 'O', 'O', 'O'},
// //     //     {'O', 'X', 'X', 'X', 'O', 'O'},
// //     //     {'O', 'X', 'O', 'O', 'O', 'O'},
// //     //     {'O', 'O', 'O', 'O', 'O', 'O'},
// //     //     {'O', 'X', 'O', 'X', 'O', 'O'},
// //     //     {'O', 'O', 'O', 'O', 'X', 'O'},
// //     //     {'O', 'O', 'O', 'O', 'O', 'O'},
// //     // };

// //     vector<vector<char>> maze = {
// //         {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
// //         {'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
// //         {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X'},
// //         {'S', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X'},
// //         {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
// //         {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
// //         {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X'},
// //         {'X', 'O', 'O', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'X'},
// //         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X'},
// //         {'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'X'},
// //         {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
// //         {'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X'},
// //         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'X'},
// //         {'X', 'O', 'X', 'O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
// //         {'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
// //         {'X', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X'},
// //         {'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X'},
// //         {'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
// //         {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'E', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},    
// //     };

    
// //     // vector<vector<char>> maze = {
// //     //     {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','S','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
// //     //     {'X','O','O','O','X','O','X','O','O','O','X','O','O','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','O','O','X','O','O','O','X','O','X'},
// //     //     {'X','X','X','O','X','O','X','O','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X','O','X','O','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','X','O','X','O','X','O','X','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','X','O','X','O','X','O','X','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','X'},
// //     //     {'X','O','X','X','X','O','X','O','X','O','X','O','X','X','X','O','X','X','X','X','X','O','X','O','X','X','X','X','X','X','X','O','X','X','X','X','X','O','X','X','X'},
// //     //     {'X','O','O','O','O','O','X','O','X','O','X','O','O','O','X','O','O','O','O','O','X','O','X','O','O','O','O','O','O','O','X','O','X','O','O','O','X','O','O','O','X'},
// //     //     {'X','O','X','X','X','X','X','O','X','O','X','X','X','O','X','O','X','X','X','X','X','O','X','X','X','X','X','X','X','O','X','O','X','X','X','O','X','X','X','O','X'},
// //     //     {'X','O','O','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','X','O','O','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','X'},
// //     //     {'X','X','X','O','X','O','X','X','X','X','X','O','X','X','X','X','X','O','X','O','X','X','X','X','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','X','O','X','O','X','O','O','O','O','O','X','O','X','O','X','O','X'},
// //     //     {'X','O','X','X','X','X','X','X','X','O','X','X','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','X','O','O','O','X','O','X','O','X','O','X','O','X','O','O','O','O','O','X','O','X','O','X'},
// //     //     {'X','X','X','O','X','O','X','O','X','X','X','O','X','X','X','O','X','O','X','O','X','X','X','O','X','O','X','X','X','O','X','O','X','O','X','X','X','O','X','X','X'},
// //     //     {'X','O','X','O','O','O','X','O','X','O','O','O','O','O','X','O','X','O','X','O','X','O','O','O','X','O','X','O','O','O','X','O','X','O','O','O','X','O','O','O','X'},
// //     //     {'X','O','X','O','X','X','X','O','X','O','X','X','X','O','X','O','X','O','X','O','X','O','X','X','X','O','X','O','X','O','X','X','X','X','X','X','X','X','X','O','X'},
// //     //     {'X','O','X','O','O','O','X','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','O','O','X','O','O','O','O','O','X','O','O','O','X','O','X'},
// //     //     {'X','O','X','X','X','O','X','O','X','X','X','X','X','O','X','X','X','X','X','O','X','X','X','X','X','O','X','X','X','O','X','X','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','X','X','X','X','X','X','X','X','O','X','O','X','X','X','X','X','O','X','X','X','O','X','O','X','X','X','O','X','O','X','O','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','O','X','O','O','O','O','O','O','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','X','O','X','O','O','O','X','O','O','O','X'},
// //     //     {'X','O','X','O','X','X','X','X','X','X','X','X','X','X','X','O','X','X','X','O','X','X','X','O','X','O','X','O','X','X','X','O','X','X','X','X','X','X','X','X','X'},
// //     //     {'X','O','O','O','X','O','O','O','X','O','O','O','X','O','X','O','O','O','O','O','X','O','X','O','X','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','X'},
// //     //     {'X','X','X','X','X','O','X','O','X','O','X','O','X','O','X','X','X','O','X','X','X','O','X','O','X','O','X','X','X','O','X','X','X','O','X','O','X','X','X','O','X'},
// //     //     {'X','O','O','O','O','O','X','O','O','O','X','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','X'},
// //     //     {'X','O','X','X','X','X','X','X','X','X','X','O','X','X','X','O','X','X','X','O','X','O','X','X','X','X','X','O','X','O','X','X','X','X','X','X','X','O','X','O','X'},
// //     //     {'X','O','X','O','X','O','O','O','O','O','X','O','X','O','X','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','O','O','O','O','X','O','X'},
// //     //     {'X','O','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X','O','X','X','X','X','X','X','X','O','X','X','X','X','X','X','X','O','X','X','X','X','X','O','X'},
// //     //     {'X','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','O','O','O','O','X'},
// //     //     {'X','O','X','O','X','X','X','O','X','O','X','O','X','X','X','O','X','O','X','O','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X','O','X','X','X','X','X'},
// //     //     {'X','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','X','O','X','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','O','O','X'},
// //     //     {'X','O','X','X','X','O','X','X','X','X','X','X','X','O','X','X','X','O','X','O','X','O','X','O','X','O','O','O','X','X','X','X','X','X','X','O','X','X','X','X','X'},
// //     //     {'X','O','O','O','X','O','X','O','O','O','O','O','X','O','O','O','X','O','X','O','X','O','X','O','X','O','X','O','X','O','O','O','O','O','X','O','X','O','O','O','X'},
// //     //     {'X','X','X','O','X','O','X','O','X','X','X','O','X','X','X','O','X','O','X','O','X','O','X','O','X','O','X','X','X','O','X','X','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','X','O','X','O','X','O','X','O','O','O','X','O','O','O','X','O','X','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','X','O','X','O','X'},
// //     //     {'X','O','X','X','X','X','X','O','X','O','X','O','X','O','X','X','X','X','X','O','X','O','X','X','X','X','X','O','X','X','X','O','X','X','X','X','X','X','X','O','X'},
// //     //     {'X','O','X','O','O','O','O','O','X','O','X','O','X','O','O','O','O','O','O','O','X','O','X','O','O','O','O','O','X','O','X','O','X','O','O','O','X','O','O','O','X'},
// //     //     {'X','O','X','O','X','X','X','O','X','O','X','O','X','X','X','X','X','X','X','X','X','O','X','O','X','X','X','X','X','O','X','O','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','X','O','O','O','X','O','X','O','O','O','X','O','O','O','X','O','O','O','X','O','O','O','O','O','O','O','X','O','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','X','X','X','X','O','X','X','X','O','X','X','X','O','X','X','X','O','X','O','X','X','X','X','X','X','X','X','X','O','X','O','X','O','X','O','X','O','X','O','X'},
// //     //     {'X','O','O','O','O','O','O','O','O','O','O','O','X','O','O','O','O','O','X','O','O','O','X','O','O','O','O','O','O','O','X','O','O','O','X','O','O','O','X','O','X'},
// //     //     {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','E','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
// //     //     };


    
// //     MazePathFinding mpf(maze);
// //     mpf.printPath();
// // }