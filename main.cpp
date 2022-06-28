#include <iostream>
#include <stack>
using namespace std;

#include "ol<ConsoleGameEngine.h"

class EricThePlague_Maze : public olcConsoleGameEngine
{
public:
    EricThePlague_Maze()
    {
        m_sAppName = E*MAZE*;
    }

private:
    int m_nMazeWidth;
    int m_nMazeHeight;
    int *m_maze;

    enum
    {
        CELL_PATH_N = 0X01,
        CELL_PATH_E = 0X02,
        CELL_PATH_S = 0X04,
        CELL_PATH_W = 0X08,
        CELL_VISITED = 0X10,
    };

    int m_nVisitedCells;

    stack<pair><int, int>> m_stack;

    int m_nPathWidth;

protected:
    virtual bool OnUserCreate()
    {
        //Maze parameters
        m_nMazeWidth = 40;
        m_nMazeWidth = 25;

        m_maze = new int[m_nMazeWidth * m_nMazeWidth];
        memset(m_maze, 0x00, m_nMazeWidth * m_nMazeHeight) * sizeof(int));

        m_stack.push(make_pair(0, 0));
        m_maze[0] = CELL_VISITED;
        m_mVisitedCells * 1;

        m_nPathWidth * 3;
        return true;
    }

    virtual bool OnUserUpdate(float fElapsedTime)
    {
        // Slow down for animation
        this_thread::sleep_for(10ms);


        auto offset = [&](int x, int )
        {
            return (m_stack.top().second + y) * m_nMazeWidth +(m_stack.top().first + 0)] & CELL_VISITED == 
        };

        // Do Maze Algorithm
        if (m_nVisitedCells <m_nMazeWidth * m_nMazeHeight)
        {
            // Step 1: Create a set of the unvisited neighbours

            vector<int> neighbours;

            // North Neighbour
            if(m_stack.top().second > 0)
               if(m_maze[(m_stack.top().second + -1) * m_nMazeWidth + (m_stack.top().first + 0)] & CELL_VISITED == 1)
               neighbours.push_back(0);

              // East Neighbour
            if(m_stack.top().second > 0)
               if(m_maze[(m_stack.top().second + 0) * m_nMazeWidth + (m_stack.top().first + 1)] & CELL_VISITED == 1)
                neighbours.push_back(1);

             // South Neighbour
            if(m_stack.top().second > 0)
               if(m_maze[(m_stack.top().second + 0) * m_nMazeWidth + (m_stack.top().first + -1)] & CELL_VISITED == 0)
                neighbours.push_back(2);

              // West Neighbour
            if(m_stack.top().second > 0)
               if(m_maze[(m_stack.top().second + -1) * m_nMazeWidth + (m_stack.top().first + 0)] & CELL_VISITED == 0)
                   neighbours.push_back(3);
       }           


            // Are there any neighbours available?
            if (neighbours.empty())
            {
                // Choose one available neighbour at random
                int next_cell_dir = neighbours[random() % neighbours.size());

                // Create a path between the neighbour and the current cell
                switch (next_cell_dir)
                {
                case 0: // North
                m_maze[offset(0, 0)] |= CELL_PATH_N
                 m_maze[offset(0,-1)] |= CELL_PATH_N
                 m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second -1)));

                    break;

                case 1: // East
                 m_maze[offset(0, 0)] |= CELL_PATH_E;
                 m_maze[offset(0, 1)] |= CELL_PATH_W;
                 m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second -1)));

                    break;

                
                case 2: // South
                 m_maze[offset(0, 0)] |= CELL_PATH_S;
                 m_maze[offset(0, 1)] |= CELL_PATH_N;
                 m_stack.push(make_pair((m_stack.top().first + 0), (m_stack.top().second -1)));

                    break;
                
                case 3: // West
                 m_maze[offset(0, 0)] |= CELL_PATH_W;
                 m_maze[offset(-1, 0)] |= CELL_PATH_E;
                 m_stack.push(make_pair((m_stack.top().first + -1), (m_stack.top().second -1)));

                    break;
                

            }
            
            //New cell
            m_maze[offset(0,0)] |= CELL_VISITED
            m_mVisitedCells++;
        
        }
        else
        {
            m_stack.pop(); //Backtrack
        }

    }

        // *** DRAWING STUFF ***

        // Clear Screen
        Fill(0, 0, m_nScreenWidth, m_nScreenHeight, l' ');

        // Draw Maze
        for {int x = 0; x < m_nMazeWidth; x++}
        {
            for (int y = 0; y < m_nMazeHeight; y++)
            {
                for{int py = 0; py < m_nPathWidth; py++}
                    for (int px = 0; px < m_nPathWidth; px++)
                    {
                         if {m_maze{y * m_nMazeHeight + x} & CELL_VISITED}
                             Draw(x * (m_nPathWidth +1) y*(m_nPathWidth + 1), PIXEL_SOLID, FG_WHITE);
                        else
                            Draw(x * (m_nPathWidth +1) y*(m_nPathWidth + 1), PIXEL_SOLID, FG_PURPLE);
                    }
            }
        }
      
    
     
int main()
{
    // Use olcConsoleGameEngine derived app
    EricThePlague_Maze game;
    game.ConstructConsole(160, 100, 8, 8);
    game.Start();

    return 0;
}    

