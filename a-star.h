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
#include <limits>
#include <cmath>

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
        unsigned uGlobalGoalX, uGlobalGoalY, uLocalGoalX, uLocalGoalY;



        // have we visited the node
        bool bVisited = false; 

        // Is this node in the way of the path?
        float bObstacle = false;

        // The node's position in 2D space
        unsigned xPos, yPos; 

        // Weights
        unsigned dX = std::abs(xPos - uGlobalGoalX);
        unsigned dY = std::abs(yPos - uGlobalGoalY);
        unsigned localX = std::abs(xPos - uLocalGoalX);
        unsigned localY = std::abs(yPos - uLocalGoalY);

        unsigned uGlobalDist = std::sqrt(dX * dX + dY * dY);
        unsigned uLocalDist = std::sqrt(localY * localY + localX + localX);

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

    /*
    * TO DO: A function to change the graph 
    * which changes what nodes are bObstacles
    * 
    * */
    std::vector<std::vector<int>> createGrid(int rows, int columns, int low, int high){
        std::srand(5);
        std::vector<std::vector<int>> vect(rows, std::vector<int> (columns, std::rand() % high + low));
        return vect;
    }
    

    /**
     * TO DO:
     * Function to check heuristics of neighbor nodes
     * */

    unsigned getNextWeight(Node* currNode, Node* nextNode)
    {
        // Current node is root?
        if (currNode->nParent == NULL)
        {
            currNode->xPos = 0;
            currNode->yPos = 0;

            // We don't know anything about anyone else yet!
            // Set heuristic to infinity
            currNode->uGlobalGoalX = std::numeric_limits<unsigned>::infinity();
            currNode->uGlobalGoalY = std::numeric_limits<unsigned>::infinity();
            currNode->uLocalGoalX = std::numeric_limits<unsigned>::infinity();
            currNode->uLocalGoalY = std::numeric_limits<unsigned>::infinity();
        }

        // if the local goal is less than what we have already
        if (nextNode->xPos < currNode->uLocalGoalX && nextNode->yPos < currNode->uLocalGoalY)
        {
            currNode->uLocalGoalY = nextNode->yPos;
            currNode->uLocalGoalX = nextNode->xPos;

            currNode->neighbors.push_back(nextNode);
        }

        return currNode->uLocalDist;

    }


    /**
     * TO DO:
     * Function to solve A*
     * */
    
};