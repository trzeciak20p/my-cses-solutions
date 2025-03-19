#include <iostream>

enum t_status{
    checked,
    to_check,
    update_around,
    waiting
};

struct t_pos{
    int x;
    int y;
};

void displayStatus(t_status *status[], int cols, int rows){
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << status[i][j];
        }    
        std::cout << "\r\n";
    }
    std::cout << "\r\n"; 
}

t_pos checkBounds(t_pos pos, int col_size, int row_size){
    if (pos.x < 0){
        pos.x = 0;
    }else if(pos.x > col_size-1){
        pos.x = col_size-1;
    }
    if (pos.y < 0){
        pos.y = 0;
    }else if(pos.y > row_size-1){
        pos.y = row_size-1;
    } 
    return pos;
}

bool updateTile(bool *map[], t_status *status[], t_pos pos){
    if (!map[pos.x][pos.y] && status[pos.x][pos.y] == t_status::waiting)
    {
        status[pos.x][pos.y] = t_status::to_check;
        return true;
    }
    return false;
}

void toCheckToUpdateAround(t_status *status[], int cols, int rows){
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (status[i][j] == t_status::to_check)
            {
                status[i][j] = t_status::update_around;
            }
        }    
    }
}

bool floodTick(bool *map[], t_status *status[], int cols, int rows){
    bool to_updated = false;
    // displayStatus(status, cols, rows);
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (status[i][j] == t_status::update_around)
            {                
                to_updated = updateTile(map, status, checkBounds({i+1,j}, cols, rows)) || to_updated;
                to_updated = updateTile(map, status, checkBounds({i-1,j}, cols, rows)) || to_updated;
                to_updated = updateTile(map, status, checkBounds({i,j+1}, cols, rows)) || to_updated;
                to_updated = updateTile(map, status, checkBounds({i,j-1}, cols, rows)) || to_updated;
                
                status[i][j] = t_status::checked;
                toCheckToUpdateAround(status, cols, rows);
                // displayStatus(status, cols, rows);
            }
        }
    }
    return to_updated;
}

void findRoomBorders(bool *map[], t_status *status[], int cols, int rows, t_pos start){
    status[start.x][start.y] = t_status::update_around;

    while(floodTick(map, status, cols, rows));
    // floodTick(map, status, cols, rows);

    // displayStatus(status, cols, rows);
}



int getRoomCount(bool *map[], int cols, int rows){
    int room_count = 0;

    t_status *status[cols]{};
    for (int i = 0; i < cols; i++)
    {
        t_status *row = new t_status[rows]{};
        for (int j = 0; j < rows; j++)
        {
            row[j] = t_status::waiting;
        }    
        status[i] = row;
    }

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (status[i][j] != t_status::checked && !map[i][j])
            {
                // std::cout << ".";
                room_count++;
                std::cout << room_count<<"--------\r\n";
                findRoomBorders(map, status, cols, rows, {i, j});
            }else{
                // std::cout << "#";
            }
        }   
        std::cout << "\r\n";
    }


    for (int i = 0; i < cols; i++)
    {
        delete[] status[i];
    }
    // delete status;
    return room_count;
}

int main(int argc, char const *argv[])
{

    int cols = 5;
    int rows = 8;
    // std::cin >> rows;
    // std::cin >> cols;


    bool *map[cols] = {
        new bool[rows]{0,0,0,1,0,0,0,1},
        new bool[rows]{0,0,0,1,1,1,1,1},
        new bool[rows]{0,0,0,1,0,0,0,1},
        new bool[rows]{1,1,1,1,1,1,1,0},
        new bool[rows]{1,1,1,1,1,0,0,0}
    };

    std::cout << getRoomCount(map, cols, rows) << "\r\n";

    return 0;
}