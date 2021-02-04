//
// Created by Ankit Batra on 2/3/21.
//

/* Design a Snake game that is played on a device with screen size height x width.
 * Play the game online if you are not familiar with the game.
 * The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.
 * You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of
 * food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.
 * Each piece of food appears one by one on the screen, meaning the second piece of food will not
 * appear until the snake eats the first piece of food.
 * When a piece of food appears on the screen, it is guaranteed that it will not appear on a block
 * occupied by the snake.
 * The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space
 * that its body occupies after moving (i.e. a snake of length 4 cannot run into itself).
 * Implement the SnakeGame class:
 * SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size
 * height x width and the positions of the food.
 * int move(String direction) Returns the score of the game after applying one direction move by the snake.
 * If the game is over, return -1. */

#include <deque>
#include <set>
#include <string>
#include <vector>

using std::deque;
using std::pair;
using std::set;
using std::string;
using std::vector;

class SnakeGame {
    int w;
    int h;
    int score;
    vector<vector<int>> food;
    int foodPos;
    set<pair<int, int>> history;
    deque<pair<int, int>> snake;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;
        score = 0;
        this->food = food;
        foodPos = 0;
        snake.push_front({0, 0});
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> loc = snake.front();
        int headR = loc.first, headC = loc.second;
        if (direction == "U") headR--;
        else if (direction == "L") headC--;
        else if (direction == "R") headC++;
        else headR++;

        if (headR < 0 || headR >= h || headC < 0 || headC >= w) return -1;

        if (foodPos < food.size() && food[foodPos][0] == headR && food[foodPos][1] == headC) {
            snake.push_front({headR, headC});
            history.insert({headR, headC});
            foodPos++;
            score += 1;
        }
        else {
            pair<int, int> p = snake.back();
            snake.pop_back();
            history.erase(p);

            if (history.find({headR, headC}) != history.end()) return -1;
            else {
                snake.push_front({headR, headC});
                history.insert({headR, headC});
            }
        }

        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */

