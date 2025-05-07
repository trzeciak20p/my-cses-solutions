#include <iostream>

enum env{
    wall = '#',
    empty = '.',
    start = 'A',
    finish = 'B'
};

struct t_pos{
    int x;
    int y;
};

void displayPath(int** path, int cols, int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cout << path[i][j] << " ";
        }
        std::cout << "\r\n";
    }
    std::cout << "\r\n";
}

bool checkBounds(const t_pos& pos, const int col_size, const int row_size){
    return !(pos.x < 0 || pos.x > col_size-1 || pos.y < 0 || pos.y > row_size-1);
}

void tickTile(env** map, int** path, int cols, int rows, const int tick, const t_pos pos){
    if (map[pos.x][pos.y] != env::wall && path[pos.x][pos.y] == 0 && checkBounds({pos.x, pos.y}, rows, cols))
    {
        path[pos.x][pos.y] = tick;
    }
}

void tickAdjacent(env** map, int** path, int cols, int rows, const int tick, const t_pos pos){
    tickTile(map, path, cols, rows, tick, {pos.x+1,pos.y});
    tickTile(map, path, cols, rows, tick, {pos.x-1,pos.y});
    tickTile(map, path, cols, rows, tick, {pos.x,pos.y+1});
    tickTile(map, path, cols, rows, tick, {pos.x,pos.y-1});   
}

bool checkForFinish(env** map, int** path, int cols, int rows){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (map[i][j] == env::finish && path[i][j] != 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool tickFlood(env** map, int** path, int cols, int rows, const int tick){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (path[i][j] == tick)
            {
                tickAdjacent(map, path, cols, rows, tick+1, {i,j});
            }      
        }
    }

    if (checkForFinish(map, path, cols, rows))
    {
        return false;
    }  
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (path[i][j] == tick+1)
            {
                return true;
            }           
        }        
    }
    return false;
}

bool checkPathTile(int** path, t_pos pos, int cols, int rows, int tick){
    return checkBounds(pos, rows, cols) && path[pos.x][pos.y] == tick;
}

std::string reverseTrack(env** map, int** path, int cols, int rows){
    t_pos pos{};
    int finish_tick = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] == env::finish)
            {
                if (path[i][j] == 0)    // no path found
                {
                    return "NO";
                }
                finish_tick = path[i][j];
                pos = {i,j};
            }        
        }        
    }

    std::string res = "";
    while (finish_tick > 1)
    {
        finish_tick--;
        if (checkPathTile(path, {pos.x+1, pos.y}, cols, rows, finish_tick))
        {
            pos = {pos.x+1, pos.y};
            res = 'U' + res;
        }else if (checkPathTile(path, {pos.x-1, pos.y}, cols, rows, finish_tick))
        {
            pos = {pos.x-1, pos.y};
            res = 'D' + res;
        }else if (checkPathTile(path, {pos.x, pos.y+1}, cols, rows, finish_tick))
        {
            pos = {pos.x, pos.y+1};
            res = 'L' + res;
        }else if (checkPathTile(path, {pos.x, pos.y-1}, cols, rows, finish_tick))
        {
            pos = {pos.x, pos.y-1};
            res = 'R' + res;
        }else{
            std::cout << res << "\r\n";
            return "NO";
        }
    }
    return res;
}

std::string findPath(env** map, int cols, int rows){
    int** path = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        path[i] = new int[cols]{};
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] == env::start){
                path[i][j] = 1;
            }else if(map[i][j] == env::wall){
                path[i][j] = 0;
            }
        }       
    }

    int tick = 1;
    while (tickFlood(map, path, cols, rows, tick)){
        // displayPath(path, cols, rows);
        tick++;
    }
    // displayPath(path, cols, rows);
    
    std::string res = reverseTrack(map, path, cols, rows);
    for (int i = 0; i < rows; i++)
    {
        delete[] path[i];
    }
    delete[] path;
    return res;
}

int main(int argc, char const *argv[])
{
    int rows = 5;
    int cols = 8;

    env** map = new env*[rows]{
        new env[cols]{(env)'#', (env)'#', (env)'#', (env)'#', (env)'#', (env)'#', (env)'#', (env)'#'},
        new env[cols]{(env)'#', (env)'.', (env)'A', (env)'#', (env)'.', (env)'.', (env)'.', (env)'#'},
        new env[cols]{(env)'#', (env)'.', (env)'#', (env)'#', (env)'.', (env)'#', (env)'.', (env)'#'},
        new env[cols]{(env)'#', (env)'.', (env)'.', (env)'B', (env)'.', (env)'.', (env)'.', (env)'#'},
        new env[cols]{(env)'#', (env)'#', (env)'#', (env)'#', (env)'#', (env)'#', (env)'#', (env)'#'},
    };

    std::cout << findPath(map, cols, rows) << "\r\n";

    return 0;
}