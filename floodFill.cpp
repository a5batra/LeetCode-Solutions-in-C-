//
// Created by Ankit Batra on 5/13/21.
//

/* An image is represented by a 2-D array of integers, each integer representing the pixel value of the image
 * (from 0 to 65535).
 * Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a
 * pixel value newColor, "flood fill" the image.
 * To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the
 * starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those
 * pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the
 * aforementioned pixels with the newColor.
 * At the end, return the modified image. */

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        if (m == 0) return image;
        int n = image[0].size();

        int currColor = image[sr][sc];

        dfs(image, sr, sc, currColor, newColor);

        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int currColor, int newColor) {
        if (sr >= image.size() || sc >= image[0].size() || image[sr][sc] != currColor || image[sr][sc] == newColor) return;
        image[sr][sc] = newColor;
        dfs(image, sr, sc + 1, currColor, newColor);
        dfs(image, sr + 1, sc, currColor, newColor);
        dfs(image, sr, sc - 1, currColor, newColor);
        dfs(image, sr - 1, sc, currColor, newColor);
    }
};

