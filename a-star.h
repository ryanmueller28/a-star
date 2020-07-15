/***
 * The A* variant of Dijkstra's algorithm without 
 * using a class the algorithm is contained inside a single
 * namespace, the goal is to perform the algorithm
 * in a data oriented way, with some Object Oriented
 * Principles included.
 * 
 * CODE by: Ryan Mueller and Nathan Derr
 * GitHub: @ryanmueller28 and @naderr34
 * 
 * Inspirations and attributions:
 * 
 * -------------------------
 * JavidX9 - One Lone Coder
 * His fantastic video on the topic in the OLC console engine
 * and the source code included are huge inspirations, OLC's source code
 * licensed under GNU GPLv3
 * -------------------------
 * Geeks for Geeks
 * Their A* explanation gives a solid explanation of
 * how to do the algorithm in a Data Oriented way
 * -------------------------
 * EXPLANATION:
 * The A* algorithm is a Breadth (or Best) First Search variant of the
 * Popular Dijkstra's Shortest Path algorithm. The A* algorithm employs 
 * heuristics when testing nodes distance to a node and to the destination, which reduces
 * the total number of comparisons needed to find the shortest path
 * 
 * 
 * */

#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

namespace astar
{
    /**
     * A struct that will hold the parameters
     * the shortest path algorithm is cheking
     * 
     * */
    struct Node
    {
        // The distance to global goal and next goal
        float fGlobalGoal, fLocalGoal;

        // have we visited the node
        bool bVisited = false; 

        // Is this node in the way of the path?
        float bObstacle = false;

        // The node's position in 2D space
        int xPos, yPos; 

        // A vector of nodes next to the node
        std::vector<Node*> neighbors;
        Node* nParent;
    };

    Node *nodes = nullptr;
    int height = 16;
    int width = 16;

    Node *nodeStart = nullptr;
    Node *nodeEnd = nullptr;

    bool isValid(int row, int col)
    {
        return (row >= 0) && (row < width) && (col >= 0) && (col < height);
    }

    bool isDestination(int row, int col, Node* dest)
    {
        if (row == nodeEnd->xPos && col == nodeEnd->yPos)
        {
            return true;
        }
        return false;
    }

    // ripple the heuristic
    double calculateHeuristic(int row, int col, Node* destination)
    {

    }

    // A bool funciton to return if a node cannot be passed through
    bool isObstacle(Node* node, int row, int col)
    {
        if (node->bObstacle)
        {
            return true;
        }
        
        return false;
    }
    
    //function to create the grid
    std::vector<std::vector<int> > createGrid(int rows, int columns, int low, int high){
        std::srand(9);
        std::vector<std::vector<int> > vect(rows);
        for(int i = 0; i < rows; i++){
          for(int j = 0; j < columns; j++){
            vect[i].push_back(std::rand() % high + low);
          }
        }
        return vect;
    }

    /*
    * TO DO: A function to change the graph 
    * which changes what nodes are bObstacles
    * 
    * */
    std::vector<std::vector<int> > addBarriers(int high, int xStart, int yStart, int xEnd, int yEnd, int barriers, std::vector<std::vector<int> > vect){
        int barrierValue = high + 1; //this will represent the barriers. if ran into, set node.bObstacle to True
        int x = vect[0].size();
        int y = vect.size();

        //get random locations for the barriers
        std::srand(9);
        for(int i = 0; i < barriers; i++){
            int xNum = std::rand() % x + 0;
            int yNum = std::rand() % y + 0;
            if(xNum != xStart && yNum !=yStart){
                if(xNum != xEnd && yNum !=yEnd){
                    vect[xNum][yNum] = barrierValue;
                }
            }
        }
        return vect;
    }


    

    /**
     * TO DO:
     * Function to check heuristics of neighbor nodes
     * */

    /**
     * TO DO:
     * Function to solve A*
     * */
    
};